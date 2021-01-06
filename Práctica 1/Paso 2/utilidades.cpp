#include <cmath>
#include "utilidades.h"

double calcularDistanciaPuntos(Punto p1, Punto p2){
  double x1, y1, x2, y2, distancia;

  x1 = p1.getX();
  y1 = p1.getY();
  x2 = p1.getX();
  y2 = p1.getY();
  distancia = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));

  return distancia;
}

Punto calcularPuntoMedio(Punto p1, Punto p2){
  double x1, x2, y1, y2, xmedio, ymedio;
  Punto puntosalida;

  x1 = p1.getX();
  y1 = p1.getY();
  x2 = p1.getX();
  y2 = p1.getY();
  xmedio = (x1 + x2) / 2;
  ymedio = (y1 + y2) / 2;
  puntosalida.setX(xmedio);
  puntosalida.setY(ymedio);

  return puntosalida;
}

double calcularDistanciaCirculos(Circulo c1, Circulo c2){
  Punto centro1, centro2;
  double distancia;

  centro1 = c1.getCentro();
  centro2 = c2.getCentro();
  distancia = calcularDistanciaPuntos(centro1, centro2);

  return distancia;
}

bool comprobarInterior(Punto p, Circulo c){
  Punto centro;
  double distancia, radio;
  bool interior = false;

  centro=c.getCentro();
  radio=c.getRadio();
  distancia=calcularDistanciaPuntos(p, centro);
  if(distancia <= radio)
      interior=true;

  return interior;
}
