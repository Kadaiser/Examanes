#include "productos.h"

void muestra(const tProducto & producto){
	cout << producto.codigo << " - " << producto.unidades << " x " << producto.precio << " $ = " << totalVenta(producto) << " $" << endl; 
}

double totalVenta(const tProducto & producto){
	return producto.unidades*producto.precio;
}
