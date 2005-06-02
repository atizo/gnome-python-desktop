## Process this file with automake to produce Makefile.in

REFERENCE_MAIN_FILE = gnomeprint-classes.xml
REFERENCE_DOC_NAME = pygnomeprint
DOC_MODULE = pygnomeprint

NULL=

REFERENCE_XML_FILES =                           \
  gnomeprint-gnomeprintcontext.xml              \
  gnomeprint-gnomeprintconfig.xml               \
  gnomeprint-gnomeprintjob.xml	                \
  $(NULL)

include $(top_srcdir)/docs/pygtk-ref-docs.make

# we ship html docs with the tarball
EXTRA_DIST += html.stamp html
