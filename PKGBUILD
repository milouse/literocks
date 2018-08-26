# Maintainer: jun7 <jun7@hush.com>
# Contributor: tobias <tobias@archlinux.org>
# Contributor: Jochem Kossen <j.kossen@home.nl>

pkgname=literocks
pkgver=2.11.h
pkgrel=1
branch=stable
pkgdesc="A fork of rox-filer having no desktop features, just a filer"
arch=('i686' 'x86_64')
conflicts=('literocks')
provides=('literocks')
license=('GPL')
url="https://github.com/jun7/literocks"
depends=('gtk2')
makedepends=('libxslt' 'git')
source=("git://github.com/jun7/literocks.git#branch=$branch")
md5sums=('SKIP')

pkgver(){
  cd "$srcdir/literocks"
  printf "2.11.h.%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd "$srcdir/literocks"
  git pull --rebase origin $branch
}

build() {
  cd "$srcdir/literocks"
  ./literocks/AppRun --compile LIBS="-ldl -lm"
  xsltproc -o literocks.1 "$srcdir/literocks/literocks/src/Docs/to_man.xsl" "$srcdir/literocks/literocks/src/Docs/Manual.xml"
}

package() {
  cd "$srcdir/literocks"
  install -d "$pkgdir/usr/share/Choices/MIME-types"
  install -m755 Choices/MIME-types/* "$pkgdir/usr/share/Choices/MIME-types/"
  cp -rp literocks "$pkgdir/usr/share/"
  rm -fr "$pkgdir"/usr/share/literocks/{src,build}

  install -Dm755 "$srcdir/literocks/literocks.sh" "$pkgdir/usr/bin/literocks"
  install -Dm644 literocks.1 "$pkgdir/usr/share/man/man1/literocks.1"
  ln -sf literocks.1 "$pkgdir/usr/share/man/man1/literocks.1"

  install -Dm644 "$srcdir/literocks/literocks.desktop" "$pkgdir/usr/share/applications/literocks.desktop"
  install -Dm644 "$srcdir/literocks/literocks.svg" "$pkgdir/usr/share/pixmaps/literocks.svg"
  install -Dm644 "$srcdir/literocks/literocks/.DirIcon" "$pkgdir/usr/share/pixmaps/literocks.png"
}
