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
  ./configure
  make
}

package() {
  cd "$srcdir/${_gitname}"
  make -C src install DESTDIR="$pkgdir"
}

# Local Variables:
# sh-basic-offset: 2
# End:
