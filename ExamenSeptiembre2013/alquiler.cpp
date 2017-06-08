#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include "alquiler.h"

void mostrarAlquiler(tAlquiler alquiler) {
   cout << "     " << setw(11) << left << categoriaStr(alquiler.categoria) 
      << " " << alquiler.fecha << " " << setw(2) << right << alquiler.dias << " d�as" 
      << "  " << fixed << setprecision(2) << setw(7) << alquiler.coste << " �" << endl;
}
