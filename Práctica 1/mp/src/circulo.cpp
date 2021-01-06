#include <iostream>
#include <cmath>
#include "circulo.h"

using namespace std;

void Circulo::mostrar() const{
  centro.mostrar_datos();
  cout << "\n El radio es " << radio;
}

void Circulo::leer_Datos (){
  cout << "Dime el radio \n";
  cin >> radio;
  Punto vcentro;
  vcentro.leer_datos();
}

double Circulo::calcularArea() const {
    double area=2*M_PI*pow(radio,2);
    return area;
}
