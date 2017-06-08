#ifndef cliente_h
#define cliente_h

#include "listaAlq.h"

typedef struct {
   string nif;
   tListaAlquiler lista;
} tCliente;

void mostrarCliente(tCliente cliente, double &coste);

#endif
