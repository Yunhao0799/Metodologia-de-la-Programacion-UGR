#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "punto.h"
#include "circulo.h"


double calcularDistanciaPuntos(Punto p1, Punto p2);

Punto calcularPuntoMedio(Punto p1, Punto p2);

double calcularDistanciaCirculos(Circulo c1, Circulo c2);

bool comprobarInterior(Punto p, Circulo c);


#endif
