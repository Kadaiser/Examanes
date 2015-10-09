/**
*	Las funciones aqui indicadas se usan como plantillas respecto del siguiente ejemplo de interfaz de programa
*/

const int MAX_ELEMENTOS = 100;

typedef struct{
	int dia;
	int mes;
	int anio;
}tFecha;

typedef enum {grupo1, grupo2, grupo3} tGrupo;

typedef struct{
	tFecha fecha;
	tGrupo grupo;
	int propiedad1;
	string propiedad2;
	bool propiedad3;
}tElemento;

/**---------------------------------------------------------------------------------------------------------------*/

/**
* 	FUNCION PARA LA CARGA DESDE UN FICHERO
*	Habitualmente manejamos ficehro con centinela, este metodo lee linea a linea
*	Identificando el centinela, y se caso correspondiente devolviendo true o false
*	y el elmento ya formado en caso de true. Suele ser un sub-programa de la funcione
*	"insertar" cuand se cargan listas.
*/
bool leer(ifstream & fichero, tElemento & elemento){
	bool ok = false;
	char grupo;

	fichero >> elemento.propiedad1;
	if(elemento.propiedad1 != CENTINELA){
		fichero >> elemento.propiedad2;
		fichero >> elemento.propiedad3;
		fichero >> aux;
		elemento.grupo = charToGrupo(grupo);
		fichero >> elemento.fecha; //dependera de si es un string, en un tipo estrucutrado habria que crear un metodo para leer la fecha.
	}
	return ok;
}

/**
*	FUNCION PARA RELACIONAR UN DATO CON UN ENUMERADO
*	En ocasiones, puede que de un fichero de texto se lea una letra (o un numero, o un string...) y eso
* 	haya que relacionarlo con un elemento determinado de un dato enumerado.
*/
tGrupo intToGrupo(int dato){

tGrupo grupo;

	if(grupo == 'A') clase = grupo1;
	else if(grupo == 'B') clase = grupo1;
	else grupo = grupo3;
return grupo;
}

/**
*	FUNCION PARA MANEJAR UN TIPO ENUMERADO COMO STRING
*	Dado un dato enumerado, se devuelve como string para ser mostrado facilmente por consola
*/

string grupoToString(const tGrupo & operacion){
	string str;
	if(grupo == grupo1) str = "grupo1";
	else if(grupo == grupo2) str = "grupo2";
	else str = "grupo3";
	return str;
}

/**
*	FUNCION PARA MANEJAR UN TIPO ESTRUCTURADO COMO STRING
*	Dado un dato estructurado, se devuelve como string para ser mostrado facilmente por consola
*/
string fechaToString(const tFecha & fecha){
	string str;
	str = to_string(fecha.anio);
	str += '/';
	str +=to_string(fecha.mes);
	str += '/';
	str +=to_string(fecha.dia);
	return str;
}
