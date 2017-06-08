#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include "cliente.h"

void mostrarCliente(tCliente cliente, double &coste) {
   coste = 0;
   cout << cliente.nif << endl;
   for (int i = 0; i < cliente.lista.cont; i++) {
      mostrarAlquiler(cliente.lista.alquileres[i]);
      coste = coste + cliente.lista.alquileres[i].coste;
   }
   cout << "     Coste total alquileres del cliente: " << fixed << setprecision(2)
        << coste << " €" << endl;
}
