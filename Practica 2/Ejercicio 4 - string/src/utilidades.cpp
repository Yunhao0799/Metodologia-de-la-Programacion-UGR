#include "utilidades.h"

int localizarSubcadena(char cad[], char sub[])
{
  int flag = -1;
  string cadena = cad;
  string subcadena = sub;
  if (cadena.find(subcadena) != string::npos)
    flag = 1;
  return flag;
}
