#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    cout << "     #####                                                              #     #                                       #               " << endl;
    cout << "   #     # #####  ######   ##   ##### ###### #####     #####  #   #     #   #  #    # #    # #    #   ##    ####     #       # #    # " << endl;
    cout << "   #       #    # #       #  #    #   #      #    #    #    #  # #       # #   #    # ##   # #    #  #  #  #    #    #       # ##   # " << endl;
    cout << "   #       #    # #####  #    #   #   #####  #    #    #####    #         #    #    # # #  # ###### #    # #    #    #       # # #  # " << endl;
    cout << "   #       #####  #      ######   #   #      #    #    #    #   #         #    #    # #  # # #    # ###### #    #    #       # #  # # " << endl;
    cout << "   #     # #   #  #      #    #   #   #      #    #    #    #   #         #    #    # #   ## #    # #    # #    #    #       # #   ## " << endl;
    cout << "    #####  #    # ###### #    #   #   ###### #####     #####    #         #     ####  #    # #    # #    #  ####     ####### # #    # " << endl;
    cout << "******************************************************************************************************************************************" << endl;
    cout << endl;
    cout << endl;
    
    //Constructor por defecto
    BigInt hola1(1021);
    cout << "Constructor con parametros" << endl;
    cout <<hola1;
    cout << "--------------------------------" << endl;

    BigInt hola2(hola1);
    cout << "Constructor de copia" << endl;
    cout <<hola2;
    cout << "--------------------------------" << endl;

    cout << "Casos de prueba de suma" << endl;
    cout << endl;
    cout << "CASO 1: a > b o a < b" << endl;
    BigInt hola3;
    BigInt hola4(20);
    hola3.sumar(hola1, hola4);
    cout <<hola3;
    cout << "--------------------------------" << endl;

    cout << "CASO 2: a = b" << endl;
    BigInt hola5;
    hola5.sumar(hola1, hola2);
    cout <<hola5;
    cout << "--------------------------------" << endl;

  
}