#include<iostream>

using namespace std;

double solicitar();
double resultado(double fahrenheit);
void mostrar(double fahrenheit);

int main(){
	double fahrenheit;
	fahrenheit = solicitar();
	system("cls");
	mostrar(fahrenheit);
	
	system("pause");
	return 0;
}

double solicitar(){
	int cifra;
	cout << "introduca una cifra de grados fahrenheit: ";
	cifra = scanf("%d", cifra);
	cin.sync();
	while(!isdigit(cifra)){
		cout << "Introduzca una cifra numerica: "
		cin >> cifra;
		cin.sync();
	}
	return cifra;
}

double resultado(double fahrenheit){
	return 5/(9 * (fahrenheit - 32));
}

void mostrar(double fahrenheit){
	cout << "El valor de grados Celsius equivalente a " << fahrenheit << " grados fahrenheit es de ";
	cout << resultado(fahrenheit) << " grados celsius" << endl; 
}