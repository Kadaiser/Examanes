/**
- El fichero modificaciones.txt incluye también la hora de cada modificación en el formato HH:MM:SS. Se debe utilizar el tipo tHora, estructura con tres números enteros, y implementar el correspondiente operador de orden operator< (que se utiliza en el siguiente punto).

- Apartado f) Implementar una función mostrarModificaciones que muestre las modificaciones del día, ordenadas por hora, y en el formato que se indica mediante este ejemplo:

            12:35:23 Venta de 5 unidad(es) de lata-coca-cola (codigo 234)

*/






#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//CONSTANTES GLOBALES

const string INVENTARIO = "inventario.txt";
const string INVENTARIO2 = "inventario2.txt";
const int MAXPRODUCTOS = 100;
const int MAXMODIFICACIONES = 100;
const int CENTINELA = -1;
const string MODIFICACIONES = "modificaciones.txt";

//ESTRUCTURA DE DATOS

typedef struct {
int codigoProducto;
string nombreProducto;
int numeroUnidades;
double precioUnidad;
}tProducto;


typedef struct {
tProducto elementos[MAXPRODUCTOS];
int contador;
}tInventario;




typedef enum {venta, compra, devolucion} tOperacion;

typedef struct{
	long double hora;
	long double minutos;
	long double segundos;
}tMomento;

typedef struct {
int codigoProducto;
tOperacion codigoOperacion;
int	numeroUnidades;
tMomento momento;
}tModificacion;

typedef struct{
tModificacion elementos[MAXMODIFICACIONES];
int contador;
}tMovimientos;


//CABECERA DE FUNCIONES
bool leerProducto(ifstream & fichero, tProducto & producto);
bool leerModificacion(ifstream & fichero, tModificacion & modificacion);
bool cargaListaProductos(tInventario & Inventario);
bool cargaListaMovimientos(tMovimientos & movimientos);
tOperacion charToOperacion(const char operacion);
bool carga(tInventario & inventario, tMovimientos & movimientos);
bool guardarInventario(const tInventario & inventario);
void escribeProducto(ofstream & fichero,tProducto producto);
string operacionToString(tOperacion operacion);
void ordenarPorFecha(tMovimientos & movimientos);
bool operator< (tMomento hora1, tMomento hora2);
void mostrarProducto(const tInventario & inventario,const tMovimientos & movimientos);
void mostrarMovimiento(const tModificacion & modificacion, const tInventario & inventario);
bool buscarCodigo(const tInventario &inventario, int codigo,int &pos);
string horaToString(const tMomento & momento);

//PROGRAMA PRINCIPAL
int main(){
	tInventario inventario;
	tMovimientos movimientos;
	inventario.contador = 0; //Por defecto y hasta que se cargue, se consiera el inventario vacio
	movimientos.contador = 0;
	if(carga(inventario,movimientos)){
		ordenarPorFecha(movimientos);
		mostrarProducto(inventario,movimientos);

	}
	else{
		cout << "Hubo un problema al cargar alguno de los ficheros" << endl;
	}

	if(guardarInventario(inventario)){
		cout << "El inventario se guardo correctamente en el fichero inventario2.txt" <<endl;
	}
	else{
		cout << "Se produjo un error al guardar inventario en el fichero inventario2.txt"<<endl;
	}
	system("pause");
	return 0;
}



//FUNCIONES Y PROCEDIMIENTOS

bool carga(tInventario & inventario, tMovimientos & movimientos){
	if(cargaListaProductos(inventario) && cargaListaMovimientos(movimientos)){
	return true;
	}
	return false;
}

bool cargaListaProductos(tInventario & inventario){
	ifstream fichero;
	
	fichero.open(INVENTARIO);
	if(fichero.is_open()){
		while (leerProducto(fichero, inventario.elementos[inventario.contador])){
		inventario.contador++;
		}
		fichero.close();
	}
	else{
	return false;
	}
	return true;
}

/**
* rellena los campos de una estructura de datos tProducto segun lo leido en un fichero
*/
bool leerProducto(ifstream & fichero, tProducto & producto){
	fichero >> producto.codigoProducto;
	if(producto.codigoProducto == CENTINELA){
	return false;
	}
	else{
		fichero >> producto.nombreProducto;
		fichero >> producto.numeroUnidades;
		fichero >> producto.precioUnidad;
	}
	return true;
}

bool cargaListaMovimientos(tMovimientos & movimientos){
	ifstream fichero;
	
	fichero.open(MODIFICACIONES);
	if(fichero.is_open()){
		while(leerModificacion(fichero, movimientos.elementos[movimientos.contador])){
		movimientos.contador++;
		}
		fichero.close();
	}
	else{
	return false;
	}
	return true;
}

