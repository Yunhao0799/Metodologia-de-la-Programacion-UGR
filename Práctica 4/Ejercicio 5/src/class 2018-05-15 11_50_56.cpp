#include <iostream>
#include "class.h"

using namespace std;

void printLogo()
{
    cout << "    #####                                                              #     #                                       #               " << endl;
    cout << "   #     # #####  ######   ##   ##### ###### #####     #####  #   #     #   #  #    # #    # #    #   ##    ####     #       # #    # " << endl;
    cout << "   #       #    # #       #  #    #   #      #    #    #    #  # #       # #   #    # ##   # #    #  #  #  #    #    #       # ##   # " << endl;
    cout << "   #       #    # #####  #    #   #   #####  #    #    #####    #         #    #    # # #  # ###### #    # #    #    #       # # #  # " << endl;
    cout << "   #       #####  #      ######   #   #      #    #    #    #   #         #    #    # #  # # #    # ###### #    #    #       # #  # # " << endl;
    cout << "   #     # #   #  #      #    #   #   #      #    #    #    #   #         #    #    # #   ## #    # #    # #    #    #       # #   ## " << endl;
    cout << "    #####  #    # ###### #    #   #   ###### #####     #####    #         #     ####  #    # #    # #    #  ####     ####### # #    # " << endl;
    cout << "******************************************************************************************************************************************" << endl;
    cout << endl;
    cout << endl;
}

void printLine()
{
    cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

ostream& operator<<(ostream &os, const MatrizDispersa &otra){
    os << endl;
    int i, j;
    for (i = 1; i < otra.getFilas(); i++){
        for(j = 1; j < otra.getColumnas(); j++)
            os << otra.valor(i, j) << " ";
        os << endl;
    }
    printLine();
} 

//CLASS MATRIZ DISPERSA

//Constructor por defecto
MatrizDispersa::MatrizDispersa(){
    nfilas = 0;
    ncolumnas = 0;
}

//Destructor
MatrizDispersa::~MatrizDispersa(){
    delete [] valores;
}

//Copy constructor
MatrizDispersa::MatrizDispersa(const MatrizDispersa &otra){
    nfilas = otra.getFilas();
    ncolumnas = otra.getColumnas();
    numeroValores = otra.getOcupados();

    //reservo memoria
    valores = new Valor[numeroValores];

    //copio
    for(int i = 0; i < numeroValores; i++){
        valores[i] = otra.getElemento(i);
    }
}

//constructor con parametros
MatrizDispersa::MatrizDispersa(int filas[], int columnas[], double valo[], int longi){
    //reservamos memoria
    valores = new Valor[longi];

    numeroValores = longi;
    //buscamos el tamaño maximo de las filas y columnas
    nfilas = filas[0];
    ncolumnas = columnas[0];
    for(int i = 0; i < longi; i++){
        if(filas[i] > nfilas)
            nfilas = filas[i];
    }
    for(int i = 0; i < longi; i++){
        if(columnas[i] > ncolumnas)
            ncolumnas = columnas[i];
    }
    ncolumnas++;
    nfilas++;
    //asignamos
    Valor auxiliar;
    for( int i = 0; i < longi; i++){
        auxiliar.fila = filas[i];
        auxiliar.columna = columnas[i];
        auxiliar.valor = valo[i];
        valores[i] = auxiliar;
    }
}

//Getters
int MatrizDispersa::getFilas() const{
    return nfilas;
}

int MatrizDispersa::getColumnas() const{
    return ncolumnas;
}

int MatrizDispersa::getOcupados() const{
    return numeroValores;
}

Valor MatrizDispersa::getElemento(int pos) const{
    return valores[pos];
}

double MatrizDispersa::valor(int posx, int posy) const{
    double valor = 0;
    if(posx < nfilas && posy < ncolumnas){
        for(int i = 0; i < numeroValores; i++){
            if(getElemento(i).fila == posx && getElemento(i).columna == posy)
                valor = getElemento(i).valor;
        }
    }
    return valor;
}

/*
void MatrizDispersa::print(){
    cout << endl;
    int i, j;
    for (i = 0; i < getFilas(); i++){
        for(j = 0; j < getColumnas(); j++)
            cout << valor(i, j) << " ";
        cout << endl;
    }
    printLine();
}*/

MatrizDispersa MatrizDispersa::operator+(const MatrizDispersa &otra){
    Valor *salida;
    int tam = otra.getOcupados();
    int tam_sal, i, j, pos;
    bool repe = false;
    tam_sal = 0;
    //copio los elementos de otra
    for(i = 0; i < tam; i++){
        salida[i] = otra.getElemento(i);
        tam_sal++;
    }

    //busco en la propia los elementos que estan en esta pero no en otra
    // en caso contrario los sumo
    j = 0;
    for(i = 0; i < numeroValores; i++){
        while(!repe && j < numeroValores){
            if(((salida[j]).fila) == ((valores[i]).fila) && ((salida[j]).columna) == ((valores[i]).columna)){
                repe = true;
                pos = j;
            }
        
            j++;
        }

        if(repe){
            salida[pos].valor = salida[pos].valor + valores[i].valor;
        }
        else{
            salida[tam_sal] = valores[i];
            tam_sal++;
        }
        j = 0;
        repe = false;
    }

    MatrizDispersa salida(salida, tam_sal);

    return salida;

}

MatrizDispersa::MatrizDispersa(Valor v[], int tam){
    numeroValores = tam;
    valores = new Valor[numeroValores];
    valores = v;

    //buscamos el tamaño maximo de las filas y columnas
    nfilas = v[0].fila;
    ncolumnas = v[0].columna;
    for(int i = 1; i < tam; i++){
        if(v[i].fila > nfilas)
            nfilas = v[i].fila;
    }
    for(int i = 1; i < tam; i++){
        if(v[i].columna > ncolumnas)
            ncolumnas = v[i].columna;
    }
    ncolumnas++;
    nfilas++;
}