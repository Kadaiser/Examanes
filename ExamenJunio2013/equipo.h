#ifndef	EQUIPO_H
#define EQUIPO_H

#include "listacomponente.h"

typedef struct{
	string codigo;
	double precio;
	tListaComponentes perifericos;
}tEquipo;


/**
* dado un equipo y un componente, añade éste último a
* la lista de componentes del equipo y actualiza el precio del equipo.
*/
bool insertaComponente(tEquipo & equipo, const tComponente & componente);

/**
* muestra la información de un equipo con este formato
*/
void muestraEquipo(const tEquipo & equipo);



#endif