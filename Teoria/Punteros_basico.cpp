#include <iostream>

using namespace std;

int main(){
	
	int i = 10;
	
	int *punt = nullptr;
	
	//DIRECCIONAMIENTOS DE PUNTEROS
	cout << "El contenido de la variable (i) es: " << i << endl;
	cout << "La direccion de memoria de i es: " << &i << endl;
	cout << "Un puntero inicializado a nullptr posee una direccion tal que : " << punt << endl;
	
	punt = &i;
	
	cout << "Tras la instruccion  (punt = &i;), el puntero posee la direccion de i: " << punt <<	endl;
	cout << "ahora podemos acceder al DATO al que apunta ese puntero con (*punt):" << *punt << endl;
	
	int *punt2;
	punt2 = punt;
	
	//OPERACIONES CON PUNTEROS
	cout << "Podemos copiar direcciones de un puntero a otro, ahora (punt2) posse la misma direccion que (punt):" << punt2 << endl;
	cout << "Ademas los punteros se pueden usar para operar sobre sus contenidos, tal que ";
	cout << *punt << " + " << *punt2 << " = " << *punt + *punt2 << endl;
	
	cout << "Un puntero puede actualizar el contenido al que apunta una vez esta cargado con una direccion" << endl;
	*punt = 20;
	cout << "De esta manera, si varios punteros apuntan al mismo dato, todos ellos no cambiaran sus direcciones" << endl;
	cout << "Direccion de (punt):" << punt <<"	Direccion de (punt2):" << punt2 << endl;
	cout << "Pero al cambiar el contenido del dato al que apuntan con  una instruccion tipo (*punt = 20;)" << endl;
	cout << "El resultado de la misma operacion cambia: " << *punt << " + " << *punt2 << " = " << *punt + *punt2 << endl;
	cout << "O bien al cambiar directamente el valor de la variable a la que apuntan los puntero (i=5): ";
	i = 5;
	cout << *punt << " + " << *punt2 << " = " << *punt + *punt2 << endl;
	
	//COMPARACIONES DE PUNTEROS
	cout << "Los punteros pueden ser comparados con los operandos tipicos == | !=" << endl;
	cout << "De esta menra sabemos que (punt) y (punt2) ";
		if(punt == punt2) cout << "poseen la misma direccion." << endl;
		else cout << "no poseen la misma direccion" << endl;
	
	system("pause");
}