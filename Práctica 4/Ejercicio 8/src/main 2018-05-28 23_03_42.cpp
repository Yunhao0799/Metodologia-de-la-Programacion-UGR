#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    printLogo();
    
    cout << "Probamos nuestro metodo de agregar el titulo:" << endl;
    Menu menu1;
    char v[] = "Esto es el titulo";
    menu1.setTitulo(v);
    char v2[] = "Esto es la opcion 1";
    menu1.agregarOpcion(v2);
    menu1.print();

}