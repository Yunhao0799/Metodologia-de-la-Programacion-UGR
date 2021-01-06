#include "Matriz2D.h"
#include <iostream>

using namespace std;

Matriz2D::Matriz2D(int numeroFilas, int numeroColumnas){
	if ((numeroFilas > 0) && (numeroColumnas > 0)){
		this->numeroFilas = numeroFilas;
		this->numeroColumnas = numeroColumnas;

		matriz = new int *[numeroFilas];
		
		for (int i = 0; i < numeroFilas; i++)
			matriz[i] = new int[numeroColumnas];
		
	}
	
}

Matriz2D::~Matriz2D(){
	for(int i = 0; i < numeroFilas; i++)
        delete[] matriz[i];
    delete[] matriz;
}

Matriz2D::Matriz2D( Matriz2D & objeto){
	if ((numeroFilas > 0) && (numeroColumnas > 0)){
		objeto.obtenerFilas(numeroFilas);
		objeto.obtenerColumnas(numeroColumnas);

		matriz = new int *[numeroFilas];
		for (int i = 0; i < numeroFilas; i++)
			matriz[i] = new int[numeroColumnas];

		for (int i = 0; i < numeroFilas; i++){
			for (int j = 0; j < numeroColumnas; j++)
				matriz[i][j] = objeto.obtenerValor(i, j);
		}
		
	}
}

void Matriz2D::mostrarPantalla(){
	cout << endl;
	for (int i = 0; i < numeroFilas; i ++){
		for (int j = 0; j < numeroColumnas; j++)
			cout << matriz[i][j] << " ";
		cout <<endl;
	}
	
	cout << endl;
}

void Matriz2D::asignarValor(int fila, int columna, int valor){

    if (fila < numeroFilas && columna < numeroColumnas) 
        matriz[fila][columna] = valor;
    
}


Matriz2D *Matriz2D::copiarMatriz(){
	Matriz2D *resultado = new Matriz2D(numeroFilas, numeroColumnas);

	for (int i = 0; i < numeroFilas; i ++){
		for (int j = 0; j < numeroColumnas; j++){
			resultado->asignarValor(i, j, matriz[i][j]);
		}
		
	}
	
	return resultado;
}

Matriz2D * Matriz2D::extrarSubmatriz(int filaIni, int colIni, int filaFin, int colFin){
    /*
	Matriz2D *salida = copiarMatriz(); //new Celda((filaFin - filaIni + 1), (colFin - colIni + 1));
    int i, j;
    for(i = 0; i < filaIni; i++){
        /*(*salida).eliminarFila(i);salida -> eliminarFila(i);
        salida -> matriz[i][j] = matriz[i + 1][j];
    }

    for (i = filaFin + 1; i < numeroFilas; i++)
        /*(*salida).eliminarFila(i);salida -> eliminarFila(i);
       
    for (j = 0; j < colIni; j++)
        /*(*salida).eliminarColumna(j);salida -> eliminarColumna(j);

    for (j = colFin + 1; j < numeroColumnas; j++)
        /*(*salida).eliminarColumna(j);salida -> eliminarColumna(j);
    
    return salida;*/
    Matriz2D *salida = new Matriz2D(filaFin - filaIni + 1, colFin - colIni + 1);
	int rCol = colFin - colIni + 1, rFil = filaFin - filaIni + 1, k = filaIni, z = colIni;
	
	for (int i = 0; i < rFil; i++){
		for (int j = 0; j < rCol; j++){
			salida->asignarValor(i, j, matriz[k][z]);
			z++;
		}
		z = colIni;
		k++;
	}

	return salida;
}

void Matriz2D::eliminarFila(int fila){
	// Se crea una nueva estructura para la matriz, con una fila
    // menos
    int **matrizNueva = new int *[numeroFilas - 1];


    // Se enlazan los punteros a las filas con las posiciones
    // correspondientes
    for(int i=0; i < numeroFilas-1; i++){
        matrizNueva[i]= new int[numeroColumnas];
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
    for(int i = 0; i < numeroFilas; i++)
        delete[] matriz[i];

    // Se borra el array de punteros previo
    delete [] matriz;

    // Ahora podemos hacer que matriz apunte a la nueva matriz
    matriz = matrizNueva;

    // Se cambia el valor del dato miembro numeroFilas
    numeroFilas--;

}

void Matriz2D::eliminarColumna(int columna){
	int i, j;
    // Se crea una nueva estructura para la matriz, con una columna
    // menos
    int **matrizNueva = new int *[numeroFilas];

    

    // Se enlazan los punteros a las filas con las posiciones
    // correspondientes
    for( i=0; i < numeroFilas-1; i++){
        matrizNueva[i]=new int[(numeroColumnas - 1)];
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
    for(int i = 0; i < numeroFilas; i++)
        delete[] matriz[i];

    // Se borra el array de punteros previo
    delete [] matriz;

    // Ahora podemos hacer que matriz apunte a la nueva matriz
    matriz = matrizNueva;

    // Se cambia el valor del dato miembro numeroFilas
    numeroColumnas--;
}

void Matriz2D::obtenerFilas(int &fila){
	fila = numeroFilas;
}

void Matriz2D::obtenerColumnas(int &columna){
	columna = numeroColumnas;
}

int Matriz2D::obtenerValor(int fila, int columna){
	return matriz[fila][columna];
}
