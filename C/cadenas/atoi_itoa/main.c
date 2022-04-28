#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntParser.h"
int main()
{
    //int res = 0;
    char cad[30], *rescad;
    int num = 92999;
    //printf("%d",a/10);
    rescad = miItoa(cad, num, 10);
    printf("%s\n",rescad);

    printf("%d",miAtoi(rescad));
    return 0;
}
