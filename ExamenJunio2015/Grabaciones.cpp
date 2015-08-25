
#include"Grabaciones.h"



void crear(tGrabaciones & grabaciones){
	grabaciones.grabacion = new tGrabacion[MAX_CAP];
	grabaciones.contador = 0;
}

bool solapan(const tGrabacion & grabacion1, const tGrabacion & grabacion2){
	bool iguales = false;
	double diferencia, duracion;
	diferencia = abs(grabacion1.programa->fecha - grabacion2.programa->fecha);
	duracion = grabacion2.programa->duracion * 60;
	if (diferencia < duracion){
		iguales = true;
	}
	return iguales;
}

bool insertar(tGrabaciones & grabaciones, const tGrabacion & grabacion){
	bool insertado = false;
	for (int i = 0; i < grabaciones.contador; i++){
		if (!solapan(grabaciones.grabacion[i], grabacion) && grabaciones.contador < MAX_CAP){
			grabaciones.grabacion[grabaciones.contador] = grabacion;
			grabaciones.contador++;
			insertado = true;
		}		
	}
	return insertado;
}

void mostrar(const tGrabaciones & grabaciones){
	for (int i = 0; i < grabaciones.contador; i++){
		if (grabaciones.grabacion[i].grabado = false){
			mostrar(*grabaciones.grabacion[i].programa);
		}		
	}
}

void destruir(tGrabaciones & grabaciones, tListaProgramas & listaProgramas){
	destruir(listaProgramas);
	delete[] grabaciones.grabacion;
}