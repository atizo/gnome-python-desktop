## Process this file with automake to produce Makefile.in

REFERENCE_MAIN_FILE = gtksourceview-classes.xml
REFERENCE_DOC_NAME = pygtksourceview
DOC_MODULE = pygtksourceview

NULL=

REFERENCE_XML_FILES =				\
  gtksourceview-gtksourceview.xml		\
  gtksourceview-gtksourcebuffer.xml		\
  gtksourceview-gtksourcelanguage.xml		\
  gtksourceview-gtksourcelanguagesmanager.xml	\
  gtksourceview-gtksourcemarker.xml		\
  gtksourceview-gtksourcestylescheme.xml	\
  gtksourceview-gtksourcetagtable.xml		\
  gtksourceview-gtksourcetagstyle.xml		\
  $(NULL)

include $(top_srcdir)/docs/pygtk-ref-docs.make

# we ship html docs with the tarball
EXTRA_DIST += html html.stamp
