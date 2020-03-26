ROX-Filer Changes
=================

> Note: you don't need to update file this when committing a
> change. Just add a log message with the commit and I'll update this
> file only when making a new release.

Release 2.11 (2011-10-09)
-------------------------

- Converted from Glade to GtkBuilder.

- Fixed typo in German translation (Alek).

- "build" script runs autoconf and build the documentation if
  necessary. This is needed for Git checkouts.

- Don't lower panel when the pointer moves over an applet. Reported by
  mark76 on IRC.

- Centre the pinboard image correctly if larger than the screen (Mohamed
  Amine IL Idrissi). Patch sent to Ubuntu anonymously and forwarded; see
  Ubuntu bug #615490.

- Depend on 0compile 0.19.1. Fixes bug using distribution-provided
  pkg-config.

- Added build dependency on pkg-config.

- Bugfix: unselect item when menu is closed. We used to listen for
  `unmap_event`, but this is no longer emitted in recent versions of
  GTK.  Switched to using `selection-done` instead. Closes #2925212
  (reported by Barry Kauler).

- Added button to options window to create the `rox` start up script
  (Stephen Watson).

- Updated Italian translation (Yuri).

- Updated Brazilian Portuguese translation (Sérgio Cipolla).

- Updated Spanish and Galician translations (Antonio Sánchez). The
  how-to-change-permissions explanation had a mistake that made the help
  window appear blank.

- Updated Spanish translation (Antonio Sánchez and Luis Felipe Abad).

- Turn the error on invalid line breaks in uri_list_to_glist into a
  warning (Stephen Watson). Firefox 3.5 upto and including 3.5.2 gets it
  wrong, but we don't want to stop drops working until they fix it.

- Eliminated the duplicated code between `pixmap_background_thumb()` and
  `pixmap_try_thumb()`. `pixmap_background_thumb()` now calls
  `pixmap_try_thumb()` to get from memory or load from cache (Stephen
  Watson).

- Added option to place panels under the control of the `_NET_WORKAREA`
  property (Stephen Watson). Note it only checks the work area at the
  point it creates the panel.

- Fix bug in XDG MIME magic: if two matches at the same priority
  returned exactly the same type, it was considered a conflict (Stephen
  Watson).

- Newer versions of GTK+ issue warnings if a spin button has a non-zero
  page size (Stephen Watson).

- If a file has a thumbnail, display it in the infobox (Stephen Watson).

Release 2.10 (2009-07-18)
-------------------------

- Added "Don't ask..." to `may_offer_unmount()` (Tony Houghton).

- Update japanese trancslation (heroaki_TANAKA)

- Applied Bernard Jungen's patch and suggestion (Tony Houghton):
  - `_()` i18n wrappers for new infobox buttons.
  - Don't save learnt mount points with default of "ASK".
  - Use `GPOINTER_TO_INT(NULL)` instead of assuming 0.

- New options in mount point Properties dialog (Tony Houghton):
  What action to take when all a mount point's windows are closed.

- Left align permissions labels in Properties (Tony Houghton).

Release 2.9 (2009-05-10)
------------------------
- ROX-Filer didn't compile without inotify support. `dnotify_fd_to_dir`
  got renamed in 71061457fee9e95d65c53f2bdcc400bc4ac502c0, but not
  everywhere.

- Removed separate source feed. For historical reasons, ROX-Filer had a
  somewhat confused build system. The main feed claimed it to be a
  binary that worked on any architecture (because it compiled itself if
  the binary was missing), while a separate "source" feed provided the
  build dependencies. Now it has just a single feed, asserting that this
  is source code. Compiling it generates a binary release, including a
  binary feed. Also, there is a new 0compile.properties file so you can
  easily compile it with "0compile build". Clicking on the source's
  AppRun when there is no binary compiles it as before (without using
  Zero Install).

- Don't use `cp -u` in build script; doesn't work on FreeBSD.

- Updated Chinese translations (Babyfai Cheung)

- Support back-references when bulk renaming (Rogutės). Back references
  from \0 to \9 can be used in the "With:" field of the bulk renaming
  dialog. Every back-reference is replaced by a captured substring from
  the "Replace:" field. As a side effect, \0, \1, ..., \9 become special
  characters and they must be escaped with an additional backslash
  (e.g. \\3).

- Update panels correctly when the screen size changes (Tony Houghton)

- Support "Show per workspace" pinboard option when the window manager
  is using viewports instead of desktops. This is needed for things like
  compiz (Stephen Watson).

- Make more terms become translatable in log.c (Babyfai Cheung).

- Fix detection of *BSD systems for large file support. Third attempt.
  Instead of including huge autoconf files, restore the uname call that
  was accidentally removed in 462ae76daefc4f536f474982b4452e640ea48350.

- Use inotify to monitor directories when available, in preference to
  dnotify (Stephen Watson).

- Handle desktop files that have a blank Path (Stephen Watson).

- Handle the case where there is nothing following the version number
  when checking the `gcc --version output` (Stephen Watson).

- Improve detection of GCC version (Stephen Watson).

- Plug memory leak looking for local apps (Stephen Watson).

- Fix getting `$APPDIRPATH` when finding apps (Stephen Watson).

- Added Galician to AppInfo.xml (Maria).

- Update Spanish translation and add new Galego translation (Maria).
  This is from the GALPon MiniNo project, a Debian distribution for old
  computers.

- Don't lose selection when starting a drag with Ctrl. If we drag from
  an unselected item, we normally unselect any other items. However, if
  we're also holding down Ctrl it's probably unselected only because we
  mis-interpreted the click as toggle-selected, so just re-select it in
  that case (reported by Kacper Wysocki).

- Launch buttons in the options dialog now look for a locally installed
  app when 0launch isn't available (Stephen Watson).

- Creating a new file from a template works when the template is a
  symlink (Bernard Jungen). It now creates a copy of the symlink's
  target, not a copy of the symlink. However, if the template target is
  a directory containing symlinks, those are copied as they are.

- Make the symlink box remember the "relative" setting between
  invocations (Bernard Jungen).

- Updated Japanese translation (TANAKA hiroaki).

- Remove very old code for /uri filesystem.

- Change the way emblems are drawn on icons (Stephen Watson). The emblem
  images are no longer MaskedPixmaps but are fetched from stock when
  needed. This allows the theming mechanism to work on them.  There may
  be an overhead due to repeated calls to `gtk_style_lookup_icon_set` and
  `gtk_icon_set_render_icon`.

- Updated Italian translation (Yuri Bongiorno)

- Added missing release notes to Changes file. For versions 2.7.1 and
  2.8.


Release 2.8 (2008-05-17)
------------------------

- Add a "keep panel on top" option (Tony Houghton) On compiz-fusion
  0.7.4, the panels come off the screen; I think it's compiz's
  fault. This is a work-around (reported by Lucas Hazel).

- Support "Path" key in .desktop files (Stephen Watson) Reported by
  Mildred in http://sourceforge.net/tracker/index.php?func=detail&aid=1936189&group_id=7023&atid=107023

- Updated Vietnamese translation (Anh Tuan).

- Renamed icons to use new freedesktop.org scheme.

- Use correct name for coredump icon (Stephen Watson).

- Don't crash trying to display invalid timestamps. `localtime()` can
  return NULL if the input is out-of-range.

- MIME magic lookup now returns text/plain for certain unknown file
  types (Stephen Watson). Restored the code, lost in the update to the
  newer XDG MIME code, which checks unknown files to see if they are
  text.

- Updated Russian translation (Nikita E. Shalaev).

- Fix validity error in French manual XML (Stephen Watson)

- Italian translation update (Yuri Bongiorno).

- Typo in panel options (Vincent Lefèvre).

- Updated Italian translation (Yuri Bongiorno).

- Updated French manual translation (Arnaud Calvo).


Release 2.7.1
-------------

- Don't try to copy install.sh when building binary release.

- Give choice of using 0launch when building. `make` gives the old
  behaviour. `make with0launch` gets the headers using 0launch.

- Updated Chinese Translations (BabyfaiCheung)

- Fixed segfault on startup due to missing import. Recent versions of
  GTK import time.h for us, but older ones didn't, leading to a segfault
  in `log_info_paths`.

- Running 'make' in the src directory now uses 0launch to find the
  headers. This ensures that doing a normal build uses the same headers
  that 0compile will use, hopefully detecting problems earlier (e.g. use
  of a function from a newer GTK than the one we want to support). Note
  that `AppRun --compile` is unaffected.

- Fixed check to ensure that the ROX theme is available. Before, we just
  checked that the postscript icon could be found, but now we fallback
  to the GNOME theme so that always succeeds. Also, if the theme exists
  but is a broken link then we fix it automatically rather than popping
  up a box telling the user to fix it.

- Fix: Set the output codeset to UTF-8 (Andras Mohari). This should fix
  the problems in non-UTF-8 locales.

- Ensure the Glade templates go in the binary release. Reported by
  Lennon Cook.

- Fix checking for gcc version (Stephen Watson).

- Don't use `-fno-stack-protector` unless we are using GCC 4.1 or later
  (Stephen Watson). Should probably also check for GLIBC as well.

- Fix typo in the save display settings window (Stephen Watson).
  (Reported by Vincent Lefèvre)

- Fixed typo in label. Reported by Vincent Lefèvre.

- Updated README. Was *very* out-of-date (reported by Vincent Lefevre).

- Removed install script. I haven't run this thing for years. There are
  plenty of better ways of adding the filer to your system (using a
  package, Zero Install, running it in-place, etc). Also added Glade to
  the requirements in the manual, and updated the instructions there.

- Remove unnecessary argument in the unmount message (Adam Sampson).


Release 2.7 (2007-11-29)
------------------------

### NEW FEATURES

- New panel configuration GUI (Tony Houghton):
  + Created new Panel Options dialog in Templates.glade.
  + Changing panel side is now in the dialog.
  + Created new panel menu item.
  + Implemented Remove Panel menu item.
  + Pinboard menu has "Add panel" submenu.
  + Added panel_side_to_{translated_}name.
  + Options are stored with each panel.

  Use new panels config file to decide which panels to create with -S (Tony
  Houghton) .

  Fixed some problems and cleaned up some things in my new Panel Options
  code spotted by Thomas Leonard (Tony Houghton).

  Got rid of panel options from main Options dialog (Tony Houghton).
  No longer warn about options without widgets.

- Added a log viewer (Thomas Leonard).

  On the Window menu there is now a "Show Log" item which opens a window
  displaying a log of recent actions. Currently, only actions involving
  an action window are logged. The action is logged when you request the
  action (so it might not have actually been performed). The log window
  was created using Glade, and this therefore adds a Glade dependency on
  ROX-Filer, along with some support code to use it.

  Make the log window close when the Close button is clicked (Stephen
  Watson)

- Added automatic placement and updating to PinboardAdd RPC (Dennis
  Tomas).

- Try to find icons in ROX and gnome themes if not in configured
  theme (Tony Houghton).

### CHANGES

- Use text/base theme colours for the Collection widget, not
  fg/bg. (Andras Mohari) This provides a good default for the Collection
  widget, and is consistent with other widgets (GtkEntry,
  GtkTreeView...).

  Setting the colours in .gtkrc-2.0 is unnecessary now (unless someone
  wants to override theme colours, of course).

- Updated xdgmime* files from CVS source (retrieved 2007-08-18)
  (Stephen Watson).

- Making new ROX-Filer releases is now handled by 0release (Thomas
  Leonard).

### TRANSLATIONS

- Switched completely to standard gettext (Thomas Leonard).

  We used to use our own implementation of the gettext functions so that
  the user could switch langauges on the fly. However, that doesn't work
  with Glade and it wasn't very useful anyway, so it has all been
  removed.

  One visible change is that e.g. `LANG=fr rox -n` no longer works. You
  have to use the full string (e.g. `LANG=fr_FR.utf8 rox -n`).

- Added preliminary support for Glade translations (Andras Mohari, as
  suggested by Lennon Cook). We check for the presence of libintl.h and
  use the `bindtextdomain()` call to tell Glade where to find its
  catalogs.

  Build failed on Solaris, because libintl wasn't linked in (Stephen
  Watson).

- Updated Hungarian translation (Andras Mohari).

- Updated Chinese translation (Babyfai Cheung).

### BUG FIXES

- In the Properties box, the text in the "Contents Indicate" part of the
  box can now be selected and pasted (Thomas Leonard).

- Made uniconify from pinboard work properly with metacity (Tony
  Houghton): `_NET_ACTIVE_WINDOW` message now has timestamp and source
  field is set to 2 (pretend we're a pager).

  When uniconifying, set "requestor's currently active window" to zero
  to be on the safe side (Thomas Leonard).

- Arrow keys didn't work in details view (Thomas Leonard; reported by
  Dennis Nezic and others).

  GTK likes to select rows as you move over them. Since we don't want
  that, ROX-Filer marks the rows as unselectable. However, newer GTK
  versions refuse to move the cursor at all if the selection behaviour
  is disabled.

- Don't print CRITICAL message if there is no fstab available, for Mac
  OS X (Stephen Watson, suggested by Anders F. Björklund).

- Make it clearer what the "Save Display Settings" does (Stephen
  Watson).

- Combined adding of release event with motion event for pinboard icons
  (Tony Houghton). Doesn't seem necessary to add release event
  explicitly, but best be on safe side.

- Fixed build problem on GTK 2.6: `GTK_STOCK_INFO` doesn't exist (Thomas
  Leonard; reported by Stephen Watson).

- Escape special characters when opening the shell minibuffer (Thomas
  Leonard).

  If you click on files while the shell minibuffer is open then the
  names are escaped, but if you open it with a file under the cursor
  then the name wasn't escaped (reported by Nils-Erik Svangård).

- Fix occasional core dump with multiple magic matches (Stephen Watson).

- Use the directory icon for mount points if the icon theme has no icon
  for mount points (Andras Mohari).

- Use `pathdup()` in `diritem_restart()`, not `readlink_dup()`, to
  ensure that we get the full pathname and not a path relative to the
  filer's working directory (Stephen Watson).

- Fixed crash when running a .desktop file in terminal (Dennis Tomas).

- Strip .xpm or .svg extensions from Icon entry in .desktop files
  (Dennis Tomas).

- When clicking on toolbar buttons, don't crash if
  `gtk_get_current_event` returns `NULL` (Thomas Leonard). This is the
  case when ATK is used.

- Need to use unsigned char when reading the header of an Exif file to
  avoid problems on some hardware (Stephen Watson, reported by Musus
  Umbra).


Release 2.6.1 (2007-06-10)
--------------------------

### SESSION MANAGER CHANGES

- When run with -S, restart with -S too rather than expanding the
  current panels and pinboard on the command-line (Thomas Leonard).

- If the filer was started with -S, ask the session manager to
  automatically restart it if it crashes (Thomas Leonard).

- If 0launch is available, use that as the session restart command when
  using a session manager. Without this, restoring a session would
  always reload the same version of ROX-Filer that was used when you
  saved it, not the current version (Thomas Leonard).

### BUILDING

- Shouldn't use `==` in /bin/sh scripts, that's a bashism (Stephen
  Watson).

