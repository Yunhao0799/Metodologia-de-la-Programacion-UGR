#include<iostream>
#include "utilidades.h"

using namespace std;

int mezclar (double array1[], int tam1, double array2[], int tam2, double salida[]){
  int tam_salida;
  tam_salida = tam1;
  int i, j;
  double elemento;

  //copia el primer vectopr en nuestro vector auxiliar
  for( i = 0; i < tam1; i++){
    salida[i] = array1[i];
  }
  //buscamos elemento a elemento de la secuencia dos en el uno, si no esta repetido se añade
  for (i = 0; i < tam2; i++){
    elemento = array2[i];
    if (!(buscarepe(salida, tam_salida, elemento))){
      salida[tam_salida] = array2[i];
      tam_salida++;
    }
  }
  //ordenamos el vector auxiliar
  ordenavector(salida, tam_salida);

  return tam_salida;
}

void imprimirArray(double array[], int tam){
  int i;
  for(i = 0; i < tam; i++)
    cout << array[i] << " ";
}

void ordenavector(double array[], int tam){
  int i, j;

    for(i = 1; i < tam; i++)
    {

        double tmp = array[i];
         
        for(j = i; j > 0 && array[j-1] > tmp; j--)
            array[j] = array[j-1];
         
        
        array[j] = tmp;
    }
}

bool buscarepe (double array[], int tam, double elemento){
  bool encontrado = false;
  int i = 0;
  while( i < tam && !encontrado){
    if (array[i] == elemento)
      encontrado = true;
    i++;
  }
  return encontrado;
}
