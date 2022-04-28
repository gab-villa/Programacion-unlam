#ifndef MOSTRARPARTESDEMATRIZ_H_INCLUDED
#define MOSTRARPARTESDEMATRIZ_H_INCLUDED

#include <stdio.h>
#define COL 4
void mostrarMatrizCompleta(const int matriz[][COL], size_t fila, size_t col);
void mostrarDiagonal(const int matriz[][COL], size_t tam);
void mostrarTriangularSuperior(const int matriz[][COL], size_t tam);
void mostrarTriangularInferior(const int matriz[][COL], size_t tam);
void mostrarDiagonalSec(const int matriz[][COL], size_t tam);
void mostrarTriangularSupSec(const int matriz[][COL], size_t tam);
void mostrarTriangularInfSec(const int matriz[][COL], size_t tam);
#endif // MOSTRARPARTESDEMATRIZ_H_INCLUDED
