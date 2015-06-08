#include "listaequipos.h"


void inicializar(tListaEquipos & listaEquipos){
listaEquipos.contador = 0;
}
/**
* Carga la informaci�n del archivo equipos.txt; para cada
* l�nea localiza el c�digo de equipo en la lista (si no existe, lo inserta) y a�ade un
* componente en su lista de componentes con el c�digo, precio y nombre; y
* actualiza el precio del equipo. Devuelve la Devuelve la lista con los datos le�dos, o vac�a si el
* archivo no existe.
*/
bool cargaEquipos(tListaEquipos & listaEquipos){
	bool ok = false;
	return ok;
}

/**
* dada una lista ordenada de equipos y un c�digo, devuelve la
* posici�n (�ndice) para ese c�digo en la lista; y si se ha encontrado o no un
* equipo con ese c�digo.
*/

bool buscaEquipo(const tListaEquipos & listaEquipos, string codigo, int & pos){
	bool ok = false;
	return ok;
}
/**
* dada una lista de equipos y un equipo, a�ade �ste a la lista.
* La lista debe seguir ordenada por c�digo.
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