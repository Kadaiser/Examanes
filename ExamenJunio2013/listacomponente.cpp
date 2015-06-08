#include "listacomponente.h"

void inicializar(tListaComponentes & listaComponentes){
	listaComponentes.contador = 0;
	listaComponentes.componentes = new tComponente [MAXCOMPONENTES];
}

void destruye(tListaComponentes & listaComponentes){
	delete[] listaComponentes.componentes;
}

void mostrarListaComponentes(const tListaComponentes & listaComponentes){
	for(int i = 0; i < listaComponentes.contador; i++){
		mostrarComponente(listaComponentes.componentes[i]);
	}
}

double totalPrecioComponentes(const tListaComponentes & listaComponentes){
	double total = 0;

	for(int i = 0; i < listaComponentes.contador; i++){
		total += listaComponentes.componentes[i].precio;
	}
	return total;
}
