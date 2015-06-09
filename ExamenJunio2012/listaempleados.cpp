#include "listaempleados.h"

void inicializar (tListaEmpleados & listaEmpleados){
	listaEmpleados.empleados = new tEmpleado [MAXEMPLEADOS];
	listaEmpleados.contador = 0;
}

bool buscarCodigo(const tListaEmpleados & listaEmpleados, int codigo, int & pos){
	int fin = listaEmpleados.contador -1, ini = 0, mitad;
		bool encontrado = false;
		
	while(ini <= fin && !encontrado){
		mitad = (ini + fin) / 2;
		if(codigo < listaEmpleados.empleados[mitad].codigo){
			fin = mitad -1;
		}
		else if(listaEmpleados.empleados[mitad].codigo < codigo){
			ini = mitad +1;
		}
		else encontrado = true;
		}
	if(encontrado) pos = mitad;
	else pos = ini;
	return encontrado;
}

void GenerarEmpleado(tListaEmpleados & listaEmpleados){
	int codigo, pos;
	string nombre;
	int numDepartamento;
	
	if (listaEmpleados.contador < MAXEMPLEADOS){
		cout << "inserte el codigo de empleado a crear: ";
		cin >> codigo;
		cin.sync();
		
		if(!buscarCodigo(listaEmpleados, codigo, pos)){
			tEmpleado empleado;
			cout << endl << "inserte el nombre completo del empleado: ";
			getline(cin, nombre);
			mostrarDepartamentos();
			cout << endl << "indique el departamento del empleado: ";
			cin >> numDepartamento;
			cin.sync();
			crearEmpleado(empleado,codigo,nombre,numDepartamento);
			cout << endl << "El empleado se genero correctamente ";
			insertarEmpleado(listaEmpleados,empleado, pos);
				cout << " y se inserto en la lista de empleados" << endl;
		}
		else{
			cout << "El empleado ya existe" << endl;
		}
	}
	else
		cout << "La lista de empleados esta llena" << endl;
}

void insertarEmpleado(tListaEmpleados & listaEmpleados, const tEmpleado & empleado,int pos){
	
	for(int i = listaEmpleados.contador; i > pos; i++){
		listaEmpleados.empleados[i] = listaEmpleados.empleados[i - 1];
	}
	listaEmpleados.empleados[pos] = empleado;
	listaEmpleados.contador++;
}

void eliminarDepartamento (tListaEmpleados & listaEmpleados){
	int numDepartamento, pos = 0;
	mostrarDepartamentos();
	cout << "Seleccione el departamento que desea eliminar:  " << endl;
	do{
	cin >> numDepartamento;
	cin.sync();
	}while(numDepartamento < 0 || numDepartamento > 3);
	
	while(pos < listaEmpleados.contador){
		if(perteneceDepartamento(listaEmpleados.empleados[pos], numDepartamento)){
			eliminarEmpleado(listaEmpleados,listaEmpleados.empleados[pos], pos);
		}
		else
			pos++;
	} 
	cout << "Se han eliminado los empelados del departamento." << endl;

}

void eliminarEmpleado(tListaEmpleados &listaEmpleados, const tEmpleado & empleado, int pos){
	if ((pos < 0) || (pos >= listaEmpleados.contador)){
	}
	else{
		for(int i = pos + 1; i < listaEmpleados.contador; i++)
		listaEmpleados.empleados[i - 1] = listaEmpleados.empleados[i];
    listaEmpleados.contador--;
  }
}

void listado(const tListaEmpleados & listaEmpleados){
	cout << "Lista de emleados" << endl << endl;
	for(int i = 0; i < listaEmpleados.contador; i++){
	muestraEmpleado(listaEmpleados.empleados[i]);
	}
}

void guardar(const tListaEmpleados & listaEmpleados){
	ofstream fichero;
	
	fichero.open(BACKUP);
	for (int i = 0; i < listaEmpleados.contador; i++){
	fichero << listaEmpleados.empleados[i].codigo << " ";
	fichero << listaEmpleados.empleados[i].jornada.horas  << ":";
	fichero << listaEmpleados.empleados[i].jornada.minutos << endl;	
	}
	fichero.close();
}

void destruir(tListaEmpleados & listaEmpleados){
	delete[] listaEmpleados.empleados;
}
