VERSION    = $(shell sed -n "s/^VERSION=\"\(.*\)\"$$/\1/p" ../configure.in)

L10N_LANGS = fr
PO_FILES   = $(L10N_LANGS:%=%/LC_MESSAGES/literocks.po)
MO_FILES   = $(PO_FILES:%.po=%.mo)

PROG         = literocks
SRCS         = $(wildcard ../*.c)
TRANSLATABLE = $(SRCS) tips.c

.PHONY: clean lang uplang

all: lang

tips:
	python tips.py

literocks.pot: tips
	xgettext --keyword=_ --keyword=N_ --from-code=UTF-8 \
		--copyright-holder="Literocks volunteers" \
		--package-name=$(PROG) --package-version=$(VERSION) \
		--output=literocks.pot $(TRANSLATABLE)
	xgettext --join-existing --language=Glade --output=literocks.pot \
		../Data/Templates.ui

%.po: literocks.pot
	mkdir -p $(@D)
	msginit -l $(@:%/LC_MESSAGES/literocks.po=%) \
		--no-translator -i $< -o $@

%/LC_MESSAGES/literocks.mo: %/LC_MESSAGES/literocks.po
	msgfmt -o $@ $<

%.po~:
	msgmerge --lang $(@:%/LC_MESSAGES/literocks.po~=%) \
		-o $@ $(@:%~=%) literocks.pot
	sed -i -e "s|Copyright (C) [0-9]*|Copyright (C) $(shell date +%Y)|" \
		-e "s|Id-Version: Literocks [0-9.-]*|Id-Version: Literocks $(VERSION)|" \
		-e "s|Id-Version: ROX-Filer [0-9.-]*|Id-Version: Literocks $(VERSION)|" \
		$@
	cp $@ $(@:%~=%) && rm $@

lang: $(PO_FILES)

uplang: $(PO_FILES:%=%~)

clean:
	rm -f tips.c
	rm -f $(MO_FILES)
