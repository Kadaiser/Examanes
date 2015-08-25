#include"ListaProgramas.h"

void inicializar(tListaProgramas & listaProgramas){
	for (int i = 0; i < MAX_COMP; i++){
		listaProgramas.programa[i] = nullptr;
	}
	listaProgramas.contador = 0;
}

bool buscar(tListaProgramas & listaProgramas, string nombre, int & pos){
	bool encontrado = false;
	int ini = 0, mitad, fin = listaProgramas.contador - 1;

	while ((ini <= fin) && !encontrado){
		mitad = (ini + fin) / 2;
		if (nombre < listaProgramas.programa[mitad]->nombre){
			fin = mitad - 1;
		}
		else if (listaProgramas.programa[mitad]->nombre < nombre){
			ini = mitad + 1;
		}
		else encontrado = true;
	}
	if (encontrado) pos = mitad;
	else pos = ini;
	return encontrado;
}

void insertar(tListaProgramas & listaProgramas, const tPrograma & programa){
	int pos;
	if (!buscar(listaProgramas, programa.nombre, pos)){
		for (int i = listaProgramas.contador; i > pos; i--){
			listaProgramas.programa[i] = listaProgramas.programa[i - 1];
		}
		listaProgramas.programa[pos] = new tPrograma(programa);
		listaProgramas.contador++;
	}	
}

bool cargar(tListaProgramas & listaProgramas){
	ifstream archivo;
	archivo.open(FICHERO);
	bool esCargado = archivo.is_open();
	inicializar(listaProgramas);
	tPrograma programa;
	if (esCargado){
		while (cargar(archivo, programa) && listaProgramas.contador < MAX_COMP){
			insertar(listaProgramas, programa);
		}		
	}
	else cout << "Error no abierto fichero";

	archivo.close();
	return esCargado;
}

tPrograma selecPrograma(const tListaProgramas & listaProgramas){
	int opcion;
	for (int i = 0; i < listaProgramas.contador; i++){
		cout << i << "- ";
		mostrar(*listaProgramas.programa[i]);
		cout << endl;
	}
	cout << "Selecciona un programa: ";
	cin >> opcion;
	return *listaProgramas.programa[opcion];
}

void destruir(tListaProgramas & listaProgramas){
	for (int i = 0; i < listaProgramas.contador; i++)
	delete listaProgramas.programa[i];
}