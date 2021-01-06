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

        Skyline(double, double, double);

        Skyline(double *, double *, int);

        ~Skyline();        

        double getAbscisas(int) const;

        double getAltura(int) const;

        int getTam() const;

        void print();

        double operator[](const int);

};

#endif