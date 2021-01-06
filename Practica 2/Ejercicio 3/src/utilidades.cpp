#include "utilidades.h"

#include<iostream>
using namespace std;

void obtenerMayorSecuenciaMonotonaCreciente( int array[], int util_array, int salida[], int &util_salida){
  util_salida = 0;
  int maximo = 0;
  int pos, valor;
  int i;
  for ( i = 0; i < util_array; i++){
    valor = ascendentesDesdei(array, util_array, i);
    if(valor > maximo){
      maximo = valor;
      pos = i;
    }
  }
  util_salida = maximo + 1;

  for( i = 0; i < util_salida; i++ ){
    salida[i] = array[i + pos];
  }
}


//funcion que comprueba cantidad de numeros ascendentes desde una posicion
int ascendentesDesdei (int array[], int tam, int posicion){
  int i = posicion;
  int contador = 0;
  while ( i < (tam - 1) && array[i] < array[i + 1] )
  {
    contador++;
    i++;
  }
    

  return contador;
}

void imprimirArray (int array[], int tam)
{
  int i;
  for( i = 0; i < tam; i++)
    cout << array[i] << " ";
  cout << endl;
}
