#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    printLogo();

    cout << "Pruebas constructor con parametros" << endl;
    Skyline edi1(5, 6, 7);
    edi1.print();

    double v1[] = {1, 3, 2, 4, 5};
    double v2[] = {5, 6, 8 ,7, 0};
    Skyline edi2(v1, v2, 5);
    edi2.print();

    cout << "Sobrecarga del operador []" << endl;
    cout << "Abscisas:  ";
    int i;
    for( i = 0; i < edi2.getTam(); i++)
        cout << edi2.getAbscisas(i) << " ";
    
    cout << endl;
    cout << endl;
    cout << "Mostramos la posicion 2: ";
    cout << edi2[2] << endl;
  
}