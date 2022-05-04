#ifndef OPMAESTRO_H_INCLUDED
#define OPMAESTRO_H_INCLUDED

#include <stdio.h>
#include "estructuras.h"
#include "trozadoArchTexto.h"

//modos de apertura
#define LECTURA_TEXTO "rt"
#define ESCRITURA_TEXTO "wt"
#define LECTURA_BIN "rb"
#define ESCRITURA_BIN "wb"
#define LEC_ESC_BIN "r+b"

//longitudes variables
#define TAM_REG 100

//ok :)
#define TODO_OK 1

//errores :(
#define SIN_STOCK 2
#define PROD_INEX 3

#define ERROR 0
#define ERROR_NOV -1
#define ERROR_MAESTRO -2
#define ERROR_SSTOCK -3
#define ERROR_INEX -4

//otros :|
#define SEP_ARCH_NOV ';'
#define COMPRA 'C'
#define VENTA 'V'

//fuinciones de auxilio
int abrirArchivo(FILE** arch, const char* nomArch, const char* modoAp);

int crearArchMaestro(const char* nomArchMaestro);
void mostrarArchMaestro(const char* nomArchMaestro);
void mostrarArchMaestroProc(FILE* archMaestro);
void mostrarProd(const tProd* prod);
void mostrarArchInex(const char* nomArchInex);
void mostrarProdInexProc(FILE* archInex);
// lo principal
int cargarNovEnMaestro(const char* nomArchNov, const char* nomArchMaestro,
                       const char* nomArchSinStock, const char* nomArchInex);
void cargarNovEnMaestroProc(FILE* archNov, FILE* archMaestro,
                            FILE* archSinStock, FILE* archProdInex);
int actProdEnMaestro(const tNov* nov, FILE* archMaestro);

#endif // OPMAESTRO_H_INCLUDED
