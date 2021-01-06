#ifndef CLASS_H
#define CLASS_H

class Menu
{
    private:
        char *titulo; //titulo del menu
        char **opc; //cadenas de longitud variable que describen cada una de las opciones
        int nopc; //numero de opciones
        //constructor de copia
        friend Menu(const Menu &otra);
    public:
        //constructor por defecto
        Menu();

        //destructor
        ~Menu();

        s//metodos, setters y getters
        void setTitulo(char *v);

        int getNumeroOpciones();
};

#endif