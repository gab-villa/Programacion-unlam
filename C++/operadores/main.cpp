#include <iostream>
#include <stdlib.h>
#include "vector.h"
using namespace std;

int main()
{
    Vector v(1,2,3), w(3,2,2), u(2,7,9),suma, prod;
    Vector aux(v);
    Vector z(9,9,9);
    z = w; //porque funcionaaaa
    suma = v+w+u;

    mostrarVector(z);
    mostrarVector(aux);
    mostrarVector(suma);
    prod = v*u*w;
    mostrarVector(prod);

    return 0;
}
