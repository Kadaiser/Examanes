#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "ListaClientes.h"

const string FICHERO = "datos.txt";

int main(){
	tListaClientes listaClientes;
	ifstream archivo;
	archivo.open(FICHERO);

	if(!archivo.is_open()){
	cout << "Error al abrir el fichero";
	}

	else{
		carga(listaClientes, archivo);
		muestra(listaClientes);
		archivo.close();
	}

	cout << "Se procede a destruir la memoria del programa" << endl;
	destruye(listaClientes);
	system("pause");
return 0;
}
