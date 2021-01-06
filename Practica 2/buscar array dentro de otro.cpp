#include<iostream>

using namespace std;



int main()
{
    bool contiene;
    int v1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v2[5] = {4, 5, 6, 7};
    int i, j;
    int b = 10;

    for(i = 0; i < 10; i++)
    {
    	contiene = true;
    	for (j = 0; j < 5; j++)
    	{
    		if (v1[i + j] != v2[j])
    		{
    			contiene = false;
    			break;
			}
		}
	}
    
    if(contiene)
        cout <<  "contenido " << i;
    else    
        cout << "no";
}
