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


/************************************
*************************************                                   
************CLASS BARQUITOS**********
*************************************
*************************************/


//Constructor con el tamaño del tablero
Barquitos::Barquitos(int filas, int columnas){
    int i, j;
    //creamos nuestro tablero con memoria dinamica
    nfil = filas;
    ncol = columnas;
    m = new int*[nfil];
        for ( i = 0; i < nfil; i++)
            m[i] = new int [ncol];
    //ponemos el tablero en agua
    for(i = 0; i < nfil; i++)
    {
        for( j = 0; j < ncol; j++)
            m[i][j] = 9;
    }
    
}

//Destructor
Barquitos::~Barquitos(){
    for(int i = 0; i < nfil; i++)
        delete [] m[i];
    delete [] m;
}

//Getters
int Barquitos::getFilas() const{
    return nfil;
}

int Barquitos::getColumnas() const{
    return ncol;
}

int Barquitos::getElemento(int posx, int posy) const{
    return m[posx][posy];
}

//constructor de copia
Barquitos::Barquitos(const Barquitos &otra){
    nfil = otra.getFilas();
    ncol = otra.getColumnas();
    int i, j;
    //reservamos el tamaño de nuestra matriz
    m = new int*[nfil];
    for(i = 0; i < nfil; i++)
        m[i] = new int [ncol];

    //copiamos
    for(i = 0; i < nfil; i++){
        for(j = 0; j < ncol; j++)
            m[i][j] = otra.getElemento(i, j);
    }
}

//metodo para insertar un nuevo barco
bool Barquitos::newShip(int fila, int col, int tam, char hv, bool orientacion){ //valores que tomara orientacios:
    bool insertable = true;
    if( hv == 'H'){                                           // 0 izquierda o arriba
        if (orientacion = true){
            /*if(col + tam >= ncol)
                insertable = false;    */                                   // 1 derecha o abajo       
            //estamos comprobando si lo podemos insertar horizontal derecha
            for (int i = 0; i < tam; i++){
                if(m[fila][col + i] != 9 || (col + i) >= ncol)
                    insertable = false;
            }            
        }
        else{
            /*if(col - tam < 0)
                insertable = false;*/
            for (int i = 0; i < tam; i++){
                if(m[fila][col - i] != 9 || (col - i) < 0)
                    insertable = false;
            }
        } 
    }                            
    else{
        if (orientacion = true){                                            
            //estamos comprobando si lo podemos insertar vertical abajo
            /*if(fila + tam >= nfil)
                insertable = false;*/
            for (int i = 0; i < tam; i++){
                if(m[fila + i][col] != 9 || (fila + i) >= nfil)
                    insertable = false;
            }        
        }
        else{
            /*if(fila - tam < 0)
                insertable = false;*/
            for (int i = 0; i < tam; i++){
                if(m[fila - i][col] != 9 || (fila - i) < 0  )
                    insertable = false;
            }        
        }
    }           
    return insertable;                                          
}                           

//sobrecarda de la salida
ostream& operator<<(ostream &os, const Barquitos &tablero){
    os << endl;
    int i, j;
    for (i = 0; i < tablero.getFilas(); i++){
        for(j = 0; j < tablero.getColumnas(); j++)
            os << tablero.getElemento(i, j) << " ";
        os << endl;
    }
    printLine();
}  

//Sobrecarga del operador de asignacion
Barquitos& Barquitos::operator=(const Barquitos &tablero){
    if (&tablero != this){
        //borramos
        for(int i = 0; i < nfil; i++)
            delete [] m[i];
        delete [] m;

        //reservamos memoria
        nfil = tablero.getFilas();
        ncol = tablero.getColumnas();
        m = new int*[nfil];
        for(int i = 0; i < nfil; i++)
            m[i] = new int[ncol];

        //copiamos
        for(int i = 0; i < nfil; i++){
            for(int j = 0; j < ncol; j++)
                m[i][j] = tablero.getElemento(i, j);
        }
    }
    return *this;
}                                                  

void Barquitos::asignship(int fila, int col, int tam, char hv, bool orientacion){
    if(newShip(fila, col, tam, hv, orientacion) == true){
        if( hv == 'H'){                                           // 0 izquierda o arriba
            if (orientacion = true){                                       // 1 derecha o abajo       
            //estamos comprobando si lo podemos insertar horizontal derecha
                for (int i = 0; i < tam; i++){
                    m[fila][col + i] = tam;
                }            
            }
            else{
                for (int i = 0; i < tam; i++){
                    m[fila][col - i] = tam;
                }
            } 
        }                            
        else{
            if (orientacion = true){                                            
                //estamos comprobando si lo podemos insertar vertical abajo
                for (int i = 0; i < tam; i++){
                    m[fila + i][col] = tam;
                }        
            }
            else{
                for (int i = 0; i < tam; i++){
                    m[fila - i][col] = tam;
                }        
            }
        }          
    }
    else    
        cout << "Limites sobrepasados" << endl;
}
