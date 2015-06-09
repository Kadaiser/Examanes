#ifndef LISTEMPLEADOS_H
#define LISTEMPLEADOS_H

#include "empleado.h"

const int MAXEMPLEADOS = 100;
const string BACKUP = "BACKUP.TXT";

typedef struct{
	tEmpleado* empleados;
	int contador;
}tListaEmpleados;

void inicializar (tListaEmpleados & listaEmpleados);

bool buscarCodigo(const tListaEmpleados & listaEmpleados, int codigo, int & pos);

void insertarEmpleado(tListaEmpleados & listaEmpleados, const tEmpleado & empleado,int pos);

void eliminarDepartamento (tListaEmpleados & listaEmpleados);

void eliminarEmpleado(tListaEmpleados &listaEmpleados, const tEmpleado & empleado, int pos);

void listado(const tListaEmpleados & listaEmpleados);

void guardar(const tListaEmpleados & listaEmpleados);

void destruir(tListaEmpleados & listaEmpleados);

void GenerarEmpleado(tListaEmpleados & listaEmpleados);

#endif