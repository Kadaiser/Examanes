
#include"Grabaciones.h"

int menu();

int main(){
	tGrabaciones grabaciones;
	tListaProgramas listaProgramas;
	tGrabacion grabacion;
	tPrograma programa;

	int opcion;
	crear(grabaciones);
	cargar(listaProgramas);
	do{
		system("cls");
		opcion = menu();
		switch (opcion){
		case 1:
			system("cls");

			programa = selecPrograma(listaProgramas);
			grabacion.programa = new tPrograma(programa);
			grabacion.grabado = true;

			insertar(grabaciones, grabacion);
			break;
		case 2:
			mostrar(grabaciones);
			system("pause");
			break;
		case 3:
			destruir(grabaciones, listaProgramas);
			break;
		}
	} while (opcion != 3);
	system("pause");
	return 0;
}



int menu(){
	int opcion = 0;

		cout << "Menu." << endl;
		cout << "Elige una opcion:" << endl;
		cout << "1) Programar una grabacion nueva" << endl;
		cout << "2) Mostrar las grabaciones programadas hasta ahora" << endl;
		cout << "3) Salir" << endl;
		cout << "Opcion: ";

		do{
			cin >> opcion;
	} while (opcion < 0 || opcion > 3);
	return opcion;
}