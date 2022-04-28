#include "batNaval.h"
void crearTab(tTablero* tab)
{
    int i, j;

    for(i = 0;i < TAM_TABLERO;++i)
    {
        for(j = 0;j < TAM_TABLERO;++j)
        {
            tab->tablero[i][j] = C_VACIA;
        }
    }
}
void mostrarTab(tTablero* tab)
{
    char col;
    int i, j;
    system("cls");

    printf("%5c",'A');
    for(col = 'B';col < TAM_COL;++col)
    {
        printf("%4c",col);
    }
    printf("\n\n");
    //imprimir las columnas
    for(i = 0;i < TAM_TABLERO;++i)
    {
        printf("%-4d",i+1);
        for(j = 0;j < TAM_TABLERO;++j)
        {
            printf("%-4c",tab->tablero[i][j]);
        }
        printf("%-4d",i+1);
        printf("\n\n");
    }
    printf("%5c",'A');
    for(col = 'B';col < TAM_COL;++col)
    {
        printf("%4c",col);
    }
}
//rand() % (N+1)  0-N
void cargarNavesRand(tTablero* tab)
{

    tNave* naves = tab->naves;
    int i;

    for(i = 0;i < CANT_NAVES;i++)
    {
        mostrarTab(tab);

        printf("\n\nNAVE-%d:",i+1);

        //la direccion de la estructura de un solo barco

        ++naves;
    }
}
int cargarNave(char tab[][TAM_TABLERO], tNave* pNav, int tamNave)
{
    tCasilla despNave; //ini y despConst
    int* inc, fin;

    if(pNav->c1.x == pNav->c2.x)
    {
        despNave.y = pNav->c1.x; // despConst
        despNave.x = pNav->c1.y; // inicio
        fin = pNav->c2.y; // fin
        inc = &despNave.x; // puntero a la cord de incremento
    }
    else if(pNav->c1.y == pNav->c2.y)
    {
        despNave.x= pNav->c1.y;
        despNave.y = pNav->c1.x;
        fin = pNav->c2.x;
        inc = &despNave.y;
    }
    defIniFin(inc, &fin);

    if((fin - *inc) != tamNave)
    {
        return ERROR;
    }
    return cargarBarcoEnTab(tab, &despNave, inc, fin) ? TODO_OK : ERROR;
}
/*
int cargarNave(char tab[][TAM_TABLERO], tNave* pNav)
{
    if(pNav->c1.x == pNav->c2.x)
    {
        return cargarBarcoEnTab(tab, &(tCasilla){pNav->c1.y, pNav->c1.x},
                                &pNav->c1.y, pNav->c2.y) ? TODO_OK : ERROR;
    }
    else if(pNav->c1.y == pNav->c2.y)
    {
        return cargarBarcoEnTab(tab, &(tCasilla){pNav->c1.x, pNav->c1.y},
                                &pNav->c1.x, pNav->c2.x) ? TODO_OK : ERROR;
    }
    return ERROR;
}*/

int cargarBarcoEnTab(char tab[][TAM_TABLERO], tCasilla* despNave,
                      int* inc, int fin)
{

    int aux = *inc;

    while(*inc <= fin)
    {
        if(tab[despNave->x][despNave->y] == C_NAVE)
        {
            return ERROR;
        }
        ++(*inc);
    }
    *inc = aux;
    while(*inc <= fin)
    {
        tab[despNave->x][despNave->y] = C_NAVE;
        //tab[ini][pNav->c1.x] = C_NAVE;
        ++(*inc);
    }
    return TODO_OK;
}
void defIniFin(int *ini, int *fin)
{
    int aux;
    if(*ini > *fin)
    {
        aux = *ini;
        *ini = *fin;
        *fin = aux;
    }
}

void cargarNaves(tTablero* tab, const int* tamNaves)
{
    tNave* naves = tab->naves;
    int i;

    for(i = 0;i < CANT_NAVES;i++)
    {
        mostrarTab(tab);

        printf("\n\nNAVE-%d: TAM-%d",i+1, *tamNaves);
        //la direccion de la estructura de un solo barco
        cargarCordNave(&(*naves));
        while(!cargarNave(tab->tablero, &(*naves), *tamNaves))
        {
            printf("\nLa nave ingresada no es valida.\n");
            cargarCordNave(&(*naves));
        }
        ++tamNaves;
        ++naves;
    }
}
void cargarCordNave(tNave* nave)
{
    while(!validarCordNave(nave))
    {
        printf("\nLas posiciones del barco NO son validas!\n");
    }
}
int validarCordNave(tNave* nave)
{
    cargarCasilla(&(nave->c1), 1);
    cargarCasilla(&(nave->c2), 2);
    return nave->c1.x == nave->c2.x ||
           nave->c1.y == nave->c2.y;
}
void cargarCasilla(tCasilla* casilla, int numPos)
{
    printf("\nPosicion %d: ", numPos);
    while(!validarCasilla(casilla))
    {
        printf("\nPosicion no valida!");
        printf("\nPosicion %d: ", numPos);
    }
    --casilla->y; //pos a indice
    casilla->x -= 'A'; //col a indice
}
int validarCasilla(tCasilla* casilla)
{
    char col;
    fflush(stdin);
    scanf("%c %d",  &col, &(casilla->y));
    casilla->x = col;
    return validarCol(col) &&
           validarCord(casilla->y);
}
int validarCol(char col)
{
    return col >= 'A' && col <= 'J';
}
int validarCord(int cord)
{
    return cord > 0 && cord <= TAM_TABLERO;
}

