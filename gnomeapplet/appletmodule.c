/* -*- Mode: C; c-basic-offset: 4 -*- */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* include this first, before NO_IMPORT_PYGOBJECT is defined */
#include <pygobject.h>
#include <panel-applet.h>

void pyapplet_register_classes (PyObject *d);

extern PyMethodDef pyapplet_functions[];

DL_EXPORT(void)
initapplet(void)
{
	PyObject *m, *d;
	
	init_pygobject ();

	m = Py_InitModule ("applet", pyapplet_functions);
	d = PyModule_GetDict (m);
	
	pyapplet_register_classes (d);
	PyModule_AddIntConstant (m, "NO_BACKGROUND", PANEL_NO_BACKGROUND);
	PyModule_AddIntConstant (m, "COLOR_BACKGROUND", PANEL_COLOR_BACKGROUND);
	PyModule_AddIntConstant (m, "PIXMAP_BACKGROUND", PANEL_PIXMAP_BACKGROUND);
	
	gnome_program_module_register (LIBGNOMEUI_MODULE);
	
	if (PyErr_Occurred ()) {
		Py_FatalError ("can't initialise module applet");
	}
}
