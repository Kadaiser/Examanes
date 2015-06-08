#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int MAXDEPARTAMENTO = 50;

typedef enum {Informatica, RRHH, Publicidad, Ventas} tDepartemento;

typedef struct{
	int horas;
	int minutos;
}tJornada;

typedef struct{
	int numeroEmpleado;
	string nombre;
	tDepartemento departamento;
	int* companieros;
	tJornada jornada;
}tEmpleado;

void inicializar(tEmpleado & empleado);

void crearEmpleado(int numeroEmpleado, string nombre, int numDepartamento);

void destruir(tEmpleado & empleado);

void insertarJornada(tEmpleado & empleado, tJornada & jornada);

tDepartemento intToDepartamento(int numDepartamento);

string departamentoToString(const tDepartemento & departamento);

#endif