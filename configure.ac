-*- mode: autoconf -*-
AC_PREREQ(2.52)

dnl the gnome-python version number
m4_define(gnome_python_extras_major_version, 2)
m4_define(gnome_python_extras_minor_version, 9)
m4_define(gnome_python_extras_micro_version, 0)
m4_define(gnome_python_extras_version, gnome_python_extras_major_version.gnome_python_extras_minor_version.gnome_python_extras_micro_version)

dnl required versions of other packages
m4_define(pygtk_required_major_version, 2)
m4_define(pygtk_required_minor_version, 4)
m4_define(pygtk_required_micro_version, 0)
m4_define(pygtk_required_version, pygtk_required_major_version.pygtk_required_minor_version.pygtk_required_micro_version)
m4_define(glib_required_version,              2.4.0)
m4_define(gtk_required_version,               2.4.0)
m4_define(gnome_python_required_version,      2.9.0)
m4_define(libpanelapplet_required_version,    2.0.0)
m4_define(gtkhtml2_required_version,          2.3.1)
m4_define(libgnomeprint_required_version,     2.2.0)
m4_define(libgnomeprintui_required_version,   2.2.0)
m4_define(gtksourceview_required_version,     1.1.0)
m4_define(wnck_required_version,              2.8.0)


AC_INIT(gnome-python-extras, gnome_python_extras_version,
        [http://bugzilla.gnome.org/enter_bug.cgi?product=gnome-python])
dnl AC_CONFIG_SRCDIR([gnome/uimodule.c])
AM_CONFIG_HEADER(config.h)

AM_INIT_AUTOMAKE

AC_DEFINE(GNOME_PYTHON_EXTRAS_MAJOR_VERSION, gnome_python_extras_major_version,
                                            [Gnome-Python-Extras major version])
AC_DEFINE(GNOME_PYTHON_EXTRAS_MINOR_VERSION, gnome_python_extras_minor_version,
                                            [Gnome-Python-Extras minor version])
AC_DEFINE(GNOME_PYTHON_EXTRAS_MICRO_VERSION, gnome_python_extras_micro_version,
                                            [Gnome-Python-Extras macro version])


dnl put the ACLOCAL flags in the makefile
ACLOCAL="$ACLOCAL $ACLOCAL_FLAGS"

AC_DISABLE_STATIC
AC_PROG_LIBTOOL

dnl check for python
AM_PATH_PYTHON(2.3)
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

PKG_CHECK_MODULES(GNOME_PYTHON, gnome-python-2.0 >= gnome_python_required_version)
AC_MSG_CHECKING(for gnome-python argtypes dir)
GNOME_PYTHON_ARGTYPES_DIR=`$PKG_CONFIG --variable=argtypesdir gnome-python-2.0`
AC_SUBST(GNOME_PYTHON_ARGTYPES_DIR)
AC_MSG_RESULT($GNOME_PYTHON_ARGTYPES_DIR)

dnl get rid of the -export-dynamic stuff from the configure flags ...
export_dynamic=`(./libtool --config; echo eval echo \\$export_dynamic_flag_spec) | sh`

dnl check for glib
AM_PATH_GLIB_2_0(glib_required_version,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extras_mods)
if test -n "$export_dynamic"; then
  GLIB_LIBS=`echo $GLIB_LIBS | sed -e "s/$export_dynamic//"`
fi

dnl check to make sure we can find gtk
AM_PATH_GTK_2_0(gtk_required_version,,[AC_MSG_ERROR(maybe you want the gtk-gnome-1-2 branch?)],$extras_mods)
if test -n "$export_dynamic"; then
  GTK_LIBS=`echo $GTK_LIBS | sed -e "s/$export_dynamic//"`
fi


dnl should we build the gnome.applet module?
build_applet=false
PKG_CHECK_MODULES(LIBPANELAPPLET, libpanelapplet-2.0 >= libpanelapplet_required_version,
  build_applet=true,
  build_applet=false)
AC_SUBST(LIBPANELAPPLET_CFLAGS)
AC_SUBST(LIBPANELAPPLET_LIBS)
AM_CONDITIONAL(BUILD_APPLET, $build_applet)
if test -n "$export_dynamic"; then
  LIBPANELAPPLET_LIBS=`echo $LIBPANELAPPLET_LIBS | sed -e "s/$export_dynamic//"`
fi


PKG_CHECK_MODULES(GTKHTML2, libgtkhtml-2.0 >= gtkhtml2_required_version,
  build_gtkhtml2=true,
  build_gtkhtml2=false)
AC_SUBST(GTKHTML2_CFLAGS)
AC_SUBST(GTKHTML2_LIBS)
AM_CONDITIONAL(BUILD_GTKHTML2, $build_gtkhtml2)
if test -n "$export_dynamic"; then
  GTKHTML2_LIBS=`echo $GTKHTML2_LIBS | sed -e "s/$export_dynamic//"`
fi


dnl should we build the gnomeprint module?
build_gnomeprint=false
PKG_CHECK_MODULES(LIBGNOMEPRINT, libgnomeprint-2.2 >= libgnomeprint_required_version,
  build_gnomeprint=true,
  build_gnomeprint=false)
AC_SUBST(LIBGNOMEPRINT_CFLAGS)
AC_SUBST(LIBGNOMEPRINT_LIBS)
AM_CONDITIONAL(BUILD_GNOMEPRINT, $build_gnomeprint)
if test -n "$export_dynamic"; then
  LIBGNOMEPRINT_LIBS=`echo $LIBGNOMEPRINT_LIBS | sed -e "s/$export_dynamic//"`
fi

if [ $build_gnomeprint = true ]; then
   AC_MSG_CHECKING([for libgnomeprint 2.8 API])
   if $PKG_CONFIG --modversion "libgnomeprint-2.2 >= 2.7.2" > /dev/null 2>&1; then
      AC_MSG_RESULT([found])
      PYGNOMEPRINT_DEFS="-DHAVE_GNOMEPRINT28";
   else
      AC_MSG_RESULT([not found])
   fi
fi
AC_SUBST(PYGNOMEPRINT_DEFS)

dnl should we build the gnomeprint.ui module?
build_gnomeprintui=false
PKG_CHECK_MODULES(LIBGNOMEPRINTUI, libgnomeprintui-2.2 >= libgnomeprintui_required_version,
  build_gnomeprintui=true,
  build_gnomeprintui=false)
AC_SUBST(LIBGNOMEPRINTUI_CFLAGS)
AC_SUBST(LIBGNOMEPRINTUI_LIBS)
AM_CONDITIONAL(BUILD_GNOMEPRINTUI, $build_gnomeprintui)
if test -n "$export_dynamic"; then
  LIBGNOMEPRINTUI_LIBS=`echo $LIBGNOMEPRINTUI_LIBS | sed -e "s/$export_dynamic//"`
fi

dnl should we build the gtksourceview module?
build_gtksourceview=false
PKG_CHECK_MODULES(GTKSOURCEVIEW, gtksourceview-1.0 >= gtksourceview_required_version,
  build_gtksourceview=true,
  build_gtksourceview=false)
AM_CONDITIONAL(BUILD_GTKSOURCEVIEW, $build_gtksourceview)
if test -n "$export_dynamic"; then
  GTKSOURCEVIEW_LIBS=`echo $GTKSOURCEVIEW_LIBS | sed -e "s/$export_dynamic//"`
fi

dnl should we build the egg.trayicon module?
build_eggtray=false
PKG_CHECK_MODULES(EGGTRAY, gtk+-2.0 >= 2.2.0 libgnomeui-2.0 >=  2.2.0,
  build_eggtray=true,
  build_eggtray=false)
AM_CONDITIONAL(BUILD_EGGTRAY, $build_eggtray)
if test -n "$export_dynamic"; then
  EGGTRAY_LIBS=`echo $EGGTRAY_LIBS | sed -e "s/$export_dynamic//"`
fi

dnl should we build the egg.recent module?
build_eggrecent=false
PKG_CHECK_MODULES(EGG_RECENT, gtk+-2.0 >= 2.0.0 gnome-vfs-2.0 libbonoboui-2.0 librsvg-2.0 libgnomeui-2.0,
  build_eggrecent=true,
  build_eggrecent=false)
AM_CONDITIONAL(BUILD_EGGRECENT, $build_eggrecent)
if test -n "$export_dynamic"; then
  EGGRECENT_LIBS=`echo $EGGRECENT_LIBS | sed -e "s/$export_dynamic//"`
fi

dnl should we build the wnck module
build_wnck=false
PKG_CHECK_MODULES(WNCK, libwnck-1.0 >= wnck_required_version,
  build_wnck=true,
  build_wnck=false)
AM_CONDITIONAL(BUILD_WNCK, $build_wnck)
if test -n "$export_dynamic"; then
  WNCK_LIBS=`echo $WNCK_LIBS | sed -e "s/$export_dynamic//"`
fi

dnl add required cflags ...
JH_ADD_CFLAG([-Wall])
dnl commented because it causes compilation problems in egg/recent
dnl JH_ADD_CFLAG([-std=c9x])
JH_ADD_CFLAG([-fno-strict-aliasing])

AC_CONFIG_FILES(
  Makefile
  gtkhtml2/Makefile
  gnomeapplet/Makefile
  gnomeprint/Makefile
  gtksourceview/Makefile
  egg/Makefile
  egg/tray/Makefile
  egg/recent/Makefile
  wnck/Makefile
  gnome-python-extras-2.0.pc
)
AC_OUTPUT

echo
echo "The following modules will be built:"
echo
$build_gtkhtml2          && echo     gtkhtml2
$build_applet            && $have_pyorbit && echo     gnomeapplet
$build_gnomeprint        && echo     gnomeprint
$build_gnomeprintui      && echo     gnomeprint.ui
$build_gtksourceview     && echo     gtksourceview
$build_eggtray           && echo     egg.trayicon
$build_wnck              && echo     wnck
echo

echo "The following modules will NOT be built:"
echo
$build_gtkhtml2          || echo     gtkhtml2
$build_applet            && $have_pyorbit || echo     gnomeapplet
$build_gnomeprint        || echo     gnomeprint
$build_gnomeprintui      || echo     gnomeprint.ui
$build_gtksourceview     || echo     gtksourceview
$build_eggtray           || echo     egg.trayicon
$build_wnck              || echo     wnck

