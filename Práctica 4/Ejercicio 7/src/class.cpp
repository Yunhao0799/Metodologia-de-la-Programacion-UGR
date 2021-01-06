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

Presecuencias::Presecuencias(){
    parejas = 0;
    npares = 0;
}

Presecuencias::~Presecuencias(){
    if(parejas != NULL)
        delete[] parejas;
}

Presecuencias::Presecuencias(const Presecuencias &otra){
    npares = otra.getPares();
    int i;
    parejas = new Pareja[npares];
    for(i = 0; i < npares; i++){
        parejas[i].dato = otra.getPos(i).dato;
        parejas[i].nveces = otra.getPos(i).nveces;
    }
        
}

void Presecuencias::agregarValor(int numero){
    int i = 0, encontrado = -1;
    for(i = 0; i < npares ; i++){
        if(parejas[i].dato == numero){
            encontrado = i;
            break;
        }
    }

    if(encontrado >= 0){
        //parejas[encontrado].dato = numero;
        parejas[encontrado].nveces++;
    }
    else{
        Pareja *aux;
        aux = new Pareja[npares + 1];
        for(int j = 0; j < npares; j++){
            aux[j].dato = parejas[j].dato;
            aux[j].nveces = parejas[j].nveces;
        }
            
            
        aux[npares].dato = numero;
        aux[npares].nveces = 1;
        delete [] parejas;
        parejas = aux;
        npares++;
    }
}

int Presecuencias::getPares() const{
    return npares;
}

Pareja Presecuencias::getPos(int pos) const{
    return parejas[pos];
}

void Presecuencias::print(){
    int i;
    for(i = 0; i < npares; i++){
        cout << "Numero: " << parejas[i].dato << "  Veces: " << parejas[i].nveces << endl;
    }
    printLine();
}

bool Presecuencias::existe(int numero){
    bool encontrado = false;
    for(int i = 0; i < npares && !encontrado; i++){
        if(parejas[i].dato == numero)
            encontrado = true;
    }        

    return encontrado;
}

bool Presecuencias::operator== (const Presecuencias &otra){
    int i, j;
    bool encontrado = true;
    if(getPares() != otra.getPares())
        encontrado = false;
    else{
        for(i = 0; i < getPares(); i++){
            if(parejas[i].dato != otra.getPos(i).dato || parejas[i].nveces != otra.getPos(i).nveces)
                encontrado = false;
        }
    }
    return encontrado;
}

bool Presecuencias::operator!= (const Presecuencias &otra){
    int i, j;
    bool encontrado = true;
    if(getPares() != otra.getPares())
        encontrado = false;
    else{
        for(i = 0; i < getPares(); i++){
            if(parejas[i].dato != otra.getPos(i).dato || parejas[i].nveces != otra.getPos(i).nveces)
                encontrado = false;
        }
    }
    if (encontrado)
        return !encontrado;
    else 
        return true;
}


