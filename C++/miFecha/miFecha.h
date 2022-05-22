#ifndef MIFECHA_H_INCLUDED
#define MIFECHA_H_INCLUDED

#include <ctime>
#include <iostream>
#include <stdio.h>

using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        Fecha operator++(int);
        Fecha operator+=(int);
        Fecha& operator--();
        friend ostream& operator <<(ostream& sal, const Fecha&);
        friend istream& operator >>(istream& ent, Fecha&);

        bool operator ==(const Fecha&) const;
};

#endif // MIFECHA_H_INCLUDED
