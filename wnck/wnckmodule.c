/* -*- Mode: C; c-basic-offset: 4 -*- */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <libwnck/libwnck.h>

/* include this first, before NO_IMPORT_PYGOBJECT is defined */
#include <pygobject.h>

#include <pygtk/pygtk.h>

void pywnck_register_classes(PyObject *d);
extern PyMethodDef pywnck_functions[];

DL_EXPORT(void)
initwnck (void)
{
	PyObject *m, *d;

	init_pygobject();
	init_pygtk ();

	m = Py_InitModule ("wnck", pywnck_functions);
	d = PyModule_GetDict (m);

	pywnck_register_classes (d);
}
