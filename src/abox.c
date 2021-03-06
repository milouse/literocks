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

/* abox.c - the dialog box widget used for filer operations.
 *
 * The actual code for specific operations is in action.c.
 */

#include "config.h"

#include <string.h>

#include "global.h"

#include "main.h"
#include "abox.h"
#include "gui_support.h"
#include "filer.h"
#include "display.h"
#include "support.h"
#include "diritem.h"
#include "pixmaps.h"

#define RESPONSE_QUIET 1
// RESPONSE_SEQNO 2
// RESPONSE_SEQNO_ALL 3

/* Static prototypes */
static void abox_class_init(GObjectClass *gclass, gpointer data);
static void abox_init(GTypeInstance *object, gpointer gclass);
static gboolean abox_delete(GtkWidget *dialog, GdkEventAny *event);
static void response(GtkDialog *dialog, gint response_id);
static void abox_finalise(GObject *object);
static void shade(ABox *abox);

GType abox_get_type(void)
{
	static GType type = 0;

	if (!type)
	{
		static const GTypeInfo info =
		{
			sizeof (ABoxClass),
			NULL,			/* base_init */
			NULL,			/* base_finalise */
			(GClassInitFunc) abox_class_init,
			NULL,			/* class_finalise */
			NULL,			/* class_data */
			sizeof(ABox),
			0,			/* n_preallocs */
			(GInstanceInitFunc) abox_init
		};

		type = g_type_register_static(GTK_TYPE_DIALOG,
						"ABox", &info, 0);
	}

	return type;
}

GtkWidget* abox_new(const gchar *title, gboolean quiet)
{
	GtkWidget *widget;
	ABox	  *abox;

	widget = GTK_WIDGET(gtk_widget_new(abox_get_type(), NULL));
	abox = ABOX(widget);

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(abox->quiet), quiet);

	gtk_window_set_title(GTK_WINDOW(widget), title);
//	gtk_dialog_set_has_separator(GTK_DIALOG(widget), FALSE);

	return widget;
}

static void abox_class_init(GObjectClass *gclass, gpointer data)
{
	GtkWidgetClass *widget = (GtkWidgetClass *) gclass;
	GtkDialogClass *dialog = (GtkDialogClass *) gclass;
	ABoxClass *abox = (ABoxClass *) gclass;

	widget->delete_event = abox_delete;
	dialog->response = response;
	abox->flag_toggled = NULL;
	abox->abort_operation = NULL;

	g_signal_new("flag_toggled", G_TYPE_FROM_CLASS(gclass),
		G_SIGNAL_RUN_LAST, G_STRUCT_OFFSET(ABoxClass, flag_toggled),
		NULL, NULL, g_cclosure_marshal_VOID__INT,
		G_TYPE_NONE, 1, G_TYPE_INT);

	g_signal_new("abort_operation", G_TYPE_FROM_CLASS(gclass),
		G_SIGNAL_RUN_LAST, G_STRUCT_OFFSET(ABoxClass, abort_operation),
		NULL, NULL, g_cclosure_marshal_VOID__VOID,
		G_TYPE_NONE, 0);

	gclass->finalize = abox_finalise;
}

