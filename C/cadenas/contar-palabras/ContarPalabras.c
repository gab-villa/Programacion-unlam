#include "ContarPalabras.h"
int contarPalabras(const char* cad)
{
    int cantPalabras = 0;
    //char*  = cad;
    while(!esAlfa(*cad) && *cad)
    {
        ++cad;
    }
    while(*cad)
    {
        while(esAlfa(*cad))
        {
            ++cad;
        }
        ++cantPalabras;
        while(!esAlfa(*cad) && *cad)
        {
            ++cad;
        }
    }
    return cantPalabras;
}
int contarPalabraPorCriterio(const char* cad, const char* crit)
{
    int cantPalabras = 0;
    //char*  = cad;
    while(!esAlfa(*cad) && *cad)
    {
        ++cad;
    }
    while(*cad)
    {
        while(esAlfa(*cad))
        {
            ++cad;
        }
        ++cantPalabras;
        while(!esAlfa(*cad) && *cad)
        {
            ++cad;
        }

    }
    return cantPalabras;
}
int esAlfa(char letra)
{
    //con parentesis se entiende un poco mejor la condicion
    return (letra >= 'A' && letra <= 'Z') ||
           (letra >= 'a' && letra <= 'z');
}
