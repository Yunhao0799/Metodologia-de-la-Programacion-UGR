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
    char v3[] = "Esto es la opcion 2";
    menu1.agregarOpcion(v3);
    char v4[] = "Esto es la opcion 3";
    menu1.agregarOpcion(v4);
    char v5[] = "Esto es la opcion 4";
    menu1.agregarOpcion(v5);

    menu1.print();

    printLine();
    cout << "Prueba del constructor de copia" << endl;
    Menu menu2(menu1);
    menu2.print();
    printLine();
    cout << endl;

    cout << "Probando el operador de asignacion =" << endl;
    Menu menu3;
    menu3 = menu1;
    menu3.print();


}