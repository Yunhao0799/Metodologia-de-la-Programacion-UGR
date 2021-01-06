#include <iostream>
#include "Matriz2D.h"

using namespace std;


// Constructor de la clase
Matriz2D::Matriz2D(int numeroFilas, int numeroColumnas)
{
    // Se asignan los datos miembro
    this->numeroFilas = numeroFilas;
    this->numeroColumnas = numeroColumnas;

    // Se reserva espacio de memoria para los punteros
    // de las filas
    matriz = new int *[numeroFilas];

    // Se reserva espacio de memoria para el espacio de
    // almacenamiento en si
    matriz[0] = new int[numeroFilas*numeroColumnas];

    // Se hace que los punteros a las filas apunten a los
    // lugares correctos
    for (int i = 1; i < numeroFilas; i++) {
        matriz[i] = matriz[i-1]+numeroColumnas;

}
   
// Constructor de copia
Matriz2D::Matriz2D(const Matriz2D & objeto)
{
    objeto.obtenerFilas(numeroFilas);
	objeto.obtenerColumnas(numeroColumnas);

	matriz = new int *[numeroFilas];
	matriz[0] = new int [numeroFilas*numeroColumnas];
		
	for (int i = 1; i < numeroFilas; i++)
		matriz[i] = matriz[i-1] + numeroColumnas;

	for (int i = 0; i < numeroFilas; i++){
		for (int j = 0; j < numeroColumnas; j++)
			matriz[i][j] = objeto.obtenerValor(i, j);
	}
}
   
// Destructor
Matriz2D::~Matriz2D() 
{
    // Se borra el espacio de almacenamiento de valores
    delete [] matriz[0];

    // Se borra el array de punteros a filas
    delete[] matriz;

}
   
// Asignar valor a posicion
bool Matriz2D::asignarValor(int fila, int columna, int valor)
{
    bool asignable = false;

    if (fila < numeroFilas && columna < numeroColumnas) 
    {
        asignable = true;
        matriz[fila][columna] = valor;
    }

    // Devolver asignado
    return asignable;

}
   
// Metodo para mostrar por pantalla
void Matriz2D::mostrarPantalla()
{
    cout << endl;
    for (int i = 0; i < numeroFilas; i++) {
        for (int j = 0; j < numeroColumnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


}
   
// Metodo de copia
Matriz2D * Matriz2D::copiarMatriz()
{
    Matriz2D *salida = new Matriz2D(numeroFilas, numeroColumnas);
    for(int i = 0; i < numeroFilas; i++)
    {
        for(int j = 0; j < numeroColumnas; j++)
            salida -> matriz[i][j] = matriz[i][j];
    }

    return salida;
}
   
// Metodo para extraer submatriz
Matriz2D * Matriz2D::extrarSubmatriz(int filaIni, int colIni, int filaFin, int colFin)
{

}
   
// Metodo para eliminar fila de la matriz
void Matriz2D::eliminarFila(int fila)
{
    // Se crea una nueva estructura para la matriz, con una fila
    // menos
    int **matrizNueva = new int *[numeroFilas - 1];

    // Se reserva nuevo espacio de almacenamiento
    matrizNueva[0] = new int[(numeroFilas-1)*numeroColumnas];

    // Se enlazan los punteros a las filas con las posiciones
    // correspondientes
    for(int i=1; i < numeroFilas-1; i++){
        matrizNueva[i]=matrizNueva[i-1]+numeroColumnas;
    }

    // Se copian los valores de filas pervias
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < numeroColumnas; j++) {
            matrizNueva[i][j] = matriz[i][j];
        }
    }

    // Se copian valores de filas posteriores
    for (int i = fila + 1; i < numeroFilas; i++) {
        for (int j = 0; j < numeroColumnas; j++) {
            matrizNueva[i - 1][j] = matriz[i][j];
        }
    }

    // Se libera el espacio de la matriz previa
    delete [] matriz[0];

    // Se borra el array de punteros previo
    delete [] matriz;

    // Ahora podemos hacer que matriz apunte a la nueva matriz
    matriz = matrizNueva;

    // Se cambia el valor del dato miembro numeroFilas
    numeroFilas--;

}

// Metodo para eliminar una columna
void Matriz2D::eliminarColumna(int columna)
{
    
    int i, j;
    // Se crea una nueva estructura para la matriz, con una columna
    // menos
    int **matrizNueva = new int *[numeroFilas];

    // Se reserva nuevo espacio de almacenamiento
    matrizNueva[0] = new int[numeroFilas * (numeroColumnas - 1)];

    // Se enlazan los punteros a las filas con las posiciones
    // correspondientes
    for( i=1; i < numeroFilas-1; i++){
        matrizNueva[i]=matrizNueva[i-1]+(numeroColumnas - 1);
    }

    //inicio algoritmo eliminacion columna
    for(i = 0; i < numeroFilas; i++)
    {
        for (j = 0; j < columna; j++)
            matrizNueva[i][j] = matriz[i][j];
    }

     for ( i = 0; i < numeroFilas; i++) {
        for ( j = (columna + 1); j < numeroColumnas; j++) {
            matrizNueva[i][j - 1] = matriz[i][j];
        }
    }

    // Se libera el espacio de la matriz previa
    delete [] matriz[0];

    // Se borra el array de punteros previo
    delete [] matriz;

    // Ahora podemos hacer que matriz apunte a la nueva matriz
    matriz = matrizNueva;

    // Se cambia el valor del dato miembro numeroFilas
    numeroFilas--;
};
