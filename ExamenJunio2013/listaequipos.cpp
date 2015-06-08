#include "listaequipos.h"


void inicializar(tListaEquipos & listaEquipos){
listaEquipos.contador = 0;
}


bool cargaEquipos(tListaEquipos & listaEquipos){
	bool ok = false;
	int pos;
	ifstream archivo;
	string codigo;

	archivo.open(FICHERO);

	if(archivo.is_open()){
		archivo >> codigo;
		while(codigo != CENTINELA){

			tEquipo equipo;
			equipo.codigo = codigo;
			inicializar(equipo.perifericos);

			tComponente componente;
			archivo >> componente.codigo;
			archivo >> componente.precio;
			getline(archivo, componente.nombre);
			if(!buscaEquipo(listaEquipos, codigo, pos)){
				insertaComponente(equipo, componente);
				insertaEquipo(listaEquipos, equipo, pos);


			}
			else{

				insertaComponente(listaEquipos.equipos[pos], componente);
			}



		archivo >> codigo;
		}
		archivo.close();
		ok = true;
	}
	else
		cout << "Error al abrir el fichero" << endl;
	return ok;
}


bool buscaEquipo(const tListaEquipos & listaEquipos, string codigo, int & pos){
	int ini = 0, fin = listaEquipos.contador -1, mitad;
	bool encontrado = false;

	while(ini <= fin && !encontrado){
			mitad = (ini + fin) / 2;
		if(codigo < listaEquipos.equipos[mitad].codigo){
			mitad = mitad - 1;
		}
		else if(listaEquipos.equipos[mitad].codigo < codigo){
			mitad = mitad + 1;
		}
		else encontrado = true;
	}
	if(encontrado) pos = mitad;
	else pos = ini;
	return encontrado;
}


bool insertaEquipo(tListaEquipos & listaEquipos, const tEquipo & equipo, int pos){
	bool ok = false;
	if(listaEquipos.contador < MAXEQUIPOS){
		for(int i= listaEquipos.contador; i > pos; i--){
			listaEquipos.equipos[i] = listaEquipos.equipos[i -1];
		}

		listaEquipos.equipos[pos]= equipo;
		listaEquipos.contador++;
		ok = true;
	}
	else{
		cout << "La lista de equipos esta llena" << endl;
	}

	return ok;
}


void muestraEquipos(const tListaEquipos & listaEquipos){
	for(int i = 0; i < listaEquipos.contador; i++){
		muestraEquipo(listaEquipos.equipos[i]);
		precioEquipo(listaEquipos.equipos[i]);
	}
}

/**
* aplica a todos los componentes el porcentaje de incremento que
* se proporciona, actualizando los precios de los equipos.
*/
void actualiza(tListaEquipos & listaEquipos, double porcentaje){
}

void destruir(tListaEquipos & listaEquipos){
	for (int i = 0; i < listaEquipos.contador; i++){
	destruye(listaEquipos.equipos[i].perifericos);
	}
}