static void abox_init(GTypeInstance *object, gpointer gclass)
{
	GtkWidget *frame, *scrolledwin, *button;
	ABox *abox = ABOX(object);
	GtkDialog *dialog = GTK_DIALOG(object);
	int i;

	gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_MOUSE);

	abox->src_label = gtk_label_new(_("<src>"));
	gtk_widget_set_size_request(abox->src_label, 8, -1);
	gtk_label_set_ellipsize(GTK_LABEL(abox->src_label), PANGO_ELLIPSIZE_MIDDLE);
	make_heading(abox->src_label, 1.0);
	gtk_misc_set_alignment(GTK_MISC(abox->src_label), 0., 0.5);
	gtk_box_pack_start(VBOX(dialog), abox->src_label, FALSE, TRUE, 0);

	abox->results = NULL;
	abox->entry = NULL;
	abox->question = FALSE;

	abox->log_hbox = gtk_hbox_new(FALSE, 0);
	gtk_box_pack_start(VBOX(dialog), abox->log_hbox, TRUE, TRUE, 4);

	frame = gtk_frame_new(NULL);
	gtk_box_pack_start(GTK_BOX(abox->log_hbox), frame, TRUE, TRUE, 0);
	gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

	abox->log = gtk_text_view_new();
	scrolledwin = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_policy((void *)scrolledwin,
			GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
	gtk_container_add(GTK_CONTAINER(scrolledwin), abox->log);
	gtk_container_add(GTK_CONTAINER(frame), scrolledwin);

	gtk_text_buffer_create_tag(
			gtk_text_view_get_buffer(GTK_TEXT_VIEW(abox->log)),
			"error", "foreground", "red",
			NULL);
	gtk_text_buffer_create_tag(
			gtk_text_view_get_buffer(GTK_TEXT_VIEW(abox->log)),
			"question", "weight", PANGO_WEIGHT_BOLD,
			NULL);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(abox->log), FALSE);
	gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(abox->log), FALSE);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(abox->log), GTK_WRAP_WORD);
	gtk_widget_set_size_request(abox->log, 400, 70);

	abox->btn_cancel = gtk_dialog_add_button(dialog,
			GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
	abox->btn_close = gtk_dialog_add_button(dialog,
			GTK_STOCK_CLOSE, GTK_RESPONSE_CANCEL);

	abox->btn_seqno = gtk_button_new_with_label(_("+.Num"));
	gtk_dialog_add_action_widget(dialog, abox->btn_seqno, 2);
	abox->btn_seqno_all = button_new_mixed(GTK_STOCK_GOTO_LAST, _("+.Num"));
	gtk_dialog_add_action_widget(dialog, abox->btn_seqno_all, 3);

	gtk_dialog_add_buttons(dialog,
			GTK_STOCK_NO, GTK_RESPONSE_NO,
			GTK_STOCK_YES, GTK_RESPONSE_YES,
			NULL);

	abox->cmp_area = gtk_table_new(2, 6, FALSE);
	gtk_box_pack_start(VBOX(dialog), abox->cmp_area, FALSE, FALSE, 2);
	gtk_table_set_row_spacings(GTK_TABLE(abox->cmp_area), 2);
	gtk_table_set_col_spacings(GTK_TABLE(abox->cmp_area), 2);

	for (i = 0; i < 2; i++)
	{

		abox->cmp_icon[i] = gtk_image_new();
		gtk_table_attach(GTK_TABLE(abox->cmp_area),
				abox->cmp_icon[i],
				1, 2, i, i + 1,
				GTK_SHRINK, GTK_SHRINK, 4, 1);
		abox->cmp_name[i] = gtk_label_new("");
		gtk_label_set_line_wrap(GTK_LABEL(abox->cmp_name[i]), TRUE);
		gtk_label_set_line_wrap_mode(GTK_LABEL(abox->cmp_name[i]),
				PANGO_WRAP_WORD_CHAR);
		gtk_misc_set_alignment(GTK_MISC(abox->cmp_name[i]), 0., 0.5);
		gtk_table_attach(GTK_TABLE(abox->cmp_area),
				abox->cmp_name[i],
				2, 3, i, i + 1,
				 GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 4, 1);
		abox->cmp_size[i] = gtk_label_new("");
		gtk_table_attach(GTK_TABLE(abox->cmp_area),
				abox->cmp_size[i],
				3, 4, i, i + 1,
				GTK_SHRINK, GTK_SHRINK, 4, 1);
		abox->cmp_date[i] = gtk_label_new("");
		gtk_table_attach(GTK_TABLE(abox->cmp_area),
				abox->cmp_date[i],
				4, 5, i, i + 1,
				GTK_SHRINK, GTK_SHRINK, 4, 1);
	}
	abox->cmp_arrow=gtk_arrow_new(GTK_ARROW_DOWN, GTK_SHADOW_IN);
	gtk_widget_set_size_request(abox->cmp_arrow, 32, 64);
	gtk_table_attach(GTK_TABLE(abox->cmp_area),
				abox->cmp_arrow,
				0, 1, 0, 2,
				GTK_SHRINK, GTK_EXPAND | GTK_FILL, 1, 2);

	abox->progress=NULL;

	abox->flag_box = gtk_hbox_new(FALSE, 16);
	gtk_box_pack_end(VBOX(dialog), abox->flag_box, FALSE, TRUE, 2);

	abox->fileprog = gtk_progress_bar_new();
	gtk_widget_set_size_request(abox->fileprog, -1, small_height * (1./3.));
	gtk_box_pack_end(VBOX(abox), abox->fileprog, FALSE, TRUE, 2);

	button = button_new_mixed(GTK_STOCK_GOTO_LAST, _("_Quiet"));
	gtk_widget_set_can_default(button, TRUE);
	gtk_dialog_add_action_widget(dialog, button, RESPONSE_QUIET);
	gtk_dialog_set_default_response(dialog, RESPONSE_QUIET);

	gtk_widget_show_all(gtk_dialog_get_content_area(dialog));
	gtk_widget_hide(abox->cmp_area);
	gtk_widget_hide(abox->fileprog);
	gtk_widget_hide(abox->btn_close);
	gtk_widget_hide(abox->btn_seqno);
	gtk_widget_hide(abox->btn_seqno_all);

	abox->quiet = abox_add_flag(abox,
			_("Quiet"), _("Don't confirm every operation"),
			'Q', FALSE);

	shade(abox);
}

