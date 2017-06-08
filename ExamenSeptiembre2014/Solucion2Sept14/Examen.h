#ifndef Examen_h
#define Examen_h

#include <iostream>
#include <string>
using namespace std;
#include <iomanip>

const int NumNotasCual = 5;

typedef enum {SS,AP,B,NT,SB} tNotaCual;

typedef struct {
   string fecha;
   double notaNumerica;
   tNotaCual notaCualitativa;
} tExamen;

typedef tExamen *tExamenPtr;

void muestra(tExamen examen);
tNotaCual notaCualitativa(double notaNumerica);
void creaExamen(string nif, double notaNum, tExamen &examen);

#endif