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
#include <nautilus-burn-drive.h>
void initdrive(void);

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    gboolean destroy;
   	NautilusBurnDrive *drive;
} nb_Drive;

/* returns 0 on success, -1 on failure */
int nb_drive_init(PyObject *module);
PyObject *nb_drive_new_from_native (const NautilusBurnDrive *drive);
PyObject *nb_drive_new (NautilusBurnDrive *drive);
