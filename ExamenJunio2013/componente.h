#ifndef COMPONENTE_H
#define COMPONENTE_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

typedef struct{
	double precio;
	string nombre;
	string codigo;
}tComponente;

double masIva (double precio);

void mostrarComponente(const tComponente & componente);

#endif
