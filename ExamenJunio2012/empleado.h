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
	int codigo;
	string nombre;
	tDepartemento departamento;
	tJornada jornada;
}tEmpleado;

void muestraEmpleado(const tEmpleado & empleado);

void crearEmpleado(tEmpleado& empleado, int codigo, string nombre, int numDepartamento);

void insertarJornada(tEmpleado & empleado, tJornada & jornada);

tDepartemento intToDepartamento(int numDepartamento);

int departamentoToInt(const tDepartemento & departamento);

bool perteneceDepartamento(const tEmpleado & empleado, int numDepartamento);

void mostrarDepartamentos();

#endif