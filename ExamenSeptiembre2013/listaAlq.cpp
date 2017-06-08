#include "listaAlq.h"

void insertarAlquiler(tListaAlquiler &lista, tAlquiler alquiler) {
   if (lista.cont < MaxAlq) { // Si no hay sitio lo ignoramos
      lista.alquileres[lista.cont] = alquiler;
      lista.cont++;
   }
}