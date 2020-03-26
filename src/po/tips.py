# Grab the tips from Options.xml

from xml.sax import parse
from xml.sax.handler import ContentHandler


class Handler(ContentHandler):
    data = ""

    def startElement(self, tag, attrs):
        for x in ["title", "label", "end", "unit"]:
            if x in attrs:
                self.trans(attrs[x])
        self.data = ""

    def characters(self, data):
        self.data = self.data + data

    def endElement(self, tag):
        data = self.data.strip()
        if data:
            self.trans(data)
        self.data = ""

    def trans(self, data):
        data = '\\n'.join(data.split('\n'))
        if data:
            meth = '_("{}")\n'.format(data.replace('"', '\\"'))
            out.write(meth.encode())


print("Extracting translatable bits from Options.xml...")
out = open("tips.c", "wb")
parse("../Data/Options.xml", Handler())
out.close()