static void flag_toggled(GtkToggleButton *toggle, ABox *abox)
{
	gint	code;

	code = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(toggle),
						 "abox-response"));

	if (code == 'Q')
		shade(abox);

	g_signal_emit_by_name(abox, "flag_toggled", code);

}

GtkWidget *abox_add_flag(ABox *abox, const gchar *label, const gchar *tip,
		   	 gint response, gboolean default_value)
{
	GtkWidget	*check;

	check = gtk_check_button_new_with_label(label);
	gtk_widget_set_tooltip_text(check, tip);
	g_object_set_data(G_OBJECT(check), "abox-response",
			  GINT_TO_POINTER(response));
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check), default_value);
	g_signal_connect(check, "toggled", G_CALLBACK(flag_toggled), abox);
	gtk_box_pack_end(GTK_BOX(abox->flag_box), check, FALSE, TRUE, 0);
	gtk_widget_show(check);

	return check;
}

static void response(GtkDialog *dialog, gint response_id)
{
	ABox *abox = ABOX(dialog);

	if (response_id == GTK_RESPONSE_CANCEL)
		g_signal_emit_by_name(abox, "abort_operation");
	else if (response_id == RESPONSE_QUIET)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(abox->quiet), TRUE);
		gtk_dialog_response(dialog, GTK_RESPONSE_YES);
	}
	else if (response_id == GTK_RESPONSE_YES ||
					response_id == GTK_RESPONSE_NO ||
					response_id == 2 || response_id == 3) //seqno
	{
		abox->question = FALSE;
		shade(abox);
	}
}

/* Display the question. Unshade the Yes, No and entry box (if any).
 * Will send a response signal when the user makes a choice.
 */
void abox_ask(ABox *abox, const gchar *question)
{
	g_return_if_fail(abox != NULL);
	g_return_if_fail(question != NULL);
	g_return_if_fail(IS_ABOX(abox));

	abox_log(abox, question, "question");

	abox->question = TRUE;
	shade(abox);
}

void abox_cancel_ask(ABox *abox)
{
	g_return_if_fail(abox != NULL);
	g_return_if_fail(IS_ABOX(abox));

	abox->question = FALSE;
	shade(abox);
}

