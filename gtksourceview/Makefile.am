AUTOMAKE_OPTIONS=1.7

INCLUDES = $(PYTHON_INCLUDES) $(GTKSOURCEVIEW_CFLAGS) $(PYGTK_CFLAGS)

EXTRA_DIST = gtksourceview.defs gtksourceview.override

pkgpythondir = $(pyexecdir)/gtk-2.0
pkgpyexecdir = $(pyexecdir)/gtk-2.0

# gtksourceview module
pkgpyexec_LTLIBRARIES = gtksourceviewmodule.la
gtksourceviewmodule_la_LDFLAGS = -module -avoid-version -export-symbols-regex initgtksourceview
gtksourceviewmodule_la_LIBADD = $(GTKSOURCEVIEW_LIBS)
gtksourceviewmodule_la_SOURCES = gtksourceviewmodule.c 
nodist_gtksourceviewmodule_la_SOURCES = gtksourceview.c
gtksourceview.c: gtksourceview.defs gtksourceview.override
CLEANFILES = gtksourceview.c

.defs.c:
	(cd $(srcdir)\
	 && $(PYGTK_CODEGEN) \
		--override $*.override \
	    --register $(PYGTK_DEFSDIR)/gdk-types.defs \
	    --register $(PYGTK_DEFSDIR)/pango-types.defs \
	    --register $(PYGTK_DEFSDIR)/gtk-types.defs \
	    --register $(top_srcdir)/gnomeprint/print.defs \
		--prefix py$* $*.defs) > gen-$*.c \
	    && cp gen-$*.c $*.c \
	    && rm -f gen-$*.c
