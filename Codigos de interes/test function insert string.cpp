#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 = "hola";
	string str2 = "adios";
	
	str1 = str1.insert(2, str2);
	
	cout << str1;
}
