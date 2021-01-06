#include <iostream>
#include "class.h"

using namespace std;

/************************
*                       *
*    CLASE PUNTO        *
*                       *
*************************/
//Constructor sin parametros
Punto::Punto()
{
    x = 0; y = 0;
}

//Constructor con parametros
Punto::Punto(int a, int b)
{
    x = a; y = b;
}

//Destructor
Punto::~Punto()
{
}

//Print
void Punto::printP()
{
    cout << "( " << x << " , " << y << " )";    
}

int Punto::getX()
{
    return x;
}

int Punto::getY()
{
    return y;
}

//Setters
void Punto::setX(int num)
{
    x = num;
}
void Punto::setY(int num)
{
    y = num;
}

void Punto::setXY(int a, int b)
{
    x = a;
    y = b;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/************************
*                       *
*    CLASE POLILINEA    *
*                       *
*************************/

//Constructor por defecto
Polilinea::Polilinea()
{
    num = 0;
    p = 0;
}

//Destructor
Polilinea::~Polilinea()
{
    delete [] p;
}

//Constructor de copia
Polilinea::Polilinea(Polilinea &otra)
{
    int tam = otra.getSize();
    p = new Punto[tam];
    for(int i = 0; i < tam; i++)
        p[i] = otra.getPos(i);
    num = tam;
}

//Getter of size
int Polilinea::getSize()
{
    return num;
}

//Devolucion posicion
Punto Polilinea::getPos(int pos)
{
    return p[pos];
}

//Metodo para añadir un nuevo punto a una polilinea
void Polilinea::agregarPunto (Punto point)
{
    //reservo nuevo array con una posicion mas
    Punto *aux = new Punto[num + 1];
    for(int i = 0; i < num; i++)
        aux[i] = p[i];
    aux[num] = point;
    delete [] p;
    p = aux;
    num++;
    
}


//Print
void Polilinea::imprime()//porque no puedo hacer una llamada a printP???
{
    int i;
    for(i = 0; i < num - 1; i++)
        cout << "( " << (*(p + i)).getX() << " , " << (*(p + i)).getY() << " )" << " |~|~| ";
    cout << "( " << (*(p + num - 1)).getX() << " , " << (*(p + num - 1)).getY() << " )";
    cout << endl;
}


//sobrecarga del +
Polilinea Polilinea::operator+( Polilinea &p1 /*, const Polilinea &p2*/) 
{
    int tam = p1.getSize();
    int i;
    Polilinea salida;
    //Punto aux;
    for(i = 0; i < this -> getSize(); i++)
    {
        //aux = getPos(i);
        //aux.setX((getPos(i)).getX());
        //aux.setY((getPos(i)).getY());
        salida.agregarPunto(this -> getPos(i)/*aux*/);
    }
        
    for( i = 0; i < tam; ++i)
    {
        //aux = p1.getPos(i);
        //aux.setX((p1.getPos(i)).getX());
        //aux.setY((p1.getPos(i)).getY());
        salida.agregarPunto(p1.getPos(i)/*aux*/);
    }
    
    return salida;
}

void printLogo()
{
    cout << "    #####                                                              #     #                                       #               " << endl;
    cout << "   #     # #####  ######   ##   ##### ###### #####     #####  #   #     #   #  #    # #    # #    #   ##    ####     #       # #    # " << endl;
    cout << "   #       #    # #       #  #    #   #      #    #    #    #  # #       # #   #    # ##   # #    #  #  #  #    #    #       # ##   # " << endl;
    cout << "   #       #    # #####  #    #   #   #####  #    #    #####    #         #    #    # # #  # ###### #    # #    #    #       # # #  # " << endl;
    cout << "   #       #####  #      ######   #   #      #    #    #    #   #         #    #    # #  # # #    # ###### #    #    #       # #  # # " << endl;
    cout << "   #     # #   #  #      #    #   #   #      #    #    #    #   #         #    #    # #   ## #    # #    # #    #    #       # #   ## " << endl;
    cout << "    #####  #    # ###### #    #   #   ###### #####     #####    #         #     ####  #    # #    # #    #  ####     ####### # #    # " << endl;
    cout << "******************************************************************************************************************************************" << endl;
    cout << endl;
    cout << endl;
}

void printLine()
{
    cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}