#ifndef ListaExamenes_h
#define ListaExamenes_h

#include <iostream>
#include <string>
using namespace std;
#include "Examen.h"

//Notas agrupadas
typedef int tArrayNotasAgrupadas[NumNotasCual];  // Array estático para almacenar el número de notas de cada tipo

//Lista de examenes
const int MaxExamenes = 100;

typedef tExamenPtr tArrayExamenes; // Array dinámico para la lista de examenes

typedef struct {
	tArrayExamenes examenes;
	int cont;
} tListaExamenes;

//Subprogramas de alumno
void estadisticaNotas(const tListaExamenes &listaExamenes, tArrayNotasAgrupadas notasAgrupadas);
void muestra(const tListaExamenes &listaExamenes);
void destruye(tListaExamenes &listaExamenes);
void insertaExamen(tListaExamenes &listaExamenes, tExamen examen);
void creaListaExamenes(tExamen examen, tListaExamenes &listaExamenes);

//Subprogramas de notas agrupadas
void inicializarEstadisticas(tArrayNotasAgrupadas notasAgrupadas);
void muestraEstadisticas(tArrayNotasAgrupadas notasAgrupadas);

#endif
