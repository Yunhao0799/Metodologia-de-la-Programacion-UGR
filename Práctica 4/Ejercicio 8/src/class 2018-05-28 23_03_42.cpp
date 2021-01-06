#include <iostream>
#include <cstring>
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

//Constructor por defecto
Menu::Menu()
{
    titulo = 0;
    opc = 0;
    nopc = 0;
}

//Destructor
Menu::~Menu()
{
    delete titulo;
    for(int i = 0; i < nopc; i++)
        delete [] opc[i];
    delete [] opc;
}

Menu::Menu(Menu &otra){
    //copiamos el titulo
    int tam_title = otra.title_size();
    titulo = new char[tam_title];
    int i, j;
    for(i = 0; i < tam_title; i++)
        titulo[i] = get_Title(i);
    
    //copiamos el numero de opciones
    nopc = otra.getNumeroOpciones();
    //reservamos filas de ese tamaño
    opc = new char*[nopc];
    //reservamos las columnas
    int tam_aux = 0, k = 0;
    for(i = 0; i < nopc; i++){
        while(opc[i][k] != '\0'){
            k++;
            tam_aux++;
        }
        tam_aux++;
        opc[i] = new char[tam_aux];
        tam_aux = 0;
        k = 0;
    }

    //copiamos
    k = 0;
    for(i = 0; i < nopc; i++){
        while(otra.getpos(i, k) != '\0'){
            k++;
            opc[i][k] = otra.getpos(i, k);
        }
    }

}

char Menu::get_Title(int pos){
    return titulo[pos];
}

int Menu::title_size(){
    int tam = 0, i = 0;
    while(titulo[i] != '\0'){
        tam++;
        i++;
    }
    tam++;
    return tam;
}

int Menu::getNumeroOpciones(){
    return nopc;
}

char Menu::getpos(int i, int j){
    return opc[i][j];
}

void Menu::setTitulo(char *v){
    //determinamos primero el tamaño del vector que nos pasan
    int i = 0, tam = 0;
    while(v[i] != '\0'){
        tam++;
        i++;
    }
    tam++;
    //reservamos un vector del tamaño del vector
    titulo = new char[tam];
    for(i = 0; i < tam; i++)
        titulo[i] = v[i];
}

void Menu::print(){
    //imprimimos el titulo
    int i = 0, j = 0;
    while(titulo[i] != '\0'){
        cout << titulo[i];
        i++;
    }

    cout << endl;
    
    //imprimimos las opciones
    for(i = 0; i < nopc; i++){
        while(opc[i][j] != '\0'){
            cout << opc[i][j];
            j++;
        }
        cout << endl;
    }

}

void Menu::agregarOpcion(char *opcion){
    //Determinamos el tamaño de la opcion
    int i = 0, tam = 0;
    while(opcion[i] != '\0'){
        tam++;
        i++;
    }
    tam++;
    
    //copiamos nuestra matriz en uno auxiliar con un tamaño mayor
    char **aux;
    aux = new char*[nopc + 1];
    int tam_aux = 0, j = 0;
    for(i = 0; i < nopc; i++){
        while(opc[i][j] != '\0'){
            j++;
            tam_aux++;
        }
        tam_aux++;
        opc[i] = new char[tam_aux];
        for(j = 0; j < tam_aux; j++)
            aux[i][j] = opc[i][j];
        tam_aux = 0;
        j = 0;
    }
    
    //en la ultima fila copiamos el nuevo vector
    /*i = 0;
    while(opcion[i] != '\0'){
        aux[nopc][i] = opcion[i];
        i++;
    }*/
    for(i = 0; i < tam; i++)
        aux[nopc][i] = opcion[i];
        
    
    
    /*//borramos las antiguas opciones y reasignamos
    for(int i = 0; i < nopc; i++)
        delete [] opc[i];
    delete [] opc;*/

    opc = aux;
    nopc++;
    

}