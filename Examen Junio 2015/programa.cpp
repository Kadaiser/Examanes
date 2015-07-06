#include "programa.h"


bool carga(ifstream & archivo, tPrograma & programa){
	bool esPrograma = false;
	char c;
		getline(archivo, programa.nombre);
		if (programa.nombre != CENTINELA){

			archivo >> programa.inicio;
			archivo >> programa.duracion;
			archivo.get(c);
			esPrograma = true;
		}

	return esPrograma;
}

void mostrar(const tPrograma & programa){
	cout << programa.nombre << " " << mostrarFecha(programa.inicio) << ". Duracion " << programa.duracion << " minutos" << endl;
}


string mostrarFecha(tFecha fecha){
	stringstream resultado;	
	tm	ltm;
	localtime_s(&ltm, &fecha);
	resultado << ltm.tm_mday << "/" <<	1 + ltm.tm_mon << "/" << 1900 + ltm.tm_year;
	resultado << " ("<< ltm.tm_hour << ":" << ltm.tm_min << ")";
	return
		resultado.str();
}