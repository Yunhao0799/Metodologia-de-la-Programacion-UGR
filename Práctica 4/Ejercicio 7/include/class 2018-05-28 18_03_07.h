#ifndef CLASS_H
#define CLASS_H

void printLogo();

void printLine();

/********************************************
 *                                          *
 *              CLASS PAREJA                *
 *                                          * 
 ********************************************/ 
class Pareja
{
    private:
        int dato;
        int nveces;
        friend class Presecuencias;
    public:
        //constructor por defecto
        Pareja();

};

/*************************************************************************/

/********************************************
 *                                          *
 *          CLASS PRESECUENCIAS             *
 *                                          * 
 ********************************************/ 
class Presecuencias
{
    private:
        Pareja *parejas;
        int npares; //tamaño del array
    
    public:
        //Constructor por defecto
        Presecuencias();

        //destructor
        ~Presecuencias();

        //constructor de copia
        Presecuencias(const Presecuencias &otra);

        //metodo que recibe un entero y lo agrega en nuestro array
        //si esta se incremeta su contador, si no incluir una nueva
        // pareja
        void agregarValor(int entero);
};


#endif