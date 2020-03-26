DESTDIR=$(shell realpath build)

.PHONY: build clean install

all: build

build: src/configure src/Makefile
	$(MAKE) -C src build DESTDIR=$(DESTDIR)

install: src/literocks
	$(MAKE) -C src install DESTDIR=$(DESTDIR)

src/configure:
	cd src && autoconf

src/Makefile:
	cd src && ./configure --prefix=$(DESTDIR)

src/literocks: build

clean:
	rm -rf build
	$(MAKE) -C src clean
