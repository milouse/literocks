ROX-Filer
=========
A RISC OS-like filer for X
by Thomas Leonard

ROX-Filer is a simple and easy to use graphical file manager for X11,
the windowing system used on Unix and Unix-like operating systems. It is
also the core component of the ROX Desktop.

Quick start
-----------

If you downloaded a source or binary tarball directly, type this ($ is the
shell prompt) to compile the filer.

    $ make

Then, type the following to run it:

    $ ./build/usr/bin/literocks

ROX-Filer
---------

Documentation for ROX-Filer can be found in the
[`src/Docs` directory](./src/Docs/Manual.html).

Conditions
----------

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

Please report any bugs to [my github repository](https://github.com/milouse/literocks/issues).

Credits
-------

ROX-Filer was created by Thomas Leonard, but many people have
contributed to it one way or another...

If you think you should be included here then write and tell me ;-)

First, a few people/projects whose work I've used:

- Andrew Clover: most of the file icons;
- David MacKenzie: the code for parsing Permissions commands;
- John Lindal: co-author of the XDS protocol;
- Midnight Commander: the Virtual File System library & pinboard bits;
- GNOME Desktop: some of the icons (including the toolbar);
- Red Hat: MIME type guessing library.

A huge number of people have submitted code, suggestions and
encouragement - many of them are listed in the
[`Changes.md` file](./Changes.md)... thanks!
