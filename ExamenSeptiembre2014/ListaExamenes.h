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
* Dada una lista de exámenes y una posición muestra en pantalla los exámenes a partir de esa posición. 
* Se implementará de forma recursiva.
*/
void muestraLista(const tListaExamenes & listaExamenes, int pos);

/**
* Muestra en pantalla una lista de exámenes junto a sus estadísticas:
*/
void muestra(const tListaExamenes & listaExamenes);

bool insertarNota(tListaExamenes & listaExamenes, const tExamen & examen);

void destruye(tListaExamenes & listaExamenes);


#endif