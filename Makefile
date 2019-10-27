DESTDIR=$(shell realpath build)

.PHONY: clean docs

all:
	[ ! -f src/configure ] && cd src && autoconf
	cd src && ./configure --prefix=$(DESTDIR)
	$(MAKE) -C src DESTDIR=$(DESTDIR)

clean:
	rm -rf build
	$(MAKE) -C src clean

docs:
	$(MAKE) -C src/Docs
