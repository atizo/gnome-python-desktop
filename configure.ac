-*- mode: m4 -*-
AC_PREREQ(2.52)

dnl the gnome-python version number
m4_define(gnome_python_major_version, 1)
m4_define(gnome_python_minor_version, 99)
m4_define(gnome_python_micro_version, 6)
m4_define(gnome_python_version, gnome_python_major_version.gnome_python_minor_version.gnome_python_micro_version)

dnl required versions of other packages
m4_define(pygtk_required_version,          1.99.6)
m4_define(gtk_required_version,            1.3.12)
m4_define(libgnome_required_version,       1.108.0)
m4_define(libgnomeui_required_version,     1.108.0)
m4_define(libgnomecanvas_required_version, 1.108.0)
m4_define(libzvt_required_version,         1.108.0)
m4_define(libbonobo_required_version,      1.108.0)
m4_define(libbonoboui_required_version,    1.108.0)

AC_INIT(gnome-python, gnome_python_version,
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
AC_MSG_CHECKING(for python >= 2.2)
prog="
import sys, string
minver = (2,2,0,'final',0)
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
PKG_CHECK_MODULES(PYGTK, pygtk-2.0 >= pygtk_required_version)
AC_SUBST(PYGTK_CFLAGS)
AC_PATH_PROG(PYGTK_CODEGEN, pygtk-codegen-2.0, no)
if test "x$PYGTK_CODEGEN" = xno; then
  AC_MSG_ERROR(could not find pygtk-codegen-2.0 script)
fi

AC_MSG_CHECKING(for pygtk defs)
PYGTK_DEFSDIR=`$PKG_CONFIG --variable=defsdir pygtk-2.0`
AC_SUBST(PYGTK_DEFSDIR)
AC_MSG_RESULT($PYGTK_DEFSDIR)

dnl required version substitutions for use in the spec file
PYGTK_VERSION=pygtk_required_version
LIBGNOMECANVAS_VERSION=libgnomecanvas_required_version
LIBGNOME_VERSION=libgnome_required_version
GTK_VERSION=gtk_required_version
LIBZVT_VERSION=libzvt_required_version
AC_SUBST(PYGTK_VERSION)
AC_SUBST(LIBGNOMECANVAS_VERSION)
AC_SUBST(LIBGNOME_VERSION)
AC_SUBST(GTK_VERSION)
AC_SUBST(LIBZVT_VERSION)

dnl check to make sure we can find gtk
AM_PATH_GTK_2_0(gtk_required_version,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extra_mods)

PKG_CHECK_MODULES(GNOME, libgnome-2.0 >= libgnome_required_version,,
  [AC_MSG_ERROR(libgnome-2.0 is required.)])
AC_SUBST(GNOME_CFLAGS)
AC_SUBST(GNOME_LIBS)

build_gnomeui=false
PKG_CHECK_MODULES(GNOMEUI, libgnomeui-2.0 >= libgnomeui_required_version,
  build_gnomeui=true,
  build_gnomeui=false)
AC_SUBST(GNOMEUI_CFLAGS)
AC_SUBST(GNOMEUI_LIBS)
AM_CONDITIONAL(BUILD_GNOMEUI, $build_gnomeui)

dnl should we build the gnome.canvas module?
build_gnomecanvas=false
PKG_CHECK_MODULES(GNOMECANVAS, libgnomecanvas-2.0 >= libgnomecanvas_required_version,
  build_gnomecanvas=true,
  build_gnomecanvas=false)
AC_SUBST(GNOMECANVAS_CFLAGS)
AC_SUBST(GNOMECANVAS_LIBS)
AM_CONDITIONAL(BUILD_GNOMECANVAS, $build_gnomecanvas)

dnl should we build the gnome.zvt module?
build_zvt=false
PKG_CHECK_MODULES(LIBZVT, libzvt-2.0 >= libzvt_required_version,
  build_zvt=true,
  build_zvt=false)
AC_SUBST(LIBZVT_CFLAGS)
AC_SUBST(LIBZVT_LIBS)
AM_CONDITIONAL(BUILD_ZVT, $build_zvt)

dnl should we build the bonobo._bonobo module?
build_bonobo=false
PKG_CHECK_MODULES(BONOBO, libbonobo-2.0 >= libbonobo_required_version,
  build_bonobo=true, build_bonobo=false)
AC_SUBST(BONOBO_CFLAGS)
AC_SUBST(BONOBO_LIBS)
AM_CONDITIONAL(BUILD_BONOBO, $build_bonobo)

dnl should we build the bonobo.ui module?
build_bonoboui=false
PKG_CHECK_MODULES(BONOBOUI, libbonoboui-2.0 >= libbonoboui_required_version,
  build_bonoboui=true, build_bonoboui=false)
AC_SUBST(BONOBOUI_CFLAGS)
AC_SUBST(BONOBOUI_LIBS)
AM_CONDITIONAL(BUILD_BONOBOUI, $build_bonoboui)

dnl 
AC_CONFIG_FILES(
  Makefile
  gnome/Makefile
  bonobo/Makefile
  gnome-python.spec)
AC_OUTPUT
