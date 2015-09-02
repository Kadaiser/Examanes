#include "grabaciones.h"
int menu();

int main(){
	int opcion;
	tListaGrabaciones listaGrabaciones;
	tListaProgramas listaProgramas;

	inicializar(listaProgramas);
	crear(listaGrabaciones);

	if (cargar(listaProgramas)){
		do{
			system("pause");
			system("cls");
			opcion = menu();
			switch (opcion){

			case 1:
			tProgramaPtr programa;
			programa = selecPrograma(listaProgramas);
			if (insertar(listaGrabaciones, programa))
					cout << "Nueva grabacion inserada" << endl;
				else
					cout << "Hubo un fallo al insertar la grabacion" << endl;
				break;

			case 2:
				mostrar(listaGrabaciones, 0);
				break;

			case 3:
				destruir(listaProgramas);
				destruir(listaGrabaciones);
				cout << "Se han eliminado las listas de programas y grabaciones" << endl;
				break;

			}
		} while (opcion != 3);
	}
	else
		cout << "Error al cargar la lista de programas desde el fichero" << endl;

	cout << "Cerrando aplicacion..." << endl;
	system("pause");
	return 0;
}

int menu(){
	int opcion;
	cout << "1- Programar una grabacion nueva" << endl;
	cout << "2- Mostrar grabaciones programas" << endl;
	cout << "3- Salir" << endl;
	cout << "Seleccione una opcion: ";
	do{
		cin >> opcion;
		cin.sync();
	} while (opcion < 1 || opcion > 3);

	return opcion;
}
