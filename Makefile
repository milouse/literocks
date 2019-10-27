DESTDIR=$(shell realpath build)

.PHONY: clean docs

all:
	[ ! -f src/configure ] && cd src && autoconf
	[ ! -f src/Makefile ] && cd src && ./configure --prefix=$(DESTDIR)
	$(MAKE) -C src install DESTDIR=$(DESTDIR)

clean:
	rm -rf build
	$(MAKE) -C src clean

docs:
	$(MAKE) -C src/Docs
