#include "ListaExamenes.h"

void inicializar(tListaExamenes & listaExamenes){
	listaExamenes.examenes = new tExamen [MAXEXAMENES];
	listaExamenes.contador = 0;
}

void estadisticasNotas (const tListaExamenes & listaExamenes, tArrayCalificaciones & arrayCalificaciones){
	
	arrayCalificaciones[5] = {0}; //inicializar el array
	
	for(int i = 0; i < listaExamenes.contador; i++){
		int nota = listaExamenes.examenes[i].nota;
		
		if(nota < 5) arrayCalificaciones[0]++;
		else if(nota >=5 || nota < 6) arrayCalificaciones[1]++;
		else if(nota >=6 || nota < 7) arrayCalificaciones[2]++;
		else if(nota >=7 || nota < 9) arrayCalificaciones[3]++;
		else arrayCalificaciones[4]++;
	}	
}


void muestra(const tListaExamenes & listaExamenes){
	tArrayCalificaciones arrayCalificaciones;
	
	estadisticasNotas(listaExamenes, arrayCalificaciones);
	muestraLista(listaExamenes, 0);
	
	cout << "SS: " << arrayCalificaciones[0] << "AP: " << arrayCalificaciones[1] << "B: " << arrayCalificaciones[2] << "NT: " << arrayCalificaciones[3] << "SB: " << arrayCalificaciones[4] << endl;
}


void muestraLista(const tListaExamenes & listaExamenes, int pos) {
	if (pos < listaExamenes.contador){
		muestra(listaExamenes.examenes[pos]);
		muestraLista(listaExamenes, pos + 1);
	}
}


bool insertarNota(tListaExamenes & listaExamenes, const tExamen & examen){
	bool ok = false;
	
		if(listaExamenes.contador < MAXEXAMENES){
			listaExamenes.examenes[listaExamenes.contador]= examen;
			listaExamenes.contador++;
			ok = true;
		}	
		else
			cout << "Lista de clientes llena, no puede incluirse nuevos clientes" << endl;
	return ok;
}

void destruye(tListaExamenes & listaExamenes){
	delete[] listaExamenes.examenes;
	listaExamenes.examenes = nullptr;
	listaExamenes.contador = 0;
}