#ifndef CLASS_H
#define CLASS_H

class Punto
{
    private:
        int x,y;

    public:
        //Constructor por defecto
        Punto();

        //Constructor con parametros
        Punto(int a, int b);

        //Destructor
        ~Punto();

        //Print
        void printP();

        //Getters
        int getX();

        int getY();

        //Setters
        void setX(int );

        void setY(int );

        void setXY(int, int);



};

class Polilinea
{
    private:
        Punto *p; //array de puntos
        int num;  //numero de puntos, AKA tamaño vector
    public:
        //Constructor por defecto
        Polilinea();

        //Destructor
        ~Polilinea();

        //Constructor de copia
        Polilinea(Polilinea &otra);

        //Metodo para añadir un nuevo punto a una polilinea
        void agregarPunto (Punto point);

        //Getters
        int getSize();
        
        Punto getPos(int pos);

        //Operador de suma

        //Imprimir
        void imprime();

        //sobrecarga del +
        Polilinea operator+(  Polilinea &p1/*, const Polilinea &p2*/) ;
};

void printLogo();

void printLine();
#endif