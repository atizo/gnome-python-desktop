-*- mode: autoconf -*-
AC_PREREQ(2.52)

dnl the gnome-python version number
m4_define(gnome_python_major_version, 1)
m4_define(gnome_python_minor_version, 99)
m4_define(gnome_python_micro_version, 14)
m4_define(gnome_python_version, gnome_python_major_version.gnome_python_minor_version.gnome_python_micro_version)

dnl required versions of other packages
m4_define(pygtk_required_version,             1.99.14)
m4_define(pyorbit_required_version,           1.99.3)

m4_define(glib_required_version,              2.0.0)
m4_define(gtk_required_version,               2.0.0)
m4_define(libgnome_required_version,          2.0.0)
m4_define(libgnomeui_required_version,        2.0.0)
m4_define(libgnomecanvas_required_version,    2.0.0)
m4_define(libgnomevfs_required_version,       2.0.0)
m4_define(libzvt_required_version,            2.0.0)
m4_define(gconf_required_version,             1.2.0)
m4_define(bonobo_activation_required_version, 1.0.0)
m4_define(libbonobo_required_version,         2.0.0)
m4_define(libbonoboui_required_version,       2.0.0)
m4_define(libnautilus_required_version,       2.0.0)
m4_define(libpanelapplet_required_version,    2.0.0)
m4_define(gtkhtml2_required_version,          1.99.9)
m4_define(libgnomeprint_required_version,     2.1.9)
m4_define(libgnomeprintui_required_version,   2.1.9)

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
LIBGNOMEVFS_VERSION=libgnomevfs_required_version
GTK_VERSION=gtk_required_version
LIBZVT_VERSION=libzvt_required_version
PYORBIT_VERSION=pyorbit_required_version
NAUTILUS_VERSION=libnautilus_required_version
BONOBO_ACTIVATION_VERSION=bonobo_activation_required_version
LIBBONOBO_VERSION=libbonobo_required_version
LIBBONOBOUI_VERSION=libbonoboui_required_version
GCONF_VERSION=gconf_required_version
LIBPANELAPPLET_VERSION=libpanelapplet_required_version
GTKHTML2_VERSION=gtkhtml2_required_version
LIBGNOMEPRINT_VERSION=libgnomeprint_required_version
LIBGNOMEPRINTUI_VERSION=libgnomeprintui_required_version
AC_SUBST(PYGTK_VERSION)
AC_SUBST(LIBGNOMECANVAS_VERSION)
AC_SUBST(LIBGNOME_VERSION)
AC_SUBST(LIBGNOMEVFS_VERSION)
AC_SUBST(GLIB_VERSION)
AC_SUBST(GTK_VERSION)
AC_SUBST(LIBZVT_VERSION)
AC_SUBST(PYORBIT_VERSION)
AC_SUBST(NAUTILUS_VERSION)
AC_SUBST(BONOBO_ACTIVATION_VERSION)
AC_SUBST(LIBBONOBO_VERSION)
AC_SUBST(LIBBONOBOUI_VERSION)
AC_SUBST(GCONF_VERSION)
AC_SUBST(LIBPANELAPPLET_VERSION)
AC_SUBST(GTKHTML2_VERSION)
AC_SUBST(LIBGNOMEPRINT_VERSION)
AC_SUBST(LIBGNOMEPRINTUI_VERSION)

dnl get rid of the -export-dynamic stuff from the configure flags ...
export_dynamic=`(./libtool --config; echo eval echo \\$export_dynamic_flag_spec) | sh`

dnl check for glib
AM_PATH_GLIB_2_0(glib_required_version,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extra_mods)
GLIB_LIBS=`echo $GLIB_LIBS | sed -e "s/$export_dynamic//"`

dnl check to make sure we can find gtk
AM_PATH_GTK_2_0(gtk_required_version,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extra_mods)
GTK_LIBS=`echo $GTK_LIBS | sed -e "s/$export_dynamic//"`

PKG_CHECK_MODULES(GNOME, libgnome-2.0 >= libgnome_required_version,,
  [AC_MSG_ERROR(libgnome-2.0 is required.)])
AC_SUBST(GNOME_CFLAGS)
AC_SUBST(GNOME_LIBS)
GNOME_LIBS=`echo $GNOME_LIBS | sed -e "s/$export_dynamic//"`

have_pyorbit=false
PKG_CHECK_MODULES(PYORBIT,
  pyorbit-2 >= pyorbit_required_version,
  have_pyorbit=true, have_pyorbit=false)
AC_SUBST(PYORBIT_CFLAGS)

build_gnomeui=false
PKG_CHECK_MODULES(GNOMEUI, libgnomeui-2.0 >= libgnomeui_required_version,
  build_gnomeui=true,
  build_gnomeui=false)
