#include <stdio.h>
#include <stdlib.h>

#include "ContarPalabras.h"
int main()
{
    //int cont = 0;
    char cad[100] = "hola mundo x2";
    char* aux = cad;
    char* aux2;
    //cont = contarPalabras(cad);
    //printf("%s\nCant Palabras: %d", cad, cont);
    printf("%s\n",aux);
    ++aux;
    ++aux;
    ++aux;
    aux2 = cad;
    printf("%s\n",aux);
    printf("%s\n",aux2);
    return 0;
}
