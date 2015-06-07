#ifndef EXAMENES_H
#define EXAMENES_H

#include<iostream>
#include<string>


using namespace std;


typedef enum {SS, AP, B, NT, SB} tCalificacion;

typedef struct{
	string fecha;
	tCalificacion calificacion;
	double nota;
}tExamen;

void muestra(const tExamen & examen);

tCalificacion notaToCalificacion(double nota);

string calificacionToString(const tCalificacion & calificacion);

void creaExamen(string fecha, double nota, tExamen & examen);

#endif