#include "ListaProductos.h"

void inicializar(tListaProd & listaProductos){
	listaProductos.productos = new tProducto [MAXPRODUCTOS];
	listaProductos.contador = 0;
}

bool insertaProd(tListaProd & listaProductos,const tProducto & producto){
	bool ok = false;
	if(listaProductos.contador < MAXPRODUCTOS){
		listaProductos.productos[listaProductos.contador] = producto;
		listaProductos.contador++;
		ok = true;
	}
	return ok;
}

void muestra(const tListaProd & listaProductos){
	for (int i = 0; i < listaProductos.contador; i++){
		muestra(listaProductos.productos[i]);
	}
}

double totalVentas(const tListaProd & listaProductos){
	double total = 0;

	for(int i = 0; i < listaProductos.contador; i++){
		total += totalVenta(listaProductos.productos[i]);
	}
	return total;
}

void destruye(tListaProd & listaProductos){
	delete[] listaProductos.productos;
}
