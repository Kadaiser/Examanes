#include "empleado.h"


void muestraEmpleado(const tEmpleado & empleado){
	cout << empleado.codigo << " " << empleado.jornada.horas <<":" << empleado.jornada.minutos;
	cout << " " << empleado.nombre << endl;
}

void crearEmpleado(tEmpleado& empleado, int codigo, string nombre, int numDepartamento){
	empleado.codigo = codigo;
	empleado.nombre = nombre;
	empleado.departamento = intToDepartamento(numDepartamento);
	empleado.jornada.horas = 0;
	empleado.jornada.minutos = 0;
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

int departamentoToInt(const tDepartemento & departamento){
	int  numDepartamento;
		if(departamento == Informatica) numDepartamento = 0;
		else if(departamento == Informatica) numDepartamento = 1;
		else if(departamento == Informatica) numDepartamento = 2;
		else numDepartamento = 3;

	return numDepartamento;
}

bool perteneceDepartamento(const tEmpleado & empleado, int numDepartamento){
	tDepartemento departamento;
	bool pertenece = false;
	
	if(numDepartamento == departamentoToInt(empleado.departamento))
		pertenece = true;
	
	return pertenece; 
}

void mostrarDepartamentos(){
	cout << "0 - Informática" << endl;
	cout << "1 - RRHH" << endl;
	cout << "2 - Publicidad" << endl;
	cout << "3 - Ventas" << endl;
}
