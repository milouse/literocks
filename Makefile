.PHONY: clean docs

all:
	[ ! -f src/configure ] && cd src && autoconf
	cd src && ./configure
	$(MAKE) -C src DESTDIR=$(shell realpath build)

clean:
	rm -rf build
	$(MAKE) -C src clean

docs:
	$(MAKE) -C src/Docs
