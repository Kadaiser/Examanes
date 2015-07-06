#ifndef LISTAPROGRAMAS_H
#define LISTAPROGRAMAS_H

#include "programa.h"

const int MAXPROGRAMAS = 20;
const string FICHERO = "programas.txt";

typedef struct{
	int contador;
	tProgramaPtr programas[MAXPROGRAMAS];
}tListaProgramas;

void inicializar(tListaProgramas & listaProgramas);

bool insertar(tListaProgramas & listaProgramas, const tPrograma & programa);

bool cargar(tListaProgramas & listaProgramas);

void mostrarLista(const tListaProgramas & listaProgramas, int posicion);

tProgramaPtr selecPrograma(const tListaProgramas & listaProgramas);

void destruir(tListaProgramas & listaProgramas);
#endif 