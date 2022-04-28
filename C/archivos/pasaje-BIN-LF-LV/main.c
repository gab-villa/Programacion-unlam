#include "main.h"
int main()
{
    crearCargarArchivoBin(NOMBRE_ARCH_BIN);
    //mostrarArchivoBin(NOMBRE_ARCH_BIN);
    pasarArchivoBinTextLF(NOMBRE_ARCH_BIN, NOMBRE_ARCH_TEXT_LF);
    pasarArchivoTextLFBin(NOMBRE_ARCH_TEXT_LF, NOMBRE_ARCH_BIN);

    pasarArchivoBinTextLV(NOMBRE_ARCH_BIN, NOMBRE_ARCH_TEXT_LV, SEPARADOR_LV);
    pasarArchivoTextLVBin(NOMBRE_ARCH_TEXT_LV, NOMBRE_ARCH_BIN, SEPARADOR_LV);

    mostrarArchivoBin(NOMBRE_ARCH_BIN);
    return 0;
}
