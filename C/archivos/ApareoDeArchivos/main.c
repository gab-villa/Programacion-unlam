#include "main.h"
int main()
{
    int codRetorno;
    crearArchBin(NOMBRE_ARCH_BIN);
    printf("Archivo Binario:\n");
    mostrarArchivoBin(NOMBRE_ARCH_BIN);
    printf("\nArchivo de Texto:\n");
    mostrarArchivoTxt(NOMBRE_ARCH_TXT);

    codRetorno = apareoDeArchivos(NOMBRE_ARCH_BIN,
                                  NOMBRE_ARCH_TXT,
                                  NOMBRE_ARCH_FUS);
    if(codRetorno != TODO_OK)
    {
        return codRetorno;
    }
    printf("\nArchivo Fusion:\n");
    mostrarArchivoBin(NOMBRE_ARCH_FUS);
    return 0;
}
