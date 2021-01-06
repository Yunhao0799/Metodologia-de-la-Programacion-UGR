#include <iostream>
#include "class.h"

using namespace std;

/********************************
*                               *
*          CLASS CELDA          *
*                               *
********************************/

//Constructor de la clase
Celda::Celda(double info)
{
    this -> info = info;
    this -> sig = 0;
}

/**
* Recupera el valor almacenado en una celda
* @return
*/
double Celda::obtenerInfo() const
{
    return info;
}

/**
* Devuelve puntero a la celda siguiente
* @return sig
*/
Celda *Celda::obtenerSiguiente() const
{
    return sig;
}

/**
 *  * Se asigna valor cero al puntero siguiente
*/ 
void Celda::anularSiguiente()
{
    sig = 0;    //"this -> sig = 0;" esto nos esta diciendo que el valor de sig = 0;
}

/**
* Se asigna el valor de siguiente
*/
void Celda::asignarSiguiente(Celda *pCelda)
{
    sig = pCelda;
}

/**
* Metodo para imprimir el contenido de una celda
*/
void Celda::mostrar()
{
    cout << info << "   ";
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/********************************
*                               *
*          CLASS LISTA          *
*                               *
********************************/

/**
* Constructor de la clase   ¿TENDRIAMOS QUE CREAR UN CONSTRUCTOR DE LA CLASE SIN PARAMETROS?
*/
Lista::Lista()
{
    contenido = new Celda(0);
}

/**
* Metodo para imrimir el contenido de la lista
*/
void Lista::mostrar()
{
    Celda *paux;
    paux = contenido;
    while((paux -> obtenerSiguiente()) -> obtenerSiguiente()!= 0)
    {
        paux = (paux -> obtenerSiguiente());
        cout << paux -> obtenerInfo() << "->" ;
        
    }
    cout << (paux -> obtenerSiguiente()) -> obtenerInfo();   
    cout << endl;

}

/**
* Metodo para obtener la longitud de la lista
* @return
*/
int Lista::obtenerLongitud() const
{
    int longitud = 1; //iniciamos la longitud a 0
    Celda *paux;       
    paux = (contenido -> obtenerSiguiente()); //copiamos en nuestro puntero auxiliar a donde apunta contenido
    while (paux -> obtenerSiguiente() != 0)
    {
        longitud++;             //(en la primera iteraccion, si a donde apunta contenido es 0, no 
        paux = (paux -> obtenerSiguiente());   // entrariamos en el bucle, return longitud = 0, en caso contrario incrementamos)
    }                           //lo siguiente que hacemos es copiar en nuestro puntero aux a donde
                                //apuntaba nuestro puntero auxiliar antes
    return longitud;
}

/**
* Metodo para aniadir un elemento al final de la lista
* @param dato
*/
void Lista::agregarFinal(double dato)
{
    Celda *novo = new Celda(dato);
    //Declaro un puntero aux
    Celda *paux;
    //inicio el puntero en la segunda posicion desde el final de nuestra lista
    paux = contenido;
    //mientras donde apunta el siguiente sea != 0, reasigno a donde apunta nuestro punter
    while(paux-> obtenerSiguiente() != 0)
    {
        paux = (paux -> obtenerSiguiente());
    }
    //una vez terminado el bucle,la sig celda donde apunta nuestro paux es 0;
    //reservamos nueva celda
    //(paux -> obtenerSiguiente()) = new Celda(dato);
    //y le hacemos apuntar a 0;
    (paux /*-> obtenerSiguiente()*/) -> asignarSiguiente(novo);
    
    //(paux -> obtenerSiguiente()) -> asignarSiguiente(0);

}

/**
* Metodo para insertar un nuevo elemento al inicio de la lista
* @param dato
*/
void Lista::agregarInicio(double dato)
{
    //creamos un puntero y reservamos memoria
    Celda *paux = new Celda(dato);
    //le hacemos apuntar a contenido
    (paux -> asignarSiguiente(contenido));
    //a contenido le asignamos la posicion de memoria de inicio de paux
    contenido = paux;
   
}

/**
* Metodo para imrimir el contenido de la lista
* en sentido inverso: desde final a inicio
*/
void Lista::imprimirInvertido()
{
    const int TAM = obtenerLongitud();
    double v[TAM];
    int i = 0;
    //declaramos un puntero auxiliar con el valor de contenido
    Celda *paux = contenido;
    while((paux -> obtenerSiguiente()) != 0)
    {
        //al valor de v[i] le asignamos el valor de la celda e incrementamos contadores
        v[i] = (paux -> obtenerInfo());
        paux = (paux -> obtenerSiguiente());
        i++;
    }
    //imprimimos el vector
    for ( i = TAM; i > 1; i--)
        cout << v[i] << " -> ";
    cout << v[0];

    cout << endl;
}

/**
* Metodo para eliminar el ultimo elemento de la lista
*/
void Lista::eliminarFinal()
{
    //Declaro un puntero auxiliar
    Celda *paux;
    
    //le asignamos la posicion de inicio de nuestra lista
    paux = contenido;

    while(((paux -> obtenerSiguiente()) -> obtenerSiguiente()) != 0)
        paux = (paux -> obtenerSiguiente());

    delete [] (paux -> obtenerSiguiente());
    paux -> anularSiguiente();
}

/**
* Obtiene la celda que ocupa una determinada posicion
* de la lista
* @param posicion
* @return direccion de la celda o null si no la encuentra
*/
Celda *Lista::obtener(int posicion) const
{
    //obtenemos la longitud
    int longi = obtenerLongitud();
    //inicializamos nuestro puntero auxiliar a 0
    Celda *paux;
    //vemos si es obtenible
    if (posicion <= longi)
    {
        //int a_recorrer = longi - posicion;
        //declaramos un puntero aux
        paux = contenido;
        for(int i = 0; i < posicion + 1; i++)
        {
            paux = paux -> obtenerSiguiente();
        }
    }

    return paux;

}

/**
* Metodo para insertar una celda en una determinada posicion
* @param indice posicion de insercion
* @param dato dato a insertar
* @return
*/
bool Lista::agregarPosicion(int indice, double dato)
{
    int i;
    //declaramos nuestro puntero auxiliar y lo igualamos a contenido
    Celda *paux = contenido;
    for(i = 0; i < indice; i++)
    {
        paux = (paux -> obtenerSiguiente());
    }
    //estamos en la posicion donde le vamas a insertar
    //vamos a necesitar otro auxiliar para guardar el sig de paux
    Celda *paux2 = paux -> obtenerSiguiente();
    //hacemos que en la posicion que estamos, el siguiente apunte a una nueva celda
    //(paux -> obtenerSiguiente()) ;//= new Celda(dato);
    //"incrementamos" el contador
    paux = (paux -> obtenerSiguiente());
    //le hacemos asignar a paux el trozo de lista quhe nos quedaba 
    (paux -> asignarSiguiente(paux2)); //= paux2;

    contenido = paux;
}    

/**
* Metodo para eliminar todas las celdas de la lista
*/
void Lista::liberarEspacio()
{
    int i;
    //creamos nuestro puntero auxiliar
    Celda *paux;
    for (i = 0; i < (obtenerLongitud()); i++)
    {
        //inicializamos nuestro puntero en contenido
        paux = contenido;
        while(((paux -> obtenerSiguiente()) -> obtenerSiguiente()) != 0)
            paux = (paux -> obtenerSiguiente());
        //nos situamos en el penultimo, borramos todo
        delete [] (paux -> obtenerSiguiente());
        paux -> anularSiguiente();
    }
    delete [] (paux -> obtenerSiguiente());
    paux -> anularSiguiente();
    contenido = paux;
} 

//sobrecarga del operador de salida
ostream& operator<<(ostream& flujo, const Lista &listilla)
{
    Celda *paux;
    paux = listilla.contenido;
    while((paux -> obtenerSiguiente()) -> obtenerSiguiente() != 0)
    {
        
        flujo << paux -> obtenerInfo() << "->" ;
        paux = (paux -> obtenerSiguiente());
        
    }
    flujo << (paux -> obtenerInfo());   
    flujo << endl;

    
    printLine();

    return flujo;
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