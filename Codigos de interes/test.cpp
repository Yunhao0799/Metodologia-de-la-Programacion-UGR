#include <iostream>

using namespace std;

int ascendentesDesdei (int array[], int tam, int posicion);

int main(){
	int array[] = {10, 3, 4, 5, 6, 7, 8, 9};
	cout << ascendentesDesdei(array, 8, 2);
	
}

int ascendentesDesdei (int array[], int tam, int posicion){
  int i = posicion;
  int contador = 0;
  while ( i < (tam - 1) && array[i] < array[i + 1] )
    contador++;

  return contador;
}
