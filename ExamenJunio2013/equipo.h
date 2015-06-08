#ifndef	EQUIPO_H
#define EQUIPO_H

#include "listacomponente.h"

typedef struct{
	string codigo;
	double precio;
	tListaComponentes perifericos;
}tEquipo;


/**
* dado un equipo y un componente, a�ade �ste �ltimo a
* la lista de componentes del equipo y actualiza el precio del equipo.
*/
bool insertaComponente(tEquipo & equipo, const tComponente & componente);

void actualizarPrecio(tEquipo & equipo, double precio);

/**
* muestra la informaci�n de un equipo con este formato
*/
void muestraEquipo(const tEquipo & equipo);

double precioEquipo(const tEquipo & equipo);

#endif
