#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    printLogo();

    cout << "Vamos a probar el constructor con vectores de parametros" << endl;
    int filas[] ={1, 2, 3, 4, 4};
    int columnas[] ={1, 2, 3, 4, 2};
    double valores[] ={1.0, 2.0, 3.0, 4.0, 5};
    MatrizDispersa matriz1(filas, columnas, valores, 5);
    cout << matriz1;
    //matriz1.print();
    
    cout << "Probamos el constructor de copia" << endl;
    MatrizDispersa matriz2(matriz1);
    cout << matriz2;

    cout << "Prueba del operador +" << endl;
    MatrizDispersa matriz3;
    matriz3 = matriz2 + matriz1;
    cout << matriz3;
}
