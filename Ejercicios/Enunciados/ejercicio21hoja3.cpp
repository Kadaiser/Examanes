#include <iostream>;
#include <fstream>;

using namespace std;

const int CENTINELA = 0;
const string NOMBRE_FICH = "numeros.txt";

bool sonTriangulares(ifstream &elFich); //sin centinela
bool sonTriangularesCent(ifstream &elFich); //con centinela
bool esTriangular(int num);
int sumaDeA(int numDe, int numA);
void mostrarResultado(bool sonTriag);

/**
* Programa que resuleve el ejercicio 21 de la hoja 3, que dice as?:
* "Escribe un programa que indique si es trinagular cada n?mero entero que haya en un archivo 'enteros.txt'
* (terminado en 0 como centinela). Se dice que un n?mero entero es triangular si es igual a la suma de varios 
* enteros positivos consecutivos empezando desde 1. El program? usar? una funci?n qie indique si un entero es trangular."
*/
int main(){
	ifstream elFich;
	bool sonTrig;
	int num;
	system("chcp 1252"); //Para que se muestren de forma correcta las tildes.

	//procesar el fichero.
	elFich.open(NOMBRE_FICH);
	sonTrig = sonTriangularesCent(elFich);
	elFich.close();

	//Mostrar el resultado
	mostrarResultado(sonTrig);

	system("pause"); //Deber?a borrarse cuando genere el ejecutable, s?lo para depuraci?n en VS.

	return 0;
}

/**VERSION SIN CENTINELA
* Funci?n que indica si todos los n?meros almacenados en un fichero desde la posici?n del cursor en ?l son triangulares o no.
* En el caso de que se produzca alg?n fallo devolver? falso.
*
* @param elFich Fichero desde el que leer los n?meros abiertos para lectura.
* @return cierto si 'elFich' contiene s?lo n?meros triangulares, falso en caso contrario.
*/
bool sonTriangulares(ifstream &elFich) {
	bool sonTriang;
	int num;

	elFich >> num;       // Leo el primer n?mero
	sonTriang = !elFich.fail(); // Por ahora es cierto si no hay fallos

	// Proceso hasta que se deje de cumplir la propiedad o alcanze el centinela que es el n?mero 0.
	while (sonTriang && !elFich.eof()){
		sonTriang = !elFich.fail() && esTriangular(num); // Actualizo la propiedad de ser creciente con el valor actual.
		elFich >> num;
	}

	elFich.sync(); // Limpio lo que quede sin leer.
	elFich.clear(); // Si ha habido alg?n fallo lo dejo en buen estado

	return sonTriang;
}

/**VERSION CON CENTINELA
* Funci?n que indica si todos los n?meros almacenados en un fichero desde la posici?n del cursor en ?l son triangulares o no.
* En el caso de que se produzca alg?n fallo devolver? falso.
*
* @param elFich Fichero desde el que leer los n?meros abiertos para lectura.
* @return cierto si 'elFich' contiene s?lo n?meros triangulares, falso en caso contrario.
*/
bool sonTriangularesCent(ifstream &elFich) {
	bool sonTriang;
	int num;

	elFich >> num;       // Leo el primer n?mero
	sonTriang = !elFich.fail(); // Por ahora es cierto si no hay fallos

	// Proceso hasta que se deje de cumplir la propiedad o alcanze el centinela que es el n?mero 0.
	while (sonTriang && num != CENTINELA && !elFich.eof()){
		sonTriang = !elFich.fail() && esTriangular(num); // Actualizo la propiedad de ser creciente con el valor actual.
		elFich >> num;
	}

	elFich.sync(); // Limpio lo que quede sin leer.
	elFich.clear(); // Si ha habido alg?n fallo lo dejo en buen estado

	return sonTriang;
}

/**
* Funci?n que indiaca si el 'num' es triangular. Es decir, si es igual a la suma de varios 
* enteros positivos consecutivos empezando desde 1.
*
* @param num el n?mero a comprobar si es triangular.
* @return cierto si es triangular, falso en otro caso.
*/
bool esTriangular(int num){
	bool esTri;
	int i = 1;
	int suma = sumaDeA(1, i);

	//Busco si cumple la propiedad hasta que se cumple o descubro que no.
	while (suma < num){
		i = i + 1;
		suma = sumaDeA(1, i);
	}

	return suma == num;
}

/**
* Devuelve la suma de n?meros enteros consecutivos desde 'numDe' hasta 'numA'
*
* @param numDe n?mero inicial.
* @param numA n?mero final.
* @return la suma de los n?meros desde 'numDe' a 'numA' o 0 si no hay valores.
*/
int sumaDeA(int numDe, int numA){
	int suma;

	//Calculo la suma con la expresi?n matem?tica adecuada en vez del for.
	if (numDe <= numA) suma = (numDe + numA) * (numA - numDe + 1) / 2;
	else suma = 0;

	return suma;
}

/**
* M?todo encdargado de mostrar el resultado.
* Lo separo ya que si luego lo quiero implementar con ventanas o con mensaje m?s bonito as? lo hago m?s f?cil.
*
* @param sonTriag booleano que indica si la propiedad se cumple.
*/
void mostrarResultado(bool sonTriang){
	if (sonTriang)
		cout << "Todos los n?meros del fichero 'numeros.txt' son triangulares." << endl;
	else cout << "Alg?n n?mero del fichero NO es triangular o ha tiene algun fallo (no eran enteros).";
	cout << endl;
}

