#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    printLogo();
    
    cout << "Prueba del metodo agregaPunto:" << endl;
    cout << endl;
    Polilinea polilinea1;
    Punto punto1(784,289);
    Punto punto2(456,89);
    Punto punto3(8,16);
    polilinea1.agregarPunto(punto1);
    polilinea1.agregarPunto(punto2);
    polilinea1.agregarPunto(punto3);
    polilinea1.imprime();
    printLine();
    
    cout << "Prueba del constructor de copia" << endl;
    cout << endl;
    Polilinea polilinea2(polilinea1);
    polilinea2.imprime();
    printLine();

    
    cout << "Prueba sobrecarga del operador '+'" << endl;
    cout << endl;
    Polilinea polilinea3;
    polilinea3 = polilinea1 + polilinea2;
    polilinea3.imprime();
    printLine();
    
    
  
}