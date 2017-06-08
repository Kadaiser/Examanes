#include "ListaExamenes.h"

void muestra(const tListaExamenes &listaExamenes, int pos);

void estadisticaNotas(const tListaExamenes &listaExamenes, tArrayNotasAgrupadas notasAgrupadas){
	for (int i = 0; i < listaExamenes.cont; i++){
		tNotaCual notaCual = listaExamenes.examenes[i].notaCualitativa;
		switch(notaCual){
			case SS: notasAgrupadas[0]++;break;
			case AP: notasAgrupadas[1]++;break;
			case B: notasAgrupadas[2]++;break;
			case NT: notasAgrupadas[3]++;break;
			case SB: notasAgrupadas[4]++;break;
		}
	}
}

void muestra(const tListaExamenes &listaExamenes, int pos){
	if (pos<listaExamenes.cont){
		muestra(listaExamenes.examenes[pos]);
		muestra(listaExamenes,pos+1);
	}
}

void muestra(const tListaExamenes &listaExamenes){
	tArrayNotasAgrupadas notasAgrupadas;
	muestra(listaExamenes,0);
	cout<<endl;
	//Generamos las estadisticas
	inicializarEstadisticas(notasAgrupadas);
	estadisticaNotas(listaExamenes, notasAgrupadas);
	//Mostramos las estadisticas
	muestraEstadisticas(notasAgrupadas);
}

void inicializarEstadisticas(tArrayNotasAgrupadas notasAgrupadas){
	for (int i = 0; i < NumNotasCual; i++)
		notasAgrupadas[i] = 0;
}

void muestraEstadisticas(tArrayNotasAgrupadas notasAgrupadas){
	cout << "SS: " << notasAgrupadas[0] << " AP: " << notasAgrupadas[1] << " B: " << notasAgrupadas[2] << " NT: " << notasAgrupadas[3] << " SB: " << notasAgrupadas[4] << endl;
}

void insertaExamen(tListaExamenes &listaExamenes, tExamen examen){
	//Comprobamos si la lista está llena
	if (listaExamenes.cont < MaxExamenes) {
		//Insertamos el nuevo examen
		listaExamenes.examenes[listaExamenes.cont] = examen;
		listaExamenes.cont++;
	  }
}

void destruye(tListaExamenes &listaExamenes){
	delete [] listaExamenes.examenes;
	listaExamenes.cont = 0;
}

void creaListaExamenes(tExamen examen, tListaExamenes &listaExamenes){
	listaExamenes.examenes = new tExamen[MaxExamenes];
	listaExamenes.examenes[0] = examen;
	listaExamenes.cont=1;
}
