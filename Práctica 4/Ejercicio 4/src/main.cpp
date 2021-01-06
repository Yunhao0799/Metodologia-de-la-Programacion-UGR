#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    printLogo();

    cout << "Prueba mostrar lista inicial" << endl;
    cout << endl;
    Lista lista1;
    lista1.agregarInicio(10);
    lista1.agregarInicio(9);
    lista1.agregarInicio(8);
    lista1.agregarInicio(7);
    lista1.agregarInicio(6);
    lista1.agregarInicio(5);
    lista1.agregarInicio(4);
    lista1.agregarInicio(3);
    lista1.agregarInicio(2);
    lista1.agregarInicio(1);
    cout << lista1;
    cout << "Prueba del constructor de copia" << endl;
    Lista lista2(lista1);
    cout << lista2;
  
}