#include <iostream>
#include "utilidades.h"

using namespace std;

/* VERSION EMPLEANDO VECTORES
void ordenarPunteros(int *array, int **parray, int util)
{
    int i, posMenor;
    //asignamos a parray las direcciones de array
    for ( i = 0; i < util; i ++)
        (parray[i]) = &array[i];

    //procederemos a ordenar el puntero de punteros **parray

    for(i=0; i<util-1; i++) 
    {   
        posMenor = buscaMenor(parray,i,util);
        swap(*(parray[i]), *(parray[posMenor]));
    }
    
}

void swap(int & a, int & b) 
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int buscaMenor(int **parray, int posI, int posF) 
{
    int min, j;
    min = posI;
    for(j=posI+1; j<posF; j++) 
    {
        if(*(parray[j]) < *(parray[min]))
        min = j;
    }
    
    return(min);
}

void imprimir(int *secuencia, int util)
{
    int i;
    for (i = 0; i < util; i++)
        cout << secuencia[i] << "   ";

    cout << endl;
}

void imprimir(int **secuencia, int util)
{
    int i;
    for (i = 0; i < util; i++)
        cout << *(secuencia[i]) << "   ";

    cout << endl;
}
*/


//VERSION EMPLEANDO SOLAMENTE PUNTEROS

void ordenarPunteros(int *array, int **parray, int util)
{
    int i, posMenor;
    //asignamos a parray las direcciones de array
    for ( i = 0; i < util; i ++)
        *(parray + i) = (array + i);

    //procederemos a ordenar el puntero de punteros **parray

    for(i=0; i<util-1; i++) 
    {   
        posMenor = buscaMenor(parray,i,util);
        swap(*(*(parray + i)), *(*(parray + posMenor)));
    }
    
}


void swap(int & a, int & b) 
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int buscaMenor(int **parray, int posI, int posF) 
{
    int min, j;
    min = posI;
    for(j=posI+1; j<posF; j++) 
    {
        if(*(*(parray + j)) < *(*(parray + min)))
        min = j;
    }
    
    return(min);
}

void imprimir(int *secuencia, int util)
{
    int i;
    for (i = 0; i < util; i++)
        cout << *(secuencia + i) << "   ";

    cout << endl;
}

void imprimir(int **secuencia, int util)
{
    int i;
    for (i = 0; i < util; i++)
        cout << **(secuencia + i) << "   ";

    cout << endl;
}