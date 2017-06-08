#include <iostream>
using namespace std;

bool esDigito(char c);
bool esBlanco(char c);
bool esLetra(char c);
void leerHasta(char tope, char &c);
void procesarCar(char c, int &numDigitos, int &numLetras, int &numBlancos);
void leerContando(char &c, int &numDigitos, int &numLetras, int &numBlancos);
void mostrarResultados(int numDig, int numLetras, int numBlancos);

/**
* Programa que resuleve el ejercicio 17 de la hoja 3, que dice algo similar a:
* "Desarrolla un programa que cuente el n?mero de letras, d?gitos y blancos que hay entre la primera secuencia de 
* parentesis abierto y cerrado que introduzca el usuario por teclado. Se entender? que el usuario termina de introducir
* la secuencia de caracteres cuando meta un '.'".
*/
int main(){
	char c;
	int numDig = 0, numLetras = 0, numBlancos = 0;
	system("chcp 1252"); //Para que se muestren de forma correcta las tildes.

	cin.get(c);
	while (c != '.'){
		leerHasta('(', c);
		leerContando(c, numDig, numLetras, numBlancos);
		leerHasta('.', c);
		cin.sync();
		mostrarResultados(numDig, numLetras, numBlancos);
	}
	return 0;
}

/**
* Funci?n que indiaca si el caracter 'c' es un d?gito
*
* @param c el caracter a comprobar si es un d?gito.
* @return cierto si es un d?gito, falso en otro caso.
*/
bool esDigito(char c){ //isdigit(c) hace lo mismo.
	return ('0' <= c && c <= '9');
}

/**
* Funci?n que indiaca si el caracter 'c' es un blanco
*
* @param c el caracter a comprobar si es un blanco.
* @return cierto si es un blanco, falso en otro caso.
*/
bool esBlanco(char c){ //isblank(c) hace casi lo mismo, a?ade tabuladores
	return (c == ' ');
}

/**
* Funci?n que indiaca si el caracter 'c' es una letra
*
* @param c el caracter a comprobar si es una letra.
* @return cierto si es una letra, falso en otro caso.
*/
bool esLetra(char c){ //isalpha(c) hace lo mismo.
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

/**
* Funci?n que lee caracter a caracter hasta que encuentra el caracter 'tope'
* o llega al 'CENTINELA'. Devuelve en la variable 'c' el ?ltimo caracter leido.
*
* @param tope es el caracter que hace tope
* @param c (return) es donde se devuelve el ?ltimo caracter introducido.
* @return cierto si es una letra, falso en otro caso.
*/
void leerHasta(char tope, char &c){
	while (c != tope && c != '.') //leer hasta el centinela o el caracter c devolviendo el ?ltimo leido
		cin.get(c);
}

/**
* Funci?n que dado un caracter analiza el tipo y actualiza la variable correspondiente.
* numDigitos si es un d?gito, numLetras si es una letra y numBlancos si es un blanco.
*
* @param tope es el caracter que hace tope
* @param c el caracter a analizar
* @param (return) numDigitos variable a incrementar en 1 si la variable c contine un d?gito.
* @param (return) numLetras variable a incrementar en 1 si la variable c contine una letra.
* @param (return) numBlancos variable a incrementar en 1 si la variable c contine un blanco..
*/
void procesarCar(char c, int &numDigitos, int &numLetras, int &numBlancos){
	if (esDigito(c)) numDigitos = numDigitos + 1;
	else if (esLetra(c)) numLetras = numLetras + 1;
	else if (esBlanco(c)) numBlancos = numBlancos + 1;
}

v/**
 * Procediemiento que lee caracter a caracter hasta que encuentra el ')'
 * o llega al 'CENTINELA' contando la cantidad de digitos, blancos y letras que hay. 
 * Devuelve en la variable 'c' el ?ltimo caracter leido y en las variables numDigitos, numBlancos y numLetras
 * las incrementa con la cantidad de datos que lea de cada tipo.
* @param (return) c es donde se devuelve el ?ltimo caracter introducido.
* @param (return) numDigitos se incrementa con la cantidad de d?gitos le?dos.
* @param (return) numLetras se incrementa con la cantidad de letras leidas.
* @param (return) numBlancos se incrementa con la cantidad de blacos leidos.
*/
void leerContando(char &c, int &numDigitos, int &numLetras, int &numBlancos){
	while (c != ')' && c != '.'){
		cin.get(c);
		procesarCar(c, numDigitos, numLetras, numBlancos);
		}
}

/**
* Procedimiento encargado de mostrar los resultados numDig, numLetras y numBlancos.
*
* @param (return) numDigitos variable que contine la cantidad de d?gitos.
* @param (return) numLetras variable que contine la cantidad de letras.
* @param (return) numBlancos variable que contine la cantidad de blancos.
*/
void mostrarResultados(int numDig, int numLetras, int numBlancos){
	cout << "Digitos: " << numDig;
	cout << ". ";
	cout << "Letras: " << numLetras;
	cout << ". ";
	cout << "Blancos: " << numBlancos;
	cout << "." << endl;
}