bool leerModificacion(ifstream & fichero, tModificacion & modificacion){
	char operacion;

	fichero >> modificacion.codigoProducto;
	if(modificacion.codigoProducto == CENTINELA){
	return false;
	}
	else{
		fichero >> operacion;
		modificacion.codigoOperacion = charToOperacion(operacion);
		fichero >> modificacion.numeroUnidades;
		fichero >> modificacion.momento.hora;
		fichero >> operacion;
		fichero >> modificacion.momento.minutos;
		fichero >> operacion;
		fichero >> modificacion.momento.segundos;
	}
	return true;
}

tOperacion charToOperacion(char operacion){
tOperacion clase;

	if(operacion == 'V') clase = venta;
	else if(operacion == 'C') clase = compra;
	else clase = devolucion;
	
return clase;
}

bool guardarInventario(const tInventario & inventario){
	int cont = 0;
	ofstream fichero;
	
	fichero.open(INVENTARIO2);
	if(fichero.is_open()){
	while(cont < inventario.contador){
		escribeProducto(fichero, inventario.elementos[cont]);
		cont++;
		}
		fichero << -1;
		fichero.close();
		return true;
	}
	else{
		return false;
	}
}
void escribeProducto(ofstream & fichero, tProducto producto){
	fichero << producto.codigoProducto;
	fichero << " ";
	fichero << producto.nombreProducto;
	fichero << " ";
	fichero << producto.numeroUnidades;
	fichero << " ";
	fichero << producto.precioUnidad;
	fichero << endl;
}


string operacionToString(tOperacion operacion){
string clase;
	if(operacion==venta) clase = "venta";
	else if(operacion==compra) clase = "compra";
	else clase = "Devolucion";
return clase;
}

void ordenarPorFecha(tMovimientos & movimientos){
	bool intercambio = true;
	int i = 0;
	
	while((i<movimientos.contador) && intercambio){
		intercambio = false;
		for (int j = movimientos.contador-1; j > i; j--){
			if(movimientos.elementos[j].momento < movimientos.elementos[j-1].momento ){
				tModificacion tmp;
				tmp = movimientos.elementos[j];
				movimientos.elementos[j] = movimientos.elementos[j-1];
				movimientos.elementos[j-1] = tmp;
				intercambio = true;
			}
		}
		if (intercambio) i++;
	}
}
bool operator< (tMomento hora1, tMomento hora2){
	bool esMenor = true;
		if(hora2.hora < hora1.hora)
			esMenor = false;
		else if(hora2.hora == hora1.hora){
			if(hora2.minutos < hora1.minutos)
				esMenor = false;
			else if(hora2.minutos == hora1.minutos){
					if(hora2.segundos < hora1.segundos) 
					esMenor = false;
				}
			}
		
	return esMenor;
}


//Funciones para mostrar por consola los movimientos del dia

void mostrarProducto(const tInventario & inventario,const tMovimientos & movimientos){
	for(int i= 0; i < movimientos.contador; i++)
		mostrarMovimiento(movimientos.elementos[i], inventario);
}

void mostrarMovimiento(const tModificacion & modificacion, const tInventario & inventario){
	int pos;
	cout << horaToString(modificacion.momento) << " Se ha realizado una operacion de " << operacionToString(modificacion.codigoOperacion);
	cout << " de " << modificacion.numeroUnidades << " unidad(es) de ";
	if(buscarCodigo(inventario, modificacion.codigoProducto, pos)){
		cout << inventario.elementos[pos].nombreProducto << "   Codigo(" << modificacion.codigoProducto << ")" << endl;
	}
	else{
		cout :"ERROR (Codigo producto no encontrado)";
	}
}

bool buscarCodigo(const tInventario & inventario, int codigo, int &pos){
	int ini=0, fin = inventario.contador-1, mitad;
	bool encontrado = false;
	
	while((ini <= fin) && !encontrado){
		mitad = (ini + fin) / 2;
		if(codigo < inventario.elementos[mitad].codigoProducto)
			fin = mitad - 1;
		else if(inventario.elementos[mitad].codigoProducto < codigo)
			ini = mitad +1;
		else
			encontrado = true;
	}
	if(encontrado) pos = mitad;
	else pos = ini;
	return encontrado;
}

string horaToString(const tMomento & momento){
	string str;
	str = to_string(momento.hora);
	str += ':';
	str +=to_string(momento.minutos);
	str += ':';
	str +=to_string(momento.segundos);
	return str;
}

string operacionToString(const tOperacion & operacion){
	string str;
	if(operacion == venta) str = "venta";
	else if(operacion == compra) str = "compra";
	else str = "devolucion";
	return str;
}