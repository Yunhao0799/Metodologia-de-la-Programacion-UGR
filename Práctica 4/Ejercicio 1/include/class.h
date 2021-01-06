#ifndef CLASS_H
#define CLASS_H

#include <iostream>

using namespace std;

void printLogo();

void printLine();

class Barquitos
{
    private:
        int **m;
        int nfil, ncol;      

    public:
        //Constructor con el tamaño
        Barquitos(int filas, int columnas);

        //Destructor
        ~Barquitos();

        //Constructor de copia
        Barquitos(const Barquitos &otra);

        //Getters
        int getFilas() const;

        int getColumnas() const;

        int getElemento(int , int) const;

        bool newShip(int, int, int, char, bool);

        //Sobrecarga del operador de asignacion
        Barquitos& operator=(const Barquitos &tablero);

        void asignship(int, int, int, char, bool);

};

ostream& operator<<(ostream &os, const Barquitos &);


#endif