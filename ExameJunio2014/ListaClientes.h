#ifndef LISTACLIENTES_H
#define	LISTACLIENTES_H

#include<fstream>
#include<iostream>
#include<string>

#include "ListaProductos.h"

const int MAXCLIENTES = 100;
const string CENTINELA = "XXX";

typedef struct{
	string NIF;
	tListaProd listaProductos;
}tCliente;

typedef struct{
tCliente* clientes[MAXCLIENTES];//Array estatico de punteros
int contador;
}tListaClientes;

/**
* Inicializaliza la lista de clientes
*/
void inicializar(tListaClientes & listaClientes);

/**
* Dada una lista de clientes y un NIF localiza en la lista un cliente con ese NIF.
* Har� uso del algoritmo recursivo de b�squeda binaria.
*/
bool encuentra(const tListaClientes & listaClientes, string NIF, int & pos);

/**
* Dada una lista de clientes devuelve el total de las ventas.
*/
double totalVentas(const tListaClientes & listaClientes);

/**
* Dada una lista de clientes, un NIF y un producto, a�ade un nuevo cliente con ese NIF (y ese producto como primera venta) en la lista de clientes.
* La lista de clientes debe seguir estando ordenada por NIF tras insertar.
* Si la lista est� llena, se ignora el nuevo cliente.
*/
bool insertaCliente(tListaClientes & listaClientes, string ID, const tProducto & producto);

/**
* Dada una lista de clientes, carga en ella la informaci�n de un archivo datos.txt
* que contiene en cada l�nea la informaci�n de una venta: NIF del cliente, c�digo de producto,
* precio y unidades vendidas.
*/
void carga(tListaClientes & listaClientes, ifstream& archivo);

/**
* Dada una lista de clientes muestra sus ventas en la pantalla.
* Termina mostrando el total de las ventas.
*/
void muestra(const tListaClientes & listaClientes);

/**
*  Dada una lista de clientes libera la memoria din�mica que utiliza.
*/
void destruye(tListaClientes & listaClientes);

#endif
