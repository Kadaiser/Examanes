#include "Examen.h"

void muestra(const tExamen & examen){

	cout << examen.fecha << " - " << examen.nota << " - " << calificacionToString(notaToCalificacion(examen.nota)) << endl;
}

tCalificacion notaToCalificacion(double nota){
	tCalificacion calificacion;

	if(nota < 5 ) calificacion = SS;
	else if(nota >=5 && nota < 6) calificacion = AP;
	else if(nota >=6 && nota < 7) calificacion = B;
	else if(nota >=7 && nota < 9) calificacion = NT;
	else calificacion = SB;

return calificacion;
}

string calificacionToString(const tCalificacion & calificacion){
	string str;

	if(calificacion == SS) str = "SS";
	else if(calificacion == AP) str = "AP";
	else if(calificacion == B) str = "B";
	else if(calificacion == NT) str = "NT";
	else str = "SB";

	return str;
}

void creaExamen(string fecha, double nota, tExamen & examen){
	examen.fecha = fecha;
	examen.nota = nota;
	examen.calificacion = notaToCalificacion(nota);
}
