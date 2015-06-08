#include "listacomponente.h"

void inicializar(tListaComponentes & listaComponentes){
	listaComponentes.contador = 0;
	listaComponentes.componentes = new tComponente [MAXCOMPONENTES];
}

void destruir(tListaComponentes & listaComponentes){
	delete[] listaComponentes.componentes;
}