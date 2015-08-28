#include "grabaciones.h"


void crear(tListaGrabaciones & listaGrabaciones){
	listaGrabaciones.contador = 0;
	listaGrabaciones.capacidad = GRABACIONES;
	listaGrabaciones.grabaciones = new tGrabacion[GRABACIONES];
}


bool solapan(const tProgramaPtr & programa1, const tProgramaPtr & programa2){
	int inicio1 = programa1->inicio;
	int inicio2 = programa2->inicio;
	int fin1 = (programa1->duracion * 60) + inicio1;
	int fin2 = (programa2->duracion * 60) + inicio2;
	return (fin1 >= inicio2 && fin1 <= fin2) || (inicio1 >= inicio2 && inicio1 <= fin2);
}


bool insertar(tListaGrabaciones & listaGrabaciones, const tProgramaPtr & programa){
	bool solapamiento = true;
	for(int i = 0; i < listaGrabaciones.contador; i++){
	if(solapan(listaGrabaciones.grabaciones[i].programa, programa))
		solapamiento = false;
	}
	
	if (solapamiento && listaGrabaciones.contador < listaGrabaciones.capacidad){
		listaGrabaciones.grabaciones[listaGrabaciones.contador].programa = programa;
		listaGrabaciones.grabaciones[listaGrabaciones.contador].grabado = true;
		listaGrabaciones.contador++;
	}

	return solapamiento;
}


void mostrar(tListaGrabaciones & listaGrabaciones, int posicion){
	if (posicion < listaGrabaciones.contador){
		if (listaGrabaciones.grabaciones[posicion].grabado){			//Si no esta grabado, se muestra.
			mostrar(*listaGrabaciones.grabaciones[posicion].programa);
		}
		mostrar(listaGrabaciones, posicion + 1);
	}
}

void destruir(tListaGrabaciones & listaGrabaciones){
	delete[] listaGrabaciones.grabaciones;
}