AC_SUBST(GNOMEUI_CFLAGS)
AC_SUBST(GNOMEUI_LIBS)
AM_CONDITIONAL(BUILD_GNOMEUI, $have_pyorbit && $build_gnomeui)
GNOMEUI_LIBS=`echo $GNOMEUI_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the gnome.canvas module?
build_gnomecanvas=false
PKG_CHECK_MODULES(GNOMECANVAS, libgnomecanvas-2.0 >= libgnomecanvas_required_version,
  build_gnomecanvas=true,
  build_gnomecanvas=false)
AC_SUBST(GNOMECANVAS_CFLAGS)
AC_SUBST(GNOMECANVAS_LIBS)
AM_CONDITIONAL(BUILD_GNOMECANVAS, $build_gnomecanvas)
GNOMECANVAS_LIBS=`echo $GNOMECANVAS_LIBS | sed -e "s/$export_dynamic//"`

build_gnomevfs=false
PKG_CHECK_MODULES(GNOMEVFS, gnome-vfs-2.0 >= libgnomevfs_required_version,
  build_gnomevfs=true,
  build_gnomevfs=false)
AC_SUBST(GNOMEVFS_CFLAGS)
AC_SUBST(GNOMEVFS_LIBS)
AM_CONDITIONAL(BUILD_GNOMEVFS, $build_gnomevfs)
GNOMEVFS_LIBS=`echo $GNOMEVFS_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the gnome.zvt module?
build_zvt=false
PKG_CHECK_MODULES(LIBZVT, libzvt-2.0 >= libzvt_required_version,
  build_zvt=true,
  build_zvt=false)
AC_SUBST(LIBZVT_CFLAGS)
AC_SUBST(LIBZVT_LIBS)
AM_CONDITIONAL(BUILD_ZVT, $build_zvt)
LIBZVT_LIBS=`echo $LIBZVT_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the gnome.zvt module?
build_applet=false
PKG_CHECK_MODULES(LIBPANELAPPLET, libpanelapplet-2.0 >= libpanelapplet_required_version,
  build_applet=true,
  build_applet=false)
AC_SUBST(LIBPANELAPPLET_CFLAGS)
AC_SUBST(LIBPANELAPPLET_LIBS)
AM_CONDITIONAL(BUILD_APPLET, $build_applet)
LIBPANELAPPLET_LIBS=`echo $LIBPANELAPPLET_LIBS | sed -e "s/$export_dynamic//"`

PKG_CHECK_MODULES(GCONF, gconf-2.0 >= gconf_required_version,,
  [AC_MSG_ERROR(gconf-2.0 is required.)])
GCONF_INCLUDEDIR="`pkg-config gconf-2.0 --variable includedir`/gconf/2/gconf"
AC_SUBST(GCONF_INCLUDEDIR)
AC_SUBST(GCONF_CFLAGS)
AC_SUBST(GCONF_LIBS)
GCONF_LIBS=`echo $GCONF_LIBS | sed -e "s/$export_dynamic//"`

PKG_CHECK_MODULES(GTKHTML2, libgtkhtml-2.0 >= gtkhtml2_required_version,
  build_gtkhtml2=true,
  build_gtkhtml2=false)
AC_SUBST(GTKHTML2_CFLAGS)
AC_SUBST(GTKHTML2_LIBS)
AM_CONDITIONAL(BUILD_GTKHTML2, $build_gtkhtml2)
GTKHTML2_LIBS=`echo $GTKHTML2_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the bonobo.activation module?
build_bonobo_activation=false
PKG_CHECK_MODULES(BONOBO_ACTIVATION, bonobo-activation-2.0 >= bonobo_activation_required_version,
  build_bonobo_activation=true, build_bonobo_activation=false)
AC_SUBST(BONOBO_ACTIVATION_CFLAGS)
AC_SUBST(BONOBO_ACTIVATION_LIBS)
AM_CONDITIONAL(BUILD_BONOBO_ACTIVATION, $have_pyorbit && $build_bonobo_activation)
BONOBO_ACTIVATION_LIBS=`echo $BONOBO_ACTIVATION_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the bonobo._bonobo module?
build_bonobo=false
PKG_CHECK_MODULES(BONOBO, libbonobo-2.0 >= libbonobo_required_version,
  build_bonobo=true, build_bonobo=false)
AC_SUBST(BONOBO_CFLAGS)
AC_SUBST(BONOBO_LIBS)
AM_CONDITIONAL(BUILD_BONOBO, $have_pyorbit && $build_bonobo)
BONOBO_LIBS=`echo $BONOBO_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the bonobo.ui module?
build_bonoboui=false
PKG_CHECK_MODULES(BONOBOUI, libbonoboui-2.0 >= libbonoboui_required_version libgnome-2.0 >= libgnome_required_version,
  build_bonoboui=true, build_bonoboui=false)
