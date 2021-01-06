#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    printLogo();
    
    //Constructor por defecto
    BigInt hola1(1091);
    cout << "Constructor con parametros" << endl;
    cout << "   ";
    cout << hola1;
    printLine();

    BigInt hola2(hola1);
    cout << "Constructor de copia" << endl;
    cout << "   ";
    cout << hola2;
    printLine();

    cout << "Casos de prueba de suma" << endl;
    cout << endl;
    cout << "   CASO 1: a > b o a < b" << endl;
    cout << "       ";
    BigInt hola3;
    BigInt hola4(20);
    hola3.sumar(hola1, hola4);
    cout << hola3;
    printLine();

    cout << "   CASO 2: a = b" << endl;
    cout << "       ";
    BigInt hola5;
    hola5.sumar(hola1, hola2);
    cout << hola5;
    printLine();

  
}