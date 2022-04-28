#include "trozadoArchTexto.h"

void trozadoNovLV(char* cad, tNov* nov, char sep)
{
    char* aux = strchr(cad, '\n');
    *aux = VACIO;

    aux = strrchr(cad, sep);
    sscanf(aux+1, "%c", &nov->tipoOp);
    *aux = VACIO;

    aux = strrchr(cad, sep);
    sscanf(aux+1, "%d", &nov->cant);
    *aux = VACIO;

    sscanf(cad, "%d", &nov->codProd);
}
void trozadoLF(char* cad, tProd* prod)
{

}
