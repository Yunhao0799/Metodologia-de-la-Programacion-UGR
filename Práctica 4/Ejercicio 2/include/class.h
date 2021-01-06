#ifndef CLASS_H
#define CLASS_H

#include <iostream>

using namespace std;

class BigInt
{
    private:
        int *v;
        int tam;

    public:

    //Constructor por defecto
    BigInt();

    //constructor con parametros
    BigInt(int number);

    //Constructor con parametros dado un tamaño
    //BigInt::BigInt(int tama);

    //destructor
    ~BigInt();

    //constructor de copia
    BigInt(BigInt &acopiar);

    //Metodo que nos devuelve el tamaño
    int GetTam()const;

    //metodo que devuelve el elemento de una posicion
    int GetNumber(int position)const;

    //Metodo para sumar dos objetos de la la clase dando lugar a otro objeto de la clase
    void sumar( BigInt &obj1, BigInt &obj2);

    //Metodo para asignar un elemento en una posicion
    void SetNumber(int pos, int elemento);

    


};

//sobrecarga del operador de salida
ostream& operator<<(ostream &flujo, const BigInt &number);


void printLogo();

void printLine();


#endif
