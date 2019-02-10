/*
 * ROX-Filer, filer for the ROX desktop project
 * Copyright (C) 2006, Thomas Leonard and others (see changelog for details).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */
/* choices.c - code for handling loading and saving of user choices */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <fcntl.h>
#include <errno.h>

#include "global.h"

#include "gui_support.h"

#include "choices.h"

static gboolean saving_disabled = TRUE;
static GSList *dirs;

/* Static prototypes */
static gboolean exists(char *path);

/****************************************************************
 *			EXTERNAL INTERFACE			*
 ****************************************************************/


/* Reads in CHOICESPATH and constructs the directory list table.
 * You must call this before using any other choices_* functions.
 *
 * If CHOICESPATH does not exist then a suitable default is used.
 */
void choices_init(void)
{
	saving_disabled = FALSE;

	char *dir = g_build_filename(g_get_user_config_dir(), APPNAME, NULL);
	if (!g_file_test(dir, G_FILE_TEST_EXISTS))
		g_mkdir_with_parents(dir, 0700);

	dirs = g_slist_append(dirs, dir);

	for (const gchar * const *d = g_get_system_data_dirs(); *d; d++)
		dirs = g_slist_append(dirs, g_build_filename(*d, APPNAME, NULL));
}

void choices_free_list(GPtrArray *list)
{
	guint	i;

	g_return_if_fail(list != NULL);

	for (i = 0; i < list->len; i++)
		g_free(g_ptr_array_index(list, i));

	g_ptr_array_free(list, TRUE);
}

/* Get the pathname of a choices file to load, using the XDG paths. Eg:
 *
 * choices_find_xdg_path_load("menus", "ROX-Filer", "rox.sourceforge.net")
 *		 		-> "/etc/xdg/rox.sourceforge.net/ROX-Filer/menus".
 *
 * Falls back on choices_find_path_load(leaf, dir) if it fails
 * The return values may be NULL - use built-in defaults.
 * g_free() the result.
 */
gchar *choices_find_xdg_path_load(const char *leaf, const char *dir)
{
	for (GSList *d = dirs; d; d = d->next)
	{
		gchar	*path;

		if(dir)
			path = g_build_filename(d->data, dir, leaf, NULL);
		else
			path = g_build_filename(d->data, leaf, NULL);

		if (exists(path))
			return path;

		g_free(path);
	}

	return NULL;
}


/* Returns the pathname of a file to save to, or NULL if saving is
 * disabled. If 'create' is TRUE then intermediate directories will
 * be created (set this to FALSE if you just want to find out where
 * a saved file would go without actually altering the filesystem).
 *
 * g_free() the result.
 */
gchar *choices_find_xdg_path_save(const char *leaf, const char *dir,
				  gboolean create)
{
	if (saving_disabled) return NULL;

	char *path = g_build_filename(dirs->data, dir, NULL);
	if (create && !exists(path))
	{
		if (mkdir(path, 0777))
			g_warning("mkdir(%s): %s\n", path, g_strerror(errno));
	}

	char *retval = g_build_filename(path, leaf, NULL);
	g_free(path);

	return retval;
}

/*
 * Returns an array of the directories in XDG_CONFIG_HOME and XDG_CONFIG_DIRS
 * which contain a subdirectory called 'dir' (optionally in a subdirectory
 * called site).
 *
 * Lower-indexed results should override higher-indexed ones.
 *
 * Free the list using choices_free_list().
 */
GPtrArray *choices_list_xdg_dirs(char *dir)
{
	GPtrArray *list = g_ptr_array_new();

	for (GSList *d = dirs; d; d = d->next)
	{
		guchar *path = g_build_filename(d->data, dir, NULL);
		if (exists(path))
			g_ptr_array_add(list, path);
		else
			g_free(path);
	}

	return list;
}

/****************************************************************
 *			INTERNAL FUNCTIONS			*
 ****************************************************************/


/* Returns TRUE if the object exists, FALSE if it doesn't */
static gboolean exists(char *path)
{
	struct stat info;

	return stat(path, &info) == 0;
}
