
#include "listaequipos.h"

const double PORCENTAJE = 25;

int main(){
	tListaEquipos listaEquipos;

	cargaEquipos(listaEquipos);
	muestraEquipos(listaEquipos);
	actualiza(listaEquipos, PORCENTAJE);
	muestraEquipos(listaEquipos);
	destruir(listaEquipos);

	system("pause");
	return 0;
}
