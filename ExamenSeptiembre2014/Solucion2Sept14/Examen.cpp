#include "Examen.h"

string notaCualToString(tNotaCual notaCual);

void muestra(tExamen examen) {
   cout << setw(10) << left << examen.fecha << " - "
		<< setw(5) << fixed << setprecision(2) << examen.notaNumerica << " - "
		<< setw(2) << right << notaCualToString(examen.notaCualitativa) << endl;
}

string notaCualToString(tNotaCual notaCual){
	string result;
	switch(notaCual){
		case SS:result="SS";break;
		case AP:result="AP";break;
		case B:result="B";break;
		case NT:result="NT";break;
		case SB:result="SB";break;
	}
	return result;
}

tNotaCual notaCualitativa(double notaNumerica){
	tNotaCual notaCual;
	if (notaNumerica < 5)
		notaCual = SS;
	else
		if (notaNumerica < 6)
			notaCual = AP;
		else
			if (notaNumerica < 7)
				notaCual = B;
			else
				if (notaNumerica < 9)
					notaCual = NT;
				else
					notaCual = SB;
	return notaCual;
}

void creaExamen(string fecha, double notaNum, tExamen &examen){
	examen.fecha = fecha;
	examen.notaNumerica = notaNum;
	examen.notaCualitativa = notaCualitativa(notaNum);
}