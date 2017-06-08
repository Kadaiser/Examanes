#include <iostream>
#include <string>
using namespace std;

#include "ListaAlumnos.h"

int main() {
   tListaAlumnos listaAlumnos;

   carga(listaAlumnos);
   muestra(listaAlumnos);
   destruye(listaAlumnos);

   //system("pause");
   return 0;
}
