#ifndef LISTAPRODUCTOS_H
#define	LISTAPRODUCTOS_H

#include "Productos.h"

const int MAXPRODUCTOS = 50;

typedef struct{
tProducto* productos;
int contador;
}tListaProd;



/**
* Inicializa la lista de prodcutos
*/
void inicializar(tListaProd & listaProductos);

/**
* Dada una lista de productos y un producto a�ade el producto al final de la lista. Si la lista est� llena,
*  se ignora el nuevo producto.
*/
bool insertaProd(tListaProd & listaProductos,const tProducto & producto);

/**
* Dada una lista de productos muestra sus productos en la pantalla.
*/
void muestra(const tListaProd & listaProductos);

/**
* Dada una lista de productos devuelve el total de esas ventas.
*/
double totalVentas(const tListaProd & listaProductos);

/**
* Dada una lista de productos libera la memoria din�mica que usa.
*/
void destruye(tListaProd & listaProductos);

#endif
