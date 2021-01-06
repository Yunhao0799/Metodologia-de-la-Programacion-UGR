#include <iostream>
#include "class.h"


using namespace std;

int main()
{
    printLogo();

    cout << "Constructor por defecto" << endl;
    Presecuencias presecuencia1;
    presecuencia1.agregarValor(1);
    presecuencia1.agregarValor(1);
    presecuencia1.agregarValor(1);
    presecuencia1.agregarValor(1);
    presecuencia1.agregarValor(3);
    presecuencia1.agregarValor(3);
    presecuencia1.agregarValor(4);
    presecuencia1.print();

    cout << "Constructor de copia" << endl;
    Presecuencias presecuencia2(presecuencia1);
    presecuencia2.print();

    Presecuencias presecuencia3;
    presecuencia3.agregarValor(4);


    cout << "Test de la sobrecarga del operador ==" << endl;
    cout << "Comprobamos si dos elementoa de la clase Presecuencias son iguales, una de ellas obtenida aplicando el constructor de copia" << endl;
    cout << "Presecuencia1: " << endl;
    presecuencia1.print();
    cout << "Presecuencia2: " << endl;
    presecuencia2.print();
    if(presecuencia1 == presecuencia2)
        cout << "Son iguales" << endl;
    else   
        cout << "Son distintos" << endl;
    cout << endl;
    cout << endl;
    cout << "Dos elementos de la crase presecuencia distintos" << endl;
    cout << "Presecuencia1: " << endl;
    presecuencia1.print();
    cout << "Presecuencia3: " << endl;
    presecuencia3.print();
    if(presecuencia1 == presecuencia3)
        cout << "Son iguales" << endl;
    else   
        cout << "Son distintos" << endl;
    printLine();
    cout << endl;
    cout << endl;
    cout << endl;

    
    cout << "Test de la sobrecarga del operador !=" << endl;
    cout << "Comprobamos si dos elementoa de la clase Presecuencias son iguales, una de ellas obtenida aplicando el constructor de copia" << endl;
    cout << endl;
    cout << "Presecuencia1: " << endl;
    presecuencia1.print();
    cout << "Presecuencia2: " << endl;
    presecuencia2.print();
    if(presecuencia1 != presecuencia2)
        cout << "Son distintos" << endl;
    else   
        cout << "Son iguales" << endl;
    cout << endl;
    cout << endl;
    cout << "Dos elementos de la clase presecuencia distintos" << endl;
    cout << "Presecuencia1: " << endl;
    presecuencia1.print();
    cout << "Presecuencia3: " << endl;
    presecuencia3.print();
    if(presecuencia1 != presecuencia3)
        cout << "Son distintos" << endl;
    else   
        cout << "Son iguales" << endl;
    printLine();
  
}