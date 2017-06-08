#ifndef coches_h
#define coches_h

#include <string>
using namespace std;

typedef enum { mini, utilitario, monovolumen, lujo } tCategoria;

tCategoria leer();
string categoriaStr(tCategoria cat);
double factor(tCategoria cat);

#endif
