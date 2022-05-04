#include "main.h"

int main()
{
    crearArchMaestro(NOMBRE_ARCH_MAESTRO);
    mostrarArchMaestro(NOMBRE_ARCH_MAESTRO);
    printf("\n\n AHORA CARGANDO LAS NOVEDADES.. \n\n");
    cargarNovEnMaestro(NOMBRE_ARCH_NOV, NOMBRE_ARCH_MAESTRO,
                              NOM_ARCH_SIN_STOCK, NOM_ARCH_PROD_INEX);

    mostrarArchMaestro(NOMBRE_ARCH_MAESTRO);
    return 0;
}
