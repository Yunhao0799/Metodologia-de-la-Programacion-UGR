#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    printLogo();
    cout << "Probamos nuestro constructor" << endl;
    Barquitos tablero1(12, 12);
    cout << tablero1;

    cout << "Probemos a insertar un barco de tamaño 4" << endl;
    tablero1.asignship(2, 3, 4, 'H', 0);
    cout << tablero1;

    cout << "Y si asignamos algo que se va a salirse del mapa? " << endl;
    tablero1.asignship(3, 10, 4, 'H', 0);
    cout << tablero1;

    cout << "Vamos a probar el operador de asignacion: " << endl;
    cout << "   Nuevo tablero: " << endl;
    Barquitos tablero2(10, 2);
    cout << tablero2;
    cout << "   Una vez aplicado el operador de asignacion:" << endl;
    tablero2 = tablero1;
    cout << tablero2; 
}