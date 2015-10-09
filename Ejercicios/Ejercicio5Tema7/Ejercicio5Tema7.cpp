using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>

const int MaxModelos = 20;
const int MaxAlquileres = 100;

typedef struct {
   int codigo;
   string nombre;
} tModelo;

typedef struct {
   tModelo elems[MaxModelos];
   int cont;
} tListaModelos;


typedef struct {
   int codigo;
   string fecha;
   int dias;
} tAlquiler;

typedef struct {
   tAlquiler elems[MaxAlquileres];
   int cont;
} tListaAlquileres;


bool leerModelo(ifstream& archivo,tModelo& modelo);
bool leerModelos(tListaModelos& lista);
void anadirModelo(tListaModelos& lista,const tModelo& modelo);
bool buscarModelo(const tListaModelos& modelos, int codigo,int& pos);
bool leerAlquileres(tListaAlquileres& lista);
void anadirAlquiler(tListaAlquileres& lista,const tAlquiler& alquiler);
void ordenarPorFecha(tListaAlquileres& lista);
void mostrarAlquileres(const tListaAlquileres& alquileres,const tListaModelos& modelos);
bool leerAlquiler(ifstream& archivo,tAlquiler& alquiler);
void mostrarAlquiler(const tAlquiler& alquiler,const tListaModelos& modelos);



//PROGRAMA PRINCIPAL

int main(){
	tListaModelos modelos;
	tListaAlquileres alquileres;

	if (!leerModelos(modelos))
		cout << "Error leyendo coches.txt\n";
	else{
		if (!leerAlquileres(alquileres))
			cout << "Error leyendo rent.txt\n";
		else {
			ordenarPorFecha(alquileres);			//vease que se pasa la lista entera para ser reordenada sin usar una lista auxiliar
			mostrarAlquileres(alquileres,modelos);
			system("pause");
		}
	}
}



//FUNCIONES DE LECTURA DE MODELOS DEL FICHERO DE MODELOS
bool leerModelos(tListaModelos& lista){
	ifstream archivo;
	bool ok = true;
	tModelo modelo;

	lista.cont = 0;							//Por defecto se considera que la lista esta vacia hasta que se llene de elementos
	archivo.open("coches.txt");
	if (!archivo.is_open())
		ok = false;
	else {
		while (leerModelo(archivo,modelo))	// Mientras el metodo NO lea un centinela, devuelve true y almacena en la variable auxiliar "modelo" los datos del mismo
			anadirModelo(lista,modelo);		//Incluiremos los datos del auxiliar "modelo" en una posicion de la lista de modelos e incrementamos el contador de la lista
	}
	archivo.close();
	return ok;
}

bool leerModelo(ifstream& archivo,tModelo& modelo){
	bool ok = false;						//Por defecto se encuentra el centinela
	archivo >> modelo.codigo;
	if (modelo.codigo != -1){
		getline(archivo,modelo.nombre);		//Alamacenamos el nombre del modelo despues de verificar que su codigo no era un centinela
		ok = true;							//Cambiamos la condicion de centinela diciendo que lo que se ha leido era un modelo
	}
	return ok;
}

void anadirModelo(tListaModelos& lista,const tModelo& modelo){
	if (lista.cont == MaxModelos)					//se comprueba que el estado del contador de elementos no haya llegado a su tope
		cout << "Error: Lista de modelos llena\n";
	else {
		lista.elems[lista.cont] = modelo;		//la variable auxiliar "modelo" de la funcion padre, se pasa por lectura para que sea copiado en la lista de modelos
		lista.cont++;							//Incrementa la cantidad de elementos de la lista
	}
}


//FUNCIONES DE LECTURA DEL FICHERO DE ALQUILERES

bool leerAlquileres(tListaAlquileres& lista){
	ifstream archivo;
	bool ok = true;
	tAlquiler alquiler;

	lista.cont = 0;
	archivo.open("rent.txt");
	if (!archivo.is_open())
		ok = false;									//solo ante fallos de apertura del fichero
	else {
		while (leerAlquiler(archivo,alquiler))		// Mientras el metodo no identifique al centinela, se almacena en una variable auxiliar "alquiler" cada uno de los campos leidos en la linea
			anadirAlquiler(lista,alquiler);			//Pasamos dicha variable para que se incluya en la lista de alquileres y se incrementa el contador de elementos de la lista en cuestion
	}
	archivo.close();
	return ok;
}
bool leerAlquiler(ifstream& archivo,tAlquiler& alquiler){
	bool ok = false;
	archivo >> alquiler.codigo;
	if (alquiler.codigo != -1){
		archivo >> alquiler.fecha;					//Por norma general , las fehcas se almacenan en estrucuras de elementos enteros tipo DD/MM/AA, pero aqui se manejan como un string tipo AA/MM/DD
		archivo >> alquiler.dias;
		ok = true;
	}
	return ok;
}