void abox_log(ABox *abox, const gchar *message, const gchar *style)
{
	GtkTextIter end;
	GtkTextBuffer *text_buffer;
	GtkTextView *log = GTK_TEXT_VIEW(abox->log);
	gchar *u8 = NULL;

	if (!g_utf8_validate(message, -1, NULL))
		u8 = to_utf8(message);

	text_buffer = gtk_text_view_get_buffer(log);

	gtk_text_buffer_get_end_iter(text_buffer, &end);
	gtk_text_buffer_insert_with_tags_by_name(text_buffer,
			&end, u8 ? u8 : message, -1, style, NULL);
	gtk_text_view_scroll_to_mark(
			log,
			gtk_text_buffer_get_mark(text_buffer, "insert"),
			0.0, FALSE, 0, 0);

	g_free(u8);
}

static void abox_finalise(GObject *object)
{
	GObjectClass *parent_class;

	parent_class = g_type_class_peek(GTK_TYPE_DIALOG);

	if (G_OBJECT_CLASS(parent_class)->finalize)
		(*G_OBJECT_CLASS(parent_class)->finalize)(object);
}

void abox_set_current_object(ABox *abox, const gchar *message)
{
	g_return_if_fail(abox != NULL);
	g_return_if_fail(message != NULL);
	g_return_if_fail(IS_ABOX(abox));

	gtk_label_set_text(GTK_LABEL(abox->src_label), message);
}

static void lost_preview(GtkWidget *window, ABox *abox)
{
	abox->preview = NULL;
}

static void select_row_callback(GtkTreeView *treeview,
				GtkTreePath *path,
				GtkTreeViewColumn *col,
				ABox	    *abox)
{
	GtkTreeModel	*model;
	GtkTreeIter	iter;
	char		*leaf, *dir;

	model = gtk_tree_view_get_model(GTK_TREE_VIEW(abox->results));
	gtk_tree_model_get_iter(model, &iter, path);
	gtk_tree_model_get(model, &iter, 0, &leaf, 1, &dir, -1);

	if (abox->preview)
	{
		if (strcmp(abox->preview->real_path, dir) == 0)
			display_set_autoselect(abox->preview, leaf);
		else
			filer_change_to(abox->preview, dir, leaf);
		goto out;
	}

	abox->preview = filer_opendir(dir, NULL, NULL, FALSE);
	if (abox->preview)
	{
		display_set_autoselect(abox->preview, leaf);
		g_signal_connect_object(abox->preview->window, "destroy",
				G_CALLBACK(lost_preview), abox, 0);
	}

out:
	g_free(dir);
	g_free(leaf);
}

/* Add a list-of-results area. You must use this before adding files
 * with abox_add_filename().
 */
void abox_add_results(ABox *abox)
{
	GtkTreeViewColumn	*column;
	GtkWidget	*scroller, *frame;
	GtkListStore	*model;
	GtkCellRenderer	*cell_renderer;

	g_return_if_fail(abox != NULL);
	g_return_if_fail(IS_ABOX(abox));
	g_return_if_fail(abox->results == NULL);

	scroller = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroller),
			GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

	frame = gtk_frame_new(NULL);
	gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
	gtk_box_pack_start(VBOX(abox), frame, TRUE, TRUE, 4);

	gtk_container_add(GTK_CONTAINER(frame), scroller);

	model = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
	abox->results = gtk_tree_view_new_with_model(GTK_TREE_MODEL(model));
	g_object_unref(G_OBJECT(model));

	cell_renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(
				_("Name"), cell_renderer, "text", 0, NULL);
	gtk_tree_view_column_set_resizable(column, TRUE);
	gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_GROW_ONLY);
	gtk_tree_view_append_column(GTK_TREE_VIEW(abox->results), column);
	gtk_tree_view_insert_column_with_attributes(
			GTK_TREE_VIEW(abox->results),
			1, (gchar *) _("Directory"), cell_renderer,
			"text", 1, NULL);

	gtk_container_add(GTK_CONTAINER(scroller), abox->results);

	gtk_widget_set_size_request(abox->results, 100, 100);
	gtk_box_set_child_packing(VBOX(abox),
			  abox->log_hbox, FALSE, TRUE, 4, GTK_PACK_START);

	g_signal_connect(abox->results, "row-activated",
			G_CALLBACK(select_row_callback), abox);

	gtk_widget_show_all(frame);
}

