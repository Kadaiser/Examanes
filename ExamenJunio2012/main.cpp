#include "listaempleados.h"

void mostrarMenu();
void opcion(int & op);

int main(){
	tListaEmpleados listaEmpleados;
	inicializar (listaEmpleados);
	int op;
	
	do{
	mostrarMenu();
	opcion(op);
	
	switch(op){
	case 1:
		GenerarEmpleado(listaEmpleados);
		system("pause");
		break;
		
	case 2:
		break;
		
	case 3:
		eliminarDepartamento(listaEmpleados);
		system("pause");
		break;
		
	case 4:
		listado(listaEmpleados);
		system("pause");
		break;

	default:
		break;
	}
	}while(op != 0);
	
		cout << "Apagando sistema" << endl;
		guardar(listaEmpleados);
	
	system("pause");
	return 0;
}

void mostrarMenu(){
	system("cls");
	cout << "1 - Alta" << endl;
	cout << "2 - Procesar accesos" << endl;
	cout << "3 - Eliminar" << endl;
	cout << "4 - Listado" << endl;
	cout << "0 - Salir" << endl;
	cout << "opcion: ";
}

void opcion(int & op){
	do{
	cin >> op;
	cin.sync();
	}while(op < 0 || op > 5);
}