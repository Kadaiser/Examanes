#ifndef PROGRAMA_H
#define PROGRAMA_H


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

const string CENTINELA = "XXX";

typedef time_t tFecha;

typedef struct{
	string nombre;
	tFecha inicio;
	int duracion;
}tPrograma;

typedef tPrograma* tProgramaPtr;

bool carga(ifstream & archivo, tPrograma & programa);

void mostrar(const tPrograma & programa);

string mostrarFecha(tFecha fecha);

#endif