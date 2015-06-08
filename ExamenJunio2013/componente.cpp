#include "componente.h"


double masIva (double precio){
  return (precio) + (precio*0.25);
}

void mostrarComponente(const tComponente & componente){
  cout << componente.codigo << " " << componente.nombre << " - " << masIva(componente.precio) << " Eur" << endl;
}
