AUTOMAKE_OPTIONS = 1.6

if BUILD_GNOMEPRINT
  GNOMEPRINT_SUBDIR = gnomeprint
endif

SUBDIRS = gconf gnome bonobo gtkhtml2 $(GNOMEPRINT_SUBDIR) tests

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gnome-python-2.0.pc

EXTRA_DIST = \
  gnome-python.spec \
  gnome-python.spec.in \
  gnome-python-2.0.pc.in \
  PKG-INFO \
  PKG-INFO.in \
  ChangeLog.pre-2-0 \
  setup.py \
  ltihooks.py \
  examples/applet/applet.py \
  examples/applet/GNOME_PythonAppletSample.server \
  examples/applet/README \
  examples/bonobo/bonoboui/Bonobo_Sample_Hello.xml \
  examples/bonobo/bonoboui/hello.py \
  examples/bonobo/echo/README \
  examples/bonobo/echo/echo-client.py \
  examples/canvas/canvas-example.py \
  examples/gconf/basic-gconf-app.py \
  examples/gconf/simple-controller.py \
  examples/gconf/simple-view.py \
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
  examples/nautilus/README \
  examples/nautilus/Nautilus_View_pysample.server \
  examples/nautilus/sample.py \
  examples/zvt/zvt-demo.py \
  examples/vfs/shell.py \
  examples/vfs/async.py \
  examples/popt/popt.py
