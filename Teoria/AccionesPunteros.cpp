/**
*	Las funciones aqui indicadas se usan como plantillas respecto del siguiente ejemplo de interfaz de programa
*/
const int MAXELEMENTOS = 200;
const int CAP_INICIAL = 100;

typedef struct{
	int dia;
	int mes;
	int anio;
}tFecha;

typedef enum {grupo1, grupo2, grupo3, grupo4} tGrupo;

typedef struct{
	tFecha fecha;
	tGrupo grupo;
	int propiedad1;
	string propiedad2;
	bool propiedad3;
}tElemento;

typedef struct{
	tElemento* elementos; //Array dinamico
	int contador;
	int capacidad;
}tListaElementos;

/**---------------------------------------------------------------------------------------------------------------*/

/**
*	INICIALIZAR UNA LISTA DE PUNTEROS ESTATICA
* Dada una lista con punteros, se generan tantos punteros como capacidad de la lista
* que apuntan a datos estructurados, SE INICILIZAN A NULLPTR, y solo durante inserciones
* se generan nuevas asignaciones de memoria (new tElemento).
*/

void inicializar (tListaElementos & lista){
	for(int i = 0; i < MAXELEMENTOS; i++)
	lista.elementos[i] = nullptr;

	lista.contador = 0;
}



/**
*	INICIALIZAR UNA LISTA DE PUNTEROS CON CONTADOR (NO REDIMENSIONABLE);
* Dada una lista con punteros, se generan tantos punteros como capacidad de la lista
* que apuntan a datos estructurados.
*/

void inicializar (tListaElementos & lista){
	for(int i = 0; i < CAP_INICIAL; i++)
	lista.elementos[i] = new tElemento;

	lista.contador = 0;
}


/**
*	INICIALIZAR UNA LISTA DE PUNTEROS CON CONTADOR CON CAPACIDAD DE REDIMENSIONAMIENTO
* Dada una lista con punteros, se generan tantos punteros como capacidad de la lista
* que apuntan a datos estructurados. Esta funcion se reutiliza durante una demiension de
* la lista (pasando como parametro la lista auxiliar).
*/
void inicializar (tListaElementos & lista,int capacidad){
	lista.elementos = new tElemento [capacidad];
	lista.contador = 0;
	lista.capacidad = capacidad;
}

/**
*	REDIMENSIONA UNA LISTA DE PUNTEROS CON CONTADOR.
* Dada una lista con punteros, se genera una lista auxiliar con mayor capcidad de espacio.
* Se sobreescibe la vieja lista una vez se han copiado todos los punteros en la nueva.
*/

void redimensionar (tListaElementos &lista){
	int i = 0;
	int nuevaCapacidad = (listaRegistros.capacidad * 2); //El cietrio de redimensionamiento puede ser cualquiera...

	tListaRegistros nuevaLista; //crear nueva estructura con  array

	inicializar(nuevaLista, nuevaCapacidad); //Se inicializa la nueva lista con la nueva capacidad

	while ( i < lista.contador ){			//copiar viejo a nuevo
		insertar(nuevaLista, lista.elementos[i++]);  //En este caso puede ser una insercion lineal (no requiere ordenacion).
	}
	lista = nuevaLista; //Se sobreescriben los punteros de la vieja lista
}

/**	
*	FUNCION DE CARGA DE FICHERO CON ELEMENTOS REPETIDOS
*	este esquema se usa en listas de elementos que integras a su vez arrays dinamicos con sub-elementos,
* de manera que en la lista de elementos solo se insertan elementos si su identificador no existe,
* en caso de existir se inserta el sub-elemento en el array dinamico de ESE elemento.
* (OJO!) Esta funcion usa una funcion de "Busqueda Binaria" para determinar donde se inserta un nuevo elemento,^
* o en que elemento se inserta el sub-elemento. 
*
*/
void carga (tListaElementos &lista, ifstream & archivo){
	tSubElemento subElemento;
	string propiedad1;
	int pos;

	archivo >> propiedad1;
	while(NIF != CENTINELA && lista.contador < MAXALUMNOS){

		crearSubElemento(fecha, nota, subElemento);
		
			if(!busca(lista, NIF, pos)){
				insertar(lista, NIF, subElemento, pos);
			}
			else
				insertarSubElemento(lista.elementos[pos] ->subLista, subElemento);

			archivo>> propiedad1;
	}

}

/**
*	FUNCION DE INERCION DE UN ELEMENTO EN LA LISTA
*	Se incluye un elmento en la lista de manera ordenada, inicialiando tambien 
* 	el arraydinamico anidado en el elemento e incluyendo el subelemento a ese array
*/

bool insertar(tListaElementos &lista, string propiedad1, const tSubElemento & subElemento, int pos){
	bool ok = false;

	if(listaClientes.contador < MAXCLIENTES){

			tElemento elemento;
			elemento.propiedad1 = propiedad1;
			inicializar(elemento.subLista);							//Se genera un Elemento, eso implica inicializar su subLista

		for(int i = lista.contador; i > pos; i--){				//Se hace hueco en la lista desde pos
			lista.elementos[i] = lista.elementos[i-1];
		}

		lista.elementos[pos] = new tCliente (cliente);										//Se inclulle al elemento generado en la poscion pos

		lista.elementos[pos] -> subLista.subElementos[0] = subElemento; 	//se inclulle el subElemento en la subLista de subElementos del elemento;
		lista.elementos[pos] -> subLista.contador++;

		lista.contador++;
		ok =true;
	}
	else
		cout << "Error lista de clientes llena" << endl;

	return ok;
}

/**
*	DESTRUCCION DE UNA LISTA DE UNA LISTA DE PUNTEROS CON CONTADOR
* Dada una lista de punteros con contador destruye las asignaciones de
* esos punteros. (ojo! las estructuras a las que apuntan estos punteros
* se consideran que no tienen anidadas otras listas con punteros).
*/
void destruye(tListaElementos & lista){
	delete[] lista.elementos;
	lista.elementos = nullptr;	//Linea de atrezzo
	lista.contador = 0;			//Linea de atrezzo
}

void destruye(tListaElementos & lista) {	//En este caso se destruyen los datos anidaddos de cada elemento y luego el elemento en si
	for(int i = 0; i < lista.conadort; i++){
		delete[] lista.elementos[i].punteros;	//primero se eliminan los punteros anidados de cada elemento
		delete lista.elementos[i];				//Despues se destruye el propio elemento y se pasa al siguiente
	}
	lista.elementos = nullptr;	//Linea de atrezzo
	lista.cont = 0;				//Linea de atrezzo
}
