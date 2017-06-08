#ifndef listaalq_h
#define listaalq_h

#include "alquiler.h"

const int MaxAlq = 30;

typedef struct {
   tAlqPtr alquileres; // Array din�mico
   int cont;
} tListaAlquiler;

void insertarAlquiler(tListaAlquiler &lista, tAlquiler alquiler);

#endif
