#ifndef LISTAEQUIPOS_H
#define LISTAEQUIPOS_H

#include "equipo.h"

const string FICHERO = "equipos.txt";
const int MAXEQUIPOS = 300;
const string CENTINELA = "X";

typedef struct{
	tEquipo equipos[MAXEQUIPOS];
	int contador;
}tListaEquipos;


/**
* Carga la informaci�n del archivo equipos.txt; para cada
* l�nea localiza el c�digo de equipo en la lista (si no existe, lo inserta) y a�ade un
* componente en su lista de componentes con el c�digo, precio y nombre; y
* actualiza el precio del equipo. Devuelve la Devuelve la lista con los datos le�dos, o vac�a si el
* archivo no existe.
*/
bool cargaEquipos(tListaEquipos & listaEquipos);

/**
* dada una lista ordenada de equipos y un c�digo, devuelve la
* posici�n (�ndice) para ese c�digo en la lista; y si se ha encontrado o no un
* equipo con ese c�digo.
*/

bool buscaEquipo(const tListaEquipos & listaEquipos, string codigo, int & pos);

/**
* dada una lista de equipos y un equipo, a�ade �ste a la lista.
* La lista debe seguir ordenada por c�digo.
*/
bool insertaEquipo(tListaEquipos & listaEquipos, const tEquipo & equipo, int pos);

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
