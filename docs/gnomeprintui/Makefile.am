## Process this file with automake to produce Makefile.in

REFERENCE_MAIN_FILE = gnomeprintui-classes.xml
REFERENCE_DOC_NAME = pygnomeprintui
DOC_MODULE = pygnomeprintui

NULL=

REFERENCE_XML_FILES =                           \
  gnomeprintui-gnomeprintuidialog.xml           \
  gnomeprintui-gnomeprintuifontdialog.xml       \
  gnomeprintui-gnomeprintuifontselection.xml    \
  gnomeprintui-gnomeprintuifontpreview.xml      \
  gnomeprintui-gnomeprintuijobpreview.xml       \
  gnomeprintui-gnomeprintuipreview.xml          \
  gnomeprintui-gnomeprintuipaperselector.xml    \
  $(NULL)

include $(top_srcdir)/docs/pygtk-ref-docs.make

# we ship html docs with the tarball
EXTRA_DIST += html.stamp html
