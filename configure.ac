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
AM_PATH_PYTHON(2.0)
AM_CHECK_PYTHON_HEADERS(,[AC_MSG_ERROR(could not find Python headers)])

dnl check for pygtk
PKG_CHECK_MODULES(PYGTK, [pygtk-2.0 > 1.99])
AC_PATH_PROG(PYGTK_CODEGEN, pygtk-codegen-2.0, no)
if test "x$PYGTK_CODEGEN" = xno; then
  AC_MSG_ERROR(could not find pygtk-codegen-2.0 script)
fi
AC_MSG_CHECKING(for pygtk defs)
defsdir=`$PYGTK_CONFIG --variable=defsdir pygtk-2.0`
AC_SUBST(defsdir)
AC_MSG_RESULT($defsdir)

dnl check to make sure we can find gtk
AM_PATH_GTK_2_0(1.3.7,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extra_mods)

dnl should we build the gnome.canvas module?
build_gnomecanvas=false
PKG_CHECK_MODULES(GNOMECANVAS, [libgnomecanvas-2.0 > 1.99],
  build_gnomecanvas=true,
  build_gnomecanvas=false)
AC_SUBST(GNOMECANVAS_CFLAGS)
AC_SUBST(GNOMECANVAS_LIBS)
AM_CONDITIONAL(BUILD_GNOMECANVAS, $build_gnomecanvas)

dnl 
AC_CONFIG_FILES(
  Makefile
  gnome/Makefile)
AC_OUTPUT

