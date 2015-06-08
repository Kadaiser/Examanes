#ifndef LISTAEQUIPOS_H
#define LISTAEQUIPOS_H

#include "equipo.h"

const string FICHERO = "equipos.txt";
const int MAXEQUIPOS = 300;

typedef struct{
	tEquipo equipos[MAXEQUIPOS];
	int contador;
}tListaEquipos;


/**
* Carga la información del archivo equipos.txt; para cada
* línea localiza el código de equipo en la lista (si no existe, lo inserta) y añade un
* componente en su lista de componentes con el código, precio y nombre; y
* actualiza el precio del equipo. Devuelve la Devuelve la lista con los datos leídos, o vacía si el
* archivo no existe.
*/
bool cargaEquipos(tListaEquipos & listaEquipos);

/**
* dada una lista ordenada de equipos y un código, devuelve la
* posición (índice) para ese código en la lista; y si se ha encontrado o no un
* equipo con ese código.
*/

bool buscaEquipo(const tListaEquipos & listaEquipos, string codigo, int & pos);

/**
* dada una lista de equipos y un equipo, añade éste a la lista.
* La lista debe seguir ordenada por código.
*/
bool insertaEquipo(tListaEquipos & listaEquipos, const tEquipo & equipo);

/**
*
*/
void muestraEquipos(const tListaEquipos & listaEquipos);

/**
* aplica a todos los componentes el porcentaje de incremento que
* se proporciona, actualizando los precios de los equipos.
*/
void actualiza(tListaEquipos & listaEquipos, double porcentaje);


void destruir(tListaEquipos & listaEquipos);
#endif