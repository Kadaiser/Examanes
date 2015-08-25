
#include"Programa.h"



bool cargar(ifstream & archivo, tPrograma & programa){
	bool esPrograma = false;
	char a;
	getline(archivo, programa.nombre);
	if (programa.nombre != CENTINELA){
		archivo >> programa.fecha;
		archivo >> programa.duracion;
		archivo.get(a);
		esPrograma = true;
	}	
	return esPrograma;
}

void mostrar(const tPrograma & programa){
	cout << programa.nombre << "." << setw(2) << mostrarFecha(programa.fecha) << "." << setw(2) << programa.duracion << endl;
}

string mostrarFecha(tFecha fecha){
	stringstream resultado; tm ltm;
	localtime_s(&ltm, &fecha);
	resultado << ltm.tm_mday << "/" << 1 + ltm.tm_mon << "/" << 1900 + ltm.tm_year;
	resultado << " (" << ltm.tm_hour << ":" << ltm.tm_min << " ";
	return resultado.str();
}