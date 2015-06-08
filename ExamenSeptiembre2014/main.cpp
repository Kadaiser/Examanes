#include "ListaAlumnos.h"

const string FICHERO = "datos.txt";

int main(){
	tListaAlumnos listaAlumnos;
	inicializar(listaAlumnos);
	ifstream archivo;

	archivo.open(FICHERO);

	if(archivo.is_open()){
		carga(listaAlumnos, archivo);
		muestra(listaAlumnos);
		system("pause");
		archivo.close();
	}
	else{
		cout << "Error al abrir el fichero" << endl;
	}
	destruye(listaAlumnos);
	cout << "Se ha destruido la memoria dinamica" << endl;
	system("pause");
	return 0;
}
