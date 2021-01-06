

using namespace std;

//PREGUNTAR!! Al ser un vector tipo char, no es necesario que le pasemos el tamaño del vector??
bool insertarCadena(char *entrada, char *insertar, int posicion, char *salida)
{
  bool insertable = false;
  int i, j;
  //si la posicion a insertar es menor que el tamaño del vector entrada, insrtable = true;
  if(posicion < tam_entrada)
  {
    insertable = true;

    for( i = 0; i < tam_entrada; i++) //copio el vector de entrada al de la salida
      salida[i] = entrada[i];


    tam_salida = tam_entrada;
    //desplazamos el vector de salida a la derecha tantas veces como el tamaño a insertar
    for(i = 0; i < tam_inserta; i++)
    {
      for(j = posicion; j < tam_salida; j++)
      {
        salida[j] = salida[j - 1];
        tam_salida++;
      }

    }

    //lo añadimos
    j = 0;
    for ( i = posicion; i < (posicion + tam_inserta); i++)
    {
      salida[i] = insertar[j];
      j++;
    }


  }

  return insertable;
}
