#ifndef listacli_h
#define listacli_h

#include "cliente.h"

const int MaxCli = 100;
const double Fijo = 23.95, PorDia = 32.67;
const int IVA = 21;

typedef tCliente tArrayCli[MaxCli];
typedef struct {
   tArrayCli clientes;
   int cont;
} tListaClientes;

void insertarCliente(tListaClientes &lista, tCliente cliente);
int buscarCliente(tListaClientes lista, string nif);
void cargar(tListaClientes &lista, bool &ok);
void listado(tListaClientes lista);

#endif
