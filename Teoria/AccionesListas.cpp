/**
*	Las funciones aqui indicadas se usan como plantillas respecto del siguiente ejemplo de interfaz de programa
*/

const int MAX_ELEMENTOS = 100;

typedef struct{
	int dia;
	int mes;
	int anio;
}tFecha;		//No siempre se maneja como en una estructura muchas veces se maneja directamente como un string.

typedef enum {grupo1, grupo2, grupo3, grupo4} tGrupo;

typedef struct{
	string propiedad1;
	int propiedad2;
	bool propiedad3;
	tGrupo grupo;
	tFecha fecha;
}tElemento;

typedef struct{
	tElemento elementos[MAX_ELEMENTOS];
}tListaElementos;

/**---------------------------------------------------------------------------------------------------------------*/

/**
*	CARGAR UNA LISTA CON CONTADOR
* Dada un fichero con elementos separados por saltos de linea,
*  los guarda en una estructura de datos.
* (OBVSERVACION) Lo normal es que una funcion "leer" del modulo "elemento", se encargue de
*  constituir en un auxiliar tElemento una linea de informacion para que la
* sub-funcion  "insertar" lo incluya en la lista. Esta funcion "cargar" es util si
* el fichero ya viene ordenado o no se necesita que este ordenada, para el resto
* de casos usaremos habitualmente una insercion ordenada.
*/

bool cargar(tListaElementos & lista){
	bool ok = false;
	ifstream fichero;

	fichero.open("fichero.txt");
	if(fichero.is_open()){
		while(insertar(fichero, lista.elementos[lista.contador])){
		}
		fichero.close();
		ok = true;
	}
	return ok;
}


/**
*	GUARDAR UNA LISTA CON CONTADOR
* Dada una lista con elementos (NO PUNTEROS), la guarda en un ficehro de texto.
*/
void guardar(const tListaElementos & lista){
	int cont = 0;
	ofstream fichero;

	fichero.open("fichero.txt");
	if(fichero.is_open()){
	while(cont < lista.contador){
		escribeElementos(fichero, lista.elementos[cont]);
		cont++;
		}
		fichero << CENTINELA; //Normalmente se usa un centinela como marca EOF
		fichero.close();
	}
}

/**
*	INICIALIZAR LISTA CON CONTADOR
* Dada una lista con elementos (NO PUNTEROS), la inicializa.
*/
void inicializar(tListaElementos & lista) {
	lista.contador = 0;
}

/**
*	BUSQUEDA BINARIA EN LISTAS CON CONTADOR
* Dada una lista con elementos (No importa si son punteros o estructuras),realiza
* una busqueda a partir de una propiedad de un elemento.
*/
bool Buscar(const tListaElementos & lista, tDato propiedad, int & pos) {
   int ini = 0, fin = lista.contador - 1, mitad;
   bool encontrado = false;

   while ((ini <= fin) && !encontrado) {
      mitad = (ini + fin) / 2;

      if (propiedad < lista.elementos[mitad].propiedad)
         fin = mitad - 1;

      else if (lista.elementos[mitad].propiedad < propiedad)
         ini = mitad + 1;

      else
         encontrado = true;
   }
   if (encontrado) pos = mitad;	//Si lo encuentra, "pos" almacena el valor del inidice en la lista donde se encuentra el elemento buscado
   else pos = ini;				//Si no lo encuentra, nos indica donde DEBERIA ESTAR
  return encontrado;
}

/**
*	DESPLAZAMIENTO DE ELEMENTOS DE UNA LISTA PARA HACER HUECO EN LA INSERCCION
* Dada una lista con elementos (No importa si son punteros o estructuras), se hace
* hueco desde la posicion del array en el parametro "pos", (Se usa para inseerciones ordenadas).
*/
void desplazarDerecha(tListaElementos& lista, int pos) {
	for(int i = lista.contador; i > pos; i--) {
		lista.elementos[i] = lista.elementos[i - 1];	//Recorremos desde el final de la lista hacia pos desplazando un hueco los elementos
	}
}


