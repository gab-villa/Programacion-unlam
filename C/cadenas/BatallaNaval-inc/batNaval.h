#ifndef BATNAVAL_H_INCLUDED
#define BATNAVAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM_TABLERO 10
#define TAM_COL TAM_TABLERO + 'A'
#define CANT_NAVES 4

#define C_VACIA '_'
#define C_NAVE 'N'
#define C_LLENA 'X'
#define TODO_OK 1
#define ERROR 0
//estructuras
typedef struct
{
    int x, y;
}tCasilla;

typedef struct
{
    tCasilla c1, c2;
}tNave;

typedef struct
{
    char tablero[TAM_TABLERO][TAM_TABLERO];
    tNave naves[CANT_NAVES];

}tTablero;

//funciones
void crearTab(tTablero* tab);
void mostrarTab(tTablero* tab);
void cargarNaves(tTablero* tab, const int* tamNaves);
//void cargarNave(tTablero* tab);
int cargarNave(char tab[][TAM_TABLERO], tNave* pNav, int tamNave);

void cargarCordNave(tNave* nave);
int validarCordNave(tNave* nave);
void cargarDespNave(tNave* nave, tCasilla* despNave, int* inc, int* fin);
void defIniFin(int *ini, int *fin);
int cargarBarcoEnTab(char tab[][TAM_TABLERO], tCasilla* despNave,
                      int* inc, int fin);

void cargarCasilla(tCasilla* casilla, int numPos);
int validarCasilla(tCasilla* casilla);
int validarCord(int cord);
int validarCol(char col);
#endif // BATNAVAL_H_INCLUDED
