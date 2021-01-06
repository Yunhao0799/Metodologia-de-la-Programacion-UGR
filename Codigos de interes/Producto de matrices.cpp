#include <iostream>

using namespace std;

int main(){
	int array1[2][3] = {3, 2, 1, 4, 3, 5};
	int array2[3][2] = {7, 8, 9, 1, 3, 7};
	int i, j, col, suma;
	int salida[2][2];
	col = 0;
	suma = 0;
	
	for (i = 0; i < 2; i ++){
		for (j = 0; j < 3; j++){
			suma = suma + array1[i][j] * array2[j][i];
		}
		salida[i][col] = suma;
		suma = 0;
	}
	
	for (i = 0; i < 2; i++){
		for( j = 0; j < 2; j++){
			cout << salida[i][j] << " ";
		}
		cout << endl;
	}
}
