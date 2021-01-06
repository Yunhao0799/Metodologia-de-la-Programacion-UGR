#ifndef PUNTO_H
#define PUNTO_H

class Punto{
  private:
    double x, y;

  public:
    Punto(){
      x = 0;
      y = 0;
    }

    Punto(double vx, double vy){
      x = vx;
      y = vy;
    }

    double getX() const{
      return x;
    }

    double getY() const{
      return y;
    }

    void setX(double vx){
      x = vx;
    }

    void setY(double vy){
      y = vy;
    }

    void mostrar_datos() const;

    void leer_datos();
    


};


#endif
