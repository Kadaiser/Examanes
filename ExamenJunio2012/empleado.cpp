#include "empleado.h"

void inicializar(tEmpleado & empleado){
	empleado.companieros  = new int [MAXDEPARTAMENTO];
}

void crearEmpleado(tEmpleado& empleado, int numeroEmpleado, string nombre, int numDepartamento){
	empleado.numeroEmpleado = numeroEmpleado;
	empleado.nombre = nombre;
	empleado.departamento = intToDepartamento(numDepartamento);
	inicializar(empleado);
	empleado.jornada.horas = 0;
	empleado.jornada.minutos = 0;
}

void destruir(tEmpleado & empleado){
	delete[] empleado.companieros;
}

void insertarJornada(tEmpleado & empleado, tJornada & jornada){
	
}

tDepartemento intToDepartamento(int numDepartamento){
	tDepartemento departamento;
		if(numDepartamento = 0) departamento = Informatica;
		else if(numDepartamento = 1) departamento = RRHH;
		else if(numDepartamento = 2) departamento = Publicidad;
		else departamento = Ventas;
		
	return departamento;
}

string departamentoToString(const tDepartemento & departamento){
	string str;
	return str;
}
