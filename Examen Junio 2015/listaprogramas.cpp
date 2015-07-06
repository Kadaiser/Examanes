#include "listaprogramas.h"


void inicializar(tListaProgramas & listaProgramas){
	listaProgramas.contador = 0;
	for (int i = 0; i < MAXPROGRAMAS; i++){
		listaProgramas.programas[i] = nullptr;
	}
}


bool insertar(tListaProgramas & listaProgramas, const tPrograma & programa){
	bool espacio = false;
	if (listaProgramas.contador < MAXPROGRAMAS){

		int pos = listaProgramas.contador;

		while(pos > 0 && programa.nombre < listaProgramas.programas[pos - 1] -> nombre){
			listaProgramas.programas[pos] = listaProgramas.programas[pos - 1];
			pos--;
		}
		listaProgramas.programas[pos] = new tPrograma(programa);
		listaProgramas.contador++;
		espacio = true;
	}

	return espacio;
}


bool cargar(tListaProgramas & listaProgramas){
	bool ok = false;
	ifstream archivo;
	archivo.open(FICHERO);
	if (archivo.is_open()){

		tPrograma programa;
		while (carga(archivo, programa)){
			insertar(listaProgramas, programa);
		}
		ok = true;
	}
	archivo.close();

	return ok;
}


void mostrarLista(const tListaProgramas & listaProgramas, int posicion){
	if (posicion < listaProgramas.contador){
		cout << posicion << "- ";
		mostrar(*listaProgramas.programas[posicion]);
			mostrarLista(listaProgramas, posicion + 1);
	}
}


tProgramaPtr selecPrograma(const tListaProgramas & listaProgramas){
	int opcion;

	mostrarLista(listaProgramas, 0);
	cout << "Elige una opcion: ";
	cin >> opcion;
	cin.sync();
	
	return listaProgramas.programas[opcion];
}


void destruir(tListaProgramas & listaProgramas){
	for (int i = 0; i < listaProgramas.contador; i++){
		delete listaProgramas.programas[i];
	}
}