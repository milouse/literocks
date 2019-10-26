# Maintainer: milouse <etienne@depar.is>
# Contributor: jun7 <jun7@hush.com>
# Contributor: tobias <tobias@archlinux.org>
# Contributor: Jochem Kossen <j.kossen@home.nl>

pkgname=literocks-git
_gitname=literocks
pkgver=2.11r122.c481750
pkgrel=1
pkgdesc="A stripped-down fork of ROX-Filer"
arch=('i686' 'x86_64')
provides=('literocks')
conflicts=('literocks')
license=('GPL')
url="https://github.com/jun7/literocks"
depends=('gtk2' 'libsm')
optdepends=('ffmpegthumbnailer: for thumnails of video/*')
makedepends=('libxslt' 'git')
source=("git://github.com/jun7/${_gitname}.git")
md5sums=('SKIP')

pkgver(){
  cd "$srcdir/${_gitname}"
  printf "2.11r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
  cd "$srcdir/${_gitname}/src"
  autoconf

  mkdir "$srcdir/${_gitname}/build"
  cd "$srcdir/${_gitname}/build"
  "$srcdir/${_gitname}/src/configure" LIBS="-ldl -lm"
  make

  cd "$srcdir/${_gitname}"
  xsltproc -o ${_gitname}.1 "src/Docs/to_man.xsl" "src/Docs/Manual.xml"

  cat > ${_gitname}.sh <<EOF
#!/usr/bin/env sh
export APP_DIR=/usr/share/${_gitname}
exec /usr/share/${_gitname}/${_gitname} "\$@"
EOF
}

package() {
  cd "$srcdir/${_gitname}"

  install -d -m755 "$pkgdir/usr/share/${_gitname}"
  cp build/*.o "$pkgdir/usr/share/${_gitname}/"
  cp -r images "$pkgdir/usr/share/${_gitname}/images"
  install -D -m644 Options.xml "$pkgdir/usr/share/${_gitname}/Options.xml"
  install -D -m644 Templates.ui "$pkgdir/usr/share/${_gitname}/Templates.ui"
  install -D -m755 ${_gitname} "$pkgdir/usr/share/${_gitname}/${_gitname}"

  install -d -m755 "$pkgdir/usr/share/licenses/${_gitname}"
  install -D -m644 Help/COPYING "$pkgdir/usr/share/licenses/${_gitname}/LICENSE"

  install -d -m755 $pkgdir/usr/share/{applications,bin,man/man1,pixmaps}
  install -D -m755 ${_gitname}.sh "$pkgdir/usr/bin/${_gitname}"
  install -D -m644 ${_gitname}.1 "$pkgdir/usr/share/man/man1/${_gitname}.1"
  install -D -m644 ${_gitname}.desktop "$pkgdir/usr/share/applications/${_gitname}.desktop"
  install -D -m644 ${_gitname}.png "$pkgdir/usr/share/pixmaps/${_gitname}.png"
}

# Local Variables:
# sh-basic-offset: 2
# End:
