#include <Python.h>

#include <nautilus-burn-recorder.h>

typedef struct {
    PyObject_HEAD
    
    NautilusBurnRecorderTrack track;
} nb_Track;

int nb_track_init (PyObject *module);
int nb_AudioTrack_Check (PyObject *object);
int nb_DataTrack_Check (PyObject *object);
