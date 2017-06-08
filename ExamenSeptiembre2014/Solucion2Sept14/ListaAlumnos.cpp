#include "ListaAlumnos.h"

int busca(const tListaExamenes &listaExamenes, string fecha, bool &encontrado);
void creaAlumno(string nif, tExamen examen, tAlumno &alumno);
void muestra(const tAlumno &alumno);
void creaAlumno(string nif, tExamen examen, tAlumno &alumno);

void totalEstadisticas(const tListaAlumnos &listaAlumnos, tArrayNotasAgrupadas notasAgrupadas){
	inicializarEstadisticas(notasAgrupadas);
	for (int i = 0; i < listaAlumnos.cont; i++){
		estadisticaNotas(listaAlumnos.alumnos[i]->listaExamenes,notasAgrupadas);
	}
}

void muestra(const tListaAlumnos &listaAlumnos){
	tArrayNotasAgrupadas notasAgrupadas;
	for (int i=0; i< listaAlumnos.cont;i++){
		cout << "--------------------------------" << endl;
		muestra(*listaAlumnos.alumnos[i]);
	}
	cout << "---------------------------------------" << endl;
	//Calculamos las estadisticas totales
	totalEstadisticas(listaAlumnos,notasAgrupadas);
	//Mostramos las estadisticas totales
	cout<<"Total.- ";
	muestraEstadisticas(notasAgrupadas);
}

void muestra(const tAlumno &alumno){
	cout << "Alumno: " << alumno.nif << endl;
	muestra(alumno.listaExamenes);
}

int busca(const tListaAlumnos &listaAlumnos, string nif, bool &encontrado) {
	int ini = 0, fin = listaAlumnos.cont-1, mitad;
	encontrado = false;
	while ((ini<=fin) && (!encontrado)) {
      mitad = (ini + fin) / 2;
	  if (nif == listaAlumnos.alumnos[mitad]->nif)
         encontrado = true;
      else 
		  if (nif < listaAlumnos.alumnos[mitad]->nif) 
			fin = mitad - 1;
		  else 
			ini = mitad + 1;
   }
   if (!encontrado)
	   mitad = ini;
   return mitad;
}

void insertaAlumno(tListaAlumnos &listaAlumnos, string nif, tExamen examen, int pos){
	if (listaAlumnos.cont < MaxAlumnos){
		tAlumno alumno;
		creaAlumno(nif,examen,alumno);
		//Desplazamos hacia la derecha para abrir hueco
		for (int i= listaAlumnos.cont;i>pos;i--)
			listaAlumnos.alumnos[i]=listaAlumnos.alumnos[i-1];
		//Insertamos el nuevo alumno en el hueco que hemos dejado
		listaAlumnos.alumnos[pos]=new tAlumno(alumno);
		listaAlumnos.cont++;
	}
}

void creaAlumno(string nif, tExamen examen, tAlumno &alumno){
	alumno.nif = nif;
	creaListaExamenes(examen,alumno.listaExamenes);
}

void carga(tListaAlumnos &listaAlumnos){
	ifstream file;
	string fecha;
	string nif;
	tExamen examen;
	double notaNumerica;
	int pos;
	bool encontrado=false;

	listaAlumnos.cont = 0;
	file.open(FileName.c_str());
	if (file.is_open()) {
		file >> nif;
		while ((nif != "XXX") && (listaAlumnos.cont < MaxAlumnos)) {
			file >> fecha >> notaNumerica;
			//Creamos el examen con los datos que hemos leído
			creaExamen(fecha,notaNumerica,examen);
			//Si la lista esta vacia no es necesario buscar
			if (listaAlumnos.cont == 0)
				pos = 0;
			else
				//Buscamos el alumno en la lista
				pos = busca(listaAlumnos,nif,encontrado);
			//Si no se encuentra se añade al final de la lista
			if (!encontrado) 
				insertaAlumno(listaAlumnos, nif, examen, pos);
			//Si se encuentra añadimos la nota a la lista de notas del examen
			else 
				insertaExamen(listaAlumnos.alumnos[pos]->listaExamenes, examen);
			file >> nif;
		}
		file.close();
	}
}

void destruye(tListaAlumnos &listaAlumnos){
	for (int i = 0; i < listaAlumnos.cont; i++) {
		//Destruimos la lista de examenes de cada alumno
		destruye(listaAlumnos.alumnos[i]->listaExamenes);
		//Destruimos el dato dinámico del array de examenes
		delete listaAlumnos.alumnos[i];
   }
   listaAlumnos.cont = 0;
}

