#include <stdio.h>
#include <stdlib.h>

#include "mostrarPartesDeMatriz.h"

int main()
{
    int matriz[][COL] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    mostrarMatrizCompleta(matriz, COL, COL);
    mostrarDiagonal(matriz, COL);
    mostrarTriangularSuperior(matriz, COL);
    mostrarTriangularInferior(matriz, COL);
    mostrarDiagonalSec(matriz, COL);
    mostrarTriangularSupSec(matriz, COL);
    mostrarTriangularInfSec(matriz, COL);
    return 0;
}
