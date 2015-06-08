
#include "listaequipos.h"

const double PORCENTAJE = 5;

int main(){
	tListaEquipos listaEquipos;

	cargaEquipos(listaEquipos);
	muestraEquipos(listaEquipos);
	cout << "Se va a genrerar la lista con la nueva de precios (+"<< PORCENTAJE <<"% sobre el precio base de los componentes)" << endl; 
	system("pause");

	actualiza(listaEquipos, PORCENTAJE);
	muestraEquipos(listaEquipos);
	destruir(listaEquipos);

	system("pause");
	return 0;
}
