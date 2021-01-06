#ifndef CIRCULO_H
#define CIRCULO_H

#include "punto.h"

class Circulo {
  private:
    Punto centro;
    double radio;

  public:
    Circulo(){      //Por que no puedo hacer centro(0,0) , no hace dfalta poner 0,0; por defecto, al declarar una clase punto se inicializa en 0,0
      /*centro.setX(0);
      centro.setY(0);
      */
      //por lo tanto la forma correcta de declararla seria:
      Punto centro;
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
