/* -*- Mode: C; c-basic-offset: 4 -*- */
#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <pygobject.h>
#include <pygtk/pygtk.h>

#include <profiles/gnome-media-profiles.h>

void pymediaprofiles_register_classes(PyObject *d);
extern PyMethodDef pymediaprofiles_functions[];

DL_EXPORT (void)
initmediaprofiles (void)
{
    PyObject *m, *d;
    
    /* TODO: We leak a ref to gconf client here, who cares.. */
    gnome_media_profiles_init (gconf_client_get_default ());

    m = Py_InitModule("mediaprofiles", pymediaprofiles_functions);
    d = PyModule_GetDict(m);

    init_pygtk();
    init_pygobject();
    
    pymediaprofiles_register_classes(d);

    if (PyErr_Occurred())
        Py_FatalError("could not initialise module mediaprofiles");
}