void abox_add_filename(ABox *abox, const gchar *path)
{
	GtkTreeModel *model;
	GtkTreeIter iter;
	gchar	*dir;
	gchar	*base = g_path_get_basename(path);

	model = gtk_tree_view_get_model(GTK_TREE_VIEW(abox->results));

	gtk_list_store_append(GTK_LIST_STORE(model), &iter);

	dir = g_path_get_dirname(path);
	gtk_list_store_set(GTK_LIST_STORE(model), &iter,
			   0, base,
			   1, dir, -1);
	g_free(dir);
	g_free(base);
}

/* Clear search results area */
void abox_clear_results(ABox *abox)
{
	GtkTreeModel *model;

	g_return_if_fail(abox != NULL);
	g_return_if_fail(IS_ABOX(abox));

	model = gtk_tree_view_get_model(GTK_TREE_VIEW(abox->results));

	gtk_list_store_clear(GTK_LIST_STORE(model));
}

void abox_add_combo(ABox *abox, const gchar *tlabel, GList *presets,
		    const gchar *text, GtkWidget *help_button)
{
	GtkWidget *hbox, *label, *combo;

	g_return_if_fail(abox != NULL);
	g_return_if_fail(IS_ABOX(abox));
	g_return_if_fail(abox->entry == NULL);

	hbox = gtk_hbox_new(FALSE, 0);
	if (tlabel)
	{
		label = gtk_label_new(tlabel);
		gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, TRUE, 4);
	}

/*
	combo = gtk_combo_new();
	gtk_combo_disable_activate(GTK_COMBO(combo));
	gtk_combo_set_use_arrows_always(GTK_COMBO(combo), TRUE);
	gtk_combo_set_popdown_strings(GTK_COMBO(combo), presets);
	abox->entry = GTK_COMBO(combo)->entry;
*/

	combo = gtk_combo_box_text_new_with_entry();
	GList *gl = presets;
	for (; gl; gl = gl->next)
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), gl->data);
	abox->entry = gtk_bin_get_child(GTK_BIN(combo));

	gtk_entry_set_activates_default(GTK_ENTRY(abox->entry), TRUE);
	gtk_entry_set_text(GTK_ENTRY(abox->entry), text);
	gtk_box_pack_start(GTK_BOX(hbox), combo, TRUE, TRUE, 4);

	gtk_box_pack_start(VBOX(abox), hbox, FALSE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), help_button, FALSE, TRUE, 4);

	gtk_widget_show_all(hbox);

	shade(abox);
}

void abox_add_entry(ABox *abox, const gchar *text, GtkWidget *help_button)
{
	GtkWidget *hbox, *label;

	g_return_if_fail(abox != NULL);
	g_return_if_fail(IS_ABOX(abox));
	g_return_if_fail(abox->entry == NULL);

	hbox = gtk_hbox_new(FALSE, 0);
	label = gtk_label_new(_("Expression:"));
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, TRUE, 4);
	abox->entry = gtk_entry_new();
	gtk_widget_set_name(abox->entry, "fixed-style");
	gtk_entry_set_text(GTK_ENTRY(abox->entry), text);
	gtk_box_pack_start(GTK_BOX(hbox), abox->entry, TRUE, TRUE, 4);
	gtk_box_pack_start(VBOX(abox), hbox, FALSE, TRUE, 4);
	gtk_box_pack_start(GTK_BOX(hbox), help_button,
				FALSE, TRUE, 4);

	gtk_entry_set_activates_default(GTK_ENTRY(abox->entry), TRUE);

	gtk_widget_show_all(hbox);

	shade(abox);
}

