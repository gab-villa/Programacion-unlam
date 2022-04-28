#include "ArrayIntParser.h"

int miAtoi(const char* cad)
{
    const char* fin = cad;
    int pot = 1, num = 0, comp;

    if(!*cad)
    {
        return 0;
    }
    while(*fin)
    {
        ++fin;
    }
    --fin;

    while(fin > cad)
    {
        comp = ctoi(*fin);
        if(comp == -1)
        {
            return 0;
        }
        num += pot * comp;
        pot *= BASEDEC;
        --fin;
    }
    if(*fin == '-')
    {
        return num * -1;
    }

    comp = ctoi(*fin);
    if(comp == -1)
    {
        return 0;
    }
    num += pot * comp;
    return num;
}
char* miItoa(char* cad, int num, int base)
{
    char* ini = cad;
    //evaluar la base
    if(base < BASEMIN && base > BASEMAX)
    {
        return VACIO;
    }

    //evaluar el signo
    if(num < 0)
    {
        *cad = '-';
        //cad DEBE comienzar despues del signo
        ++cad;
        num *= -1;
    }

    if(num == 0)
    {
        *cad = '0';
        ++cad;
    }
    while(num > 0){
        *cad = itoc(num % base);
        ++cad;
        num /= base;
    }
    *cad = VACIO;

    // ini tiene que ignorar el signo negativo
    *ini == '-' ? invertirCad(ini+1) : invertirCad(ini);
    return ini;
}
char itoc(int num)
{
    static const char conjuntoNumCad[BASEMAX+1] = "0123456789ABCDEF";
    return num >= 0 && num < BASEMAX ? conjuntoNumCad[num] : '?';
}
//devuelve un numero positivo menor a 0xF, si algo sale mal devuelve negativo
int ctoi(char car)
{
    return car >= '0' && car <= '9' ? car - '0' : -1;
}
void invertirCad(char* cad)
{
    char aux;
    char* fin = cad;
    while(*fin)
    {
        ++fin;
    }
    --fin;
    while(cad < fin)
    {
        aux = *cad;
        *cad = *fin;
        *fin = aux;
        ++cad;
        --fin;
    }
}
