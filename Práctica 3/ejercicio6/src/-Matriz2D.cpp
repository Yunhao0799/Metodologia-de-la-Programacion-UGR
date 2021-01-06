
#include <iostream>
#include "Matriz2D.h"
#include <stdlib.h>

using namespace std;


// Constructor de la clase
Matriz2D::Matriz2D(int numeroFilas, int numeroColumnas)
{
    matriz = new int*[numeroFilas];
    for( int i = 0; i < numeroFilas; ++i)
        matriz[i] = new int[numeroColumnas];
}
   
// Constructor de copia
Matriz2D::Matriz2D(const Matriz2D & objeto)
{
    /*
    int i, j;
    Matriz2D copia;

    copia.matriz = new int *[numeroFilas];

    for( int i = 0; i < numeroFilas; ++i)
        copia.(matriz[i]) = new int[numeroColumnas];

    for (i = 0; i < numeroFilas; i++)
    {
        for(j = 0; j < numeroColumnas; j++)
            copia.asignarValor(i, j, matriz[i][j]);
    }

    &objeto = &copia;

    delete [] copia.(matriz[0]);

    delete[] copia.matriz;
    */
    objeto.obtenerFilas(numeroFilas);
	objeto.obtenerColumnas(numeroColumnas);

    matriz = new int*[numeroFilas];
    for( int i = 0; i < numeroFilas; ++i)
        matriz[i] = new int[numeroColumnas];
    
    for (int i = 0; i < numeroFilas; i++){
			for (int j = 0; j < numeroColumnas; j++)
				matriz[i][j] = objeto.obtenerValor(i, j);

}
   
// Destructor
Matriz2D::~Matriz2D()
{
    for (int i = 0; i < numeroFilas; ++i)
        delete[] matriz[i];
    delete[] matriz;
}
   
// Asignar valor a posicion
void Matriz2D::asignarValor(int fila, int columna, int valor)
{
    matriz[fila][columna] = valor;
}
   
// Metodo para mostrar por pantalla

void Matriz2D::mostrarPantalla()
{
    int i, j;
    for(i = 0; i < numeroFilas; i++)
    {
        for(j = 0; j < numeroColumnas; j++)
            cout << matriz[i][j];
        cout << endl;
    }

    cout << endl;
}
   
// Metodo de copia
Matriz2D *Matriz2D::copiarMatriz()
{
    Matriz2D *salida = new Matriz2D(numeroFilas, numeroColumnas);
    int i, j;
    for (i = 0; i < numeroFilas; i++)
    {
        for(j = 0; j < numeroColumnas; j++)
            (*salida).asignarValor(i, j, matriz[i][j]);
    }
    return salida;
    
}
   
   // Metodo para extraer submatriz
   Matriz2D *Matriz2D::extrarSubmatriz(int filaIni, int colIni, int filaFin, int colFin)
   {
       int i, j, col = 0;
       Matriz2D *salida = new Matriz2D((filaFin - filaIni + 1), (colFin - colIni + 1));
       for (i = filaIni; i < filaFin; i++)
       {
           for(j = colIni; j < colFin; j++)
            {
                (*salida).asignarValor(i, col, matriz[i][j]);
                col++;
            }
            col = 0;
       }

       return salida;
   }
   
   // Metodo para eliminar fila de la matriz
   void Matriz2D::eliminarFila(int fila)
   {
       int i;
        delete[] matriz[fila];
        for (i = fila; i < (numeroFilas - 1); i++)
            matriz[i] = matriz[i+1];
   }

   
   // Metodo para eliminar una columna
   void Matriz2D::eliminarColumna(int columna)
   {

   }