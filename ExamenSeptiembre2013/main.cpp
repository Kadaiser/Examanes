#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include "coches.h"
#include "alquiler.h"
#include "listaAlq.h"
#include "cliente.h"
#include "listaCli.h"

int main() {
   tListaClientes lista;
   bool ok;

   system("chcp 1252");
   cargar(lista, ok);
   if (!ok) {
      cout << "No se ha podido abrir el archivo!" << endl;
   }
   else {
      listado(lista);
   }

   // Liberar la memoria dinámica
   for (int i = 0; i < lista.cont; i++) {
      delete [] lista.clientes[i].lista.alquileres;
   }

   return 0;
}