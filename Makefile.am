
SUBDIRS =

if BUILD_GNOMEPRINT
  SUBDIRS += gnomeprint
endif

if BUILD_GTKHTML2
  SUBDIRS += gtkhtml2
endif

if BUILD_APPLET
  SUBDIRS += gnomeapplet
endif

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gnome-python-extras-2.0.pc

EXTRAS_DIST = \
  gnome-python-extras-2.0.pc.in \
  ltihooks.py \
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
  examples/gnomeprint/sample-image.png

