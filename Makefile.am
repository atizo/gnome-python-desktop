AUTOMAKE_OPTIONS = 1.5

SUBDIRS = gnome

EXTRA_DIST = \
	examples/canvas/canvas-example.py \
	gnome-python.spec.in

dist-hook: gnome-python.spec
	cp gnome-python.spec $(distdir)