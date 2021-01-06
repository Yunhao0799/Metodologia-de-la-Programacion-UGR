/////////////////////////////////////////////////////////
//													   //
//		PRUEBA PARA BORRAR REPETIDOS DE UN VECTOR	   //
//													   //
/////////////////////////////////////////////////////////



#include <iostream>

using namespace std;

int main()
{
	int v[10] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};
	int i, j, tam = 10;
	
	cout << "Vector original: " << endl;
	for (i = 0; i < 10; i++)
		cout << v[i] << "	";
	cout << endl;
	
	
	i = 1;
	while (i < tam)
	{
		if (v[i] == v[i - 1])
		{
			for(j = i; j < tam; j++)
				v[j] = v[j + 1];
			
			tam--;
		}
		i++;
	}
	
	cout << "Vector sin repetidos: " << endl;
	for (i = 0; i < tam; i++)
		cout << v[i] << "	";
	cout << endl;
	
	
	

}
