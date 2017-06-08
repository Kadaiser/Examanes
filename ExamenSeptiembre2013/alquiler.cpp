#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include "alquiler.h"

void mostrarAlquiler(tAlquiler alquiler) {
   cout << "     " << setw(11) << left << categoriaStr(alquiler.categoria) 
      << " " << alquiler.fecha << " " << setw(2) << right << alquiler.dias << " días" 
      << "  " << fixed << setprecision(2) << setw(7) << alquiler.coste << " €" << endl;
}
