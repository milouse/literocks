OUTPUT = Manual.valid Manual.html literocks.1 \
	#Manual-fr.valid Manual-fr.html \
	#Manual-it.valid Manual-it.html

TO_HTML = to_html.xsl

all: $(OUTPUT)

%.valid: %.xml
	xmllint --valid --noout --postvalid $<

%.html: %.xml
	xsltproc -o $@ $(TO_HTML) $<

literocks.1:
	xsltproc -o $@ to_man.xsl Manual.xml

clean:
	rm -f $(OUTPUT)