void anadirAlquiler(tListaAlquileres& lista,const tAlquiler& alquiler){
	if (lista.cont == MaxAlquileres)
		cout << "Error: Lista de alquileres llena\n";
	else {
		lista.elems[lista.cont] = alquiler;			//Se recibe la variable auxiliar "alquiler" de la funcion padre para ser incluida en la lista de alquileres
		lista.cont++;								//Se incrementa la cantidad de elementos de la lista
	}
}

//FUNCION PARA ORDENAR LA LISTA DE ALQUILERES
/** Cabe destacar que el metodo de ordenacion solo compara tipo string, no seria util para un metodo que manejara una estructura de fechas por campos de enteros.
*/

void ordenarPorFecha(tListaAlquileres& lista){	
	bool inter = true;												//Por defecto antes de entrar al bucle se intercambian de posicion los elementos de la lista (siempre de dos en dos)
    int i = 0;	
	while ((i < lista.cont - 1) && inter) {							//hasta que recorramos todos los elementos de la lista o no sea necesario intercambiarlos
		inter = false;												//Una vez dentro del bucle consideramos que hay que cambiarlos
		for (int j = lista.cont - 1; j > i; j--) {					//Desde el final de la lista hasta que 
			if (lista.elems[j].fecha < lista.elems[j-1].fecha) {	//se comparan los campos de la fecha (al ser tipo string ordenados por AA/MM/DD, la correspondiente conversion del char a numero de la tabla ASCII realmente nos devuelve quien es menor )
				tAlquiler tmp;										//auxiliar para el intercambio de alquileres en la lista
				tmp = lista.elems[j];								//se copia el elemento de la "derecha"  al auxiliar
				lista.elems[j] = lista.elems[j-1];					//se copia en el elemento de la "derecha" el de la "izquierda"
				lista.elems[j-1] = tmp;								//se copia en el elemento de la "izquierda" el contenido del auxiliar
				inter = true;										//se considera que hay que cambiar de posicion
			}
		}
		if (inter) i++;		//Si se cambio el estado del intercambio a cierto en el recorrido del for, incrementamos el contador del bucle.
	}
}


//FUNCIONES DE SALIDA POR CONSOLA DE LOS FICHEROS

void mostrarAlquileres(const tListaAlquileres& alquileres,const tListaModelos& modelos){
	for (int i = 0; i < alquileres.cont; i++)			//se recorre toda la lista de alquilieres mostrando linea a linea la informacion
		mostrarAlquiler(alquileres.elems[i],modelos);	//Se combina la lista de alquileres con la lista de modelos para mostar la linea en cuestion
}

void mostrarAlquiler(const tAlquiler& alquiler,const tListaModelos& modelos){
	int pos;
	cout << alquiler.fecha << " "; 
	if (buscarModelo(modelos,alquiler.codigo,pos))				//Se compara en la lista de modelos el codigo del alquiler para conocer su nombre, nos devuelve la posicion en la lista de modelos del codigo que buscamos
		cout << setw(20) << left << modelos.elems[pos].nombre 	//se escribe el nombre del modelo acudiendo a la posicion de la lista segun el codigo del alquiler
			 << " " << alquiler.dias << " dia(s)\n"; 
	else
		cout << "Error: Modelo inexistente\n";					//Si no existiera un modelo en la lista que corresponda con el codigo
}


/**
* Esta funcion esta basada en el esquema de funciones de busquedas binarias en una lista YA ORDENADA del tema 7
*/
bool buscarModelo(const tListaModelos& modelos, int codigo,int& pos) {
   int ini = 0, fin = modelos.cont - 1, mitad;			//para la busqueda es necesario habblar del final del segmento de longitud n-1 (ya que si hay 6 elementos en la lista, recorreremos desde 0 a 5, no de 1 a 6)
   bool encontrado = false;								//por defecto se considera que no se ha encontrado el codigo en cuestion ni su posicion en la lista
   while ((ini <= fin) && !encontrado) {				//mientras que NO encontramos el codigo y no hemos excedido el numero de elementos de la lista
      mitad = (ini + fin) / 2;							//Dividimos entre 2 la longitud del segmento en el que buscar 
      if (codigo < modelos.elems[mitad].codigo) 		//Si el codigo de la funcion padre es menor que el que se encuentra en esa mitad del segmento, entonces decrementamos el contador de fin hacia la izquierda del segmento en 1.
         fin = mitad - 1;
      else if (modelos.elems[mitad].codigo < codigo) 	//Si por el contrario es el codigo en esa posicion de la lista es menor que el codigo, significa que el elemento que buscamos esta hacia la derecha de la posicion, e incrementamos el contador de inicio en 1
         ini = mitad + 1;
      else 
         encontrado = true;								//Si  no es mayor ni menor, entonces es que es el mismo, y por tanto lo hemos encontrado
   }
   if (encontrado) pos = mitad;							//Si lo hemos encontrado, entonces la variable "mitad" posee la posicion en la que se encuentra el codigo que buscabamos
   else pos = ini;										//Si no lo encontramos, entonces la variable "ini" posee la posicion que deberia ocupar el codigo que buscabamos respecto de los que ya existen.
	
  return encontrado;
}