static void shade(ABox *abox)
{
	GtkDialog *dialog = (GtkDialog *) abox;
	gboolean quiet, on = abox->question;

	quiet = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(abox->quiet));

	gtk_dialog_set_response_sensitive(dialog, GTK_RESPONSE_YES, on);
	gtk_dialog_set_response_sensitive(dialog, GTK_RESPONSE_NO, on);

	if (on && !quiet)
		gtk_dialog_set_response_sensitive(dialog, RESPONSE_QUIET, TRUE);
	else
		gtk_dialog_set_response_sensitive(dialog, RESPONSE_QUIET, FALSE);

	if (!on)
	{
		gtk_widget_set_sensitive(abox->btn_seqno, on);
		gtk_widget_set_sensitive(abox->btn_seqno_all, on);
	}

	/* Unsetting the focus means that set_default will put it in the
	 * right place...
	 */
	gtk_window_set_focus(GTK_WINDOW(abox), NULL);
	/* Note: Gtk+-2.0.0 will segfault on Return if an insensitive
	 * widget is the default.
	 */
	if (quiet)
		gtk_dialog_set_default_response(dialog, GTK_RESPONSE_YES);
	else
		gtk_dialog_set_default_response(dialog, RESPONSE_QUIET);

	if (abox->entry)
	{
		gtk_widget_set_sensitive(abox->entry, on);
		if (on)
			gtk_widget_grab_focus(abox->entry);
	}
}

static gboolean abox_delete(GtkWidget *dialog, GdkEventAny *event)
{
	g_signal_emit_by_name(dialog, "abort_operation");
	return TRUE;
}

void abox_show_compare(ABox *abox, gboolean show)
{
	if (show)
		gtk_widget_show(abox->cmp_area);
	else
		gtk_widget_hide(abox->cmp_area);
}

void abox_set_file(ABox *abox, int i, const gchar *path)
{
	DirItem *item;
	gchar *base;

	g_return_if_fail(i >= 0 && i < 2);
	g_return_if_fail(IS_ABOX(abox));

	if (!path || !path[0])
	{
		gtk_widget_hide(abox->cmp_icon[i]);
		gtk_widget_hide(abox->cmp_name[i]);
		gtk_widget_hide(abox->cmp_size[i]);
		gtk_widget_hide(abox->cmp_date[i]);
		gtk_widget_hide(abox->cmp_arrow);
		return;
	}

	base = g_path_get_basename(path);
	item = diritem_new(base);
	g_free(base);
	diritem_restat(path, item, NULL, TRUE);

	gtk_image_set_from_pixbuf(GTK_IMAGE(abox->cmp_icon[i]),
				  di_image(item)->pixbuf);
	gtk_widget_show(abox->cmp_icon[i]);

	gtk_label_set_text(GTK_LABEL(abox->cmp_name[i]), item->leafname);
	gtk_widget_show(abox->cmp_name[i]);
	gtk_widget_show(abox->cmp_arrow);

	if (item->lstat_errno)
	{
		gtk_label_set_text(GTK_LABEL(abox->cmp_size[i]), "Error");
		gtk_label_set_text(GTK_LABEL(abox->cmp_date[i]),
				g_strerror(item->lstat_errno));
	}
	else
	{
		gchar *str;

		gtk_label_set_text(GTK_LABEL(abox->cmp_size[i]),
				format_size_aligned(item->size));

		str = pretty_time(&item->mtime);
		gtk_label_set_text(GTK_LABEL(abox->cmp_date[i]), str);
		g_free(str);
	}

	gtk_widget_show(abox->cmp_size[i]);
	gtk_widget_show(abox->cmp_date[i]);

	diritem_free(item);
}

static void _abox_set_percentage(ABox *abox, GtkWidget **prog, int per)
{
	if(!*prog) {
		*prog = gtk_progress_bar_new();
		gtk_widget_set_size_request(*prog, -1, small_height * (2./3.));
		gtk_box_pack_start(VBOX(abox), *prog, FALSE, FALSE, 2);
		gtk_widget_show(*prog);
	}
	if(per<0 || per>100) {
		gtk_widget_hide(*prog);
		return;
	}
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(*prog), per/100.);
}
void abox_set_percentage(ABox *abox, int per)
{
	_abox_set_percentage(abox, &abox->progress, per);
}
void abox_set_file_percentage(ABox *abox, int per)
{
	_abox_set_percentage(abox, &abox->fileprog, per);
}
