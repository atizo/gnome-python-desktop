/* 
 * Copyright (C) 2004 Tiago Cogumbreiro <cogumbreiro@users.sf.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Authors: Tiago Cogumbreiro <cogumbreiro@users.sf.net>
 */

#include <pygobject.h>
#include <Python.h>
#include "nb_drive.h"
#include "nb_track.h"
#include <nautilus-burn-recorder.h>
void nautilus_burn_register_classes (PyObject *d);
void nautilus_burn_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef nautilus_burn_functions[];

static PyObject *
nb_get_drives_list (PyObject *self, PyObject *args, PyObject *kwargs)
{
	int recorders_only, add_image, index, len;
	GList *cds, *iter;
	PyObject *cds_tuple, *cd;
	
	static char *kws[] = {"recorders_only", "add_image", NULL};
	/* defaults to 0 */
	add_image = 0;
	if (!PyArg_ParseTupleAndKeywords (args, kwargs, "i|i:get_drives_list", kws, &recorders_only,
			&add_image))
		return NULL;
	cds = nautilus_burn_drive_get_list (recorders_only, add_image);
	len = g_list_length (cds);
	cds_tuple = PyTuple_New (len);
	
	for (iter = g_list_first (cds), index = 0; iter; iter = iter->next, index++) {
		/* create the new Drive object */
		assert (iter->data);
		cd = nb_drive_new ((NautilusBurnDrive *)iter->data);
		if (!cd) {
			return NULL;
		}
		if (PyTuple_SetItem (cds_tuple, index, cd)) {
			return NULL;
		}
	}

	g_list_free (cds);
	return cds_tuple;
}

static PyObject *
nb_bytes_to_seconds (PyObject *self, PyObject *args)
{
	int size;
	if (!PyArg_ParseTuple (args, "i", &size))
		return NULL;
	return Py_BuildValue ("i", SIZE_TO_TIME(size));
}

static PyMethodDef nb_methods[] = {
	{"get_drives_list", (PyCFunction) nb_get_drives_list, METH_VARARGS | METH_KEYWORDS,
		"Scans for available drives."},
	{"bytes_to_seconds", (PyCFunction) nb_bytes_to_seconds, METH_VARARGS, "Converts a number of bytes to seconds, usefull for converting the Drive.get_media_size into time."},
	{NULL}
};


DL_EXPORT(void)
initnautilusburn(void)
{
	PyObject *m, *d;
	
	init_pygobject ();
	
	m = Py_InitModule ("nautilusburn", nb_methods);
	d = PyModule_GetDict (m);
	
	/* init Drive class */
	if (nb_drive_init (m))
		return;
	/* init Track classes */
	if (nb_track_init (m))
		return;
	/* init auto-gened classes */
	nautilus_burn_register_classes (d);
	nautilus_burn_add_constants (m, "NAUTILUS_BURN_");
}
