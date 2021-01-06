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

Skyline::Skyline(){
    alturas = 0;
    abscisas = 0;
    n = 0;
}

Skyline::Skyline(const Skyline &otra){
    n = otra.getTam();
    int i;
    abscisas = new double [n];
    alturas  = new double [n];
    //copiamos las abscisas y alturas
    for(i = 0; i < n; i++){
        abscisas[i] = otra.getAbscisas(i);
        alturas[i] = otra.getAltura(i);
    }
}

Skyline::~Skyline(){
    delete [] abscisas;
    delete [] alturas;
}

double Skyline::getAbscisas(int pos) const{
    return abscisas[pos];
}

double Skyline::getAltura(int pos) const{
    return alturas[pos];
}

int Skyline::getTam() const {
    return n;
}

Skyline::Skyline(double ini,  double fin,  double h){
    if (fin > ini){
        n = 2;
        abscisas = new double[2];
        alturas = new double[2];
        alturas[0] = h;
        alturas[1] = 0;
        abscisas[0] = ini;
        abscisas[1] = fin;
    }
}
void Skyline::print(){
    int i, fallos = 0;
    cout << "                   Posicion        Posicion        Altura del" << endl; 
    cout << "                    inicio          final           edificio" << endl; 
    for(i = 0; i < n - 1; i++){
        if(abscisas[i] < abscisas[i + 1]){
            cout << "Edificio " << i + 1 << " : " << "        " << abscisas[i] << "                " << abscisas[i + 1] << "                " << alturas[i];
            cout << endl;
        }
        else
            fallos++;
        
    }
    cout << endl;
    if(fallos > 0)
        cout << "Habia " << fallos << " edificios incorrectamente introducidos, por favor reviselo" << endl; 
    printLine();
    cout << endl;
}

Skyline::Skyline(double *abs, double *h, int tam){
    if(tam > 0){
        n = tam;
        abscisas = new double [n];
        alturas  = new double [n];
        for(int i = 0; i < n; i++){
            abscisas[i] = abs[i];
            alturas[i] = h[i];
        }
        
    }
}

double Skyline::operator[](const int pos){
    return abscisas[pos];
}