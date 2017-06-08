#ifndef alquiler_h
#define alquiler_h

#include "coches.h"

typedef struct {
   tCategoria categoria;
   string fecha;
   int dias;
   double coste;
} tAlquiler;
typedef tAlquiler *tAlqPtr;

void mostrarAlquiler(tAlquiler alquiler);

#endif
