#include iostream
using namespace std;

 Cabeceras de las funciones
bool esTriangulo(double a, double b, double c);
bool esIsosceles(double a, double b, double c);
bool esEquilatero(double a, double b, double c);
bool esEscaleno(double a, double b, double c);
double leerLongSegm(int i);

 Implementaci?n de las funciones
double leerLongSegm(int i) {
	double num;
	cout  Introduce la longitud del segmento   i   ;
	cin  num;
	while (cin.fail()) {
		cin.clear(); cin.sync();
		cout  Numero no valido!  Introduce un n?mero entero  ;
		cin  num;
	}
	cin.sync();
	return num;
}

bool esTriangulo(double a, double b, double c){
	return (a  0) && (b  0) && (c  0) && (a + b  c) && (a + c  b) && (b + c  a);
}

bool esIsosceles(double a, double b, double c){
	return esTriangulo(a, b, c) && (((a == b) && (b != c))  ((a == c) && (b != c))  ((b == c) && (a != c)));
}

bool esEquilatero(double a, double b, double c){
	return esTriangulo(a, b, c) && (a == b) && (b == c);
}

bool esEscaleno(double a, double b, double c){
	return esTriangulo(a, b, c) && (a != b) && (a != c) && (b != c);
}

int main(){
	 las tres longitudes de los segmentos.
	double longSeg1, longSeg2, longSeg3;

	 lectura de datos
	longSeg1 = leerLongSegm(1);
	longSeg2 = leerLongSegm(2);
	longSeg3 = leerLongSegm(3);

	 mostrar resultados
	if (esTriangulo(longSeg1, longSeg2, longSeg3)) {
		cout  Tus l?ngitudes forman un tri?ngulo ;
		if (esIsosceles(longSeg1, longSeg2, longSeg3))
			cout  isosceles.;
		else if (esEquilatero(longSeg1, longSeg2, longSeg3))
			cout  equilatero.;
		else
			cout  escaleno.;
	}
	else
		cout  Tus longitudes NO forman un tri?ngulo.;
	cout  endl;


	system(pause);

	return 0;
}
