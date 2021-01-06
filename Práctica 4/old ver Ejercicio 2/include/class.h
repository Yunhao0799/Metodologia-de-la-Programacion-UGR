#ifndef CLASS_H
#define CLASS_H

#include <iostream>
class BigInt
{
    private:
        int *v;
        int tam;
        friend std::ostream& operator<<(ostream &flujo, const BigInt &number);

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
    int GetTam();

    //metodo que devuelve el elemento de una posicion
    int GetNumber(int position);

    //Metodo para sumar dos objetos de la la clase dando lugar a otro objeto de la clase
    void sumar( BigInt &obj1, BigInt &obj2);

    //Metodo para asignar un elemento en una posicion
    void SetNumber(int pos, int elemento);

    


};

//sobrecarga del operador de salida
std::ostream& operator<<(ostream &flujo, const BigInt &number);





#endif