#include "utilidades.h"


#include<iostream>


using namespace std;

int combinarSuma(Valor *v1, int tam1, Valor *v2, int tam2, Valor *salida)
{
  int tam_sal, i, j;
  bool repe = false;
  tam_sal = 0;
  for(i = 0; i < tam1; i++)
  {
    salida[i] = v1[i];
    tam_sal++;
  }

  //Busco en el segundo vector los iguales
  j = 0;
  for (i = 0; i < tam2; i++)
  {
    //Busco el elemento actual e ¡n mi vector salida, si esta, repetido true y se suma los valores, si no se añade
    while( !repe && j < tam1 )
    {
      if(((salida[j]).fila) == ((v2[i]).fila) && ((salida[j]).columna) == ((v2[i]).columna))
        repe = true;
    }

    if (repe)
    {
      //valor de la salida[j] = valor salida[j] + valor v2[i]
      salida[j].valor = salida[j].valor + v2[i].valor;
    }
    else
    {
      salida[tam_sal] = v2[i];
      tam_sal++;
    }

    j = 0;
    repe = false;

  }

  return tam_sal;
}

void mostrarContenido(Valor array[], int tam)
{
  int i = 0;
  for (i = 0; i < tam; i++)
    cout << "{" << array[i].fila << ", " << array[i].columna << ", " << array[i].valor << "}  --  ";
  
}