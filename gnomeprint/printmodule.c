/* -*- Mode: C; c-basic-offset: 4 -*- */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* include this first, before NO_IMPORT_PYGOBJECT is defined */
#include <pygobject.h>
#include <libgnomeprint/gnome-print.h>

void pyprint_register_classes (PyObject *d);
extern PyMethodDef pyprint_functions[];

void
pyprint_add_defined_constants (PyObject *dict)
{
#define add_item(short)\
    PyModule_AddStringConstant (dict, #short, GNOME_PRINT_##short)
      /* GnomePrintConfig keys */
    add_item(KEY_PAPER_SIZE);
    add_item(KEY_PAPER_WIDTH);
    add_item(KEY_PAPER_HEIGHT);
    add_item(KEY_PAPER_ORIENTATION);
    add_item(KEY_PAPER_ORIENTATION_MATRIX);
    add_item(KEY_PAGE_ORIENTATION);
    add_item(KEY_PAGE_ORIENTATION_MATRIX);
    add_item(KEY_LAYOUT);
    add_item(KEY_LAYOUT_WIDTH);
    add_item(KEY_LAYOUT_HEIGHT);
    add_item(KEY_RESOLUTION);
    add_item(KEY_RESOLUTION_DPI);
    add_item(KEY_RESOLUTION_DPI_X);
    add_item(KEY_RESOLUTION_DPI_Y);
    add_item(KEY_NUM_COPIES);
    add_item(KEY_COLLATE);
    add_item(KEY_PAGE_MARGIN_LEFT);
    add_item(KEY_PAGE_MARGIN_RIGHT);
    add_item(KEY_PAGE_MARGIN_TOP);
    add_item(KEY_PAGE_MARGIN_BOTTOM);
    add_item(KEY_PAPER_MARGIN_LEFT);
    add_item(KEY_PAPER_MARGIN_RIGHT);
    add_item(KEY_PAPER_MARGIN_TOP);
    add_item(KEY_PAPER_MARGIN_BOTTOM);
    add_item(KEY_OUTPUT_FILENAME);
    add_item(KEY_DOCUMENT_NAME);
    add_item(KEY_PREFERED_UNIT);
#undef add_item

#define add_item(short)\
    PyModule_AddIntConstant (dict, #short, GNOME_PRINT_##short)
      /* error codes */
    add_item(OK);
    add_item(ERROR_UNKNOWN);
    add_item(ERROR_BADVALUE);
    add_item(ERROR_NOCURRENTPOINT);
    add_item(ERROR_NOCURRENTPATH);
    add_item(ERROR_TEXTCORRUPT);
    add_item(ERROR_BADCONTEXT);
    add_item(ERROR_NOPAGE);
    add_item(ERROR_NOMATCH);
#undef add_item

#define add_item(short)\
    PyModule_AddIntConstant (dict, #short, GNOME_##short)
      /* GnomeFontWeight values */
    add_item(FONT_LIGHTEST);
    add_item(FONT_EXTRA_LIGHT);
    add_item(FONT_THIN);
    add_item(FONT_LIGHT);
    add_item(FONT_BOOK);
    add_item(FONT_REGULAR);
    add_item(FONT_MEDIUM);
    add_item(FONT_SEMI);
    add_item(FONT_DEMI);
    add_item(FONT_BOLD);
    add_item(FONT_HEAVY);
    add_item(FONT_EXTRABOLD);
    add_item(FONT_BLACK);
    add_item(FONT_EXTRABLACK);
    add_item(FONT_HEAVIEST);
#undef add_item

      /* ArtPathcode */
#define add_item(short)\
    PyModule_AddIntConstant (dict, #short, ART_##short)
    add_item(MOVETO);
    add_item(MOVETO_OPEN);
    add_item(CURVETO);
    add_item(LINETO);
#undef add_item

}


DL_EXPORT(void)
init_print (void)
{
    PyObject *m, *d;
	
    init_pygobject ();
    
    m = Py_InitModule ("_print", pyprint_functions);
    d = PyModule_GetDict (m);
	
    pyprint_register_classes (d);
    pyprint_add_defined_constants (m);

    if (PyErr_Occurred ()) {
	Py_FatalError ("can't initialise module gnome.print");
    }
}

