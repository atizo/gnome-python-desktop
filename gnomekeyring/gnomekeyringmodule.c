/* -*- Mode: C; c-basic-offset: 4 -*- */
#include <Python.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* include this first, before NO_IMPORT_PYGOBJECT is defined */
#include <pygobject.h>


void pygnomekeyring_register_classes(PyObject *d);
void pygnomekeyring_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef pygnomekeyring_functions[];

DL_EXPORT(void)
initgnomekeyring(void)
{
    PyObject *m, *d;

    init_pygobject();
    
    m = Py_InitModule("gnomekeyring", pygnomekeyring_functions);
    d = PyModule_GetDict(m);
    
    pygnomekeyring_register_classes(d);
    pygnomekeyring_add_constants(m, "GNOME_KEYRING_");
}

