#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>

using namespace std;

bool multiplicar(double matriz1[][10], int fila1, int col1, double matriz2[][10], int fila2, int col2, double salida[][10], int &filaS, int &colS){
  bool multiplicable = false;
  int i, j, k;
  int tam;
  if (col2 == fila1){
    filaS = fila1;
    colS = col2;
    multiplicable = true;

    for(i = 0; i < filaS; i++){
      for(j = 0; j < colS; j++){
        salida[i][j] = 0;
        for (k = 0; k < filaS; k++)
          salida[i][j] = salida[i][j] + (matriz1[i][k] * matriz2[k][j]);
      }
    }
  }
  return multiplicable;
}

void mostrarMatriz(double matriz[][10], int fil, int col)
{
  int i, j;
  for( i = 0; i < fil; i++)
  {
    for( j = 0; j < col; j++)
      cout << matriz[i][j] << "   ";
    cout << endl;
  }
}


#endif
