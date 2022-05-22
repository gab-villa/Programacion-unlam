#ifndef CADENAMIO_H_INCLUDED
#define CADENAMIO_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

class Cadena{
    private:
        char* cad;
    public:
        ~Cadena();
        Cadena();
        Cadena(const char* cad);
        Cadena(const Cadena& c);
        Cadena(const char*, const char*);

        Cadena operator+(const Cadena& c) const;
        Cadena operator+(const char* cad) const;

        //Cadena operator+(const char* cad, const Cadena& c);
        friend ostream& operator <<(ostream& sal, const Cadena& c);
        friend istream& operator >>(istream& ent, Cadena& c);
        friend Cadena operator+(const char* cad, const Cadena& c);

        unsigned longitud() const;
};
//Cadena operator+(const char* cad, const Cadena& c);
// funciona pero no esta permitido

#endif // CADENAMIO_H_INCLUDED
