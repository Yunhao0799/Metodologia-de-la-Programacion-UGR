#include <iostream>
#include "class.h"

using namespace std;

//constructor sin parametros
BigInt::BigInt()
{
    tam = 1;
    v = new int [tam];
    v[0] = 0;
}


//constructor con parametros
BigInt::BigInt (int number)
{
    int i;
    if(number == 0)
    {
        tam = 1;
        v = new int [tam];
        v[0] = 0;
    }
    else
    {
        int auxiliar1, auxiliar2;
        int contador = 0;
        auxiliar1 = number;
        while( auxiliar1 > 0)
        {
            auxiliar1 = auxiliar1/10;
            contador++;
        }    
        auxiliar1 = number;
        v = new int[contador];

        for (i = 0; i < contador; i++)
        {
            auxiliar2 = auxiliar1%10;
            auxiliar1 = auxiliar1/10;
            v[i] = auxiliar2;
        }
        this -> tam = contador;
    }

}
/*
//Constructor con parametros dado un tamaño
BigInt::BigInt(int tama)
{
    if(tama > 0)
    {
        v = new int[tama];
        for(int i = 0; i < tama; i++)
            v[i] = 0;
    }
}
*/
//Destructor
BigInt::~BigInt()
{
    delete [] v;
}

//constructor de copia
BigInt::BigInt(BigInt &acopiar)
{
    int tama = acopiar.GetTam();
    this -> tam = tama;
    v = new int[tam];
    for (int i = 0; i < tam; i++)
        v[i] = acopiar.GetNumber(i);
}

//metodo que nos devuelve el tamaño de un elemento de la clase

int BigInt::GetTam()
{
    return tam;
}

//metodo que devuelve el elemento de una posicion
int BigInt::GetNumber(int position)
{
    return *(v + position);
}

//Metodo para sumar dos objetos de la la clase dando lugar a otro objeto de la clase
void BigInt::sumar( BigInt &obj1, BigInt &obj2)
{
    int i;
    int tam1 = obj1.GetTam(), tam2 = obj2.GetTam();
    if (tam1 >= tam2)
    {
        v = new int [tam1];
        tam = tam1;
        for(i = 0; i < tam1; i++)
            v[i] = obj1.GetNumber(i);
        for(i = 0; i < tam2; i++)
            v[i] = v[i] + obj2.GetNumber(i);
    }

    else
    {
        v = new int [tam2];
        tam = tam2;
        for(i = 0; i < tam2; i++)
            v[i] = obj2.GetNumber(i);
        for(i = 0; i < tam1; i++)
            v[i] = v[i] + obj1.GetNumber(i);
    }
}

//sobrecarga del operador de salida
std::ostream& operator<<(ostream &flujo, const BigInt &number)
{
    
    for (int i = number.GetTam() - 1; i > -1 ; i--)
        flujo << number.GetNumber(i);
    flujo << endl;
    return flujo;
}
/*
//Metodo para asignar un elemento en una posicion
void BigInt::SetNumber(int pos, int elemento)
{
    v[pos] = elemento;
    

}*/
/*
//sobrecarga del operador de salida
ostream& operator<<(ostream &flujo, const BigInt &number)
{
    
    for (int i = number.GetNumber() - 1; i > -1 ; i--)
        flujo << number.GetNumber(i);
    flujo << endl;
    return flujo;
}
*/