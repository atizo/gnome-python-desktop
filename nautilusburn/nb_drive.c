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
#include <Python.h>
#include <glib.h>
#include <nautilus-burn-drive.h>
#include "nb_drive.h"
#include "nb_typebuiltins.h"
#include <pygobject.h>

staticforward PyTypeObject nb_Drive_Type;

PyObject *
nb_drive_new (NautilusBurnDrive *drive)
{
	nb_Drive *self;
	self = (nb_Drive *) PyObject_NEW (nb_Drive, &nb_Drive_Type);
	if (!self)
		return NULL;
	self->destroy = TRUE;
	self->drive = drive;
	return (PyObject *)self;
}

PyObject *
nb_drive_new_from_native (const NautilusBurnDrive *drive)
{
	PyObject *ret = nb_drive_new ((NautilusBurnDrive *) drive);
	((nb_Drive *)ret)->destroy = FALSE;
	return ret;
}

static void
nb_Drive_dealloc (nb_Drive *self)
{
	if (self->destroy)
		nautilus_burn_drive_free (self->drive);
	self->ob_type->tp_free ((PyObject *)self);
}

static PyObject *
nb_Drive_get_media_size (nb_Drive *self)
{
	return Py_BuildValue("l", nautilus_burn_drive_get_media_size (self->drive));
}

static PyObject *
nb_Drive_unlock (nb_Drive *self)
{
	return Py_BuildValue ("i", nautilus_burn_drive_unlock (self->drive));
}

static PyObject *
nb_Drive_lock (nb_Drive *self)
{
	return Py_BuildValue ("i", nautilus_burn_drive_lock (self->drive, NULL, NULL));
}

static PyObject *
nb_Drive_get_display_name (nb_Drive *self)
{
	return Py_BuildValue ("s", self->drive->display_name);
}

static PyObject *
nb_Drive_get_device (nb_Drive *self)
{
	return Py_BuildValue ("s", self->drive->device);
}

static PyObject *
nb_Drive_get_cdrecord_id (nb_Drive *self)
{
	return Py_BuildValue ("s", self->drive->cdrecord_id);
}

static PyObject *
nb_Drive_get_max_speed_read (nb_Drive *self)
{
	return Py_BuildValue ("i", self->drive->max_speed_read);
}

static PyObject *
nb_Drive_get_max_speed_write (nb_Drive *self)
{
	return Py_BuildValue ("i", self->drive->max_speed_write);
}

static PyObject *
nb_Drive_get_media_type (nb_Drive *self)
{
	return pyg_enum_from_gtype(NAUTILUS_BURN_TYPE_MEDIA_TYPE, nautilus_burn_drive_get_media_type(self->drive));
}

static PyMethodDef nb_Drive_methods[] = {
	{"get_media_size", (PyCFunction)nb_Drive_get_media_size, METH_NOARGS,
		"get_media_size()->long\nReturns the media size."},
	{"unlock", (PyCFunction)nb_Drive_unlock, METH_NOARGS, 
		"unlock()->Boolean\nUnlocks the drive."},
	{"lock", (PyCFunction)nb_Drive_lock, METH_NOARGS, "lock()->Boolean\nLocks the drive."},
	{"get_display_name", (PyCFunction) nb_Drive_get_display_name,
		METH_NOARGS, "get_display_name()->int\nReturns the display name."},
	{"get_max_speed_write", (PyCFunction) nb_Drive_get_max_speed_write,
		METH_NOARGS, "get_max_speed_write()->int\nReturns the max writting speed."},
	{"get_max_speed_read", (PyCFunction) nb_Drive_get_max_speed_read,
		METH_NOARGS, "get_max_speed_read()->int\nReturns the max reading speed."},
	{"get_cdrecord_id", (PyCFunction) nb_Drive_get_cdrecord_id, METH_NOARGS,
		"get_cd_record_id()->string\nReturns the cdrecord ID."},
	{"get_device", (PyCFunction) nb_Drive_get_device, METH_NOARGS,
		"get_device()->string\nReturns the device filename."},
	{"get_media_type", (PyCFunction) nb_Drive_get_media_type, METH_NOARGS,
		"get_media_type()->MEDIA_TYPE_*\nReturns the media type which drive contains."},
    {NULL}  /* Sentinel */
};

static PyTypeObject nb_Drive_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "nautilusburn.Drive",            /*tp_name*/
    sizeof(nb_Drive),        /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor) nb_Drive_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "Represents a Drive",    /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		               /* tp_iter */
    0,		               /* tp_iternext */
    nb_Drive_methods,       /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    0,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
};

int
nb_drive_init(PyObject *module) 
{
 
    nb_Drive_Type.tp_new = PyType_GenericNew;
    if (PyType_Ready(&nb_Drive_Type) < 0)
        return -1;

    Py_INCREF(&nb_Drive_Type);
    PyModule_AddObject(module, "Drive", (PyObject *)&nb_Drive_Type);
    return 0;
}
