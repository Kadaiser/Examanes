#include <iostream>
using namespace std;

const int CENTINELA = 0;

bool esCrecienteSecuencia();
void mostrarResultado(bool esCreciente);

/**
* Programa que resuleve el ejercicio 18 de la hoja 3, que dice as?: 
* "Desarrolla un programa que determine si una secuencia de enteros introducidos por teclado
* y terminada en 0 (centinela) es creciente o no (cada elemento es mayor o igual que el anterior."
*/
int main(){
	bool esCreciente;
	system("chcp 1252"); //Para que se muestren de forma correcta las tildes.

	//Pedir la secuencia
	cout << "Escribe una secuencia de enteros, el valor para terminar la secuencia es el 0." << endl;
	//Calcular si es creciente o no
	esCreciente = esCrecienteSecuencia();
	//Mostrar el resultado
	mostrarResultado(esCreciente);

	system("pause"); //Deber?a borrarse cuando genere el ejecutable, s?lo para depuraci?n en VS.

	return 0;
}

/**
* Funci?n encargada de realizar la lectura y comprobar la propiedad.
* Esta funci?n est? preparada para fallos del usuario, en tal caso indicar? que la propiedad es falsa.
* Con fallos me refiero, por ejemplo a que el usuario meta letras en vez de n?meros, etc.
*
* @return cierto si la secuencia es creciente y no ha tenico fallos, falso en otro caso.
*/
bool esCrecienteSecuencia(){
	bool esCrec;
	int numAnterior, numNuevo;

	cin >> numNuevo;       // Leo el primer n?mero
	esCrec = !cin.fail(); // Inicializaci?n: Por ahora es creciente si no hay fallos

	// Proceso hasta que se deje de cumplir la propiedad o alcanze el centinela que es el n?mero 0.
	while (esCrec && numNuevo != CENTINELA){
		numAnterior = numNuevo;
		cin >> numNuevo;
		if (numNuevo != CENTINELA) // Si no es el centinela actualizo esCrec
			esCrec = !cin.fail() && numAnterior <= numNuevo; // Actualizo la propiedad de ser creciente con el valor actual.
	}

	cin.sync(); // Limpio lo que quede sin leer.
	cin.clear(); // Si ha habido alg?n fallo lo dejo en buen estado

	return esCrec;
}

/**
* M?todo encdargado de mostrar el resultado.
* Lo separo ya que si luego lo quiero implementar con ventanas o con mensaje m?s bonito as? lo hago m?s f?cil.
*
* @param esCreciente booleano que indica si la propiedad es creciente o no.
*/
void mostrarResultado(bool esCreciente){
	if (esCreciente)
		cout << "La secuencia introducida es CRECIENTE.";
	else cout << "La secuencia introducida NO es CRECIENTE o ha cometido algun fallo (no eran enteros).";
	cout << endl;
}

