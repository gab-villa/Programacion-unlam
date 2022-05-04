#ifndef TROZADOARCHTEXTO_H_INCLUDED
#define TROZADOARCHTEXTO_H_INCLUDED

#define VACIO '\0'

#include <string.h>
#include <stdio.h>
#include "estructuras.h"

//tambien se podria hacer el trozado de LF del archivo Sin Stock
void trozadoNovLV(char* cad, tNov* nov, char sep);

#endif // TROZADOARCHTEXTO_H_INCLUDED
