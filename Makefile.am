
SUBDIRS = egg

if BUILD_GNOMEPRINT
  SUBDIRS += gnomeprint
endif

if BUILD_GTKHTML2
  SUBDIRS += gtkhtml2
endif

if BUILD_APPLET
  SUBDIRS += gnomeapplet
endif

if BUILD_GTKSOURCEVIEW
  SUBDIRS += gtksourceview
endif

if BUILD_WNCK
  SUBDIRS += wnck
endif

if BUILD_GTKMOZEMBED
  SUBDIRS += gtkmozembed
endif

if BUILD_GTKSPELL
  SUBDIRS += gtkspell
endif

if BUILD_GDL
  SUBDIRS += gdl
endif

if BUILD_TOTEM_PLPARSER
  SUBDIRS += totem
endif

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gnome-python-extras-2.0.pc

EXTRA_DIST = \
  gnome-python-extras-2.0.pc.in \
  ltihooks.py \
  examples/gtksourceview/test-widget.py \
  examples/egg/trayicon.py \
  examples/egg/recent/populate-recent.py \
  examples/egg/recent/gtk-view.py \
  examples/egg/recent/bonobo-view.py \
  examples/egg/recent/Bonobo_Sample_Hello.xml \
  examples/applet/applet.py \
  examples/applet/GNOME_PythonAppletSample.server \
  examples/applet/README \
  examples/gtkhtml2/simple-browser.py \
  examples/gnomeprint/test-print.py \
  examples/gnomeprint/example_01.py \
  examples/gnomeprint/example_02.py \
  examples/gnomeprint/example_03.py \
  examples/gnomeprint/example_04.py \
  examples/gnomeprint/example_05.py \
  examples/gnomeprint/example_06.py \
  examples/gnomeprint/example_08.py \
  examples/gnomeprint/example_09.py \
  examples/gnomeprint/example_10.glade \
  examples/gnomeprint/example_10.py \
  examples/gnomeprint/example_11.py \
  examples/gnomeprint/README \
  examples/gnomeprint/sample-image.png \
  examples/gtkspell/test.py \
  examples/gdl/gdl_test.py
