#include<iostream>
#include<cmath>

using namespace std;

const double RADIO = 14.5;
const double ALTURA = 26.79;
const double PI = 3.141592;

double formula();
void mostrar();

int main(){
	
	mostrar();
	system("pause");
	return 0;
}

double formula(){
	return (PI * pow(RADIO,2) * ALTURA) / 3;
}

void mostrar(){
	cout << "El volumen del cono de radio base 14,5 y altura 26,79 es de " << formula() << " unidades cubicas" << endl;
}