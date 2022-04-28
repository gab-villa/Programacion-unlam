#include "main.h"

#define NOMBRE_ARCH_MAESTRO "archMaestro.bin"
#define NOMBRE_ARCH_NOV "archNovLV.txt"
int main()
{
    crearArchMaestro(NOMBRE_ARCH_MAESTRO);
    mostrarArchMaestro(NOMBRE_ARCH_MAESTRO);
    printf("\n\n AHORA CARGANDO LAS NOVEDADES.. \n\n");
    cargarNovEnMaestro(NOMBRE_ARCH_NOV, NOMBRE_ARCH_MAESTRO);
    mostrarArchMaestro(NOMBRE_ARCH_MAESTRO);
    return 0;
}
