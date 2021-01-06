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
        Valor *valores;//array de valores significativos
        int numeroValores; //numero de valores significativos almacenados
        //friend MatrizDispersa operator+(const MatrizDispersa&);

    public:
        //Constructor por defecto
        MatrizDispersa();

        //Destructor
        ~MatrizDispersa();

        //Constructor de copia
        MatrizDispersa(const MatrizDispersa &otra);

        //Constructor de copia para una matriz determinada
        MatrizDispersa(int[], int[], double[], int);

        //constructor con vector valor
        MatrizDispersa(Valor[], int);

        //Getters
        int getFilas() const;

        int getColumnas() const;

        int getOcupados() const;

        Valor getElemento(int) const;

        //metodo para para ver si existe un elemento i j
        double valor(int, int) const;

        //void print();
        MatrizDispersa operator+(const MatrizDispersa&);
        
        MatrizDispersa& operator=(const MatrizDispersa&);

};

ostream& operator<<(ostream &os, const MatrizDispersa &);

#endif