- Don't abort the build if we can't create debugging symbols (Thomas
  Leonard, reported through 0compile as bug#1678076).

### OTHER CHANGES

- Reduced panel border width to 1 pixel (Tony Houghton).

- For JPEG files in Exif format attempt to read an embedded thumbnail
  first (Stephen Watson).

- Bugfix: The `Thumb::Size` tag is optional in the thumbnail spec
  (reported by Jochen Seidel).

### TRANSLATIONS

- Updated French manual translation (Arnaud Calvo).

- Updated Chinese translations (Babyfai Cheung).


Release 2.6 (2007-02-25)
------------------------

### CHANGES

- If a .desktop file says "Terminal=true" then run the program in a terminal
  (Thomas Leonard, reported by Frank McCormick). Note: this is currently
  hard-coded to use xterm.

- Option to display xattr indicator now independant of xattr support option

- The symlink and xattr emblems are now loaded from stock items and therefore
  themeable. Made clear that setting type on directories sets the contents, not
  the directory.  inode/* types excluded from the list of types available for
  setting (Stephen Watson).

- Added "Fit" backdrop image scaling mode (Peter Hyman). Like "Scale", this
  scales the image without distorting it, but it will make it larger than the
  screen if necessary to avoid a border.

- New MIME type for Jar archives.

- Lookup URI handlers by scheme in choices (Stephen Watson)

- Added -U option for parsing filenames in URL form (Stephen Watson).

- Added a new SOAP method, RunURI, and made the -U option use that. In addition
  error returns from SOAP methods implicitly invoked (not via -R) are printed
  as simple messages rather than the XML data (Stephen Watson).

- Add eject button to the unmount/don't unmount dialog (Stephen Watson).

- Mount and unmount commands can have additional parameters, eject command can
  also be changed in the same way (Jim Ramsay, Stephen Watson).

- Menu option to control whether directories are filtered by name along with
  other files (Janek Kozicki and Andras Mohari).

### BUG FIXES

- Don't try to thumbnail zero-byte files. They're either empty, or special and
  may cause us to hang (Thomas Leonard; reported by Barry Kauler).

- Always use the default RTL setting to render filenames, even if they start
  with a character that suggests the opposite. Fixes a positioning problem
  (Thomas Leonard; reported by Alexander McLeay).

- Use $MAKE to run make, for *BSD users

- Don't display a warning about deprecated options; it just confuses people
  (Thomas Leonard; reported by Peter).

- When moving the cursor down on the last row of a collection in vertical mode,
  move to the start of the next column (Thomas Leonard).

- When reporting an invalid MIME type, include the type's name in the error
  message (Thomas Leonard).

- Fix bug when checking for escape characters in command string (Stephen Watson).

### COMPILATION

- Removed code to set location of pkg-config files. No longer needed, since the
  discovery of ${pcfiledir} (suggested by Stephen Watson).

- Made ROX-Filer-src.xml use the gtk-2.4 build environment, rather than
  depending on all the headers directly. The build environment sets up a
  temporary directory with some symlinks, which means you can compile without
  having any version of the GTK headers installed at all. Before, an existing
  -dev installation was required (but only to get the major version number of
  the library!).

### TRANSLATIONS

- Updated French translation (Vincent Lefèvre).

- Updated Hungarian translation (amohari).

- Updated Italian translation (deslar).

- Updated Russian translation (Nikita E. Shalaev).

- Updated Ukrainian translation (Yury Bulka).

- Updated Vietnamese translation (Anhtuan).


Release 2.5 (2006-07-07)
------------------------

### New features

- Allow pinboard and panel icons to be locked (Dennis Tomas, suggested
  by Abrolag).

- Display extra information in properties box for desktop files (Stephen
  Watson).

- Allow setting icons in the AppInfo.xml file (Dennis Tomas). Example:

    <AppMenu>
        <Item option="--options" icon="gtk-preferences">...</Item>
    </AppMenu>

- Added SetIcon and UnsetIcon SOAP calls (Jonatan Liljedahl). With this
  you can have your volume manager (like ivman) set icons for the
  mounted media that represents what type of media it is (cdr, cdrw, usb
  stick, etc).

- Right-clicking on the Show/hide button now turns thumbnails on and off
  (Peter Federighi).

- Added options to change the "mount" and "umount" commands (Thomas
  Leonard).  This may be useful for using programs such as "pmount" and
  "pumount" (which allow mounting removable media without an fstab
  entry, or encrypted filesystems).

- Added a 'Manage Thumbnails' link to the Options box (Thomas Leonard).
  If 0launch isn't available, tell the user the URL of the program we
  were trying to run so they can get it themselves. Tell users about
  right-click behaviour in a tooltip (Thomas Leonard).

### Changes

- Removed separator from icon properties dialog box (Thomas Leonard).

- Updated Word MIME type for new MIME database (Keith Warno).

- When the handler for a MIME type is a symlink to a program, run the
  program using the target of the symlink rather than the link itself so
  that programs like gvim see the right name and behave correctly
  (Thomas Leonard, reported by Keith Warno).

- Use full URI, not local path, for DocBook stylesheet (Pär Forsling).

- When setting or clearing a globicon, redraw pinboard and panel icons
  too (Dennis Tomas).

- When loading MIME icons from the current theme only get the pathname
  from GTK, but actually load it through our own cache (Thomas Leonard).
  GTK was loading a new copy of the image each time!

- Changed name of save settings menu option to be more explicit (Stephen
  Watson).

- In many .desktop files there is no "%F" or similar parameter to the
  "Exec" entry, although the application can open files. Work around
  this problem by adding the arguments to the end of the command in this
  case (Dennis Tomas).

- Added Zero Install source interface (Thomas Leonard). Run this with
  0launch to compile against the GTK and GLib 2.4 headers (which will be
  downloaded automatically). This produces a binary that runs with these
  older versions, as well as with all later releases. Note that this has
  been somewhat superceded by the GTK-2.4 compatibility environment:

  http://0install.net/2006/interfaces/GTK-2.4.xml

- New type for XML files; "application/" rather than "text/" to match
  freedesktop.org updates (Thomas Leonard).

- Moved test for a hidden file into its own function. Allows us to
  define additional tests as to whether a file is hidden, rather than
  just the first character of the file name (Stephen Watson).

- Updated source file headers by removing the Id line, updating the
  year and clarifying the copyrights (Thomas Leonard).

- The monospace font for the list view is now configurable via a
  ViewDetails::mono-font gtkrc entry (Stephen Watson).

- When iconfiying a window, try to find space on the pinboard of the
  current screen first (Tony Houghton).

- Updated the help text for rox --help (Andras Mohari).

- Use a monospace font for the size and permissions columsn in the list
  view (Andras Mohari).

### Bug fixes

- When a panel icon's image changed, the display didn't update (Thomas
  Leonard, reported by Dennis Tomas).

- Any line in a .desktop file would be ignored if there was a blank line
  directly before it (Dennis Tomas).

- Escape " characters when generating translations for the Options.xml
  file (Andras Mohari).

- When reading the output from 'du' for the Properties box, set the
  channel's encoding to NULL to avoid errors with non-UTF-8 filenames
  (Andras Mohari).

- When running ROX-Filer for the first time ever, don't tell users that
  the Choices directory has been migrated unless they already had one.
  Also, don't bother creating symlinks to the new locations in this
  case. Other applications have had a while to catch up to the new
  system, and the message is rather confusing to new users (Thomas
  Leonard).

### Translations

- Updated Chinese Translations (Babyfai Cheung).

- Updated French manual translation (Arnaud Calvo).

- Updated French translation (Vincent Lefèvre).

- Updated Hungarian translation and converted to UTF-8 (Andras Mohari).

- Updated Italian translation (Yuri Bongiorno).

- Updated Russian translation (Nikita E. Shalaev).

- Added Ukrainian translation (Yourko).

- Added Vietnamese translation (Xomhau Newnick).

- Updated instructions for creating a translation (reported by Yourko).

- Make sure all the help message is translatable (Stephen Watson,
  reported by Andras Mohari).



30-Dec-2005 (Release 2.4.1)
---------------------------
Updated Estonian translation (Teet Tärno).

29-Dec-2005
-----------
Some .desktop files put ".png" after the icon name, which prevents the icon
from being found. Ignore it (Thomass Leonard; reported by Peter).

28-Dec-2005
-----------
Updated Hungarian translation (Andras Mohari).

27-Dec-2005
-----------
If we can't find libc.so.6 for xattr support, try libc.so in case we only have
uClib (Lucas Correia Villa Real).

18-Dec-2005
-----------
Allow .desktop files to be used as run actions (Thomas Leonard).

17-Dec-2005
-----------
Bugfix: New detail crashes cleanice theme (reported by Andras Mohari; reported
	as CleanIce bug #1383457). Try another value...

16-Dec-2005
-----------
Highlight icons using the theme's preferred colour instead of always using
blue (Andras Mohari).
Bugfix: Don't set style detail to "base" when highlighting items in a
	Collection, as it confuses GTK's lighthouseblue theme engine
	(Thomas Leonard).

15-Dec-2005
-----------
Bugfix: Changing the display style crashes the filer with GTK >= 2.8.9 because
	it sends a selection changed event before the view has finished
	initialising (Thomas Leonard; reported by Tobias Kieslich).
Removed some done entries from the TODO file (Stephen Watson).

13-Dec-2005 (Release 2.4)
-----------
Updated Chinese translations (Babyfai Cheung).

11-Dec-2005
-----------
Updated French manual translation (Arnaud Calvo).
Make Path optional in PanelRemove SOAP call, allowing removal of items based
only on their label (Jonatan Liljedahl).
Bugfix: The install script failed to compile ROX-Filer on Debian systems, due
	to a bug in recent versions of xterm (Vincent Lefèvre). Added a
	workaround.
Bugfix: On 64-bit systems communication between ROX-Filer processes didn't
	work, because GDK uses sizeof(long) bytes (not always 4 bytes) to store
	a 32 bit property (Lucas Hazel).

29-Nov-2005
-----------
Removed 'Open AVFS' from menu. It doesn't do anything on most systems, and you
can always add it with 'Customise menu...' if you want it (Thomas Leonard).
Better support for old GNOME themes with GNOME-specific MIME names (Dennis
Tomas).

21-Nov-2005
-----------
Bugfix: Let -R work again (Stephen Watson).

12-Nov-2005
-----------
Added initial support for .desktop files (Thomas Leonard). They are now shown
as executable, with the appropriate icons, and clicking on them runs the
application.
Bugfix: If stdin wasn't set when ROX-Filer was started it could get used for
	the X connection, before ROX-Filer got around to replacing it with
	/dev/null (Thomas Leonard).

28-Oct-2005
-----------
Added Hungarian translation for the <About> section in AppInfo.xml
(Andras Mohari).

25-Oct-2005
-----------
Updated Japanese translation (Hiroaki Tanaka).

22-Oct-2005
-----------
In details mode, clicking on an item while the keyboard focus is visible
moves the focus to the item clicked on (suggested by Anthony DiSante).

19-Oct-2005
-----------
Updated Hungarian translation (Andras Mohari).

18-Oct-2005
-----------
Updated Estonian translation (Teet Tärno).
Bugfix: An (extremely unlikely to occur) error message was missing some
	arguments (Thomas Leonard; spotted by Andras Mohari).

17-Oct-2005
-----------
Updated it.po and Manual-it.xml (Yuri Bongiorno)

02-Oct-2005
-----------
Make all option menus into the options box wide enough for the widest item
to avoid resizing when the item is changed (Andras Mohari).

15-Sep-2005
-----------
Only require shared-mime-database 0.14, not 0.16. Add the missing subclasses
manually (Thomas Leonard).

13-Sep-2005
-----------
Allow some labels used to display file names to wrap over more than one line,
improving display of very long file names (Stephen Watson).
Show progress bar from start when an action is on more than one item
(Stephen Watson).

08-Sep-2005
-----------
Bugfix: The refresh feature was accidentally broken during the upgrade to the
	new MIME system (Thomas Leonard; reported by Frantisek Fuka).

04-Sep-2005
-----------
Bugfix: If you editing the target of a symlink in the properties box, and then
	unfocussed the entry when the symlink no longer existed, the filer
	would crash trying to display the error message. Added work-around
	(Thomas Leonard; reported as GTK bug #315229).

27-Aug-2005
-----------
When using 'From LANG', check for translations with and with the territory
part (seventh guardian). Also do this when loading the manual or finding
a summary in AppInfo.xml (Thomas Leonard).

22-Aug-2005
-----------
Marked some titlebar flags as translatable (reported by seventh guardian).

17-Aug-2005
-----------
Updated install.sh with the current shared-mime-info URL (Stephen Watson).

16-Aug-2005
-----------
Updated French translation (Vincent Lefèvre).
Bugfix: Fix typo in the Solaris xattr implementation (Stephen Watson).

15-Aug-2005
-----------
Bugfix: When doing Tab completion, part of the code was still case sensitive,
	causing it to sometimes fail to notice multiple matched (Keith Warno;
	reported by Tristan McLeay).

14-Aug-2005
-----------
Added ROX-Filer.xml file, giving details of the current version. This can be
used to register a CVS version of the filer with the injector easily (Thomas
Leonard).
Renamed 'Xterm Here' to 'Terminal Here' (suggested by seventh guardian).

13-Aug-2005
-----------
Removed GNOME-VFS from --version output; we never use it now (Thomas Leonard).
Failure to create a usable default icon theme can be due to a broken link, so
inform the user and show ~/.icons (Stephen Watson).
Extended attribute support more general, not just types (Stephen Watson).

12-Aug-2005
-----------
Updated Polish translation (Wit Wiliński).
Added Portuguese (for Portugal) translation (Renato Caldas).

09-Aug-2005 (Release 2.3)
-----------
Opening the menu with the menu key had broken. Also fixed a few minor leaks
(Thomas Leonard).

06-Aug-2005
-----------
Updated French manual translation (Arnaud Calvo).
Fixed memory leak in new SOAP RPC calls (Thomas Leonard).
Provide alternate to_html.xsl file for different location of Docbook
stylesheets (Stephen Watson).
GTK bug #152151 also causes BadDrawable errors so ignore them as well
(Stephen Watson).

04-Aug-2005
-----------
Bugfix: Ultimate++ could crash the filer when its window was iconified
	(Guido Schimmels).

01-Aug-2005
~~~~~~~~~~
Updated Dutch translation (Jan Wagemakers).

31-Jul-2005
-----------
Added a button for configuring video thumbnails (with Stephen Watson's
VideoThumbnail application) to the Options window (Thomas Leonard).
Manual updates.
Right-clicking on a launcher button shows available versions (Thomas Leonard).
Bugfix: Added some missing gdk_event_free() calls (Thomas Leonard).
Bugfix: In vertical ordering mode, the blank space after all the items
	acted as if there were icons there (reported by Arnaud Calvo).

30-Jul-2005
-----------
Don't abort on BadWindow errors. GTK bug #152151 is still not fixed after
nearly a year, so give up trying to fix it and just ignore it (Thomas Leonard).
Don't show Help menu item for applications with no Help subdirectory (Thomas
Leonard).

29-Jul-2005
-----------
Added option to only show iconified windows belonging to the current workspace
(Tom Morton).
Added option to allow vertical ordering when laying out the icon view
(Piotr Zielinski).

28-Jul-2005
-----------
Updated Dutch translation (Jan Wagemakers).

27-Jul-2005
-----------
Renamed Python MIME icon to keep up with freedesktop.org's current thinking in
the endless text vs application war (Thomas Leonard).

26-Jul-2005
-----------
Removed custom platform detection (which was designed to allow a single
copy of ROX-Filer to contain binaries for multiple platforms). Let the
packaging system deal with it (Thomas Leonard).

25-Jul-2005
-----------
Check for shared-mime-info 0.16 when building (Stephen Watson).

24-Jul-2005
-----------
An executable text file of unknown type is marked as executable if its name
doesn't contain a '.'. This is so that 'readme.txt' on a filesystem with
all execute bits set is seen as text, but a shell script with no extension
or interpreter header still shows up as an executable on Solaris (Thomas
Leonard; requested by Stephen Watson).

23-Jul-2005
-----------
Added icon for messages/* MIME types (Thomas Leonard).
Improvements for file type guessing (Thomas Leonard):
- When getting the type for a symlink, we need the absolute path now that we
  check file contents.
- Also check for extended attributes for the symlink target.
- Removed all of our code for guessing types from file names, since it
  duplicates the new xdgmime code.
- Files with control characters are now considered to be binary, even
  though they may be valid UTF-8.
- Executable files of unknown type are now marked as executable, not
  octet-stream.
- When complaining that there is no run action for an executable type,
  give the user a hint about setting the execute permission.
- Refreshing the MIME system also refreshes xdgmime.
- Added MIME rules to say that Python, PERL and Ruby are executable, as
  old versions of the MIME database don't have these rules (reported by
  Stephen Watson).


22-Jul-2005
-----------
At install time, add a rule to the MIME database that shell scripts are
executable, as the defaults are missing this (Thomas Leonard; reported by
Stephen Watson).
In the properties box, don't say that the run action is executable just
because the MIME type is executable. The execute bit must be set too
(Thomas Leonard).

21-Jul-2005
-----------
Replaced the text the Options box telling people to download and run
MIME-Editor with a button that actually does it (Thomas Leonard).

17-Jul-2005
-----------
Bugfix: Opening a new filer window with a key press warped the pointer
	to the top-left of the screen (Matthew Weier O'Phinney and Thomas
	Leonard).

16-Jul-2005
-----------
Detect GCC 4 and disable pointer signedness warnings (Thomas Leonard).
Mark files as executable if their MIME type is a subclass of
application/x-executable (Thomas Leonard).
Removed the option for choosing panel side for -S, since we can use the new
method of choosing the panel side indead (Thomas Leonard).
Split Mount SOAP operation into separate Mount and Unmount operations
(Thomas Leonard).
Bugfix: The path entry buffer didn't work in /, due to recent changes
	(Thomas Leonard).
Bugfix: Clicking on a directory which was mounted but shown as unmounted,
	due to the display being out-of-date, tried to unmount it.
	(Thomas Leonard, reported by Mephistopheles Jones as bug #1007402).

15-Jul-2005
-----------
Copied xdgmime library into the filer, so we don't need gnomevfs just
to do MIME guessing from file contents (Guido Schimmels).

26-Jun-2005
-----------
Renamed the 'ROX Session' section in options to 'Desktop' as it could be
used by any session manager (Stephen Watson).

25-Jun-2005
-----------
Panel side is now stored with the panel file, and is reused on start-up if
you use --border in place of the old --top, --bottom, --left and --right
(which still work). The panel menu has a new 'Panel Options...' choice to let
you change which edge to use (Thomas Leonard).

11-Jun-2005
-----------
Updated Chinese translation (Babyfai Cheung).

09-Jun-2005
-----------
Removed AC_PATH_X, which stopped configure working on Mac OS X (Thomas Leonard;
reported by Tristan McLeay). We already had AC_PATH_XTRA anyway.

07-Jun-2005
-----------
Add Basque transation (Piarres Beobide).

Entering ~ as the first character in the Goto: entry goes to the users
home directory (Stephen Watson, suggested by james).
Install script now installs MIME run actions into $XDG_CONFIG_HOME
(Stephen Watson).

20-May-2005
-----------
Change the way that ROX-Session runs ROX-Filer.  It now uses the -S option to
open the default Panel and Pinboard, with the configuration of panel and
pinboard in ROX-Filer options (Stephen Watson).
Fixed error in tooltip in bulk rename box (Vincent Lefèvre).

13-May-2005
-----------
Type changes for 64-bit compatibility (Tony Houghton).

Tests whether dnotify_wakeup_flag is set instead of dnotify_wakeup which is a
function address (Tony Houghton).

08-May-2005
-----------
Selecting an entry from the bookmarks menu can open a new window, depending
on the mouse button used and the 'New window on button 1' setting
(Stephen Watson).

03-May-2005
-----------
World-writable directories can't be app dirs (Thomas Leonard).

02-May-2005
-----------
Updated Chinese translation (Babyfai Cheung).
Fixed missing argument in remote.c (Pär Forsling).

01-May-2005
-----------
When using the drag-and-drop menu, give the choice of creating relative or
absolute symlinks. For Ctrl-Shift-Drag, always make relative links rather
than absolute ones (Thomas Leonard; requested by Peter Prohaska).

28-Apr-2005
-----------
If we can't find getopt_long, try looking in libgnugetopt (Stephen Watson).

26-Apr-2005
-----------
Bugfix: Broke get_xdg_data_dirs while writing choices_list_xdg_dirs (Stephen
        Watson, reported by Pär Forsling).
Bugfix: Don't try to move directories that aren't there, but make symbolic
        links for them anyway (Stephen Watson, reported by Thomas Leonard).
Old choices_find_path_load/save now static, use new XDG functions exclusively
(Stephen Watson).

25-Apr-2005
-----------
Change over from CHOICESPATH to XDG_CONFIG_HOME and XDG_CONFIG_DIRS (Stephen
Watson).

21-Apr-2005
-----------
Try to cope with BadWindow errors (Thomas Leonard; suggested by Kacper Wysock).

17-Apr-2005
-----------
Bugfix: Replacing an existing display settings would erase all the other
        existing settings (Stephen Watson, reported by Henrik Jacobsson).

16-Apr-2005
-----------
Bugfix: Expired thumbnails were not being purged from the memory cache
        because of a reference counting issue (Stephen Watson).

14-Apr-2005
-----------
Updated Danish translation (Christian Storgaard).

28-Mar-2005
-----------
Simplify code to set minibuffer text to red on error (Dennis). Also set
background to white, in case a theme's colour clashes with red (Thomas
Leonard).
Make tab completion in the minibuffer case insensitive (Jonatan Liljedahl).

23-Mar-2005
-----------
Option in list view to show the full MIME-Type comment rather than
just "File" (Stephen Watson).

12-Mar-2005
-----------
When building the SendTo menu, allow nested subdirectories more than one
level deep (Jonatan Liljedahl).
Add 'Customise Menu...' to New submenu (Thomas Leonard, suggested by Jesse
Wagner).
Can specify panel item arguments and short cut when adding via SOAP
call (m0n5t3r).
Also for pinboard items (and fixed bugs related to pinboard_add_with_args)
(Stephen Watson).

28-Feb-2005
-----------
Bugfix: Progress bar for count operation didn't finish when the count did
        (Stephen Watson, reported by Alexander Wagner).

24-Feb-2005
-----------
Look out for new line character when reading EA MIME type under Solaris
(Stephen Watson).

13-Feb-2005
-----------
Added Estonian translation (Teet Tärno).

12-Feb-2005
-----------
Removed copy of GTK icon theme system. We now depend on GTK 2.4, which
includes it (Thomas Leonard).
Renamed 'Before' and 'After' in the bulk rename box to 'Old name' and
'New name', as they were causing problems for translators (reported by
Yuri Bongiorno).
Bugfix: The help for the "Set Type..." box wasn't translated (reported
	by Yuri Bongiorno).

09-Feb-2005
-----------
Defer re-generating a thumbnail until 5 seconds after the timestamp on
the old one (Stephen Watson).
Bugfix: A file could be added many times to the thumbnail queue, causing
        the progress bar to behave strangely (Stephen Watson).
More changes for installing onto NFS mounted directory (Stephen Watson).

31-Jan-2005
-----------
Fixed a compiler warning by removing an unnecessary extra tooltips object
(Andreas Jochens).

30-Jan-2005
-----------
Updated French translation (Vincent Lefèvre).

29-Jan-2005 (Release 2.2.0)
-----------
Added Finnish translation (Jari Rahkonen).
Updated Dutch translation (Jan Wagemakers).

24-Jan-2005
-----------
Bugfix: More crashes due to Japanese characters; last patch didn't fix all
	the problems (Thomas Leonard; reported by Lewis Denizen).

23-Jan-2005 (Release 2.1.6)
-----------
Updated French translation (Vincent Lefèvre).
Bugfix: Japanese digit characters crashed the filer, because some code thought
	they were digits, and anothers thought they weren't (Thomas Leonard;
	reported by Lewis Denizen).

22-Jan-2005
-----------
Updated French manual translation (Arnaud Calvo).

21-Jan-2005
-----------
Bugfix: If, when building, objcopy exits with an error then don't strip
	the binary (Stephen Watson).

20-Jan-2005
-----------
Updated Dutch translation (Jan Wagemakers).

18-Jan-2005
-----------
Bugfix: Don't show the permissions in the properties window for
        symbolic links as they don't behave as you might expect
	(Stephen Watson, reported by Max Power).

16-Jan-2005
-----------
Fixed some spelling errors and made some messages easier to translate
(Vincent Lefèvre).

15-Jan-2005 (Release 2.1.5)
-----------
Bugfix: An extra arrow had appeared in the Find box (Thomas Leonard).
Bugfix: We were inconsistent about when filenames were escaped. Eg, creating
	a directory called "a%20b" actually created "a b" (Thomas Leonard).
Bugfix: Panel icons with no label displayed an empty tooltip (Thomas Leonard).
Bugfix: Selecting a pinboard icon only redrew the text path (Thomas Leonard).

13-Jan-2005
-----------
Updated Japanese translation (Hiroaki Tanaka).

12-Jan-2005
-----------
Slight change to install script for when the installation directory is
on an NFS mount (Stephen Watson).

10-Jan-2005
-----------
Can now disable use of extended attributes (Stephen Watson).

08-Jan-2005
-----------
Allow renaming multiple files at once. This opens the Bulk Rename window,
which allows manual editing of the names, as well as regular-expression
based transformations (Thomas Leonard).

Rename buttons in Set Run Action box so that they make sense (Thomas Leonard;
reported by Jonatan Liljedahl).

Bugfix: Filer would crash when the screen was resized if there was no
	pinboard (Thomas Leonard).
Bugfix: Xinerama support had broken panel repositioning in response to
	XRANDR screen resizing events (Thomas Leonard).

03-Jan-2005
-----------
Set the name for filer windows to 'rox-filer'. This allows theming the fonts
just for ROX-Filer (Lucas Hazel).

23-Dec-2004
-----------
If an item has extended attributes, report that before checking whether they
are supported (Thomas Leonard).
Updated Chinese translation (Babyfai Cheung).
Bugfix: Pressing Escape now closes the Properties box (reported by Arnaud
	Calvo).

09-Dec-2004
-----------
Bugfix: Test for presence of extended attributes on Solaris gave wrong
        answer when they were not supported (Stephen Watson).

08-Dec-2004
-----------
The icons for mount point and symbolic link are now side-by-side, not
one on top of the other, and a new icon is used to mark files with
extended attributes (Stephen Watson).

27-Nov-2004
-----------
Bugfix: Use gtk_selection_data_set_text instead of gtk_selection_data_set when
	pasting filenames so that other applications know the string is UTF-8
	(Thomas Leonard; reported by Dennis).

27-Nov-2004
-----------
Better extended attribute detection under Solaris (Stephen Watson).

25-Nov-2004
-----------
More extended attribute support. The "Set Type..." menu item should be
disabled if not supported by the system or FS (Stephen Watson).

24-Nov-2004
-----------
Method of scaling pinboard images is now an option, as the default could
produce poor results on some systems (Stephen Watson).

22-Nov-2004
-----------
Updated it.po and Manual-it.xml (Yuri Bongiorno)

19-Nov-2004
-----------
Bugfix: Dragging a lasso box above the top of the window in details mode
	selected all the items outside the box (Thomas Leonard; reported by
	Anthony DiSante).

12-Nov-2004
-----------
Only show executable files in green if clicking would actually run them, not
just because they have the execute bit set (Thomas Leonard).

11-Nov-2004
-----------
Much faster thumbnail generation (Ken Hayber, reported by Anthony DiSante).

08-Nov-2004
-----------
When closing a filer window showing a directory under a user-mounted
mount-point, offer to unmount the device if no other filer window also shows
that mount point (requested by Tony Houghton and others). Also do this check
when changing to a parent directory.
Scale iconified window icons on the pinboard down to normal size (Ken Hayber).

08-Nov-2004
-----------
Updated Dutch translation (Jan Wagemakers).

07-Nov-2004
-----------
Work on the action box, including a progress bar (Stephen Watson).

24-Oct-2004
-----------
Added PinboardRemove() SOAP call (Stephen Watson).

20-Oct-2004 (Release 2.1.4)
-----------
Added Portuguese translation (Rodrigo Cesar Herefeld).

16-Oct-2004
-----------
Some improvements to saved display settings (Takuo Yonezawa and Stephen
Watson).
Updated Spanish translation (Marcelo Ramos).

15-Oct-2004
-----------
Allow multiple arguments for executable pinboard and panel icons (Thomas
Leonard).
Updated it.po and Manual-it (Yuri Bongiorno).

12-Oct-2004
-----------
Use a higher quality setting when scaling the backdrop image (Ken Hayber).

06-Oct-2004
-----------
Added PanelRemove() SOAP call (Sabin Iacob).
Bugfix: Mounting a directory that was accessed through a symlinked directory
	used the symbolic path, confusing the mount command (Thomas Leonard;
	reported by Anthony DiSante).

29-Sep-2004
-----------
Force panel to not take focus when using GTK 2.4 (Thomas Leonard).

28-Sep-2004
-----------
Minimum width of toolbar now an option (requested by Matthew Weier O'Phinney).

21-Sep-2004
-----------
Only examine items that are actually displayed, not all items in a directory.
Saves checking hidden files, which typically speeds up opening the home
directory. Removed an unnecessary extra scan when opening a directory
with the default filter setting. Removed the double scan when clicking Refresh
and two windows show the same directory (Thomas Leonard).

20-Sep-2004
-----------
Added option to make panels have the type _NET_WM_WINDOW_TYPE_DOCK (Tony
Houghton). Metacity needs this.

17-Sep-2004
-----------
If we can't guess a file's type from its name or extended attribute, try
looking at its contents too, if we have gnomevfs 2.8.0 or later available
(Thomas Leonard).

11-Sep-2004
-----------
Panel and pinboard icons can now have a single argument set for them.
If you need more than one argument, consider creating a wrapper
(Stephen Watson).

09-Sep-2004
-----------
Added --massif option for profiling memory usage (Thomas Leonard).
Warn about missing libsm in configure.in (reported by fedewico).

06-Sep-2004
-----------
When resizing a window, only warp the pointer as much as necessary to keep
it inside the window (Thomas Leonard).

02-Sep-2004
-----------
Ensure that a panel applet's properties are set before starting the applet
(reported by Tony Houghton).

01-Sep-2004
-----------
Fixed panel menu positioning for multiple monitors with different resolutions
(Tony Houghton).
Use _NET_WM_STATE_BELOW to raise and lower the panel (Tony Houghton). Not
changing to type DOCK yet as it breaks some WMs.

25-Aug-2004
-----------
Use new GTK 2.2 functions to set window hints now that we don't support 2.0
anymore (Guido Schimmels).

23-Aug-2004
-----------
Plug a memory leak when loading SVG type icons (Stephen Watson).

18-Aug-2004
-----------
Fix for the Solaris extended attribute support (Stephen Watson).

13-Aug-2004
-----------
Set minimum width of toolbar so that all buttons are visible (Stephen Watson).

10-Aug-2004
-----------
When adding an entry to the Recently Visited menu, remove its parent directory.
This stops the list filling up with near-duplicates when you have deeply
nested directories (Thomas Leonard).

08-Aug-2004
-----------
Updated French manual translation (Arnaud Calvo).

05-Aug-2004
-----------
For debugging, show the failed URI when dragging to the pinboard (Thomas
Leonard).

03-Aug-2004
-----------
Use Help icon instead of Info icon for popup help buttons (Thomas Leonard).

02-Aug-2004
-----------
Updated French translation (Vincent Lefèvre).

01-Aug-2004 (Release 2.1.3)
-----------
Build in ROX-Filer/build, not ~/build/ROX-Filer.

30-Jul-2004
-----------
Renamed Cancel to Close in the Properties box (suggested by Arnaud Calvo).
Updated some calls to use newer APIs, and allow compilation on systems where
deprecated widgets are disabled by default (reported by Vincent Lefèvre and
Guido Schimmels).
Bugfix: Panel icons were no longer shown highlighted when selected.

23-Jul-2004
-----------
Bugfix: When opening a new directory with saved settings, the filer would
	print a warning and then crash.

21-Jul-2004
-----------
Changed email address given as the one to send bugs to when using
--help to the rox-devel list (Stephen Watson).
Thumbnail generation now handles files with UTF-8 characters (Anatoly
Asviyan).

16-Jul-2004
-----------
Removed action window screenshot from manual to save space.

15-Jul-2004
-----------
Proper check for the stat[v]fs headers (Stephen Watson, reported by
Lucas Hazel).

13-Jul-2004
-----------
Added firefox to list of default browsers (suggested by eugene).

10-Jul-2004
-----------
Added Romanian translation (Cosma Florin).

01-Jul-2004
-----------
Can now set "Brief" option on the Copy and Move action windows (Stephen
Watson).
Properties window handles mount points specially when calculating their size
(Stephen Watson).

30-Jun-2004
-----------
Bugfix: On Linux, the filer called setxattr instead of getxattr, thus
	preventing setting filetypes with extended attributes from working.
Bugfix: Copy and Move now obey the "Brief" option (Stephen Watson, reported
        by Graham Borland)

29-Jun-2004
-----------
Bugfix: On multi-monitor setups, filer windows always opened on the top/left
	monitor (reported by Kacper Wysocki). Now they open on the monitor
	under the pointer.

27-Jun-2004
-----------
Icons of minimized windows remember their positions on the pinboard (Stephen
Watson).
Filer now officially requires GTK 2.2.0 or later (wasn't working with 2.0
anyway, and noone had complained).
Bugfix: A race in the code for updating iconified window titles could cause
	the filer to crash with a BadWindow error.

26-Jun-2004
-----------
Another Properties window fix: if there is no output from the du command
then put a message indicating an error (Stephen Watson).
Can now compile without Xinerama support on GTK+ < 2.2.0 (Tony Houghton).

23-Jun-2004
-----------
Let the panel autoscroll during a drag (Stephen Watson).

18-Jun-2004
-----------
Fix another bug when closing Properties window before it has finished
scanning the directory (Stephen Watson).

09-Jun-2004
-----------
Improved Xinerama support: now works for tooltips and action windows; filer
windows are no longer prone to leaving their borders overlapping; panel uses
_NET_WM_STRUT_PARTIAL so it only affects the monitor it's on (Tony Houghton).

04-Jun-2004
-----------
Make ignoring executable files with known extensions the default setting
(suggested by Daniel Poersch). Freedesktop.org is discussing a plan to mark
individual MIME types as executable, which may be a better long-term
solution.
Option to prevent maximising windows from covering the panels (requested
by Simon Templer and others).

29-May-2004
-----------
Type specific Send To entries now shown for multiple files when they
are all of the same type (Stephen Watson).
Can now drag icons to the very end of the panel (Stephen Watson).

28-May-2004
-----------
Another place to look for apsymbols.h (Stephen Watson).

26-May-2004
-----------
More fixes for the new build system (Stephen Watson).

25-May-2004
-----------
Fix portability of new build system and ensure configure can find the
version number again (Stephen Watson).

22-May-2004
-----------
Build object files in ~/build/ROX-Filer, in case source directory is read-only.
This also reduces the risk of distributing the object files by accident.

14-May-2004
-----------
Don't allow toolbar buttons to focus (needed for GTK 2.4).

08-May-2004
-----------
Fix loss of bookmark name when re-ordering (Rahsheen Porter).
Removed installation of thumbnail handlers via the Set Icon dialog. It was
never documented and all the thumbnailers use the mime_handler installation
anyway (Stephen Watson).

04-May-2004
-----------
Updated French manual translation (Arnaud Calvo).

02-May-2004
-----------
Updated Dutch translation (Jan Wagemakers).

01-May-2004
-----------
Updated French translation (Vincent Lefèvre).

30-Apr-2004 (Release 2.1.2)
-----------
Removed toolbar hint type from panel. It caused too many problems.

29-Apr-2004
-----------
Added 'Download handler' to drag and drop options. This program is invoked
when a URI is dragged to the filer (eg, from a web-browser). The default
command runs wget to download the file (Andrew Flegg).

27-Apr-2004
-----------
Bugfix: URIs received through drag-and-drop were unescaped twice, causing
	problems with names containing the '%' character (spotted by Jonatan
	Liljedahl).

21-Apr-2004
-----------
Cope with spaces in ROX-Filer's path.
Added a load of default keys, since many GTK setups now make it almost
impossible to change shortcuts.
Added --leaks option to run ROX-Filer through valgrind with the memory
leak option checking on (Stephen Watson).

08-Apr-2004
-----------
Added Xinerama support (Tony Houghton).
Set window type hint = toolbar for panel to prevent it appearing in pagers etc
(Tony Houghton).

04-Apr-2004
-----------
Added method of saving display settings for directories. Mostly working,
but bugs remain related to size and position (Stephen Watson).
Updated Spanish translation (Marcelo Ramos).

03-Apr-2004
-----------
Load extended attribute functions dynamically. This should mean that compiling
ROX-Filer with a new glibc won't make it stop working with older versions due
to the functions being missing.

02-Apr-2004
-----------
Use * as a synonym for unfiltered (Stephen Watson).

25-Mar-2004
-----------
Bookmarks can be given titles (Stephen Watson).

24-Mar-2004
-----------
Fix memory leak in thumbnails code (Stephen Watson).

20-Mar-2004
-----------
Fixed bug in details mode for showing hidden files (Stephen Watson).

18-Mar-2004
-----------
Don't display an error box when installing the ROX icon theme. It just
worries people for no reason.

17-Mar-2004
-----------
Updated Chinese translation (Babyfai Cheung).

16-Mar-2004
-----------
Option to make the File menu appear directly when the menu is opened with
files selected (Peter Geer).

15-Mar-2004
-----------
Added an arrow to the comparison area of the action box so you can see
which file overwrites the other (Stephen Watson).

10-Mar-2004
-----------
Sort by user/group now uses the name, not the number (Stephen Watson).

07-Mar-2004
-----------
Added 'Select by Name'.

06-Mar-2004
-----------
Cope with XRandR screen resizing (Geoff Youngs and Tom Morton).

01-Mar-2004
-----------
Can now filter files by name, using normal shell (glob) patterns (Stephen
Watson).

03-Feb-2004
-----------
Updated it.po and Manual-it (Yuri Bongiorno).

01-Feb-2004
-----------
Updated French translation (Vincent Lefèvre).

24-Jan-2004 (Release 2.1.1)
-----------
Updated French manual translation (Arnaud Calvo).
Updated Dutch translation (Jan Wagemakers).

22-Jan-2004
-----------
Updated French translation (Vincent Lefèvre).

21-Jan-2004
-----------
Misc changes for next release.

18-Jan-2004
-----------
Accept Mozilla's alternative to the standard text/uri-list target during
drag-and-drop (Andrew Flegg).

07-Jan-2004
-----------
Bugfix: Icon shortcuts with out modifier keys didn't work if NumLock,
	CapsLock, etc were turned on (reported by Peter Geer).
Bugfix: Handle case when the output of uname -m contains spaces (Stephen
	Watson, reported on #rox).

06-Jan-2004
-----------
Renamed some functions stolen from Gtk to avoid possible conflicts with
the Gtk-2.3 series (reported by Stu Tissimus).

20-Dec-2003
-----------
Make the Ctrl-button-3 menu pointer appear at the same place regardless
of the number of custom entries (Stephen Watson).

19-Dec-2003
-----------
Make Ctrl-button-3 open the menu slightly higher, so Delete isn't under the
pointer (suggested by Ryan Pavlik).

10-Dec-2003
-----------
Allow non image/* thumbnails in details mode. Label next to the combo
in the Set Type action dialog is now "Type" and not "Command" (Stephen
Watson).

03-Dec-2003
-----------
Work out which include file we need for getxattr (Stephen Watson).

02-Dec-2003
-----------
Allow editing a symlink's target from the Properties box (suggested by Arnaud
Calvo).
Experimental extended attributes support for setting MIME types (Stephen
Watson).

29-Nov-2003
-----------
More drag and drop fixes relating to escaped URI's (Stephen Watson).

23-Nov-2003
-----------
Added 'Specify the prefix' install option (Ryan Pavlik).
Updated Russian translation (Vladimir Popov).

20-Nov-2003
-----------
Bugfix: Cancelling the info window with a du process still running could
	crash the filer (reported by Peter Geer).

17-Nov-2003
-----------
Renamed 'Info' menu item to 'Properties'.

31-Oct-2003
-----------
If a panel icon has an empty label, show it full size (requested by Stephen
Crouch).

26-Oct-2003
-----------
Use apsymbols.h (from autopackage.org) if possible for binary compatibility
with older glibc versions. Use g_ascii_* functions instead of the ctypes ones
for the same reason.
Bugfix: Files with '&' in their names couldn't be saved in groups (reported
	by Nils-Erik Svangård).

25-Oct-2003
-----------
Updated Dutch translation (Jan Wagemakers).
Resizing by double clicking on background now optional (Stephen Watson).

22-Oct-2003
-----------
Added optional top and bottom margines for iconized window placement
(Stephen Watson).

16-Oct-2003
-----------
Don't lower the panel due when the pointer 'leaves' due to a grab (eg, clicking
or opening a menu). This also prevents a flickering problem with Openbox 3.

15-Oct-2003
-----------
Bugfix: FreeBSD reported file sizes with units of 'null' due to large file
	support not being detected (igla).

14-Oct-2003
-----------
Larger default size for bookmarks editor (requested by Matthew Weier OPhinney).

13-Oct 2003
-----------
Let the thumbnail helpers be app dirs, plus can be set from the Set Icon
dialog (Stephen Watson).

09-Oct-2003
-----------
Improved socket icon (taken from Howard Shane's new theme).

08-Oct-2003
-----------
Updated French manual translation (Arnaud Calvo).
Updated German translation (Guido Schimmels).
Offer Eject even for unmounted disks (reported by Matthew Weier O'Phinney).
Try to load icons at 'huge' size, so SVG icons get the chance to scale up
nicely.

07-Oct-2003 (Release 2.1.0)
-----------
Updated French translation (Vincent Lefèvre).
Removed some dead code, memory leaks, etc that had crept in.

04-Oct-2003
-----------
New icon for selection ops.

03-Oct-2003
-----------
Updated Spanish translation (Marcelo Ramos).

01-Oct-2003
-----------
Minor fix to German translation (Daniel Pörsch).

30-Sep-2003
-----------
Update error message about missing MIME database to give the new URI.

29-Sep-2003
-----------
Stock icons in panel and pinboard menus.
Added icon theme selector.

28-Sep-2003
-----------
Added 'Customise Menu' to file menu. Use this to replace Format and Free.

27-Sep-2003
-----------
Allow icons in Choices to override the theme.

26-Sep-2003
-----------
Bugfix: If no pinboard or panel icons were present, the menu could not be
	opened (reported by John Pettigrew).

22-Sep-2003
-----------
Added italian manual, updated it.po (Yuri Bongiorno).
Implementation of Format, just as a user-defined command. Also mount
point menu items reflect mounted/not mounted status (Stephen Watson).

18-Sep-2003
-----------
Implementation of Free Space (Stephen Watson). OpenDir SOAP message now
takes an optional Window element. Pass the same Window to re-use the window.

17-Sep-2003
-----------
Allow ejecting mounted media.

12-Sep-2003
-----------
Don't create a corrupted pinboard/panel file if a non-UTF8 pathname is
dragged to it (reported by Eugeni Andreechtchev).
Get file icons using freedesktop.org icon theme system.

05-Sep-2003
-----------
Added Czech translation (Jan Provaznik).

20-Aug-2003
-----------
Help, Format, Eject and Free Space now appear in the AppMenu section of the
menu. Help is only shown for applications, and the others only for mount
points.

16-Aug-2003
-----------
Added ability to call external programs to generate thumbnails for types
other than image/* (Stephen Watson).

12-Aug-2003
-----------
If a string can't be converted from the local character set to UTF-8,
fallback to converting from iso-8859-1.

07-Aug-2003
-----------
Get shared MIME database through Zero Install, if possible.
Bugfix: Didn't use XDG_DATA_DIRS to find type descriptions.

06-Aug-2003
-----------
Updated French manual translation (Arnaud Calvo).

02-Aug-2003
-----------
Allow types other than image/* to have thumbnails, although we can't
generate them yet (Stephen Watson).
Added Eject menu option for unmounted mount points (Stephen Watson).

28-Jul-2003
-----------
Doing a Refresh in a directory under /uri/0install triggers a remote refresh.

14-Jul-2003
-----------
Less frame-heavy look for info box (Thomas Leonard).
When mounting, force a refresh even if the mtime of the new disk is the same,
since some formats don't change it. Also, if mounting gives an error, check to
see if it worked anyway (Thomas Leonard).

13-Jul-2003
-----------
Added sort and selection buttons to the toolbar. They start off disabled,
enable them from Options->Tools if you want them (Stephen Watson).

Escape text/uri-list for drag and drop operations (Stephen Watson).

12-Jul-2003
-----------
Don't show hidden files on the SendTo menu (reported by Arnaud Calvo).

10-Jul-2003
-----------
Added CheckButtons to the info window to allow manipulation of permission
bits (Stephen Watson).

09-Jul-2003
-----------
Added count of directory contents to info window (Stephen Watson).

04-Jul-2003
-----------
Updated italian translation in AppInfo.xml and src/po/it.po (Yuri Bongiorno)

30-Jun-2003
-----------
When renaming a non-UTF8 file, still assume the directory is valid UTF-8
(reported by Arnaud Calvo).

29-Jun-2003
-----------
Sort items on the SendTo menu (requested by John Pettigrew).

27-Jun-2003
-----------
Removed the menu-on-button-2 option. It was too inconsistant with everything
else, including panel applets and window managers, to be useful. Edit bind.c if
you really need it.

25-Jun-2003
-----------
Button-2 drags on panel applets always work now, even if the applet doesn't
forward them explicitly.

19-Jun-2003
-----------
Fix scrolling problem with GTK+-2.2.2 (reported by Alastair Porter, with
help from Götz Waschk).

16-Jun-2003
-----------
Bugfix: Resize on style change didn't do anything (Andy Hanton).
Bugfix: Dragging to panel and pinboard directories didn't offer the DnD
	menu (reported by BluPhoenyx).

11-Jun-2003
-----------
New SetBackdrop() SOAP method (Matthew Weier O'Phinney).

04-Jun-2003
-----------
Bugfix: Closing a window using the menu didn't offer to unmount (James Bursa).

02-Jun-2003
-----------
Updated Spanish translation (Marcelo Ramos).

01-Jun-2003
-----------
Fix compiler warning when not using dnotify (reported by Damien Couderc).
Show files being operated upon in action windows (Stephen Watson).

30-May-2003 (Release 2.0.0)
-----------
Updated Japanese translation (Hirosi Utumi).

29-May-2003
-----------
Updated it.po and AppInfo.xml (Yuri Bongiorno).

28-May-2003 (Release 1.3.10)
-----------
Updated French manual translation (Arnaud Calvo).

27-May-2003
-----------
When dragging a lasso box in List view, don't stop scrolling when the pointer
leaves the window (reported by Robert Davison).
Updated Polish translation (Andrzej Borsuk).
Updated Italian translation (Yuri Bongiorno).

26-May-2003
-----------
Updated German translation (Guido Schimmels).

25-May-2003
-----------
Updated Dutch translation (Jan Wagemakers).

24-May-2003
-----------
Updated French translation (Vincent Lefèvre).

22-May-2003
-----------
Minor updates to the manual.
Bugfix: Using the Edit MIME types button in the Options window opened the
	old directory. Refer people to the MIME-Editor application instead.

18-May-2003
-----------
Fixed focussing problems in Icons View (reported by Andrzej Radecki).
Updated French manual translation (Arnaud Calvo).

16-May-2003 (Release 1.3.9)
-----------
New icon for the filer (Geoff Youngs).
Updated it.po and AppInfo.xml (Yuri Bongiorno).

15-May-2003
-----------
Added Japanese translation (Hirosi Utumi).
When a directory change is detected, wait a little before rescanning to
reduce flickering effect.

14-May-2003
-----------
Page Up and Page Down now work again in List View.

27-Apr-2003
-----------
Updated install script to use new XDG Base Directory spec (reported by
Vincent Lefevre).
Also install man pages under 'share/man'.

25-Apr-2003
-----------
Close stdout when running child processes for users running startx from the
console, since some terminal applications try to read from the console,
freezing X (Keith R. John Warno).
Forward scroll events on pinboard to window manager, and add option to
workaround *box issues (Matthew Weier O'Phinney).

24-Apr-2003
-----------
Using the bookmarks menu to open an unmounted mount point will mount it
(suggested by Arnaud Calvo).

17-Apr-2003
-----------
Updates for the new shared MIME database.

15-Apr-2003
-----------
Refresh refreshed the directory twice (because updating the MIME info triggers
a refresh too).

12-Apr-2003
-----------
Remove default GtkTreeView keys (they conflicted with the menus).
Fixed some minor cursor problems in List view.

10-Apr-2003
-----------
Winking now works in List view.

09-Apr-2003
-----------
Lasso selections now work in List view.

08-Apr-2003
-----------
The hack we have to use to draw pinboard icons on GTK+-2.0 doesn't work
on 2.2. Show a warning instead of crashing (reported by Keith R. John Warno).

03-Apr-2003
-----------
Fix the message in install.sh, since there is no information toolbar icon
now (spotted by Albert Wagner).

29-Mar-2003 (Release 1.3.8)
-----------
Updated French manual translation (Arnaud Calvo).

28-Mar-2003
-----------
Updated French translation (Vincent Lefèvre).

27-Mar-2003
-----------
Allow dragging a file into a GtkEntry to insert the filename.
Bugfix: Selections in List View didn't work properly (reported by Stephen
	Watson).
Updated Spanish translation (Marcelo Ramos).

23-Mar-2003
-----------
Fixed use of a GTK+-2.2-only function (Geoff Youngs).
New option to set the panel size (Geoff Youngs).

21-Mar-2003
-----------
Scroll panels when the pointer is at the end, not by dragging the middle
(Geoff Youngs).
Stop the pinboard from flickering when removing icons or iconfied windows.

20-Mar-2003
-----------
Centre the image for iconified windows.
Double-buffer slightly larger areas.

18-Mar-2003
-----------
Better way to implement selections in List View (suggested by Jonathan
Blandford).
Updated Italian translation (Yuri Bongiorno).

15-Mar-2003
-----------
Bugfix: Never show the copy/move/link menu when dragging to an application.

11-Mar-2003
-----------
Bugfix: Comments about a MIME type were loaded from the first file to contain
	information about the type, not the first to contain a comment about
	the type.

09-Mar-2003
-----------
Don't mark widget documentation as translatable.
Make sure the tooltip for pinboard and panel icons is up-to-date (reported
by krjw).
Use pinboard backdrop colour for scaled and centred images (requested by
Marcelo Ramos).
Shade the backdrop style buttons when an external program is being used to
set the backdrop.
Updated Spanish translation (Marcelo Ramos).

08-Mar-2003
-----------
Updated Dutch translation (Jan Wagemakers).

07-Mar-2003
-----------
Use stock icons in pinboard and panel menus.
Updated Spanish translation (Marcelo Ramos).

03-Mar-2003
-----------
Use stock icons in menus, and fix some possible problems in the menu code
(Stephen Watson).

02-Mar-2003
-----------
Stop pinboard icons flickering when you move over them (Daniele Peri).
Use XSettings drag-and-drop threshold.

01-Mar-2003
-----------
Bugfix: Backdrop image could be redrawn in the wrong place (Stephen Watson).

27-Feb-2003 (Release 1.3.7)
-----------
Updated French manual translation (Arnaud Calvo).
Allow an empty AppInfo translation so that a label can be translated without
changing the value.

25-Feb-2003
-----------
Updated Russian translation (Alexey Lubimov).

23-Feb-2003
-----------
When using the Rename and Link boxes, use the appropriate drag cursor
(suggested by Michael Adams).
Bugfix: A double-click which starts on one file and ends on another is now
	ignored (reported by Michael Adams).
Bugfix: Test for valid sort-type in SOAP call was reserved, so you couldn't set
	the sort type (reported by Damjan Bole).
Bugfix: Using a SOAP call to open a non-existant directory made the filer
	crash.
Bugfix: Drag-and-drop raising on the panel didn't quite work (Daniele Peri).

22-Feb-2003
-----------
Make Size toolbar icon only set the size. Use a second button to set automatic
mode.

13-Feb-2003
-----------
Updated Spanish translation (Marcelo Ramos).
Alpha blended pinboard icons now get clipped correctly even with GTK+-2.0.

12-Feb-2003
-----------
Fixed some spelling errors (Marcelo Ramos).
Select the current style by default when opening the Set Backdrop box
(reported by Marcelo Ramos).
Fix problems with pinboard drawing of semi-transparent icons (fixed for
GTK+-2.2 only).

11-Feb-2003
-----------
Merged Set Run Action, Set Icon and Set Backdrop dropboxes into a single
Ultimate DropBox widget, and made all three interfaces much nicer.
Dragging to the Home and Up toolbar tools now supports the menu-on-drag
option (reported by Laurent Moussault).
Allow changing the pinboard style without having to drag the image back in
(requested by Jesse Wagner).
Remove button style from iconified windows. Use a semi-transparent border
instead. The actual effect is flexible; perhaps someone with artistic
talent can do something better?
Double-buffer small pinboard updates.
Updated Spanish translation (Marcelo Ramos).

10-Feb-2003
-----------
Option to turn off column headings in List View (Adam Sampson).
Panel auto-raising also works during drag-and-drop.
Bugfix: Installing to /usr put the MIME files in the wrong place (reported
	by Albert Wagner).

09-Feb-2003
-----------
Allow dragging to a selected directory as long as it's not the source of the
drag.
If an error occurs opening a directory then don't report it in an error box if
a drag-and-drop operation is in progress.
Keep the title up-to-date for iconified windows.
Option to show menu on button-1 drags instead of copying.
Aborting an action window tries to kill all child processes, not just the
immediate child, and doesn't close the window until it has actually stopped.
Symlinks to mount points now work (reported by Daniele Peri).
Include textual description of types in various places (Stephen Watson).
Allow dragging directories to bookmarks edit window or toolbar icon, with
spring loading (suggested by Stephen Watson and George De Bruin).
Removed confusing Set Icon choice from DnD menu.
Bugfix: If a directory on the panel changed to/from being an application, the
	label wasn't hidden / shown.

08-Feb-2003
-----------
Changing the icon for a MIME type updates all filer windows.
When dragging a pinboard icon over itself, pretend the icon isn't there to
allow fine repositioning.
When an error prevents scanning a directory, show the error in the window
title bar, and only report it once in an error box.
Don't create thumbnails of thumbnails by checking if the image is in
~/.thumbnails/normal. Before, the test was the size of the file, not its
location.
Pinboard image style Scale is now called Stretch; Scale now scales without
changing the aspect ratio.

07-Feb-2003
-----------
Auto-scrolling during drag-and-drop works again, and now in list view too.

02-Feb-2003
-----------
Fixed clipping and wrapping problems with pinboard icon text.

01-Feb-2003
-----------
Don't use double-buffering for the pinboard. This might make things flicker
slightly, but it's much faster on some systems.
Updated Spanish translation (Marcelo Ramos).

31-Jan-2003
-----------
Added Bookmarks 'Recently Visited' submenu (Stephen Watson).

28-Jan-2003
-----------
Replaced some of the icons with some GNOME ones (slightly modified in some
cases).

27-Jan-2003
-----------
Slightly adjusted the 'normal' icon height to be the same size as GNOME to
make sharing icons easier.
Updated Polish translation (Marcin Juszkiewicz).

26-Jan-2003
-----------
Bugfix: Symlinking to an application required the symlink, rather than the
	target directory, to have the same owner as the AppRun (Keith Warno).

25-Jan-2003
-----------
Bugfix: Hyper and Super modifiers didn't work properly as icon shortcuts.

23-Jan-2003
-----------
Work around changes in Gtk+-2.2 that stopped the panel from appearing on all
workspaces.
Add scrollbars to bookmarks editor window (requested by George De Bruin).

22-Jan-2003
-----------
Bugfix: Filer would quit if only the Bookmarks editor window was open (reported
	by Bernard Jungen).

20-Jan-2003
-----------
New option to sort capitalised names first (requested by Paul Etchells and
others).

19-Jan-2003
-----------
Updated Spanish translation (Marcelo Ramos).
Fixed wheel mouse scroll bug in List View (reported by Vincent Lefevre and
others).
Attempt to improve the autosizing by examining the item with the longest name.
Don't scale icons up in Huge mode.
In translated <About> sections in AppInfo.xml files, allow a 'label=' attribute
to translate the key (requested by Guido Schimmels).

18-Jan-2003
-----------
Added dnotify support, so that on Linux the filer now updates automatically
when a directory is changed (requested by Taras and Dave C).

16-Jan-2003
-----------
Added icon to infobox (Geoff Youngs and Marcin Juszkiewicz).

14-Jan-2003
-----------
Add GTK versions used for compiling and running to -v output (suggested by
Vincent Lefèvre).
Bugfix: Drag-and-drop in Icons View didn't work while scrolled (reported by
	Brian Langenberger).

13-Jan-2003
-----------
Change 'Type' to 'Types' (Vincent Lefèvre).
Don't resize when changing the view type if auto-resizing is off (Keith R. John
Warno).
Added missing cast and detect long files on OpenBSD (Damien Couderc).

10-Jan-2003
-----------
Remove -o from --help output (spotted by Karol Krenski).
Updated Spanish translation (Marcelo Ramos).

09-Jan-2003 (Release 1.3.6)
-----------
Fix reference counting problem shown up by Gtk+-2.2.

06-Jan-2003
-----------
Updated German translation (Guido Schimmels).
Make toolbar extend the whole width of the window (suggested by Andrzej
Radecki).

05-Jan-2003
-----------
Updated Polish translation (Marcin Juszkiewicz).

04-Jan-2003
-----------
Updated French translation and fixed untranslatable string (Vincent Lefèvre).
When using bigger/smaller, don't wrap at the end (suggested by Arnaud Calvo).
Updated French manual translation (Arnaud Calvo).

02-Jan-2003
-----------
Updated Spanish translation (Marcelo Ramos).
Updated Dutch translation (Jan Wagemakers).

01-Jan-2003
-----------
Added button in options window to purge thumbnails cache.

30-Dec-2002
-----------
Preserve selection when changing view type.
Shade selection when we don't have primary.

29-Dec-2002
-----------
Show thumbnails in List view. Allow changing the icon size. If the size is
automatic, show thumbnails as Huge and everything else as Small.
Scroll wheel now works in List view.

28-Dec-2002
-----------
Use bold style to indicate recent items (instead of the pink background).

27-Dec-2002
-----------
Sort type is shared between Icon and List views. Sort order can be reversed.
Highlight recently changed items with a tasteful pink background.
When the bookmark editor window first opened, no item was selected. If the
user clicked on it to select it, editing mode started instead (reported by
Bernard Jungen).
Removed most of the options section of the manual, since it was just echoing
the information in the tooltips anyway.

26-Dec-2002
-----------
Various fixes to new list view (reported by George De Bruin).
Mounting and unmounting auto-resizes the window.

25-Dec-2002
-----------
Right-clicking the Size button switches to automatic mode and resizes the
window.

24-Dec-2002
-----------
Made 'Automatic' an icon size, rather than a separate option.
Size toolbar button shows a menu, including the new Automatic setting.

23-Dec-2002
-----------
Rearranged menus and options for new List View mode.

20-Dec-2002
-----------
Removed warning message from --new. It can be useful for a session manager...
Draw iconified windows with a background, so they don't get confused with other
icons (suggested by Joakim Andreasson).
Bugfix: Stupid bug stopped iconified windows from being removed and could
	cause a crash!

17-Dec-2002
-----------
The 'Directories always come first' option now only applies to name sorts.
Sort by date and size default order has been reversed.
Always use case-insensitive sort.

16-Dec-2002
-----------
Updated French manual translation (Arnaud Calvo).

12-Dec-2002
-----------
Details toolbar button switches to the new (unfinished) details view.
Bugfix: Fix detection of new pango wrapping system (Richard Olsson)

11-Dec-2002
-----------
Style improvements to Edit Icon box.
Don't show Size attribute for directories in the Info box. It was confusing,
since it didn't include the contents.
Bugfix: Right-clicking on the Bookmarks icon to edit the bookmarks would
	cause a crash if the bookmarks were not yet loaded.

10-Dec-2002
-----------
Code tidying (Bernard Jungen).

09-Dec-2002
-----------
Style improvements to options window.

08-Dec-2002
-----------
Updated Spanish translation (Marcelo Ramos).

06-Dec-2002
-----------
Updated German translation (Guido Schimmels).

04-Dec-2002 (Release 1.3.5)
-----------
Using the Close toolbar button also offers to unmount devices (spotted by
Götz Waschk).

03-Dec-2002
-----------
Clicking on a mount point auto-mounts. The shift action is now to open without
mounting. Closing a filer window showing a mount point offers to unmount it
(suggested by Guido Schimmels and others).
Use stock icons in more dialogs.

02-Dec-2002
-----------
Allow editing the path for bookmarks.

01-Dec-2002
-----------
Added 'Edit Bookmarks' dialog and 'Show Bookmarks' menu entry.

29-Nov-2002
-----------
New mount icons (suggested by Marcin Juszkiewicz).
Don't show separator in bookmarks menu when there is nothing below it.

28-Nov-2002
-----------
Added a default hander for HTML files, otherwise newbies can't read the
manual!
Bugfix: Pinboards without backdrop images didn't get the correct colour set
	by default.

27-Nov-2002
-----------
Better positioning of bookmarks menu.

22-Nov-2002
-----------
Updated Spanish translation (Marcelo Ramos).
Allow translation of About AppInfo section.
Bugfix: When using Metacity, some minimised windows weren't shown (reported by
	Alastair Porter).

21-Nov-2002
-----------
More tooltips for the Set Icon dialog.

20-Nov-2002
-----------
Use better wrapping system, if available (Richard Olsson).

15-Nov-2002
-----------
Removed ASCII sort option. Useless, and didn't work with UTF-8 anyway.

13-Nov-2002
-----------
New sorting system to cope with UTF-8 filenames.

12-Nov-2002
-----------
Use stdout, not stderr, for --help and --version, and use xmllint instead of
nsgmls to check for valid DocBook (Eric Gillespie).
Updated Chinese translation (babyfai Cheung).

11-Nov-2002
-----------
Added note about checking permissions to message complaining that the MIME
database can't be found (suggested by Keir Mierle).

07-Nov-2002
-----------
Set hint to make panels appear on all workspaces, and support metacity-style
iconified windows (reported by Alastair Porter; suggested fix by Laurent
Moussault).

05-Nov-2002
-----------
Added Bookmarks toolbar icon (Liav).

04-Nov-2002
-----------
Removed some unused code and fixed a possible race condition.

03-Nov-2002
-----------
Update error message to give correct version of MIME database (reported by
FD Cami).

31-Oct-2002
-----------
Make the Find and Permissions help windows look nicer.
Added support for shadowed labels on the pinboard (Andras Mohari).

29-Oct-2002
-----------
Stop Metacity from complaining that it can't decide whether the pinboard is
resizable or not (reported by Alastair Porter, solution suggested by
Havoc Pennington).

28-Oct-2002
-----------
Make it more obvious that --new is only for debugging.
Added Norwegian translation (Sigve Indregard).

27-Oct-2002
-----------
Use our own stock icons for 'show hidden' and 'show details' toolbar buttons
(Stephen Watson). New details icon is a modified version of a Gtk stock
icon, while show hidden is taken from sawfish.

26-Oct-2002
-----------
Code tidying (Bernard Jungen).

23-Oct-2002
-----------
Switch button-1/2 on Help, as it was too annoying.
Create thumbnails at 128x128 to be in-line with current thumbnails spec.
Bugfix: When using the lasso box with the pinboard, select icons based on
	where they actually are, not where they want to be (useful if you've
	just changed to a lower resolution and they're all stuck at the side!).

22-Oct-2002
-----------
Button-1 on Help shows the manual, other button opens the Help directory
(Marcin Juszkiewicz).

21-Oct-2002
-----------
More checks to cope with invalid filenames (Marcin Juszkiewicz).
Updated Polish translation (Marcin Juszkiewicz).

19-Oct-2002
-----------
Updated Spanish translation (Marcelo Ramos).

18-Oct-2002
-----------
Cope slightly better with invalid filenames in various places (reported by
Marcin Juszkiewicz and Andras Mohari).
Make panel menus appear nearer the edge of the screen for top, left and right
panels (suggested by Bernard Jungen).
Bugfix: When installing the binary release, don't warn the user that the source
	is missing (reported by John Pettigrew).

17-Oct-2002
-----------
Code tidying (Bernard Jungen).
Fixed broken links to citations in manual (reported by Bernard Jungen).
Renamed sp.po to es.po (requested by Quique).

12-Oct-2002
-----------
Added Swedish translation (Marcus Lundblad).
Bugfix: Invert Selection failed to work correctly on the first item (spotted by
	Stephen Watson).

09-Oct-2002
-----------
Updated French manual translation (Arnaud Calvo).

07-Oct-2002
-----------
Updated French translation (Vincent Lefèvre).

01-Oct-2002 (Release 1.3.4)
-----------
Require glib >= 2.0.3, or action windows leak file handles (reported by
Musus Umbra).

27-Sep-2002
-----------
Allow multiple pinboard icons to be repositioned at once.

26-Sep-2002
-----------
Allow multiple pinboard icons to be selected by dragging a box around them.

23-Sep-2002
-----------
Pinboard and panel icons can now have keyboard shortcuts assigned to them.
Bugfix: Fixed a couple of cursor positioning problems (reported by Andras
Mohari).

22-Sep-2002
-----------
Replace -o command-line option with a toggle button in the options window.

17-Sep-2002
-----------
Updated French manual translation (Arnaud Calvo).

05-Sep-2002
-----------
Be more forceful about setting the pinboard backdrop; some themes were
overriding it (reported by Biju Chacko).
Use K, M and G consistantly (Marcin Juszkiewicz).

03-Sep-2002
-----------
Shift Open had stopped working (spotted by Matthew Weier O'Phinney).

02-Sep-2002
-----------
Changed default Set Run Action shell command from "$1" to "$@" (suggested by
krjw).

01-Sep-2002
-----------
Updated Spanish translation (Marcelo Ramos).

30-Aug-2002
-----------
New 'Class' parameter to Filer_OpenDir SOAP method allows setting the
WM_CLASS of a new window so that the window manager can treat it
specially, such as opening it in a certain place, or make it sticky
(requested by Matthew Weier O'Phinney).

27-Aug-2002
-----------
New option to set the pinboard font (Krzysztof Luks).

26-Aug-2002
-----------
Updated French translation (Vincent Lefèvre).
Updated Italian translation (Daniele Peri).

17-Aug-2002
-----------
Increase time between updates while scanning from 0.5s to 1.5s. Now that the
names are all shown from the start, fast feedback here is less useful.
When resizing due to a key event, warp the pointer (for sloppy focus users).

13-Aug-2002
-----------
Removed Re-read MIME types button. Use Refresh on the toolbar instead.

11-Aug-2002
-----------
Internal changes: moved menu and toolbar over to View interface.

05-Aug-2002
-----------
Open the menu on the 'popup-menu' signal. Allows you to use the default Gtk
keyboard shortcuts to open the menu.
Translated AppInfo menu entries into Hungarian (Andras Mohari) and
Spanish (Marcelo Ramos).
After dragging to a remote application which didn't respond, the filer
refused to gain the primary selection until the operation timed out.

02-Aug-2002
-----------
Use stock icons for multi-file drag-and-drop, files with missing icons, and
files that can't be statted (Marcin Juszkiewicz).

01-Aug-2002
-----------
Make --version's output convert to the local character set (Vincent Lefevre).
Make menu items in AppInfo.xml files translatable (requested by
Wilbert Berendsen, Andras Mohari and Marcelo Ramos).

29-Jul-2002
-----------
Change pinboard option to forward button 3 to forward all buttons (requested
by Matthew Weier O'Phinney).

28-Jul-2002
-----------
Use Gtk's new stock info icon instead of help icon for minibuffer, etc.

26-Jul-2002
-----------
Updated French translation (Vincent Lefèvre).
Updated Spanish translation (Marcelo Ramos).
Using Edit MIME types in the Options box now opens the new 'packages'
directory instead of the old 'mime-info' one (reported by Goetz Waschk).

24-Jul-2002 (Release 1.3.3)
-----------
Updated to new shared MIME database format.

23-Jul-2002
-----------
Alt-Return or Alt-Button-1 on a file works like clicking with button-2; it
opens a directory in a new window and closes the directory when opening a file
(suggested by Gregory Spath).

22-Jul-2002
-----------
Use stock icons for toolbar, to make it themeable (requested by Michael Adams).

21-Jul-2002
-----------
Made the stepper arrows in the scrollbars scroll by one item's height, fixed
an untranslatable string and fixed a slight error in the size calculation
(Bernard Jungen).

19-Jul-2002
-----------
Rearraged File menu (suggested by Tomas Berg).

16-Jul-2002
-----------
Added support for Solaris 'Door' files (Stephen Watson).

12-Jul-2002
-----------
Added Help menu with both About and Show Files entries, and a new entry to
load the corrent manual for the current locale (suggested by Arnaud Calvo).

11-Jul-2002
-----------
Updated French manual translation (Arnaud Calvo).
Changed 'Show ROX-Filer Help' to 'About ROX-Filer...'. This shows the Info
box, with a new 'Show Help Files' button (Geoff Youngs).

09-Jul-2002
-----------
Don't close the Set Run Action box after showing the usage message if the user
enters an invalid command (spotted by krjw).

07-Jul-2002
-----------
Bugfix: Changing the pinboard colours when iconfied windows were not in use
	displayed a (harmless) warning message (reported by krjw).

02-Jul-2002
-----------
Security fix: Set Run Action to a shell command would make the executable
	      world-writeable (spotted by alexander).

28-Jun-2002
-----------
Bugfix: Tooltips for files sometimes didn't get displayed.

26-Jun-2002
-----------
Added reminder about having NumLock on when using groups from the keypad
(suggested by Gombok Arthur).

25-Jun-2002
-----------
Turned on more compiler warnings, and fixed some minor issues it threw up.

22-Jun-2002 (Release 1.3.2)
-----------
Updated French translation (Vincent Lefèvre).

21-Jun-2002
-----------
Added 'Text beside icon' toolbar style (Michael Adams).

20-Jun-2002
-----------
Bugfix: Using another window in between entering target mode and selecting
	the target printed a warning instead of performing the operation.

17-Jun-2002
-----------
Fix problem with root menu positioning on icewm (reported by Bernard Jungen).

16-Jun-2002
-----------
More robust approach to SOAP errors.

11-Jun-2002
-----------
Require version 2.0.1 or later of Gtk, due to bugs in 2.0.0.
Changing the pinboard font realigns the icons.
Bugfix: Symlinked items in the SendTo menu didn't use globicons correctly
	(spotted by Arnaud Calvo).
Bugfix: Filer sometimes failed to load the backdrop supplied by a program
	(reported by Arnaud Calvo).

10-Jun-2002
-----------
Updated Spanish translation (Marcelo Ramos).

08-Jun-2002
-----------
Move Xterm Here to Window menu and add Switch to xterm (suggested by
Gregory Spath).
Bugfix: Some shortcuts didn't work properly on some keyboards (reported by
	Lorint and Musus Umbra).

06-Jun-2002
-----------
When installing without a manpage, just warn the user instead of aborting
(suggested by Simon Britnell).

01-Jun-2002
-----------
Code tidying (Bernard Jungen).

31-May-2002
-----------
Option to switch automatically between Large and Small icons (Stephen Watson).
Allow blank icon names (suggested by Gregory Spath).
Bugfix: Default icon for iconified windows wasn't found (Jimmy Olgeni).
Bugfix: Sometimes the SOAP message sent to a running process got displayed.

30-May-2002 (Release 1.3.1)
-----------
Fix redraw bug with selected icons.

29-May-2002
-----------
Respect CHOICESPATH when installing (spotted by Vincent Lefevre).
Set Icon now creates icons in PNG format (spotted by Wilbert Berendsen).

28-May-2002
-----------
Merged in icons from rox-base (converted to PNG format and renamed).
Bugfix: When showing iconified windows, the filer could crash if a window
	disappeared at the wrong moment.

27-May-2002
-----------
Set _XROOTPMAP_ID property on root window so that Eterm and friends show
the right backdrop (requested by Simon Britnell).
Use .png icons in MIME-icons instead of .xpm (needed to change anyway as
the new shared MIME database uses different types in many places).
Updated French translation (Vincent Lefèvre).
Updated Dutch translation (Wilbert Berendsen).
Updated Hungarian translation (Andras Mohari).

24-May-2002
-----------
When using -d or -s options, don't follow symlinks in paths starting with '/'
(suggested by Darrell Taylor).

23-May-2002
-----------
Code tidying (Bernard Jungen).

21-May-2002
-----------
Updated Polish translation (Krzysztof Krzy¿aniak).

19-May-2002
-----------
Setting the background colour doesn't lose the image (spotted by Jasper
Huijsmans).

18-May-2002
-----------
Iconified windows are shown with their own icon, if they have one.

17-May-2002
-----------
Options to set iconification layout policy.
Fix compiler warnings on some systems (Stephen Watson).
Added 'Follow Symbolic Links' menu item (Stephen Watson).

16-May-2002
-----------
Pinboard background colour option works again.
Position iconified windows sensibly.
Bugfix: Typing too fast into the minibuffer could miss characters.

15-May-2002
-----------
Wrap long icon names onto multiple lines.
Options to forward button-3 clicks on the pinboard to the window manager
(requested by Ryan Harris).

14-May-2002
-----------
Code tidying (Bernard Jungen).
Bugfix: Ctrl-clicking on icons can unselect, not just select.

13-May-2002
-----------
Bugfix: Short form of '--client-id' option didn't work (reported by Julio
	Hugo Toloza).

12-May-2002
-----------
Allow hidden subdirectories in <Choices>/SendTo which have their contents
included only for certain MIME types (Geoff Youngs).
When changing directory, remove any trailing /s from the path.
Make sure panels never get lowered under the pinboard.
Iconified windows are now displayed on the pinboard, not floating over
everything else.
Bugfix: Using a savebox when the pathname contained multi-byte characters
	caused the initial selected region to be positioned incorrectly.

10-May-2002
-----------
Initial support for showing iconified windows.

09-May-2002
-----------
Changed the way pinboard icons are implemented.
Changed the way backdrop applications set the backdrop.
Always use button-3 for the pinboard menu, as the window manager menu must
be on button-2 (spotted by Geoff Youngs).

08-May-2002
-----------
Updated French manual translation (Arnaud Calvo).
Middle button clicks on the pinboard are passed to the window manager.
Many improvements to the pinboard:
- Changing font updates the pinboard icons.
- Button-2 clicks are passed to window manager.
- Drop highlight doesn't flicker.

07-May-2002
-----------
Improved highlighting of icons (Andras Mohari).

06-May-2002
-----------
The pinboard is now a screen-sized window. Faster and better looking.
Setting the backdrop is now done from the filer.

03-May-2002
-----------
The Link box allows an existing symlink to be replaced, instead of
complaining that the destination already exists (suggested by Arnaud Calvo).
Bugfix: When editing a panel icon, the tooltip didn't update until the next
	restart (Olli Helenius).

02-May-2002
-----------
Added Sort to the OpenDir SOAP method (Stephen Watson).

30-Apr-2002
-----------
Alpha-blending for Small icons, too.
Bugfix: When copying directories, ignore an error caused by filesystems,
	such as Samba shares, that don't support chmod fully (reported by
	Andrew S Dixon).

29-Apr-2002
-----------
SOAP method OpenDir now allows Style and Details to be specified
(Stephen Watson).

28-Apr-2002
-----------
Use alpha-blending in Large and Huge display modes. Limit icons in menus to
Small and Large sizes.

27-Apr-2002
-----------
Return in Permissions box activates Quiet.

26-Apr-2002
-----------
MIME information is now read from the freedesktop.org shared database rather
than the old Choices/MIME-info directories.

25-Apr-2002
-----------
Don't convert to `real' path when following symlinks, so that Up now returns
to the directory containing the symlink, not the thing it linked to
(requested by Gregory Spath).
Don't quit while Options window is open.

21-Apr-2002
-----------
Allow panel style to be set from ~/.gtkrc-2.0, using 'rox-panel' to identify
the window (requested by Ashwin).
Merged OK and Save buttons in the Options box. Revert shades when it would
have no effect.

17-Apr-2002
-----------
'New ...' for a template always copies without confirming (suggested by
Wilbert Berendsen).

16-Apr-2002
-----------
Set-keybindings button in options box now checks that this feature is on,
and explains what to do if not (suggested by Francesco Bochicchio).

15-Apr-2002
-----------
Updated French translation (Vincent Lefèvre).
Message in translation options switches language as you move through the
options.

14-Apr-2002
-----------
Added Chinese translation (babyfai cheung).

14-Apr-2002 (Release 1.3.0)
-----------
Fixed a minor redraw box (a single pixel could get left after a lasso drag).

13-Apr-2002
-----------
Place action windows under pointer (suggested by txapela).

11-Apr-2002
-----------
Set collection style in the program. Choices/ROX-Filer/Styles is no longer
used.
Made background pixmaps for Collections work again (reported by Stephen
Watson).
Removed pinboard text background style option (it never worked with Gtk+-2.0).

09-Apr-2002
-----------
Added units display to options and improved toolbar options layout (Andras
Mohari).
When setting the icon for a directory, offer to create a .DirIcon
(requested by Matjaz Mihelic).

08-Apr-2002
-----------
Much improved layout for Options box (Andras Mohari).
Allow subdirectories in the Send To menu (Stephen Watson).

06-Apr-2002
-----------
Code tidying in various places (Bernard Jungen).
Filer windows update automatically when the font or theme changes.

05-Apr-2002
-----------
Various speed improvements.
Removed GNOME VFS option (never worked with Gtk+-2.0).

04-Apr-2002
-----------
Auto-raise panels when the pointer hits the side of the screen, and lower
when it leaves the panel (Geoff Youngs).

03-Apr-2002
-----------
Slight speed increase when starting.

02-Apr-2002
-----------
Added Danish translation (Christian Storgaard).

01-Apr-2002
-----------
Internal tidy-up of the icon code: PinIcon and PanelIcon are now subclasses
of Icon, which is now a GObject. Dragging pinboard icons with the middle
button is no longer supported.

28-Mar-2002
-----------
Updated Polish translation (Krzysztof Krzy¿aniak).

25-Mar-2002
-----------
New 'Short titlebar flags' option (requested by Andras Mohari).

24-Mar-2002
-----------
Fixed problem which allowed the panel to get the input focus (reported by
Brendan McCarthy).

22-Mar-2002
-----------
Large (over 50K) image files are now loaded in a subprocess. Faster, less
likely to crash due to bad images, and more responsive.

21-Mar-2002
-----------
Filenames which are not valid UTF-8 are shown in red. A tooltip explains the
problem. CHARSET is used to try and render the name anyway, and the rename
box can be used to fix it (reported by Christopher Arndt).

20-Mar-2002
-----------
Times weren't converted to UTF-8, causing errors in some locales (reported
by Christopher Arndt and tracked down by Andras Mohari).
Informational messages are now shown with the info icon, not the error symbol
(suggested by Andras Mohari).

18-Mar-2002
-----------
Set _WIN_HINTS for pinboard and panel icons so that they don't appear on
task-lists or get selected when Alt-Tabbing (Brendan McCarthy).
Allow COMPOUND_TEXT target for pinboard and panels (allows pasting into
gnome-terminal).
The Path Entry minibuffer now highlights invalid paths in red, instead of
beeping.

17-Mar-2002
-----------
Internal changes: MaskedPixmap, Directory and XMLwrapper types are now
GObjects. FSCache now works on GObjects, and the interface is therefore
simpler now.

16-Mar-2002
-----------
Sorted out some focussing and defaulting behaviour in action windows.

14-Mar-2002
-----------
Split action window code, so that most of the GUI stuff is now in abox.c,
and converted to new dialog style.

13-Mar-2002
-----------
Removed remaining support for the old libvfs.
Updated lots of code to new Gtk+-2.0 style.

12-Mar-2002
-----------
Panel icons highlight when the pointer is over them.
Fixed some untranslatable strings (Andras Mohari).

11-Mar-2002
-----------
Converted Set Run Action box to new style.

10-Mar-2002
-----------
New panel style; better looking, and sensitive right up to the edge of the
screen.
Converted action window results list to use the new GtkTreeView widget.

09-Mar-2002
-----------
Converted Savebox widget to new Gtk style.

07-Mar-2002
-----------
Fix compile problems with Gtk+-2.0-rc1 (missing X libs and cflags).
Added stock icons to Options box. The filer now requires Gtk+-2.0.
Updated Infobox to use new GtkTreeView widget.

05-Mar-2002
-----------
Display action window questions in bold (suggested by Andras Mohari).
Added PanelAdd and PinboardAdd SOAP methods (Stephen Watson).

28-Feb-2002
-----------
Fixed sensitive region of icons in large with details display (Bernard
Jungen).

27-Feb-2002
-----------
Added Newer option for Copy and Move operations (Stephen Watson).

26-Feb-2002
-----------
Centre colour selector on mouse, and close when options box closes.
Got background pixmaps working with Gtk+-2.0.

21-Feb-2002
-----------
Changes to options now take effect instantly. The old Apply button is gone,
and Cancel is now Revert.
Fixed stupid bug in charset conversions (reported by Andras Mohari).
Initial support for gnome-vfs (Mark Heily).

20-Feb-2002
-----------
Internal changes to the options system. See text at start of options.c.

19-Feb-2002
-----------
Changed 'Ignore case' option to 'Intelligent sorting'. A non-ASCII sort now
handles numbers in a sensible way, so that 'file10' comes after 'file9', etc
(Micah Dowty).
Fix possible type conversion problem in charset conversion code
(reported by Serban Udrea).
Allow xml:lang attribute in AppInfo files for translations; see
ROX-Filer/AppInfo.xml for an example (suggested by Wilbert Berendsen).

18-Feb-2002
-----------
Try to compile against Gtk+-2.0 first, and only fallback to 1.2 if it's not
found.
In an Infobox, strip trailing newlines from file's output as Gtk+-2.0
labels display them.
Scroll in whole items with Gtk+-1.2, plus better cursor alignment (Bernard
Jungen).

17-Feb-2002 (Release 1.2.0)
-----------
New stable release.

13-Feb-2002 (Release 1.1.14)
-----------
Pressing Escape in a dialog box now closes the box.

12-Feb-2002
-----------
Fix compile problem if iconv.h is missing and allow CPPFLAGS settings to
be used in Makefile (Jim Knoble).
Undo 'double clicking unselects' change (requested by Andreas).

11-Feb-2002
-----------
Updated Spanish translation (Marcelo Ramos).
Updated French manual translation (Arnaud Calvo).

08-Feb-2002 (Release 1.1.13)
-----------
Use fixed font in minibuffer.

07-Feb-2002
-----------
Updated French manual translation (Arnaud Calvo).
Updated Russian translation (Dmitry Elfimov).

06-Feb-2002
-----------
When dragging a lasso box around items, limit the allowed overlap (the
space you can drag over the edge of the next item without selecting it)
so that very wide items (eg, those with details) are easier to select
(requested by Andras Mohari).

04-Feb-2002
-----------
Updated Italian translation (Denis Manente).

03-Feb-2002
-----------
Updated German translation (André Wyrwa).
Updated Spanish translation (Marcelo Ramos).

02-Feb-2002
-----------
Updated to version 0.5 of the thumbnails standard. You should rename
'~/.thumbnails/96x96' to '~/.thumbnails/normal' to avoid having to recreate
them all.

01-Feb-2002
-----------
Do UTF-8 conversions for globicons and file groups, as we now do for pinboards
and panels (reported by Arnaud Calvo).

31-Jan-2002
-----------
Updated Hungarian translation (Andras Mohari).
Double-clicking an item always clears the selection, removed extra newline
from man-page and fixed a misplaced #endif (Bernard Jungen).

30-Jan-2002
-----------
Updated Dutch translation (Wilbert Berendsen).
Updated to Gtk+-1.3.13 (action window scrolling now works).

28-Jan-2002
-----------
OK and Cancel buttons in savebox can no longer be focussed. Fixes problem
where opening a savebox put the focus on the last used button instead of
the entry (reported by Karol Krenski).
Added instructions for Window Maker pinboard icons to the manual
(Jim Knoble).
Resizer now allows space for the 'Running as ...' message (reported by
Wilbert Berendsen).

25-Jan-2002
-----------
If conversion to 'ISO8859-1' doesn't work, try 'iso-8859-1' and 'UTF-8' instead
of giving a warning (reported by Gregory Spath).

24-Jan-2002 (Release 1.1.12)
-----------
Updated Hungarian translation (Andras Mohari).

23-Jan-2002
-----------
Only check for thumbnails in the thumbnail scanning code, not when loading
any image (saves time).
Assume pathnames and labels for pinboards and panels are in the local charset
for Gtk+-1.2, and in UTF-8 for Gtk+-2.0.
When using 'Shell Command...' from the menu with an item selected by opening
the menu, the item now remains selected when you enter the command.

Updated French translation (Vincent Lefèvre).
Updated Dutch translation (Wilbert Berendsen).

22-Jan-2002
-----------
_ROX_PANEL_MENU_POS property is now set on each GtkSocket window, rather than
the panel, so that applets can find it more easiliy (requested by Stephen
Watson).
Only use Gtk+-2.0 if '--compile --with-gtk2' is used.
Loading a thumbnail now stores the details when loading started, not
when it finished.
Bugfix: Under Gtk+-2.0, the savebox focussed the OK button rather than the
	text entry.

21-Jan-2002
-----------
Changing the permission on a file failed to update the display (reported by
Karol Krenski). Also made other updates more efficient.
Allow COMPOUND_TEXT selection type (same as STRING for now), as gnome-terminal
has stopped accepting STRING.

20-Jan-2002
-----------
Added a configure check for iconv.h.
Use double instead of long for file sizes in find.c (Bernard Jungen).

19-Jan-2002
-----------
Thumbnails code failed to update images when they changed (reported by
Andreas).

18-Jan-2002
-----------
Use 'ISO8859-1' instead of 'iso-8859-1' and fallback to strdup if charset
conversion fails (Stephen Watson).

Deleting a symlink to a pinboard or panel icon showed a warning, even though
there was no danger, because it followed the symlink. Trying to copy a symlink
inside the directory it pointed to failed for the same reason.

17-Jan-2002
-----------
Big changes to internationalisation for pinboards and panels to fix problems
with incompatible character sets (reported by Arnaud Calvo).
When creating thumbnails, create to a temporary file and rename in case another
program tries to write the save thumbnail at the same time.
As a special case, running with just '-v' doesn't call gtk_init, allowing
installing without an X server (requested by Michael Duelli).

16-Jan-2002
-----------
Converter for old-format config files now stops if the file looks like
XML (probably from a failed conversion).
Allow '~' in globicons file.
Bugfix: When using spring-opening or following symlinks, trying to open
	a non-existant directory could cause a crash.
Bugfix: The pinboard would highlight to accept any type of drop (not just
	files).

13-Jan-2002
-----------
Fixed some compile problems on Solaris (Andreas Dehmel).
Clicking an unscanned item now scans it (instead of reporting an error).
Dialog boxes in Gtk+-2.0 now set a default button.
Number keys on the keypad couldn't be used for groups (reported by Arnaud
Calvo).

11-Jan-2002
-----------
Updated Spanish translation (Marcelo Ramos).
Updated the French manual translation (Arnaud Calvo and Vincent Lefèvre).

09-Jan-2002
-----------
Converted French manual to DocBook (Arnaud Calvo).
Fixed some compiler warnings (Vincent Lefèvre).

09-Jan-2002 (Release-1.1.11)
-----------
Mark action windows as dialogs (requested by Daniel Pittman).
Reset the background colour when drawing, as the Xenophilia keeps changing
it (reported by Wilbert Berendsen).

08-Jan-2002
-----------
Changed == to = in make-mo script (Vincent Lefèvre).
Added -lm to libpng linker flags (reported by Stephen Watson).
Updated the French translation (Vincent Lefèvre).

07-Jan-2002
-----------
Bugfix: Closing a filer window with a tooltip removes the tip now (before, the
	tooltip could get stuck on the screen).

06-Jan-2002
-----------
Bugfix: Options box didn't work unless options had already been saved
	(reported by Iain Stevenson).

05-Jan-2002
-----------
Stopped unnecessary redrawing of the display (when sorting an already-sorted
list).
Thumbnails can now also be saved using Gtk+-1.2, if libpng is available
(Andras Mohari).

04-Jan-2002
-----------
Fixed compile problem (reported by Vincent Lefèvre).
Updated French translation (Vincent Lefèvre).

03-Jan-2002
-----------
Added _ROX_PANEL_MENU_POS property on panel windows to help applets position
their menus correctly.
Bugfix: 'From LANG' translation setting had stopped working (reported by
	Vincent Lefèvre).

02-Jan-2002
-----------
Saved pinboards and panels are now stored in an XML format. Old files should
be converted automatically. Icon names may now contain the < and > characters
(requested by Bernard Jungen).

01-Jan-2002
-----------
Updated French translation (Vincent Lefèvre).
Updated Polish translation (Krzysztof Krzy¿aniak).

30-Dec-2001
-----------
Updated Spanish translation (Marcelo Ramos).

29-Dec-2001
-----------
When changing directory, make more effort to wink or select the appropriate
item.

29-Dec-2001 (Release 1.1.10)
-----------
Updated French translation (Vincent Lefèvre).
Bugfix: Using Shift to open the Send To menu without a selected file stopped
	the toggle menu items from working!

28-Dec-2001
-----------
With Gtk+-2.0, the effective permissions are now underlined (like they are
with Gtk+-1.2).
Put all the flags in the options box on one line, along with the Quiet button
(looks neater).
Updated manual.

27-Dec-2001
-----------
Reorganised the Options box somewhat.
Bugfix: Closing a window while creating thumbnails caused a crash.

26-Dec-2001
-----------
Icons are dragged from their corners again (requested by Liav Asseraf).
Unknown SOAP methods now get a SOAP Fault response. Updated SOAP namespaces.
Renamed '.DirIcon.png' to just '.DirIcon'.
In action windows, standard error from moving, copying and mounting operations
is captured and displayed, giving a more useful message (Stephen Watson).
Support for Gtk+-1.3.12.

25-Dec-2001
-----------
Updated Polish translation (Krzysztof Krzy¿aniak).

24-Dec-2001
-----------
File groups are now saved (automatically).
The old 'AppMenu' file is no longer checked for (use AppInfo.xml instead).

23-Dec-2001
-----------
Added Version SOAP RPC.
With Gtk+-2.0 UTF-8 converstion, the filer now converts from the charset
specified in the translation (was always using iso-8859-1).

22-Dec-2001
-----------
If thumbnailing is cancelled, it can be resumed later. Hiding thumbnails
stops any scan in progress automatically. Added 'All' and 'Thumbs' status
flags to title bar.

21-Dec-2001
-----------
New 'Show image thumnails' option to set this as the default (requested by
Kristian Rink).
Got details working again with Gtk+-1.2 (spotted by Kristian Rink).

20-Dec-2001
-----------
New thumbnail system. 'Create Thumbs' is now 'Show Thumbnails' and can
be turned on and off. Thumbnails are loaded in the background, and a progress
bar is displayed in the filer window.
Replaced old Gtk+-1.2.x text widget in action windows with new one.

19-Dec-2001
-----------
Improved error reporting.
Improved sizing code when details are on.

18-Dec-2001
-----------
Updated to new version 0.4 of the thumbnails standard.
Added 'Quiet' check box to action windows. Quiet button now turns on
check box and does 'Yes'.

17-Dec-2001
-----------
Gtk+-2.0 uses UTF-8 for strings. Translation files are now converted to
UTF-8 as they are loaded.
Added a missing #ifdef for the regex code (Damien Couderc).
All file leafnames now use AA fonts with Gtk+-2.0 (details are still
fixed, though).

16-Dec-2001
-----------
Closing a window with a keypress caused warnings to appear (reported by
Fabien Coutant).
Updated Spanish translation (Marcelo Ramos).
New 'Single click nagivation on the pinboard' option (requested by
Michael).
Fix for compiling problem on NetBSD (Eric Gillespie, Jr.).

Internal changes to options system:
- Options can be used as soon as they are registered (not just once the
  filer is fully initialised).
- New widget types can be registered in a modular fashion.

13-Dec-2001 (Release 1.1.9)
-----------
More fixes for panel resizing (reported by Stephen Watson).
Target mode, dragging an unselected item, and auto-selecting an item when
opening the menu now all work without grabbing the primary selection.
Finished new scanning code (image == NULL is now OK everywhere).

12-Dec-2001
-----------
Clicking on an item which is selected, but not part of the primary selection,
now reclaims the selection.
Removed default minibuffer option for now.
The dash forms in Find tests can be combined, eg '-rwx'.
Updated manual.

11-Dec-2001
-----------
Additional window hints - pinboard and panels refuse focus and pinboard
icons are marked as desktop features (requested by Laurent Moussault).
Thumbnails are now stored using an md5 hash of their names.
Pinboard icons can be repositioned by dragging with the left mouse button
(middle button drag stopped working with sawfish, and this is easier anyway).

10-Dec-2001
-----------
New scanning system: blank items are added to the window first and then the
icons and types get filled in later. Looks better and simplifies the sizing
code a bit.
Code tidying in various places.

09-Dec-2001
-----------
Bugfix: Filer would quit if only Info boxes were open.
Bugfix: Pinboard and panel windows didn't get the correct hints set under
	Gtk+-2.0.

08-Dec-2001
-----------
Many internal changes to Collection widget for Gtk+-2.0. Should be more
efficient now, and easier to get aa fonts working...

07-Dec-2001
-----------
Fixed Gtk+-2.0 wheel mouse support.
In the Info box, 'File says...' was reporting on the program used to
edit the file, not the file itself!
For glib-2.0, use the new spawn function and report errors nicely.

06-Dec-2001
-----------
Updated Russian translation (Dmitry Elfimov).
Thumbnail information in the PNG image is now namespaced to 'Thumb'
(recommended by Jens Finke).
FileType SOAP RPC return format has been updated to the latest version
of the SOAP working draft.
Added Large File Support: files over 4Gb now have their sizes detected
correctly (Stephen Watson). Note: this disables libvfs support.
New option to have the minibuffer open by default on new windows
(Bochicchio).

05-Dec-2001
-----------
When resizing the collection, only ensure the cursor is still visible if
it was in the displayed area before.

When closing the Enter Path minibuffer, keep Show Hidden on if the cursor is
on a hidden item.

When using --show with a hidden file, turn on Show Hidden. Also, delay the
winking effect until the window actually appears.

04-Dec-2001
-----------
Support for new thumbnails spec; thumbnails are saved inside ~/.thumbnails
so they redisplay quickly next time the filer is loaded (requested by
Kristian A. Rink and others).

Bugfix: Toggling the section with a middle button drag could lose the primary
	selection (Andras Mohari).

03-Dec-2001
-----------
Use gtk_set_locale instead of setlocale (Andras Mohari).

02-Dec-2001
-----------
Added 'Invert Selection' (Stephen Watson; suggested by Andras Mohari).

01-Dec-2001
-----------
Added a new root window property (_ROX_FILER_EUID_HOST) which points to
the SOAP IPC window for a particular hostname and user ID. This makes it
easier for other programs to talk to the filer.

30-Nov-2001
-----------
Added new SOAP methods Copy, Move, Link, Mount and FileType (Stephen Watson).

29-Nov-2001
-----------
Moved 'Select All', 'Clear Selection' and 'Select If...' to a new 'Select'
submenu.
The filer now closes stdin when it starts. This is to prevent child
processes, such as auto-mounters, from trying to read a password from
the console (Olivier Fourdan).

27-Nov-2001
-----------
Manpage is now generated automatically from DocBook source.
Short forms for many find expressions, such as -d for IsDir (suggested by
(Andras Mohari).

26-Nov-2001
-----------
More Gtk+-1.3.11 support, including use of the new message dialog.
When the filer loses the primary selection, display the selected items
shaded, but don't unselect them (Andras Mohari).

24-Nov-2001
-----------
Updated to Gtk+-1.3.11.

23-Nov-2001
-----------
Show the current run action for a file in the Info box (Stephen Watson).

21-Nov-2001
-----------
If a panel applet quits then it is removed from the panel, instead of being
replaced by a Restart button.

16-Nov-2001
-----------
With Gtk+-2.0 and the 'Unique windows' option on, reshow the existing window
instead of destroying it and creating a new one (suggested by Greg Spath).

15-Nov-2001
-----------
Changes to the French translation (Thierry Godefroy and Vincent Lefevre).

14-Nov-2001
-----------
Code tidying in menu.c (Bernard Jungen).

13-Nov-2001
-----------
Opening a filer window from the Set Icon dialog turns thumbnails display
on (suggested by Francesco Bochicchio).
Right-clicking the Help toolbar button reuses the same window.

12-Nov-2001
-----------
Made some strings easier to translate, fixed a problem with translating a blank
string, and changed the details toolbar button to leave the size alone (Andras
Mohari).
Improved key handling (key presses were sometimes ignored).
Bugfix: A very long and narrow icon could make the filer try to scale to a
	width or height of zero (Andras Mohari).

09-Nov-2001
-----------
Allow current directory and selection to be stored with Ctrl+[0-9] and
retrieved by pressing [0-9] (suggested by Jakub Turski). The groups are not
saved yet.

08-Nov-2001
-----------
Don't use re_set_syntax() on systems that don't have it (reported by
Damien Couderc).
In action windows, the a long filename no longer makes the window get wider
(requested by Graham Borland).
Added 'Types' section to the Options window, allowing easy(ish) access
to the MIME-info files, plus a reload button, and icons for MIME-types can
be set from the 'Set Icon...' box (Stephen Watson).

07-Nov-2001
-----------
Added a menu to the 'Set Icon...' box which shows all directories currently
used for icons (Francesco Bochicchio).
Fix small error in German translation (Christopher Arndt).
Bugfix: 'New Directory' didn't correctly select the leafname with Gtk+-2.0.

06-Nov-2001
-----------
Added Spanish translation (Marcelo Ramos).
Applied Bernard Jungen's latest patch:
- Disk usage forgot to count special files like pipes, etc.
- Page up/down scrolls a window full at a time instead of 10 items.
- Don't get icons from the cache if thumbnail mode is off anymore.
- modechange.c: deleted useless stuff and fixed octal parsing to detect
  *all* illegal values (eg 010000000000000).
- Added 'Show/hide hidden files' toolbar button.
- Lots of code tidying.


05-Nov-2001
-----------
Holding the pointer over a symlink shows the target in a tooltip
(Stephen Watson; suggested by Arnaud Calvo).

01-Nov-2001
-----------
Updated French translation (Vincent Lefèvre).

30-Oct-2001 (Release 1.1.8)
-----------
Updated to support Gtk+-1.3.10.

17-Oct-2001
-----------
Slightly better positioning of filenames and details (Bernard Jungen).
When resizing, only add space for an extra row in Small Icons mode.

16-Oct-2001
-----------
Make the Set Run Action box command box have the "$1" already filled in
(suggested by Helgi Hrafn Gunnarsson).

15-Oct-2001
-----------
Set the WM_CLASS for saveboxes, so that window managers can treat them
specially, if required (Andrew Flegg).

14-Oct-2001
-----------
Changed internal format used to send to requests to SOAP, and added --RPC
option to access it directly.

12-Oct-2001
-----------
Open new windows at the mouse position (suggested by Helgi Hrafn Gunnarsson).
Bugfix: If file doesn't accept the '-b' option then examining a file in
	the root directory didn't work (Stephen Watson).

10-Oct-2001
-----------
Use --version instead of 'which' to test for programs as not everyone has
which (suggested by Vincent Lefevre).
Bugfix: When setting an icon for a file with a space in the name, the
	setting wasn't saved correctly (spotted by Arnaud Calvo and Jakub
	Turski). The 'globicons' file should be converted automatically
	when the filer is run.

08-Oct-2001
-----------
Added support for the regex field in MIME-info. This allows files to be
matched with patterns, not just on their extensions. For example, '.gtkrc'
is now typed 'x-gtkrc' despite having no extension (Stephen Watson and
Andras Mohari).

05-Oct-2001
-----------
Allow AppIcon.xpm and .DirIcon.png to be symlinks (Bernard Jungen).

04-Oct-2001
-----------
When running on a remote machine, display the remote host's name in the
title bar (Stephen Watson).

02-Oct-2001
-----------
New option to control whether a middle button drag moves the files or
brings up a menu.
Allow submenus in AppInfo.xml file (Stephen Watson).

26-Sep-2001
-----------
Now supports Gtk+-1.3.9, but not earlier developer releases.

25-Sep-2001
-----------
Disk Usage can cope with larger sizes, and reports the number of files and
directories counted; new Show Hidden and Inherit Options options; new -D
option to close directories; and changes to formatting of file sizes
(Bernard Jungen).

24-Sep-2001
-----------
Updated Hungarian translation (Andras Mohari).
Improved the filename colouring code so that colours are only allocated
if needed (Andras Mohari) and fixed a colourmap problem (Stephen Watson).
Bugfix: When sorting while winking an item, the filer would sometimes scroll
	to the wrong place (Andras Mohari).
Bugfix: If all the selected files were deleted, then trying to paste the
	selection caused a crash (Fabien Coutant).

20-Sep-2001
-----------
Colour files by type (Andras Mohari).

11-Sep-2001
-----------
Added -p to mkdir in install scripts to create any missing parent
directories (Michel Alexandre Salim).

09-Sep-2001
-----------
Dragging files with the middle button (or Button1+Alt) brings up a menu
of possible actions (Taras).
New option to control size of icons in `New' and `Send To' menus (Stephen
Watson).
Bugfix: Pinboard icons didn't draw correctly if their windows got resized
	(reported by Michel Alexandre Salim).

06-Sep-2001
-----------
Window positions can be saved and restored by a session manager (Anders
Lundmark).

05-Sep-2001
-----------
Fixed an untranslated string (Andras Mohari).

04-Sep-2001
-----------
The style for pinboard and panel icon text can be set (requested by Greg
Spath) with:

	widget "*.pinboard-icon" style "..."
	widget "*.panel-icon.*" style "..."

03-Sep-2001
-----------
Bugfix: Entering a blank expression in the 'Select If' minibuffer displayed
	a (harmless) warning message (reported by Vincent Lefèvre).

03-Sep-2001 (Release 1.1.7)
-----------
Added an option to control whether extensions take precedence over the
executable bit of a file (requested by MJ Ray).
Updated French translation (Vincent Lefèvre and Arnaud Calvo).
Disabled the UTF-8 conversion (doesn't work on older versions of Gtk).

02-Sep-2001
-----------
The options controlling when windows resize work again.

31-Aug-2001
-----------
Better guessing of window size for display styles with details.

29-Aug-2001
-----------
The 'src/po/dist' script now converts all text to UTF-8.

28-Aug-2001
-----------
Fixed some problems with the configure.in script and autoconf 2.50 (Richard
Boulton).

27-Aug-2001
-----------
Updated Dutch translation (Jasper Huijsmans).
Send To menu lists contents of all Send To directories in Choices, not just
the first one found.
Fixed another XML compiling problem (Stephen Watson).

23-Aug-2001
-----------
Added Customise to `Send To' menu.

22-Aug-2001
-----------
Detached Send To menu from main menu structure. Allows key-binding to open
the menu, at least. Main menu now opens quicker (no scanning of Send To dir).
Shift+Menu brings up the menu directly.

20-Aug-2001
-----------
Fixed compiling problem with some versions of libxml (Stephen Watson).
Changed a text message in the Options box (about binding keys to menus) into
a button which shows the message in an alert box. Maybe people will read the
message now?

19-Aug-2001
-----------
Only use Gtk+ 2.0 if version 1.3.6 or later is installed.
Scrolling using a wheel mouse now always goes at the same speed, whatever the
display style (requested by aardvark joe).

10-Aug-2001
-----------
Added 'Send To' menu (Stephen Watson).

Bugfix: Renaming a panel icon didn't update the display (reported by Andrew
	Booker).

07-Aug-2001
-----------
Fixed some minor compilation issues (reported by Jasper Huijsmans and Daniel
Richard G.)

03-Aug-2001
-----------
Added French translation of the manual (Arnaud Calvo).

24-Jul-2001
-----------
Filer wouldn't compile or run if it was in a directory with spaces in the
name (reported by Benjamin Munoz).

23-Jul-2001
-----------
Added options for default action window settings for Brief, Force and Recurse
(Liav Asseraf).
New default for sort type is Sort By Name (requested by Andreas Dehmel).
Bugfix: Clicking on a file with no run action set gave two error boxes.

19-Jul-2001
-----------
Make Enter in the minibuffer work like Return (requested by Arnaud Calvo).

18-Jul-2001
-----------
Added some more hints to pinboard and panel windows to comply with the new
freedesktop.org window manger spec.

15-Jul-2001
-----------
New option to set the maximum size the auto-resizer will resize a window to
(requested by Andreas Dehmel).

14-Jul-2001
-----------
When using the Set Run Action box, make the command default to the currently
set command (suggested by Arnaud Calvo).

12-Jul-2001 (Release 1.1.6)
-----------
Updated the French translation (Vincent Lefèvre).

10-Jul-2001
-----------
Renamed 'New File' submenu to 'New' and moved 'New Directory' into it.

09-Jul-2001
-----------
Use the user's preferred font for item filenames, not the Gtk default
(requested by Jim Knoble).

03-Jul-2001
-----------
Redid text handling on the panel. Now uses nice fonts under Gtk+ 2.0.

02-Jul-2001
-----------
Don't show tooltips for applets as it causes problems (reported by Stephen
Watson).

30-Jun-2001
-----------
Gtk+-2.0: Support for anti-aliased fonts on the pinboard (also word-wraps
	  long names too). Fixed a crash-on-click problem on the root window.

29-Jun-2001
-----------
More work on Gtk+-2.0 -- seems to be usable now :-)

28-Jun-2001
-----------
Started work to support Gtk+-2.0.

26-Jun-2001
-----------
Moved 'relative link' option above the buttons in the Link box (Stephen
Watson).
Bugfix: Rescanning could sometimes make the cursor reappear, causing the
	display to scroll (reported by Andreas Dehmel).

21-Jun-2001
-----------
Replaced 'New File...' menu item with a submenu generated from the contents
of '<Choices>/Templates' (Stephen Watson).

20-Jun-2001
-----------
`Xterm here' command can contain arguments (Andras Mohari).
Made the menu appear in a sensible place, so it's easy to get to the File
submenu (suggested by André Wyrwa).

19-Jun-2001
-----------
Updated French translation (Vincent Lefèvre).
Added a German translation (André Wyrwa).

13-Jun-2001
-----------
Added an extra option to control the resizing behaviour. Can be set to resize
never, always, or only when the display style changes (requested by Andreas).

07-Jun-2001 (Release 1.1.5)
-----------
Updated Russian translation (Dmitry Elfimov).

06-Jun-2001
-----------
Unless compiling with mc's libvfs for virtual filesystem support, change the
menu structure for use with the newer AVFS system.
(http://www.inf.bme.hu/~mszeredi/avfs/) (José Romildo Malaquias).

Bug fix: Running the filer with a translation set would make it crash
	 (reported by Dmitry Elfimov).

04-Jun-2001 (Release 1.1.4)
-----------
Added 'Details' toolbar icon. Toggles display between Small Icons with Summary
and the default size with no details.

30-May-2001
-----------
Replaced Large/Small toolbar buttons with a single Size button which
cycles through Small/Large/Huge (other button to reverse).

28-May-2001
-----------
Added Shift Open, Set Run Action and Set Icon to the pinboard and panel
menus.

25-May-2001
-----------
Long leafnames wrap onto multiple lines in Huge mode, like they do for
Large Icons mode.

24-May-2001
-----------
Display tooltips for pinboard and panel icons, where needed.

23-May-2001
-----------
New option to show number of files / size of selected files in the toolbar
(Andras Mohari).

22-May-2001
-----------
New options section 'panel' allows icon text to be hidden for all icons, no
icons, or just applications (suggested by José Romildo Malaquias).

17-May-2001
-----------
Converted the options window to a tabbed notebook (Denis Manente).

16-May-2001
-----------
Pressing the mouse button down on an icon no longer winks it; only releasing
the button to run it does.
Added 'Show Info' to panel/pinboard menu.
The File Info box grabs the primary selection when a row is selected
(allows you to paste email addresses, URLs, etc).

15-May-2001
-----------
Opening a pinboard or panel menu over an icon no longer selects it -- this
allows the selection to be passed to an application run using its AppMenu
(requested by Christopher Arndt).

14-May-2001
-----------
In Large Icons display style, a file's name may wrap onto a second line.

13-May-2001
-----------
Merged code for handling selections and menus that was common to pinboards
and panels into icon.c.

09-May-2001
-----------
When using 'From LANG', extract the language code from the string to get
the filename, instead of using the whole string (Andras Mohari).
Added support for very old versions of libxml (reported by Lukasz Stelmach
and Vincent Lefèvre).

08-May-2001
-----------
Updated French (Vincent Lefevre) and Hungarian (Andras Mohari) translations.

07-May-2001 (Release 1.1.3)
-----------
Updated the documentation.

06-May-2001
-----------
Added 'Huge, With...' display styles. In huge mode, normal icons are scaled
up if they're too small.

03-May-2001
-----------
Gtk styles can be overridden in <Choices>/ROX-Filer/Styles (suggested by
Stephen Watson).
Pinboards and panels should now work with IceWM without needing -o
(Christopher Arndt).
Allow text messages in the toolbar to go off the side (instead of resizing the
window).

02-May-2001
-----------
Opening the shell minibuffer with a selection adds ' "$@' after the cursor.
Without a selection, the name of the file under the cursor is added.

29-Apr-2001
-----------
Pressing the `\' key opens the menu (suggested by Christopher Arndt). Hold
down Ctrl for the File submenu.

28-Apr-2001
-----------
Added a new 'About' section to AppInfo. Any elements in here are added
into the info box. Added a 'Refresh' button to the info box.
Added a ROX-Filer/Styles file for default colours (default filer background
is now lighter).

27-Apr-2001
-----------
Rewrote the file info box. Looks a bit nicer, and it's easier to add extra
info to it later...

26-Apr-2001
-----------
Updated Russian translation (Dmitry Elfimov).

25-Apr-2001
-----------
AppInfo file may contain a <Summary> element - the text inside will be
displayed in a tooltip if the mouse is held over the item in a filer
window.

22-Apr-2001
-----------
Filer now looks for AppInfo.xml before AppMenu. This is for future
expansion...

18-Apr-2001
-----------
Automatic resizing of windows when changing directory is now optional
(requested by Paul E. Johnson and Andreas Thorn).

11-Apr-2001
-----------
The symlink box allows you to choose to create relative or absolute links
(suggested by Stephen Watson).

09-Apr-2001
-----------
Fix some typos and untranslated strings (Andras Mohari).

08-Apr-2001
-----------
Added a Russian translation (Dmitry Elfimov).

06-Apr-2001
-----------
Fixed a couple of errors in the man-page (spotted by Damien Couderc).

05-Apr-2001
-----------
Winking an item in a directory makes it flash twice instead of once (easier
to see). Also, creating a new file or directory from the menu winks the new
item.

Bugfix: When a directory was rescanned because of a move operation,
	the `Set Icon...' settings didn't work (reported by Damien
	Couderc).

02-Apr-2001
-----------
New display style 'Huge Icons' to make viewing thumbnails easier.
Added a Hungarian translation (Andras Mohari).
Updated the French translation (Vincent Lefèvre).
Double clicking on a filer window's background resizes the window (Denis
Manente).

01-Apr-2001
-----------
If an item's name is truncated, show it in a tooltip when the pointer is
held over the item (Denis Manente).

30-Mar-2001 (Release 1.1.2)
-----------
Asking for help on a directory always tries to open <dir>/Help first, even
for non-applications.

29-Mar-2001
-----------
If run without -n, the filer will put itself in the background. Thus,
the 'rox' command behaves the same whether or not the filer is already
running.

27-Mar-2001
-----------
Support for the new version of libxml (reported by Andreas Dehmel).

26-Mar-2001
-----------
Rewrote parser for options. Smaller and neater (hopefully this will fix
the bugs reported by Andreas Dehmel and Ewan Mac Mahon).

Bugfix: While scanning, the resizer could make the window too large.

23-Mar-2001
-----------
Moving the cursor down in the next-to-last row will move to the last
item if there is nothing under the cursor (suggested by Graham Borland).

21-Mar-2001
-----------
When changing directory, only make the window larger (if needed), never
smaller (suggested by Diego Zamboni).

17-Mar-2001
-----------
Changing directory autosizes the window automatically (Denis Manente).
Internal changes to the way different layouts are handled.

15-Mar-2001
-----------
Pressing space (to select/unselect an item) now also moves the cursor to
the next item (suggested by Anders Lundmark).

Copying directories tries to preserve the timestamps, like it does for
files (suggested by José Romildo Malaquias).

14-Mar-2001
-----------
Added '--mime-type FILE' option, which simply writes the type of FILE to
standard output (Stephen Watson).

Added 'Home Directory' to Window menu (requested by Graham Borland).

11-Mar-2001
-----------
Copying a directory which doesn't have user write permission will give it
user write during the copy to avoid permission denied errors (suggested by
Liav Asseraf).

New sort option - 'Directories always come first' (requested by Liav Asseraf).

10-Mar-2001
-----------
Dragging a lasso box with the middle button toggles the selected state
of the items enclosed (Denis Manente).

09-Mar-2001
-----------
Changing the display style now resizes the window (Denis Manente).

08-Mar-2001
-----------
New pinboards get a 'Home' icon in the top left corner as new users often
think the pinboard isn't working because it starts empty (suggested by
Vor'Cha).

Converted AppMenu file format to XML.
Added AppMenu file with options to control the pinboard.

06-Mar-2001
-----------
Highlight invalid Find expressions in red (Anders Lundmark).

04-Mar-2001
-----------
When resizing windows, try to keep the window fully inside the screen area
(Denis Manente).

03-Mar-2001
-----------
Updated the Dutch translation (Jan Wagemakers).

27-Feb-2001
-----------
When mounting a device, the new window appears after mounting, not before.
This means that it's more likely to get sized correctly (requested by
Ewan Mac Mahon).

24-Feb-2001
-----------
Added two new options to control when minibuffer completion beeps (requested
by Liav Asseraf).

20-Feb-2001
-----------
Added 'New File...' feature (James Kermode).

16-Feb-2001
-----------
Dropping icons on the pinboard positions them sensibly (Diego Zamboni).

09-Feb-2001 (Release 1.1.1)
-----------
Moving pinboard icons is nicer - it no longer assumes you dragged the middle
of the text... (Diego Zamboni).

Added a Polish translation (Andrzej Borsuk).

Bugfix: Sometimes it wasn't possible to delete something that was on a
	pinboard or panel, even after confirming (reported by Diego Zamboni).

07-Feb-2001
-----------
Sliders in the options box can have a numerical value display (Diego Zamboni).
Fixed a stray warning message displayed when non-default pinboard options
were used (Diego Zamboni).

New menu item 'Set Icon...' allows you to choose any icon for any file or
directory. Also allow .DirIcon.png to set a directory's icon (Diego Zamboni).

03-Feb-2001
-----------
Many internal changes to the Options system.

30-Jan-2001
-----------
Bugfix: On filesystems which aren't case sensitive (eg DOS) it was possible
	to copy 'tmp' as 'Tmp' and lose it! (reported by Denis Manente)

28-Jan-2001
-----------
Added Diego Zamboni's patch to make configuring VFS easier.

27-Jan-2001
-----------
Improved compiling - now correctly reports an error if the file doesn't
compile. If configure is missing then autoconf is run automatically.

After a Find completes, you are given the option of doing the search again
(Anders Lundmark).

Applications can define a list of menu items to display on their menus
(Diego Zamboni). The file should be called 'AppMenu' and contains a list of
lines in the form 'option Text'.

24-Jan-2001
-----------
Added two new pinboard options - one to allow setting the grid step size
and one to allow icons to go slightly off the side of the screen (Diego
Zamboni).

23-Jan-2001
-----------
Bugfix: Textured window backgrounds could cause a crash (reported by Diego
	Zamboni).

22-Jan-2001
-----------
Updated the French translation (Vincent Lefèvre).

Bugfix: The pixbuf stuff didn't work on some displays (reported by Stephen
	Watson).

20-Jan-2001 (Release 1.1.0)
-----------
Removed the 'Initial window height' option. The filer tries to pick a
sensible shape itself now.

Bugfix: If an image was moved to a directory which didn't generate thumbs
	then it would display, but never be updated. Even if it wasn't that
	file at all, just a reused inode!
Bugfix: Changing the display style didn't always redraw the display.
Bugfix: In 'Small, With...' display mode, clicking beyond the far right
	column acted like clicking on the far-right column.

18-Jan-2001
-----------
Changed background colour to be more compatible with the Gtk themes system.

12-Jan-2001
-----------
Removed all the message window stuff. ROX-Filer no longer grabs standard
error from its child processes. Changed because ROX-Session now does a much
better job.

10-Jan-2001
-----------
Filer is more generous in what hostnames it considers local.
Patch to include pixbuf headers correctly (Diego Zamboni).

08-Jan-2001
-----------
Bug fix: Didn't always use the fully qualified host name for DnD.

30-Dec-2000
-----------
If a file has a known extension then it is given the appropriate type even
if the file is executable (Simon Britnell).

28-Dec-2000
-----------
Added a menu entry 'Resize Window' to set the window to a sensible size
when you want it.

25-Dec-2000
-----------
Try to open new windows at a sensible size for their contents (Denis Manente).

24-Dec-2000
-----------
Bugfix: When mounting or unmounting subdirectories of '/', the mount symbol
	wasn't updated (reported by Wilbert Berendsen).

20-Dec-2000
-----------
Fixed a couple of memory leaks in the choices system (Diego Zamboni).
Updated French translation (Vincent Lefèvre).
Added new 'Create Thumbs' entry on the Display menu which tries to load
every file in the directory as an image and use that image for the file
(suggested by Sprague and Simon Britnell).

19-Dec-2000
-----------
Converted to use gdk-pixbuf instead of ImLib.
Fixed a few compiler warnings and improved the error message displayed
if you try to invoke rox on a missing file (reported by Vincent Lefèvre).
Changed the -w, -W and -i flags to the simpler -x=FILE, which reexamines the
given file, updating directory views and icons as needed.

18-Dec-2000
-----------
AppIcon.xpm must be a regular file (stops people trying to crash the
filer by symlinking to /dev/...).
Fixed a missing translation in the pinboard options (Denis Manente).

17-Dec-2000
-----------
Attempting to run the filer before compiling will now ask if you want
to compile.
Removed lots of platform-specific mount point code and replaced it with
python's portable system.
New options section allows you to choose a translation without having to
set the LANG variable.

16-Dec-2000
-----------
Added '-w', '-i' and '-W' command line options for forcing icons or
directories to be rescanned (Diego Zamboni).

13-Dec-2000 (Release 1.0.0)
-----------
Made a few updates to the manual.

08-Dec-2000
-----------
Fixes to make compiling easier on Solaris (Diego Zamboni). Also, after showing
a pinboard icon, tries to send it to the back (might help with some WMs).

04-Dec-2000 (Release 0.1.30)
-----------
When a panel is used for the first time, put the user's home directory and
the directory containing ROX-Filer on it instead of leaving it blank.

24-Nov-2000
-----------
Patch to make compiling easier under FreeBSD (Jimmy Olgeni).
Added a #include for OSF1 (Vincent Lefevre).

23-Nov-2000
-----------
Bugfix: On many systems, the filer would fail to remove zombie processes
	due to a typo (spotted by Philip Hazel and tracked down by Stephen
	Watson).

22-Nov-2000
-----------
Bugfix: Removing an item from the panel now resizes the panel (reported
	by Wilbert Berendsen).
Bugfix: Editing an icon's path failed to update its hash entry.

20-Nov-2000
-----------
If a case-sensitve match for an extension can't be found then try a
case-insensitive match - so .BMP and similar work (Denis Manente).

17-Nov-2000
-----------
A few changes to remove some compiler warnings (reported by Vincent Lefevre).
Added a VFS menu entry for .deb files (Vincent Ledda).

11-Nov-2000
-----------
Mounting or unmounting a directory forces mtab to be reread, even if the
timestamp hasn't changed (problem reported by Wilbert Berendsen).

When the 'Unique windows' option is on, remove the old window AFTER creating
the new one, so that the filer doesn't quit because there are zero windows
open... (Denis Manente).

07-Nov-2000
-----------
Updated the Dutch translation (Jan Wagemakers).

29-Oct-2000
-----------
Updated the French translation (Vincent Lefèvre).

Using --version and --help options no longer requires an X server connection,
the man-pages are more standard, and 'man ROX-Filer' is allowed as well as
'man rox' (Bernard Jungen).

Bugfix: A corrupted AppIcon.xpm could crash the filer.

24-Oct-2000 (Release 0.1.29)
-----------
Code tidying: Replaced an XLib call with a gdk one (Denis Manente) and amended
	the makedist script to remove the .cvsignore files (spotted by Andy
	Piper).

20-Oct-2000
-----------
Improved the install script so that it installs the man-page. Also made it
easier to use. Updated the French translation and fixed a couple of
typos (Vincent Lefèvre).

17-Oct-2000
-----------
Gtk+ doesn't always scroll entry widgets to show the selection - apply a
workaround (Denis Manente) - this improves the Copy/Rename/etc boxes.

08-Oct-2000
-----------
Added a Dutch translation (Jan Wagemakers).

05-Oct-2000
-----------
Added an Italian translation (Denis Manente).

04-Oct-2000
-----------
Bugfix: If AppRun was a symlink, then the owner of the file was checked, not
	the owner of the symlink. Slight security risk, and also prevented
	users symlinking AppRun to their binaries...

29-Sep-2000
-----------
Bugfix: Deleting a pinboard icon while it was highlighted caused a crash.
	This means it is now possible to click on a pinboard icon to change
	between pinboards...

Bugfix: Textured window backgrounds didn't redraw correctly when scrolled
	or resized. Now flickers when resizing if there's a textured
	background - seems to be necessary :-(

26-Sep-2000
-----------
Running as root now simply turns on the -u flag, rather than displaying
a warning box.

The toolbar height is now correctly taken into account when sizing a new filer
window (Denis Manente).

When guessing file types from extensions, the filer now tries to find the
longest extension that matches (eg .ps.gz, then .gz).

25-Sep-2000
-----------
The lasso box is now drawn so that the box will be in the foreground colour
over the background, rather than by just inverting the pixel value and hoping
it's visible (spotted by Philip Hazel).

24-Sep-2000
-----------
If the home directory is '/' then don't show it as '~' (suggested by
Bernard Jungen).

Added '--show=FILE' option - this will be needed by other ROX
applications, so it needs to be in version 1.0.0.

Bugfix: -d option didn't use realpath before sending to an already-running
filer.

22-Sep-2000
-----------
The 'install.sh' script now uses 'printf' instead of 'echo -e' to suppress
newlines (suggested by Bernard Jungen).

Bugfix: Close tool was always disabled on startup (reported by Martin Ward).

20-Sep-2000
-----------
Added a man-page (Andy Piper).
Changed `install.sh' from bash to sh (Bernard Jungen).

18-Sep-2000 (Release 0.1.28)
-----------
Bugfix: menu entries on the pinboard menu weren't being shaded and
	unshaded correctly.

17-Sep-2000
-----------
Changed 'Rename Item' to 'Edit Icon' and allowed changing the path that
the icon points to as well as its name.

All i?86 platforms are treated as being equivalent (so, if you compile
on a 386 then it'll still run on a 486).

16-Sep-2000
-----------
Pinboard icons can also be renamed.
Pinboard and panel icons can have '~' or '~/' at the start of their
pathnames - this should make it easier to create a system-wide default
panel or pinboard with icons relative to the user's home directory.

14-Sep-2000
-----------
Panel icons can now be renamed (suggested by Ewan Mac Mahon).

13-Sep-2000
-----------
Changing the toolbar options affects existing windows, not just new ones.
Removed the 'Size Bars' display style and replaced it with 'Permissions',
'Type' and 'Times' styles.

12-Sep-2000
-----------
With items that spread over their normal width because they're on the
edge of the window, clicking on the extra bit now works.

Added a size limit of 400K on application icons. This is to prevent
someone trying to crash the filer by linking /tmp/MyApp/AppIcon.xpm
to some huge file!

Dragging an item with the middle button when none are selected unselects
the item after the drag.

Added 'Show Location' feature for pinboard and panels - opens a directory
showing where the file really is.

11-Sep-2000
-----------
Allowed items in the far right column to spread right to the edge of the
window. Fixed a bug which prevented Delete from working if there was
no pinboard.

10-Sep-2000
-----------
Deleting items first checks if it will affect the pinboard or panel. A
warning is displayed if so.

Upgraded the query dialog (from ROX-Session) - looks nicer.

09-Sep-2000
-----------
'Unique filer windows' option now has no effect while the spring open
feature is active (spotted by Andrew Booker). Also, when opening a new
window, the old window is destroyed and a new one created (rather than
reusing the old one). This ensures that the new window appears in the
right place.

When a drag from the pinboard or a filer window ends, the selection is
only cleared if the icon was selected by starting the drag. Thus, it now
works like the panels.

08-Sep-2000
-----------
New Close toolbar button (requested by Martin Ward).
Toolbar icons can be turned on and off from the Options box.
Removed the 'Mount' menu entry, since 'Shift Open' does it too.
Made the Shift Open menu text change depending on what is selected.
Bugfix: dragging icons around no longer saved the new pinboard state!

07-Sep-2000
-----------
Running a second copy of the filer as another user will start a new copy
instead of reusing the existing one. Added the '-u' option to display the
name of the user running the filer in each window (also suppresses the
normal don't-run-as-root warning).

Added '-d', which opens a directory as a directory, even if it looks like
an application.

Updated the manual.

Added Large and Small toolbar buttons. Right-clicking brings up a menu.

06-Sep-2000
-----------
Moved 'Set Run Action' to the file menu (suggested by Ewan Mac Mahon), and
made using it bring up a dialog rather than a minibuffer. Hopefully it is now
easier to use!

Added much improved icons for executables and for applications without icons
of their own (Victor Liu See-le).

Allow '/' on the pinboard and panel (text wasn't displayed - spotted by
Tim Rowledge).

Bugfix: auto-scrolling didn't always stop when a drag ended.
Bugfix: creating a panel with the same name as a file in the current
	directory caused an error due to a throwback from when panels were
	directories (spotted by Ewan Mac Mahon).

30-Aug-2000 (Release 0.1.27)
-----------
Increased the distance you have to move the pointer to start a drag
slightly. Updated the manual.

Panel icons can now be moved from one side to the other by simply moving
over the gap in the middle. Previously, you had to jump over an icon on
the other side.

Left and right panels look better now. Also, they shrink if you add a top
or bottom panel to make room.

28-Aug-2000
-----------
Dragging on the panel background allows you to slide the bar back and
forth.

27-Aug-2000
-----------
Fixed a slight bug with lasso boxes, which could cause them to be drawn in
the wrong place. Install script no longer overwrites the default run
actions; if the user has changed them leave them alone!
(Martin Ward noted that symlinking to an executable would cause the
executable to be destroyed on upgrade!)

24-Aug-2000
-----------
More improvements to the event handling. Seems to be working again at
last!
Made the toolbar buttons slightly larger, and added a textual display
for 'Next Click' mode (eg 'Delete ... ?' when it's waiting for you to
click).
Moved the pinboard over to the new mouse binding code too.

21-Aug-2000
-----------
Started rewriting the event handling for filer windows to go through
the new code in bind.c, like the panel handling does.

20-Aug-2000
-----------
You can now drag icons from the panel to other applications.

18-Aug-2000
-----------
Dragging panel icons with the middle button allows you to move them around.

New option to set the default height for new filer windows (patch from
James Kermode).

17-Aug-2000
-----------
Selecting panel icons now grabs the primary selection. Pasting pastes all
selected file path names. Icons can now be added to either side of the panel.

Bug fix: Moving a file didn't always update the source directory.

16-Aug-2000
-----------
Many improvements to the panel - drag and drop to icons, adding new icons,
selections (doesn't grab the primary selection yet though), removing icons
and automatically saving the panel when it's changed.

11-Aug-2000
-----------
Improved reference counting on images (hopefully!). Lots of work on
rewriting the panel system.

07-Aug-2000
-----------
Made the timeout for the spring-open feature configurable (requested by
Chris Garrett).

Use short form of --version in install.sh and don't use unsetenv() if it
isn't available (Mattias Engdegård).

06-Aug-2000
-----------
New options to set the pinboard text foreground and background colours
(suggested by James Kermode).

05-Aug-2000
-----------
Your home directory is now displayed as '~' in the title bar, rather
than as a full path.

01-Aug-2000 (Release 0.1.26)
----------------------------
Added a popup menu of commonly used chmod strings to the Permissions
box. Bracketed text and spaces are now ignored in the commands.
Bug fix: Only menu keys changed since the last load were saved!

31-Jul-2000
-----------
Bug fix: Mount points on the pinboard didn't always redraw when the
mounted/unmounted state changed.

30-Jul-2000
-----------
Renaming now uses the action windows. This means that you can now
rename something onto another filesystem.

28-Jul-2000
-----------
The menu key bindings are now only saved if they actually changed.

Code tidying: Moved some typedefs to the new `global.h' file and
thus removed the dependencies between header files :-)

26-Jul-2000
-----------
Tab and Shift-Tab move to next and previous selected item.

25-Jul-2000
-----------
The new display styles can now be saved as the defaults (bug spotted by
Vladimir Klebanov).

When autoscrolling is used, prevent the last-highlighted directory
from springing open. 'spring open' now defaults to off.

The toolbar Up and Home buttons can act as drop targets (and spring open
too!).

Options to set the pinboard text background style (suggested by James
Kermode).

23-Jul-2000
-----------
Added an option to control the spring-loading feature. Added tooltips
to some of the options. Improved the rule for deciding whether to open
a new window when you click on the toolbar buttons.

Stopped the spring-open window moving while it's open (prevents a bug
in GTK+ from causing problems). Please use GTK+ 1.2.8 or later now!

Dragging near the edge of a window scrolls. Improved the lasso box drag
to use the same system (so it scrolls without you having to move the
mouse).

22-Jul-2000
-----------
Added 'spring-loaded' directories. If you drag a file over a directory and
hold it there, the directory will spring open! (suggested by Barney
Clarkson)

21-Jul-2000
-----------
In the path entry minibuffer, an exact match is favoured over any other
match. So, if you enter '.xsession' and press Return you'll get it, not
'.xsession-errors' or whatever!

The filer now clears APP_DIR from the environment so that child processes
don't get it. Fixed a bug which caused problems when using a small version
of the 'missing image' image.

19-Jul-2000
-----------
Creating a new directory now makes sure the display is updated.

18-Jul-2000 (Release 0.1.25)
-----------
Prevent dragging from a pinboard selection to itself, or onto the desktop
background.

17-Jul-2000
-----------
Clicking on the root window works (button-1 clears the selection,
button-3 opens the pinboard menu). The pinboard can own the primary
selection, which means that you can select something and then paste
its name into another program.

Keys bound to menu entries are automatically saved when the filer quits.

16-Jul-2000
-----------
Changed the install script so that the CVS directories don't get installed.

The 'rox' script now just calls AppRun directly.
Panels can be created without starting a new copy of the filer.
The pinboard can be changed or removed by using --pinboard a second time.

Files can be given as arguments - they are opened as if they were clicked
on in a filer window (suggested by Alex Holden).  If no arguments are
given then the default is now the current directory (not your home
directory).

If you start the leafname in the path minibuffer with '.' then the Show
Hidden feature is temporarily turned on.

15-Jul-2000
-----------
Ctrl-clicking selects and unselects pinboard icons. Menu clicking
selects the icon clicked on while the menu is open. Pinned icons are
now updated when the pointer moves over them, if necessary.

14-Jul-2000
-----------
Menu-clicking on a pinboard icon now brings up a menu.
Clicks on the root window are still ignored though; need to support
the GNOME-compliant window manager system for passing root clicks on...

12-Jul-2000
-----------
Files can now be dragged to pinboard icons, and they highlight nicely too!
If the --override option is used, the filer will bypass the window manager
and position the icons directly.

11-Jul-2000
-----------
Pinboard icons can now be dragged to filer windows or applications, just
like normal icons.

10-Jul-2000
-----------
Changed the DnD code to make it easier for the pinboard code to use it.
Up and Home buttons on the toolbar now use the 'New window on button 1'
option setting (suggested by Vincent Lefèvre).

09-Jul-2000
-----------
Pinboard can have mount points and symlinks on it.

06-Jul-2000
-----------
Dragging with the Menu button moves icons around. Clicking with the
other button removes icons from the pinboard.

05-Jul-2000
-----------
Dragging files to the pinboard adds them to it and automatically saves
the pinboard too.

02-Jul-2000
-----------
Pinboard is now loaded from a file specified on the command line.

01-Jul-2000
-----------
'Home' now appears on the background if you run it with --pinboard.
Clicking opens your home directory. Doesn't do much else.
Fixed a bug which prevented the minibuffer label from appearing on
some versions of GTK+.

30-Jun-2000
-----------
First steps towards pinboard support (requested by P.S.S.Camp and
Darren Winsper).

16-Jun-2000
-----------
Changed the Display menu layout - now there are four basic types (Large or
Small, with or without details) and the type of detail desired is chosen
from a sub-sub-menu.

Added a new display style - bars showing the sizes of the files. The bars are
drawn on a log scale.

15-Jun-2000
-----------
Changed the display menu - you can now choose large or small icons, with or
without details. The details displayed can also be changed. I'm not quite
happy with the UI yet though...

Split the filer.c source file into two (filer.c and display.c) since it was
becoming rather unwieldy. This means that some of the option names have
changed because they've moved to a new section in the options window...

14-Jun-2000
-----------
Fixed a problem where ImLib support failed on multi-depth displays (reported
by Stephen Harrison).

06-Jun-2000 (Release 0.1.24)
----------------------------
Added the install.sh script for easier installation.

Removed 'MIME-info' file from ROX-Filer - now we always assume that the
standard types are in Choices.

Fixed a bug which could cause 'top' panels to appear in the wrong place
(Alex Holden).

Changed the sort order for Sort By Type so that directories come before
files (suggested by Chris Garrett).

`Single-click navigation' and 'Ignore case when sorting' now both default
to On.

03-Jun-2000
-----------
Improved the theme support to allow tiled background images.

Fixed a bug which prevented tilde expansion from working in the
shell command minibuffer.

02-Jun-2000
-----------
Made the help button look a bit nicer and changed the Find and Permissions
action windows to use the icon instead of a text button.
Removed the 3D borders from the help and toolbar buttons when not selected
(looks much better!). Setting a run action by dragging to a symlink now
dereferences the link (suggested by Ewan Mac Mahon).

Default search path for Choices is now:
	~/Choices:/usr/local/share/Choices:/usr/share/Choices

Fixed (possibly) a bug which sometimes causes the redraw to miss bits. This
probably slows everything down, but the next Gtk+ release should do double
buffering so all this will get changed then...

01-Jun-2000
-----------
Added a Help icon to the toolbar, which does the same as choosing `Show
ROX-Filer Help' from the menu.

25-May-2000
-----------
Started adding some code to truncate long filenames (not finished yet).

Fixed a bug which could cause directories to appear empty when using VFS.

Added the 'Select If' minibuffer, which selects all files matching the
entered expression.

21-May-2000
-----------
Moved most of the icons from pixmaps to MIME-icons (outside ROX-Filer).

Updated several of the remaining icons by copying them from the GNOME
desktop (suggested by Volker Braun).


16-May-2000 (Release 0.1.23)
-----------
Added the `Window->Set Run Action' menu item. This allows you to specify the
default run action for a file by simply dragging the file into a program.
You can also enter a shell command in the minibuffer to make that command
the default.

The cursor is a bit nicer and usually appears where you want it to now. You
can also get rid of it by pressing Escape.

12-May-2000
-----------
Applied Bernard's patch (a couple of cosmetic changes to the action windows).

Applied Vincent's patch (minor updates to the Frech translation).

Fixed a problem with the pixmap caching - the filer would detect that the
file had changed and try to reload it, but ImLib would simply return its
cached copy!

28-Apr-2000
-----------
Removed a debugging message that had somehow got into the release version :-(

Fixed a bug in the minibuffer code - pressing Return when the cursor was in
an empty directory caused odd effects.

24-Apr-2000 (Release 0.1.22)
----------------------------
When starting, the filer will check to see if it is already running.
If it is then the arguments are passed to that copy.

23-Apr-2000
-----------
Bug fix: Attempting to open a Find preview window could cause a crash
if the directory containing the item could not be opened.
Button-3 clicking on the toolbar icons opens a new window.


21-Apr-2000
-----------
Added Vincent Lefevre's French translation. Changed to using my own
gettext function because some platforms don't have it or implement
it differently.

18-Apr-2000 (Release 0.1.21)
----------------------------
Completed marking translatable strings. Dragging with the middle button
now moves files.

17-Apr-2000
-----------
Made lots of changes to the way menus are stored; this makes i18n of the
menus easier.

16-Apr-2000
-----------
Added GNU gettext support.
Shell meta-characters in shell commands are escaped.

15-Apr-2000
-----------
Tab in the shell commands minibuffer does shell-style completion.

14-Apr-2000 (Release 0.1.20)
-----------
ImLib is used for rendering if possible. Small Icons super-samples the
image down.

13-Apr-2000
-----------
Copying from inside a VFS directory now works.

09-Apr-2000
-----------
Added the Shell Command feature to the minibuffer.
Fixed a bug which causes unnecessary flickering when a hidden file was
detected.
Removed 'Touch' from the menu; easy enough from the minibuffer now.
Changed the type guessing system - scans all files in MIME-info directories
now.

02-Apr-2000
-----------
Added a nice list displaying the found files. Clicking opens a preview window
onto the directory and winks the file.

18-Mar-2000
-----------
Merged the MIME-Type and Special fields in the info window into a single
Type field (since only one could be used at a time anyway).
Made lots of changes to the panel menu. You can now remove things much more
easily.
Unstat()able files now display the error message in the Full Info display,
instead of random values.
Check for copying a directory onto itself, as well as into itself.

Applied Bernard's patch:
- Copy (menu entry) now works with action window.
- Deleted/moved directory displays are automatically hidden.
- Added option not to allow run/copy when object
  dragged to filer (not panels) icons. Some people like
  it the RISC OS way...
- Full info alignment of App objects and owner/group
  alignment corrected.
- Info window: added special info for symlinks, apps
  and mount points.

17-Mar-2000
-----------
Added support for mc's Virtual File System.

12-Mar-2000
-----------
New Window appears greyed out if Unique Windows is selected.
Added 'Permissions' (chmod) feature.

10-Mar-2000
-----------
Added Bernard Jungen's patch:
- Dates are displayed in a more RISC OS like format.
- (Scanning) is shown in the titlebar during scans.
- Option to only display one window per directory.
- User and group names displayed in the Full Info view.
- Open Parent in the root does nothing.
- Errors in options are only reported once.
- File does chdir() if -b isn't possible (prevents getting the full path
  in the file(1) says... box).


Before the Changes file
-----------------------
The following people added code before I started keeping this log:

Jens Askengren		GNOME-style toolbar
Bernard Jungen		lots of patches all over the place!
Christiansen Merel	initial support for ImLib
Chris Sawer		leafname field in the Info box
Simon Truss		support for mount points on NetBSD