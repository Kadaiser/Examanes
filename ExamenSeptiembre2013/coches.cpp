#include <iostream>
#include <string>
using namespace std;
#include "coches.h"

tCategoria leer() { // No hace falta para el programa concreto
   int op;
   
   do {
      cout << "Categoría (0=Mini, 1=Utilitario, 2=Monovolumen, 3=Lujo): ";
      cin >> op;
   } while ((op < 0) || (op > 3));
   
   return tCategoria(op);
}

string categoriaStr(tCategoria cat) {
   string cad;
   
   switch (cat) {
   case mini:
      {
         cad = "Mini";
      }
      break;
   case utilitario:
      {
         cad = "Utilitario";
      }
      break;
   case monovolumen:
      {
         cad = "Monovolumen";
      }
      break;
   case lujo:
      {
         cad = "Lujo";
      }
      break;
   }

   return cad;
}

double factor(tCategoria cat) {
   double fact;

   if (cat == mini) {
      fact = 1;
   }
   else if (cat == utilitario) {
      fact = 1.5;
   }
   else if (cat == monovolumen) {
      fact = 2,5;
   }
   else {
      fact = 4;
   }

   return fact;
}
