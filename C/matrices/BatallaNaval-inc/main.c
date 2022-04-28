#include <stdio.h>
#include <stdlib.h>

#include "batNaval.h"


int main()
{
    tTablero tab;
    const int tamNaves[CANT_NAVES+1] = {4, 4, 4, 2};
    crearTab(&tab);
    cargarNaves(&tab, tamNaves);
    mostrarTab(&tab);
    return 0;
}

