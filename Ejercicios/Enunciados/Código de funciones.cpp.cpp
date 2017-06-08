#include <iostream>
using namespace std;
#include <cmath>

// Prototipos de las funciones (excepto main())
bool par(int num);
bool letra(char car);
int suma(int num);
double formula(int x, int y);
int leerEntero();

int main() {
   int numero, sum, x, y;
   char caracter;
   double f;
 
   numero = leerEntero();

   if (par(numero)) {
      cout << "Par";
   }
   else {
      cout << "Impar";
   }
   cout << endl;
   if (numero > 1) {
      cout << "Sumatorio de 1 a " << numero << ": " << suma(numero) << endl;
   }
   cout << "Car?cter: ";
   cin >> caracter;
   if (!letra(caracter)) {
      cout << "no ";
   }
   cout << "es una letra" << endl;
   cout << "f(x, y) = " << formula(x, y) << endl;
   // Los argumentos pueden llamarse igual o no que los par?metros

   return 0;
}

// Implementaci?n de las funciones propias

int leerEntero() {
	int num;
	cout << "Dame un entero: ";
	cin >> num;
	while (cin.fail()) {
		cin.clear(); cin.sync();
		cout << "Numero no valido!" << "Introduce un n?mero entero : ";
		cin >> num;
	}
	cin.sync();
	return num;
}

bool par(int num) {
   return (num % 2 == 0);
}

bool letra(char car) {
   bool esLetra;
   esLetra = ((car >= 'a') && (car <= 'z') || (car >= 'A') && (car <= 'Z'));
   }
   return esLetra;
}

int suma(int num) {
   int sum = 0, i = 1;
   while (i < num) {
      sum = sum + i;
      i++;
   }
   return sum;
}

double formula(int x, int y) {
   double f;
   f = 2 * pow(x, 5) + sqrt(pow(x, 3) / pow(y, 2))  / abs(x * y) - cos(y);
   return f;
}


