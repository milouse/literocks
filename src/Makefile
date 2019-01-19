# Note: this Makefile is NOT built from Makefile.in. The generated Makefile
# goes in the build directory. We just call that from here.
# Use AppRun --compile to create the build directory in the first place.

BUILDDIR = ../build

all:
	cd ${BUILDDIR} && ${MAKE}

# This ensures we get the header files for GTK 2.4
with0launch:
	0launch --source --main=/literocks/build --wrapper='make -C' ../literocks-src.xml

clean:
	cd ${BUILDDIR} && ${MAKE} clean
