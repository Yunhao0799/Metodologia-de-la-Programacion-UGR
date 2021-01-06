#include <iostream>
#include "punto.h"

using namespace std;

void Punto::mostrar_datos() const{
  cout << "El punto solicitado es: (" << x << "," << y << ")" << endl;
}

void Punto::leer_datos() {
  cout << "Digame las coordenadas x e y del punto \n";
  cin >> x >> y;
}
