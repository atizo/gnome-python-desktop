AC_INIT(gnome-python, 1.99,
        [http://bugzilla.gnome.org/enter_bug.cgi?product=gnome-python])
dnl AC_CONFIG_SRCDIR([gnome/uimodule.c])
AM_CONFIG_HEADER(config.h)

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)

dnl put the ACLOCAL flags in the makefile
ACLOCAL="$ACLOCAL $ACLOCAL_FLAGS"

AC_DISABLE_STATIC
AC_PROG_LIBTOOL

dnl check for python
dnl AM_PATH_PYTHON(2.2)
AM_PATH_PYTHON
AC_MSG_CHECKING(for python >= 2.2a4)
prog="
import sys, string
minver = (2,2,0,'alpha',4)
if sys.version_info < minver:
  sys.exit(1)
sys.exit(0)"
if $PYTHON -c "$prog" 1>&AC_FD_CC 2>&AC_FD_CC
then
  AC_MSG_RESULT(okay)
else
  AC_MSG_ERROR(too old)
fi
AM_CHECK_PYTHON_HEADERS(,[AC_MSG_ERROR(could not find Python headers)])

dnl check for pygtk
PKG_CHECK_MODULES(PYGTK, [pygtk-2.0 >= 1.99.3])
AC_SUBST(PYGTK_CFLAGS)
AC_PATH_PROG(PYGTK_CODEGEN, pygtk-codegen-2.0, no)
if test "x$PYGTK_CODEGEN" = xno; then
  AC_MSG_ERROR(could not find pygtk-codegen-2.0 script)
fi

AC_MSG_CHECKING(for pygtk defs)
PYGTK_DEFSDIR=`$PKG_CONFIG --variable=defsdir pygtk-2.0`
AC_SUBST(PYGTK_DEFSDIR)
AC_MSG_RESULT($PYGTK_DEFSDIR)

PYGTK_VERSION=`$PKG_CONFIG --modversion pygtk-2.0`
AC_SUBST(PYGTK_VERSION)

LIBGNOMECANVAS_VERSION=`$PKG_CONFIG --modversion libgnomecanvas-2.0`
AC_SUBST(LIBGNOMECANVAS_VERSION)

GTK_VERSION=`$PKG_CONFIG --modversion gtk+-2.0`
AC_SUBST(GTK_VERSION)

dnl check to make sure we can find gtk
AM_PATH_GTK_2_0(1.3.7,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extra_mods)

dnl should we build the gnome.canvas module?
build_gnomecanvas=false
PKG_CHECK_MODULES(GNOMECANVAS, [libgnomecanvas-2.0 >= 1.102.0],
  build_gnomecanvas=true,
  build_gnomecanvas=false)
AC_SUBST(GNOMECANVAS_CFLAGS)
AC_SUBST(GNOMECANVAS_LIBS)
AM_CONDITIONAL(BUILD_GNOMECANVAS, $build_gnomecanvas)

dnl 
AC_CONFIG_FILES(
  Makefile
  gnome/Makefile
  gnome-python.spec)
AC_OUTPUT
