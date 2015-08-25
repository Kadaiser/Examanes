#ifndef ListaProgramas_H
#define ListaProgramas_H

#include"Programa.h"

const int MAX_COMP = 20;
const string FICHERO = "programas.txt";

typedef struct{
	tPrograma* programa[MAX_COMP];
	int contador;
}tListaProgramas;

void inicializar(tListaProgramas & listaProgramas);

bool buscar(tListaProgramas & listaProgramas, string nombre, int & pos);

void insertar(tListaProgramas & listaProgramas, const tPrograma & programa);

bool cargar(tListaProgramas & listaProgramas);

tPrograma selecPrograma(const tListaProgramas & listaProgramas);

void destruir(tListaProgramas & listaProgramas);


#endif