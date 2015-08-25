#ifndef Grabaciones_H
#define Grabaciones_H


#include"ListaProgramas.h"

const int MAX_CAP = 20;

typedef struct{
	tPrograma* programa;
	bool grabado;
}tGrabacion;

typedef struct{
	tGrabacion* grabacion;
	int contador;
}tGrabaciones;


void crear (tGrabaciones & grabaciones);

bool solapan(const tGrabacion & grabacion1, const tGrabacion & grabacion2);

bool insertar(tGrabaciones & grabaciones, const tGrabacion & grabacion);

void mostrar(const tGrabaciones & grabaciones);

void destruir(tGrabaciones & grabaciones, tListaProgramas & listaProgramas);


#endif