/**
*	INSERCION ORDENADA DE ELEMENTOS EN LA LISTA
* Dada una lista con elementos, se inserta un elemento en la poscion que le corresponda en base
* a un criterio de ordenacion (el segundo parametro), para que esta funcion realize su accion
* es imprescindible el uso de las funciones "Buscar" y "desplazarDerecha".
*/
void insercionOrdenada(tListaElementos & lista, tDato propiedad, const tElemento & elemento) {

	if (lista.contador < MAX_ELEMENTOS) {
		int pos;

		if (!Buscar(lista, propiedad, pos)) { //vease que no se inserta si ya existe!!
			desplazarDcha(lista, pos);
			lista.elementos[pos] = elemento;
			lista.contador++;
		}
	}
}

/**
*	INSERCION DE ELEMENTOS AL FINAL DE LA LISTA
* Dada una lista con elementos no ordenada, (o que el fichero desde donde se cargan TENEMOS la certeza de que los elementos
* ya esta ordenados)y un elemento, se inserta dicho elemento al final de la lista y se amplia el contador;
*/
void insertar(tListaElementos& lista,const tElemento& elemento){
	if (lista.contador == MaxModelos)
		cout << "Error: Lista de elementos llena\n";
	else {
		lista.elementos[lista.contador] = elemento;
		lista.contador++;
		}
}


/**
*	ORDENACION "Bubble Sort" DE ELEMENTOS EN UNA LISTA CON CONTADOR
*	Dada unalista la ordena segun una propiedad dada (en este caso una estructura tFecha, 3 int AA/MM/DD,
* hay que tener en cuenta la creacion de un operator< que determine cuando una fecha es menor a otra y devuelva true/false).
*/
void ordenarPorFecha(tListaElementos& lista){
	bool intercambio = true;
    int i = 0;
	while ((i < lista.cont - 1) && intercambio) {
		intercambio = false;
		for (int j = lista.contador - 1; j > i; j--) {
			if (lista.elementos[j].fecha < lista.elementos[j-1].fecha) {
				tAlquiler tmp;
				tmp = lista.elementos[j];
				lista.elementos[j] = lista.elementos[j-1];
				lista.elementos[j-1] = tmp;
				intercambio = true;
			}
		}
		if (intercambio) i++;
	}
}
/**
*	FUNCION OPERATOR< PARA DETERMINAR SI UN DATO TIPO FECHA ES MENOR QUE OTRO
*	Dados dos datos tFecha, devuelbe TRUE si el primer elemento es menor que el segundo,
*	FALSE en caso contrario, esta funcion se vuelve util si el criterio de ordenacion es en base
*	a una propiedad que a su vez es una estructura.
*/

bool operator< (tFecha fecha1, tFecha fecha2){
	bool esMenor = true;
		if(fecha2.anio < fecha1.anio)
			esMenor = false;
		else if(fecha2.anio == fecha1.anio){
			if(fecha2.mes < fecha1.mes)
				esMenor = false;
			else if(fecha2.mes == fecha1.mes){
					if(fecha2.dia < fecha1.dia)
					esMenor = false;
				}
			}
	return esMenor;
}


/**
*	FUNCION RECURSIVA DE MOSTRAR UNA LISTA CON CONTADOR
*	Se usa lenguaje recursivo para mostar los elementos de una lista de elemtos
*	(ojo!) La funcion "muestra" pertenece a un modulo distinto cuya funcion es mostrar el 
*	contenido de un UNICO elemento.
*/
void muestraLista(const tListaElementos & lista, int pos) {
	if (pos < lista.contador){
		muestra(lista.elementos[pos]);
		muestraLista(lista, pos + 1); //Si se intecambia con la linea superior, se muestra la lista, en orden descendente desde el final.
	}
}
