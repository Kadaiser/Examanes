#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>
#include "listaCli.h"

void insertarCliente(tListaClientes &lista, tCliente cliente) {
   int pos = 0;
   bool encontrado = false;

   if (lista.cont < MaxCli) { // Si no hay sitio lo ignoramos
      while ((pos < lista.cont) && !encontrado) {
         if (lista.clientes[pos].nif < cliente.nif) {
            pos++;
         }
         else {
            encontrado = true;
         }
      }
      for (int i = lista.cont; i > pos; i--) {
         lista.clientes[i] = lista.clientes[i - 1];
      }
      lista.clientes[pos] = cliente;
      lista.cont++;
   }
}

int buscarCliente(tListaClientes lista, string nif) {
   int ini = 0, fin = lista.cont - 1, mitad;
   bool encontrado = false;

   while ((ini <= fin) && !encontrado) {
      mitad = (ini + fin) / 2;
      if (lista.clientes[mitad].nif == nif) {
         encontrado = true;
      }
      else if (lista.clientes[mitad].nif < nif) {
         ini = mitad + 1;
      }
      else {
         fin = mitad - 1;
      }
   }
   if (!encontrado) {
      mitad = -1;
   }

   return mitad;
}

void cargar(tListaClientes &lista, bool &ok) {
   ifstream archivo;
   tCliente cliente;
   tAlquiler alquiler;
   string nif;
   int cat, pos;

   ok = true;
   lista.cont = 0;
   archivo.open("alquileres.txt");
   if (!archivo.is_open()) {
      ok = false;
   }
   else {
      archivo >> nif;
      while (nif != "X") {
         archivo >> cat;
         alquiler.categoria = tCategoria(cat);
         archivo >> alquiler.fecha;
         archivo >> alquiler.dias;
         alquiler.coste = Fijo + alquiler.dias * PorDia * factor(alquiler.categoria);
         alquiler.coste = alquiler.coste + alquiler.coste * IVA / 100;
         pos = buscarCliente(lista, nif);
         if (pos == -1) {
            cliente.nif = nif;
            cliente.lista.alquileres = new tAlquiler[MaxAlq];
            cliente.lista.cont = 0;
            insertarAlquiler(cliente.lista, alquiler);
            insertarCliente(lista, cliente);
         }
         else {
            insertarAlquiler(lista.clientes[pos].lista, alquiler);
         }
         archivo >> nif;
      }
      archivo.close();
   }
}

void listado(tListaClientes lista) {
   double coste, total = 0;

   for (int i = 0; i < lista.cont; i++) {
      mostrarCliente(lista.clientes[i], coste);
      total = total + coste;
   }
   cout << "Coste total de alquileres: " << fixed << setprecision(2)
        << total << " €" << endl;
}
