#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "ListaClientes.h"

void inicializar(tListaClientes & listaClientes){
	listaClientes.contador = 0;
}

bool encuentra(const tListaClientes & listaClientes, string NIF, int & pos){
	int ini = 0, fin = listaClientes.contador-1, mitad;
	bool encontrado = false;
	
	while (ini <= fin && !encontrado){
		mitad = ( ini + fin )/2;
	
		if(NIF < listaClientes.clientes[mitad]-> NIF){
			fin = mitad-1;
		}
		else if (listaClientes.clientes[mitad]-> NIF < NIF){
			ini = mitad +1;
		}
		else{
		encontrado = true;
		}
	}
	if(encontrado) pos = mitad;
	else pos= ini;
	
	return encontrado;
}

double totalVentas(const tListaClientes & listaClientes){
	double total = 0;
	for (int i = 0; i < listaClientes.contador; i++){
		total +=  totalVentas(listaClientes.clientes[i]->listaProductos);
	}
	return total;
}


bool insertaCliente(tListaClientes & listaClientes, string ID, const tProducto & producto){
	bool ok = false;
	int pos;
	if(listaClientes.contador < MAXCLIENTES){
	
		if(!encuentra(listaClientes, ID, pos)){
		listaClientes.clientes[listaClientes.contador] = new tCliente;
		inicializar(listaClientes.clientes[listaClientes.contador]->listaProductos);

		for(int i = listaClientes.contador; i > pos; i--){
			listaClientes.clientes[i] = listaClientes.clientes[i-1];
		}
		
		listaClientes.clientes[pos] -> NIF = ID;
		listaClientes.clientes[pos] -> listaProductos.productos[listaClientes.clientes[pos]->listaProductos.contador] = producto;
		ok =true;
		}	
	}
	else{
		cout << "Error lista de clientes llena" << endl;
	}
	return ok;
}


void carga(tListaClientes & listaClientes, ifstream& archivo){
	int pos;
	string NIF;
	tProducto producto;
	
	inicializar(listaClientes);

	archivo >> NIF;
	while(NIF != CENTINELA && listaClientes.contador < MAXCLIENTES){
	archivo >> producto.codigo;
	archivo >> producto.precio;
	archivo >> producto.unidades;
	
	if(!encuentra(listaClientes, NIF, pos))
			insertaCliente(listaClientes, NIF, producto);
	else
		insertaProd(listaClientes.clientes[pos]->listaProductos, producto);
		
	listaClientes.contador++;

	archivo >> NIF;
	}
}



void muestra(const tListaClientes & listaClientes){
	for(int i = 0; i < listaClientes.contador; i++){
		cout << "Cliente: " << listaClientes.clientes[i]->NIF;
		muestra(listaClientes.clientes[i]->listaProductos);
		cout <<"---------------------------------" << endl;
			system("pause");
		}
	cout << "Ventas totales: " << totalVentas(listaClientes) << endl;
	system("pause");
}


void destruye(tListaClientes & listaClientes){
	for(int i = 0; i < listaClientes.contador; i++){
	destruye(listaClientes.clientes[i]->listaProductos);
	delete[i] listaClientes.clientes[i];
	}
}