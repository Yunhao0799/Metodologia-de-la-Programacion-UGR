#include <iostream>

using namespace std;

int main()
{
	const int TAM = 10;
	int v[TAM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;
	for( i = TAM; i > 1; i--)
		cout << v[i] << " -> " ;
	cout << v[0];
}
