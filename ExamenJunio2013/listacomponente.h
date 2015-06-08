#ifndef	LISTACOMPONENTE_H
#define	LISTACOMPONENTE_H

#include "componente.h"

const int MAXCOMPONENTES = 20;

typedef struct{
	tComponente* componentes; //Array dinamico
	int contador;
}tListaComponentes;

void inicializar(tListaComponentes & listaComponentes);

void destruye(tListaComponentes & listaComponentes);

void mostrarListaComponentes(const tListaComponentes & listaComponentes);

double totalPrecioComponentes(const tListaComponentes & listaComponentes);

#endif
