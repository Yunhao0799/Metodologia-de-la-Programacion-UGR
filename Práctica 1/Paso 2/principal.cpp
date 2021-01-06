#include <iostream>
#include "punto.h"
#include "circulo.h"
#include "utilidades.h"

using namespace std;

int main()
{
  Circulo c1, c2;

  do {
      // Se leen los datos del circulo 1
      c1.leer_Datos();

      // Igual con el circulo 2
      c2.leer_Datos();
  } while (calcularDistanciaPuntos(c1.getCentro(), c2.getCentro()) == 0);

  // Se calcula la el punto medio de los dos centros
  Punto puntoMedio=calcularPuntoMedio(c1.getCentro(), c2.getCentro());

  // Se crea objeto de la clase circulo a partir de los
  // datos
  Circulo c3(puntoMedio, calcularDistanciaPuntos(c1.getCentro(), c2.getCentro()) / 2);

  // Se muestra el resultado por pantalla
  cout << "El círculo que pasa por los dos centros es: ";
  c3.mostrar();
  cout << endl;
}
