AC_INIT(gnome-python, 1.99,
        [http://bugzilla.gnome.org/enter_bug.cgi?product=gnome-python])
dnl AC_CONFIG_SRCDIR([gnome/uimodule.c])
AM_CONFIG_HEADER(config.h)

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)

dnl put the ACLOCAL flags in the makefile
ACLOCAL="$ACLOCAL $ACLOCAL_FLAGS"

AC_DISABLE_STATIC
AC_PROG_LIBTOOL

AM_PATH_PYTHON(2.0)
AM_CHECK_PYTHON_HEADERS(,[AC_MSG_ERROR(could not find Python headers)])

AM_PATH_GTK_2_0(1.3.7,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extra_mods)

AC_CONFIG_FILES(
  Makefile
  gnome/Makefile)
AC_OUTPUT

