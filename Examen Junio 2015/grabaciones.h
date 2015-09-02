#ifndef GRABACIONES_H
#define GRABACIONES_H

#include "listaprogramas.h"

const int GRABACIONES = 20;

typedef struct{
	tProgramaPtr programa;
	bool grabado;
}tGrabacion;

typedef struct{
	int capacidad;
	int contador;
	tGrabacion* grabaciones;
}tListaGrabaciones;

void crear(tListaGrabaciones & listaGrabaciones);

bool solapan(const tGrabacion & grabacion1, const tGrabacion & grabacion2);

bool insertar(tListaGrabaciones & listaGrabaciones, const tProgramaPtr & programa);

void mostrar(tListaGrabaciones & listaGrabaciones, int posicion);

void destruir(tListaGrabaciones & listaGrabaciones);

#endif
