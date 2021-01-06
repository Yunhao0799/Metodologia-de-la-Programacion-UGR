#ifndef CIRCULO_H
#define CIRCULO_H

#include "punto.h"

class Circulo {
  private:
    Punto centro;
    double radio;

  public:
    Circulo(){
      centro.setX(0);
      centro.setY(0);
      radio = 1;
    }

    Circulo(Punto vcentro, double vradio){
      centro = vcentro;
      radio = vradio;
    }

    void setCentro(Punto vcentro){
      centro = vcentro;
    }

    void setRadio(double vradio){
      radio = vradio;
    }

    Punto getCentro() const{
      return centro;
    }

    double getRadio() const{
      return radio;
    }

    void mostrar() const;

    void leer_Datos();

    double calcularArea() const;
};

#endif
