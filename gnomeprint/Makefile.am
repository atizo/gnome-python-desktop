CLEANFILES=
INCLUDES = $(PYTHON_INCLUDES) $(PYGTK_CFLAGS)

defsdir = $(datadir)/pygtk/2.0/defs
defs_DATA = print.defs printui.defs art.defs

EXTRA_DIST = $(defs_DATA)

pkgpythondir = $(pythondir)/gtk-2.0
pkgpyexecdir = $(pyexecdir)/gtk-2.0

pygnomedir = $(pkgpythondir)/gnomeprint
pygnome_PYTHON = __init__.py

pygnomeexecdir = $(pkgpyexecdir)/gnomeprint
pygnomeexec_LTLIBRARIES = _printmodule.la

# libgnomeprint binding
_printmodule_la_CFLAGS = $(LIBGNOMEPRINT_CFLAGS)
_printmodule_la_LDFLAGS = -module -avoid-version -export-symbols-regex init_print
_printmodule_la_LIBADD = $(LIBGNOMEPRINT_LIBS)
_printmodule_la_SOURCES = printmodule.c art-gtype.h art-gtype.c
nodist__printmodule_la_SOURCES = print.c
CLEANFILES += print.c
EXTRA_DIST += print.override
print.c: print.defs print.override

# libgnomeprintui binding
if BUILD_GNOMEPRINTUI
gnomeprintui_la = uimodule.la
endif
pygnomeexec_LTLIBRARIES += $(gnomeprintui_la)
uimodule_la_CFLAGS = $(LIBGNOMEPRINTUI_CFLAGS)
uimodule_la_LDFLAGS = -module -avoid-version -export-symbols-regex initui
uimodule_la_LIBADD = $(LIBGNOMEPRINTUI_LIBS)
uimodule_la_SOURCES = printuimodule.c
nodist_uimodule_la_SOURCES = printui.c
CLEANFILES += printui.c
EXTRA_DIST += printui.override  
printui.c: printui.defs printui.override


# generic rule
.defs.c:
	(cd $(srcdir) \
	 && $(PYGTK_CODEGEN) \
	    --register $(PYGTK_DEFSDIR)/pango-types.defs \
	    --register $(PYGTK_DEFSDIR)/gdk-types.defs \
	    --register $(PYGTK_DEFSDIR)/gtk-types.defs \
	    --register $(srcdir)/print.defs \
	    --register $(top_srcdir)/gnome/canvas.defs \
	    --override $*.override \
	    --prefix py$* $*.defs) > gen-$*.c \
	&& cp gen-$*.c $*.c \
	&& rm -f gen-$*.c

