#ifndef CLASS_H
#define CLASS_H
void printLogo();

void printLine();

class Skyline{
    private:
        double *abscisas;
        double *alturas;
        int n; //tamño de array
    public:
        Skyline();

        Skyline(const Skyline &otra);

        ~Skyline;

        Skyline(const int, const int, const int);



};

#endif