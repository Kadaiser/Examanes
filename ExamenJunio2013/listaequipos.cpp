#include "listaequipos.h"


void inicializar(tListaEquipos & listaEquipos){
listaEquipos.contador = 0;
}
/**
* Carga la información del archivo equipos.txt; para cada
* línea localiza el código de equipo en la lista (si no existe, lo inserta) y añade un
* componente en su lista de componentes con el código, precio y nombre; y
* actualiza el precio del equipo. Devuelve la Devuelve la lista con los datos leídos, o vacía si el
* archivo no existe.
*/
bool cargaEquipos(tListaEquipos & listaEquipos){
	bool ok = false;
	return ok;
}

/**
* dada una lista ordenada de equipos y un código, devuelve la
* posición (índice) para ese código en la lista; y si se ha encontrado o no un
* equipo con ese código.
*/

bool buscaEquipo(const tListaEquipos & listaEquipos, string codigo, int & pos){
	bool ok = false;
	return ok;
}
/**
* dada una lista de equipos y un equipo, añade éste a la lista.
* La lista debe seguir ordenada por código.
*/
bool insertaEquipo(tListaEquipos & listaEquipos, const tEquipo & equipo){
	bool ok = false;
	return ok;
}

/**
*
*/
void muestraEquipos(const tListaEquipos & listaEquipos){
}

/**
* aplica a todos los componentes el porcentaje de incremento que
* se proporciona, actualizando los precios de los equipos.
*/
void actualiza(tListaEquipos & listaEquipos, double porcentaje){
}

void destruir(tListaEquipos & listaEquipos){
	for (int i = 0; i < listaEquipos.contador; i++){
	destruir(listaEquipos.equipos[i].perifericos.componentes);
	}
}