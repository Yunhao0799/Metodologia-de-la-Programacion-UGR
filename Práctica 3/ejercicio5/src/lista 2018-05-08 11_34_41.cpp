
#include "lista.h"


int Lista::longitud()
{
    int longitud = 1; //iniciamos la longitud a 1
    Celda *paux;       
    paux = primero; //copiamos en nuestro puntero auxiliar a donde apunta primero
    while (paux -> siguiente != 0)
    {
        longitud++;             //(en la primera iteraccion, si a donde apunta primero es 0, no 
        paux = (paux -> siguiente);   // entrariamos en el bucle, return longitud = 0, en caso contrario incrementamos)
    }                           //lo siguienteuiente que hacemos es copiar en nuestro puntero aux a donde
                                //apuntaba nuestro puntero auxiliar antes
    return longitud;
}

    /**
     * Metodo para agregar elemento a la lista, al inicio
     * @param valor
     */
    void Lista::agregarElemento(double valor)
    {
        //creamos un puntero y reservamos memoria
        Celda *paux = new Celda(valor);
        //le hacemos apuntar a primero
        (paux -> siguiente) = primero;
        //a primero le asiguientenamos la posicion de memoria de inicio de paux
        primero = paux;
    }

    /**
     * Metodo para imprimir el primero de la lista
     */
    void Lista::imprimir()
    {
        //inicializamos nuestro puntero axiliar
        Celda *paux;
        paux = primero;
        while((paux -> siguiente) != 0)
       {
            cout << paux -> valor << "->" ;
           paux = (paux -> siguiente);
        }
        cout << paux -> valor;
        cout << endl;
    }



    /**
     * Metodo para particionar la lista en trozos
     * @param tam
     * @param util
     * @return
     */
    Lista *Lista::particionar(int tam, int &util)
    {
        /*
        int particiones_posibles = ((longitud()/tam) + 1);
        int i, j;
        Lista *laux;
        Celda *caux;
        caux = primero;
        Lista particionados[particiones_posibles];
        
        particionados[0] = 
        
        Lista *salida = particionados;
        return salida;*/
    }