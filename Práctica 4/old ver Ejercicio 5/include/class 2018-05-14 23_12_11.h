#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

void printLogo();

void printLine();



class Valor{
  public:
    int fila;
    int columna;
    double valor;

    /**
     * Constructor por defecto
     */
    Valor(){
    }

    /**
     * Constructor de la clase
     * @param fila
     * @param columna
     * @param valor
     */
    Valor(int fila, int columna, double valor){
        this->fila=fila;
        this->columna=columna;
        this->valor=valor;
    }

    /**
     * Metodo paa mostrar el contenido de un objeto
     */
    void mostrar(){
        cout << "{" << fila << ", " << columna << ", " << valor << "} ";
    }
};







class MatrizDispersa{
    private:
        int nfilas;
        int ncolumnas;
        Valor *valores;
        int numeroValores; //numero de valores significativos almacenados


    public:
        //Constructor por defecto
        MatrizDispersa();

        //Destructor
        ~MatrizDispersa();

        //Constructor de copia
        MatrizDispersa(const MatrizDispersa &otra);

        //Constructor de copia para una matriz determinada
        MatrizDispersa(int[], int[], double[], int);

        //Getters
        int getFilas() const;

        int getColumnas() const;

        Valor getElemento(int, int) const;
        

};

//ostream& operator<<(ostream &os, const Barquitos &);

#endif