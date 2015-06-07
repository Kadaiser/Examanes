#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "ListaClientes.h"

void inicializar(tListaClientes & listaClientes){
	for(int i = 0; i < listaClientes.contador; i++)
	listaClientes.clientes[i] = nullptr;

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


bool insertaCliente(tListaClientes & listaClientes, string NIF, const tProducto & producto){
	bool ok = false;
	int pos;
	if(listaClientes.contador < MAXCLIENTES){

		if(!encuentra(listaClientes, NIF, pos)){

			tCliente cliente;
			cliente.NIF = NIF;
			inicializar(cliente.listaProductos);							//Se genera un cliente

		for(int i = listaClientes.contador; i > pos; i--){				//Se hace hueco en la lista desde pos
			listaClientes.clientes[i] = listaClientes.clientes[i-1];
		}

		listaClientes.clientes[pos] = new tCliente (cliente);										//Se inclulle al cliente generado en la poscion pos

		listaClientes.clientes[pos] -> listaProductos.productos[0] = producto; 	//se inclulle el producto en la lista de productos del cliente;
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
		
			system("pause");	//Se usa para comprobar usuario a usuario la carga, puede borrarse (ha de borrarse antes de entregar)
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
