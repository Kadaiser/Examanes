#ifndef LISTAEXAMENES_H
#define LISTAEXAMENES_H

#include "Examen.h"

const int MAXEXAMENES = 50;

typedef struct{
	tExamen* examenes;
	int contador;
}tListaExamenes;

typedef int tArrayCalificaciones[5];



void inicializar(tListaExamenes & listaExamenes);

void estadisticasNotas (const tListaExamenes & listaExamenes, tArrayCalificaciones & arrayCalificaciones);

/**
* Dada una lista de ex�menes y una posici�n muestra en pantalla los ex�menes a partir de esa posici�n.
* Se implementar� de forma recursiva.
*/
void muestraLista(const tListaExamenes & listaExamenes, int pos);

/**
* Muestra en pantalla una lista de ex�menes junto a sus estad�sticas:
*/
void muestra(const tListaExamenes & listaExamenes);

bool insertarNota(tListaExamenes & listaExamenes, const tExamen & examen);

void destruye(tListaExamenes & listaExamenes);


#endif
