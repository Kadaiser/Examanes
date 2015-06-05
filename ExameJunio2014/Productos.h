#ifndef PRODUCTOS_H
#define	PRODUCTOS_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


typedef struct{
string codigo;
double precio;
int unidades;
}tProducto;

/**
* Dado un producto muestra su información en la pantalla 
* con el siguiente formato (código – unidades x precio = total)
*/
void muestra(const tProducto & producto);

/**
* Dado un producto devuelve el total de la venta de ese producto.
*/
double totalVenta(const tProducto & producto);


#endif