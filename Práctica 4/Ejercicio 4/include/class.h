#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;
/********************************
*                               *
*          CLASS CELDA          *
*                               *
********************************/

/**
 * Clase Celda para implementar una lista enlazada
 */
class Celda {
private:
    /**
     * Dato miembro para almacenar la informacion de la celda
     */
    double info;
 
    /**
     * Puntero a la siguiente celda que compone la lista
     */
    Celda *sig;
public:

    /**
     * Constructor de la clase
     */
    Celda(double info);

    /**
     * Recupera el valor almacenado en una celda
     * @return
     */
    double obtenerInfo() const;

    /**
     * Devuelve puntero a la celda siguiente
     * @return sig
     */
    Celda *obtenerSiguiente() const;

    /**
     * Se asigna valor cero al puntero siguiente
     */
    void anularSiguiente();

    /**
     * Se asigna el valor de siguiente
     */
    void asignarSiguiente(Celda *pCelda);

    /**
     * Metodo para imprimir el contenido de una celda
     */
    void mostrar();
};

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/********************************
*                               *
*          CLASS LISTA          *
*                               *
********************************/

/**
 * Clase Lista, clase para acceder a la funcionalidad
 * de una lista enlazada
 */ 
class Lista {
private:
    /**
     * Puntero a la primera celda de la lista, que permite
     * acceder a la funcionalidad completa de la lista
     */
    Celda *contenido;
    friend ostream& operator<<(ostream& flujo, const Lista &listilla);

public:
    /**
     * Constructor de la clase
     */
    Lista();

    /**
     * Metodo para imrimir el contenido de la lista
     */
    void mostrar();

    /**
     * Metodo para obtener la longitud de la lista
     * @return
     */
    int obtenerLongitud() const;

    /**
     * Metodo para aniadir un elemento al final de la lista
     * @param dato
     */
    void agregarFinal(double dato);

    /**
     * Metodo para insertar un nuevo elemento al inicio de la lista
     * @param dato
     */
    void agregarInicio(double dato);

    /**
     * Metodo para imrimir el contenido de la lista
     * en sentido inverso: desde final a inicio
     */
    void imprimirInvertido();

    /**
     * Metodo para eliminar el ultimo elemento de la lista
     */
    void eliminarFinal();

    /**
     * Obtiene la celda que ocupa una determinada posicion
     * de la lista
     * @param posicion
     * @return direccion de la celda o null si no la encuentra
     */
    Celda *obtener(int posicion) const;

    /**
     * Metodo para insertar una celda en una determinada posicion
     * @param indice posicion de insercion
     * @param dato dato a insertar
     * @return
     */
    bool agregarPosicion(int indice, double dato);

    /**
     * Metodo para eliminar todas las celdas de la lista
     */
    void liberarEspacio();

};

//sobrecarga del operador de salida
ostream& operator<<(ostream& flujo, const Lista &listilla);

void printLogo();

void printLine();

#endif