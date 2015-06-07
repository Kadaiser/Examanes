
#include "ListaAlumnos.h"

void inicializar(tListaAlumnos & listaAlumnos){
	for(int i = 0; i < MAXALUMNOS; i++){
		listaAlumnos.alumnos[i] = new tAlumno;
	}
	listaAlumnos.contador = 0;
}



void totalEstadisticas(const tListaAlumnos & listaAlumnos, tArrayCalificacionesAlumnos & arrayCalificacionesAlumnos){
	
	arrayCalificacionesAlumnos[5] = {0}; //inicializar el array
	
}


void muestra(const tListaAlumnos & listaAlumnos){
	tArrayCalificacionesAlumnos arrayCalificacionesAlumnos;
	
	for(int i = 0; i < listaAlumnos.contador; i++){
		cout << "----------------------------------------" << endl;
		cout << "Alumno: " << listaAlumnos.alumnos[i] ->NIF << endl;
		muestra(listaAlumnos.alumnos[i] -> listaExamenes);
	}
	
	cout << "----------------------------------------" << endl;
	totalEstadisticas(listaAlumnos, arrayCalificacionesAlumnos);
	cout << "Total : ";
		cout << "SS: " << arrayCalificacionesAlumnos[0] << "AP: " << arrayCalificacionesAlumnos[1] << "B: " << arrayCalificacionesAlumnos[2] << "NT: " << arrayCalificacionesAlumnos[3] << "SB: " << arrayCalificacionesAlumnos[4] << endl;

}

bool busca(const tListaAlumnos & listaAlumnos, string NIF, int & pos){
	int fin = listaAlumnos.contador - 1, ini = 0, mitad;
	bool encontrado = false;
	
	while(!encontrado && fin <= ini){
		mitad = (ini + fin) / 2;
		
		if(NIF < listaAlumnos.alumnos[mitad]-> NIF){
			fin = mitad - 1;
		}
		else if(listaAlumnos.alumnos[mitad]-> NIF < NIF){
			ini = mitad + 1;
		}
		else
			encontrado = true;
	}
	if(encontrado) pos = mitad;
	else pos = ini;
	
	return encontrado;
}

void creaAlumno(string NIF, tExamen examen, tAlumno &alumno){
	alumno.NIF = NIF;
	inicializar(alumno.listaExamenes);
	alumno.listaExamenes.examenes[0] = examen;
	alumno.listaExamenes.contador++;
}


void insertaAlumno(tListaAlumnos & listaAlumnos, string NIF, const tExamen & examen, int pos){
	if(listaAlumnos.contador < MAXALUMNOS){
		tAlumno alumno;
		
		creaAlumno(NIF,examen,alumno);
			
			for(int i = listaAlumnos.contador; i > pos; i--){
				listaAlumnos.alumnos[i] = listaAlumnos.alumnos[i - 1];
			}
			listaAlumnos.alumnos[pos] = new tAlumno(alumno);
			listaAlumnos.contador++;
		}
	else
		cout << "Lista de alumnos llena, no puede insertarse nuevo alumno a la lista de alumnos" << endl;
}

void carga (tListaAlumnos & listaAlumnos, ifstream & archivo){
	tExamen examen;	
	string NIF;
	string fecha;
	double nota;
	int pos;
	
	archivo >> NIF;
	while(NIF != CENTINELA && listaAlumnos.contador < MAXALUMNOS){
			archivo >> fecha;
			archivo >> nota;
			
		creaExamen(fecha, nota, examen);

			if(!busca(listaAlumnos, NIF, pos))
				insertaAlumno(listaAlumnos, NIF, examen, pos);
			else
				insertarNota(listaAlumnos.alumnos[pos] ->listaExamenes, examen);
		
			archivo>> NIF;
	}
	
}

void destruye(tListaAlumnos & listaAlumnos){
	for(int i = 0; i < listaAlumnos.contador; i++){
		destruye(listaAlumnos.alumnos[i] -> listaExamenes);
		delete listaAlumnos.alumnos[i];
	}
}
