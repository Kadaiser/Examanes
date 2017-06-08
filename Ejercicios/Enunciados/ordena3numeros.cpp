#include <iostream>
using namespace std;
// Implementaci?n de las funciones

void leerTresNumeros(double &num1, double &num2, double &num3);
double leerUnNumero(int i);
void ordenar(double &num1, double &num2);
void intercambiar(double &num1, double &num2);
void ordenarTresNumeros(double &num1, double &num2, double &num3);
void mostrarLosValores(double num1, double num2, double num3);


int main(){
	// las tres longitudes de los segmentos.
	double num1, num2, num3;

	// lectura de datos
	leerTresNumeros(num1, num2, num3);

	// realizar c?lculos
	ordenarTresNumeros(num1, num2, num3);

	// mostrar los resultados
	mostrarLosValores(num1, num2, num3);

	system("pause");

	return 0;
}

void leerTresNumeros(double &num1, double &num2, double &num3){
	num1 = leerUnNumero(1);
	num2 = leerUnNumero(2);
	num3 = leerUnNumero(3);
}

double leerUnNumero(int i) {
	double num;
	cout << "Introduce el n?mero " << i << ": ";
	cin >> num;
	while (cin.fail()) {
		cin.clear(); cin.sync();
		cout << "Numero no valido!" << "Introduce un n?mero entero : ";
		cin >> num;
	}
	cin.sync();
	return num;
}

void ordenarTresNumeros(double &num1, double &num2, double &num3){
	ordenar(num1, num2);
	ordenar(num2, num3);
	ordenar(num1, num2);
}

void ordenar(double &num1, double &num2){
	if (num1 < num2) intercambiar(num1, num2);
}

void intercambiar(double &num1, double &num2){
	double aux;
	aux = num1;
	num1 = num2;
	num2 = aux;
}

void mostrarLosValores(double num1, double num2, double num3){
	cout << "Los n?meros ordenados de mayor a menor son: " << num1 << " > " << num2 << " > " << num3 << ".";
}
