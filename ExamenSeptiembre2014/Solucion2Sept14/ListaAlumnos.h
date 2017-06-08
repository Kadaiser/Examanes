#ifndef ListaAlumnos_h
#define ListaAlumnos_h

#include <fstream>
#include "ListaExamenes.h"

const int MaxAlumnos = 400;

// Alumno
typedef struct {
    string nif;
	tListaExamenes listaExamenes;
} tAlumno;

typedef tAlumno *tAlumnoPtr;

typedef tAlumnoPtr tArrayAlumnos[MaxAlumnos]; // Array estático de datos dinámicos

typedef struct {
   tArrayAlumnos alumnos;
   int cont;
} tListaAlumnos;

const string FileName = "datos.txt";

void totalEstadisticas(const tListaAlumnos &listaAlumnos, tArrayNotasAgrupadas notasAgrupadas);
void muestra(const tListaAlumnos &listaAlumnos);
void insertaAlumno(tListaAlumnos &listaAlumnos, string fecha, tExamen examen, int pos);
void carga(tListaAlumnos &listaAlumnos);
void destruye(tListaAlumnos &listaAlumnos);

#endif
