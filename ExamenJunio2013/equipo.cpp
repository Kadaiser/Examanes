#include "equipo.h"


bool insertaComponente(tEquipo & equipo, const tComponente & componente){
	bool ok = false;
	if(equipo.perifericos.contador < MAXCOMPONENTES){
		equipo.perifericos.componentes[equipo.perifericos.contador] = componente;
		equipo.perifericos.contador++;
		ok = true;
	}
	else
	cout << "No hay sitio para mas componente en el equipo " << equipo.codigo  << endl;
	return ok;
}


void actualizarPrecio(tEquipo & equipo, double precio){

}

void muestraEquipo(const tEquipo & equipo){
	cout << equipo.codigo << endl;
	cout << "/t";
	mostrarListaComponentes(equipo.perifericos);

}

double precioEquipo(const tEquipo & equipo){
	double total;
	total  = totalPrecioComponentes(equipo.perifericos);
	masIva(total);
	return total;
}
