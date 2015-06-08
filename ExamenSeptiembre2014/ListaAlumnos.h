#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H

#include<fstream>
#include "ListaExamenes.h"

const int MAXALUMNOS = 100;
const string CENTINELA = "XXX";

typedef struct{
	string NIF;
	tListaExamenes listaExamenes;
}tAlumno;


typedef struct{
	tAlumno* alumnos[MAXALUMNOS];
	int contador;
}tListaAlumnos;

typedef int tArrayCalificacionesAlumnos[5];

void inicializar(tListaAlumnos & listaAlumnos);

void totalEstadisticas(const tListaAlumnos & listaAlumnos, tArrayCalificacionesAlumnos & arrayCalificacionesAlumnos);

void muestra(const tListaAlumnos & listaAlumnos);

bool busca(const tListaAlumnos & listaAlumnos, string NIF, int & pos);

void creaAlumno(string NIF, tExamen examen, tAlumno &alumno);

void insertaAlumno(tListaAlumnos & listaAlumnos, string NIF, const tExamen & examen, int pos);

void carga (tListaAlumnos & listaAlumnos, ifstream & archivo);

void destruye(tListaAlumnos & listaAlumnos);


#endif