AC_SUBST(BONOBOUI_CFLAGS)
AC_SUBST(BONOBOUI_LIBS)
AM_CONDITIONAL(BUILD_BONOBOUI, $have_pyorbit && $build_bonoboui)
BONOBOUI_LIBS=`echo $BONOBOUI_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the nautilus module?
build_nautilus=false
PKG_CHECK_MODULES(LIBNAUTILUS, libnautilus >= libnautilus_required_version,
  build_nautilus=true,
  build_nautilus=false)
AC_SUBST(LIBNAUTILUS_CFLAGS)
AC_SUBST(LIBNAUTILUS_LIBS)
AM_CONDITIONAL(BUILD_NAUTILUS, $have_pyorbit && $build_nautilus)
LIBNAUTILUS_LIBS=`echo $LIBNAUTILUS_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the gnomeprint module?
build_gnomeprint=false
PKG_CHECK_MODULES(LIBGNOMEPRINT, libgnomeprint-2.2 >= libgnomeprint_required_version,
  build_gnomeprint=true,
  build_gnomeprint=false)
AC_SUBST(LIBGNOMEPRINT_CFLAGS)
AC_SUBST(LIBGNOMEPRINT_LIBS)
AM_CONDITIONAL(BUILD_GNOMEPRINT, $build_gnomeprint)
LIBGNOMEPRINT_LIBS=`echo $LIBGNOMEPRINT_LIBS | sed -e "s/$export_dynamic//"`

dnl should we build the gnomeprint.ui module?
build_gnomeprintui=false
PKG_CHECK_MODULES(LIBGNOMEPRINTUI, libgnomeprintui-2.2 >= libgnomeprintui_required_version,
  build_gnomeprintui=true,
  build_gnomeprintui=false)
AC_SUBST(LIBGNOMEPRINTUI_CFLAGS)
AC_SUBST(LIBGNOMEPRINTUI_LIBS)
AM_CONDITIONAL(BUILD_GNOMEPRINTUI, $build_gnomeprintui)
LIBGNOMEPRINTUI_LIBS=`echo $LIBGNOMEPRINTUI_LIBS | sed -e "s/$export_dynamic//"`

dnl add debugging options ...
changequote(,)dnl
if test "x$GCC" = xyes; then
  case " $CFLAGS " in
  *[\	\ ]-Wall[\	\ ]*) ;;
  *) CFLAGS="$CFLAGS -Wall" ;;
  esac

  case " $CFLAGS " in
  *[\	\ ]-std=c9x[\	\ ]*) ;;
  *) CFLAGS="$CFLAGS -std=c9x" ;;
  esac
fi
changequote([,])dnl
dnl
AC_CONFIG_FILES(
  Makefile
  gconf/Makefile
  gtkhtml2/Makefile
  gnome/Makefile
  gnomeprint/Makefile
  bonobo/Makefile
  gnome-python.spec
  gnome-python-2.0.pc)
AC_OUTPUT

echo
echo "The following modules will be built:"
echo
$build_gnome             && echo     gnome
$build_gnomeui           && echo     gnome.ui
$build_gnomecanvas       && echo     gnome.canvas
$build_gnomevfs          && echo     gnome.vfs
$build_zvt               && echo     zvt
$build_gconf             && echo     gconf
$build_gtkhtml2          && echo     gtkhtml2
$build_bonobo            && echo     bonobo
$build_bonobo_activation && echo     bonobo.activation
$build_bonoboui          && echo     bonobo.ui
$build_applet            && echo     gnome.applet
$build_nautilus          && echo     nautilus
$build_gnomeprint        && echo     gnomeprint
$build_gnomeprintui      && echo     gnomeprint.ui
echo

echo "The following modules will NOT be built:"
echo
$build_gnome             || echo     gnome
$build_gnomeui           || echo     gnome.ui
$build_gnomecanvas       || echo     gnome.canvas
$build_gnomevfs          || echo     gnome.vfs
$build_zvt               || echo     zvt
$build_gconf             || echo     gconf
$build_gtkhtml2          || echo     gtkhtml2
$build_bonobo            || echo     bonobo
$build_bonobo_activation || echo     bonobo.activation
$build_bonoboui          || echo     bonobo.ui
$build_applet            || echo     gnome.applet
$build_nautilus          || echo     nautilus
$build_gnomeprint        || echo     gnomeprint
$build_gnomeprintui      || echo     gnomeprint.ui

if [ ! $have_pyorbit ]; then
  echo
  echo "Note: PyORBit pyorbit_required_version or later is required by bonobo, gnomeui"
  echo "and nautilus bindings."
  echo "Download it from: http://ftp.gnome.org/pub/GNOME/pyorbit/1.99/"
  echo
fi
