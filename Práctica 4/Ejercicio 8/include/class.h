#ifndef CLASS_H
#define CLASS_H

void printLogo();
void printLine();


class Menu
{
    private:
        char *titulo; //titulo del menu
        char **opc; //cadenas de longitud variable que describen cada una de las opciones
        int nopc; //numero de opciones
        
    public:
        //constructor por defecto
        Menu();

        //destructor
        ~Menu();

        //constructor de copia
        Menu( Menu &otra);

        //metodos, setters y getters
        void setTitulo(char *v);

        int getNumeroOpciones()const;

        char get_Title(int)const;

        int title_size()const;

        char getpos(int, int)const;

        void print();

        void agregarOpcion(char *);

        Menu& operator= (const Menu &otra);
};

#endif