#include "mostrarPartesDeMatriz.h"
void mostrarMatrizCompleta(const int matriz[][COL], size_t fila, size_t col){
    int i, j;
    printf("Elementos de la matriz:\n");
    for(i = 0;i < fila;++i)
    {
        for(j = 0;j < col;++j)
        {
            printf("%-3d",matriz[i][j]);
        }
        printf("\n");
    }
}
// FUNCIONES DE MATRIZ CUADRADA:
// SE ASUME QUE LA MATRIZ QUE SE PASA POR ARGUMENTO ES CUADRADA
// NO PASAR MATRICES QUE NO SEAN CUADRADAS
void mostrarDiagonal(const int matriz[][COL], size_t tam){
    int i;
    printf("Elementos de la diagonal principal:\n");
    for(i = 0;i < tam;++i)
    {
        printf("%-3d",matriz[i][i]);
    }
    printf("\n");
}
void mostrarTriangularSuperior(const int matriz[][COL], size_t tam)
{
    int i, j;
    printf("Elementos en la triangular superior:\n");
    for(i = 0;i < tam;++i)
    {
        for(j = i+1;j < tam;++j)
        {
            printf("%-3d",matriz[i][j]);
        }
        printf("\n");
    }
}
void mostrarTriangularInferior(const int matriz[][COL], size_t tam)
{
    int i, j;
    printf("Elementos en la triangular inferior:\n");
    for(i = 0;i < tam;++i)
    {
        for(j = i+1;j < tam;++j)
        {
            printf("%-3d",matriz[j][i]);
        }
        printf("\n");
    }
}
void mostrarDiagonalSec(const int matriz[][COL], size_t tam){
    int i, j = tam-1; //necesito un j que valla contando desde el final
    printf("Elementos de la diagonal secundaria:\n");
    for(i = 0;i < tam;++i)
    {
        printf("%-3d",matriz[i][j]);
        j--;
    }
    printf("\n");
}
void mostrarTriangularSupSec(const int matriz[][COL], size_t tam)
{
    int i, j;
    printf("Elementos en la triangular superior secundaria:\n");
    for(i = 0;i < tam-1;++i)
    {
        // j retrocede 2 porque no existe la posicion en tam
        // y ademas se tiene que ignorar los elementos
        // de la diagonal secundaria.
        for(j = tam-i-2;j >= 0;--j)
        {
            printf("%-3d",matriz[i][j]);
        }
        printf("\n");
    }
}
void mostrarTriangularInfSec(const int matriz[][COL], size_t tam)
{
    int i, j;
    printf("Elementos en la triangular inferior secundaria:\n");
    for(i = 1;i < tam;++i)
    {
        for(j = tam-1;j > tam-i-1;--j)
        {
            printf("%-3d",matriz[i][j]);
        }
        printf("\n");
    }
}
