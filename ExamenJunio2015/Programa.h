#ifndef Programa_H
#define Programa_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<ctime>
#include<sstream>
#include <cmath>
using namespace std;

const string CENTINELA = "XXX";

typedef time_t tFecha;

typedef struct{
	string nombre;
	tFecha fecha;
	int duracion;
}tPrograma;

bool cargar(ifstream & archivo, tPrograma & programa);

void mostrar(const tPrograma & programa);

string mostrarFecha(tFecha fecha);

#endif