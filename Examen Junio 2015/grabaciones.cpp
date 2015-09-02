#include "grabaciones.h"


void crear(tListaGrabaciones & listaGrabaciones){
	listaGrabaciones.contador = 0;
	listaGrabaciones.capacidad = GRABACIONES;
	listaGrabaciones.grabaciones = new tGrabacion[GRABACIONES];
}


bool solapan(const tGrabacion & grabacion1, const tGrabacion & grabacion2){
	int inicio1 = grabacion1.programa->inicio;
	int inicio2 = grabacion2.programa->inicio;
	int fin1 = grabacion1.programa->duracion * 60;
	int fin2 = grabacion2.programa->duracion * 60;
	return (fin1 >= inicio2 && fin1 <= fin2) || (inicio1 >= inicio2 && inicio1 <= fin2);
}


bool insertar(tListaGrabaciones & listaGrabaciones, const tGrabacion & grabacion){
	bool ok = true;
	int i = 0;
	while (i < listaGrabaciones.contador && ok){
		if (solapan(listaGrabaciones.grabaciones[i], grabacion))
			ok = false;
		else
			i++;
	}
	if (ok && listaGrabaciones.contador < listaGrabaciones.capacidad){
		listaGrabaciones.grabaciones[listaGrabaciones.contador] = grabacion;
		listaGrabaciones.contador++;
	}
	else
		ok = false;

	return ok;
}


void mostrar(tListaGrabaciones & listaGrabaciones, int posicion){
	if (posicion < listaGrabaciones.contador){
		if (!listaGrabaciones.grabaciones[posicion].grabado){			//Si no esta grabado, se muestra.
			mostrar(*listaGrabaciones.grabaciones[posicion].programa);
		}
		mostrar(listaGrabaciones, posicion + 1);
	}
}

void destruir(tListaGrabaciones & listaGrabaciones){
	delete[] listaGrabaciones.grabaciones;
}
