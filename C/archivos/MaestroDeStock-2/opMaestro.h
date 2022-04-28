#ifndef OPMAESTRO_H_INCLUDED
#define OPMAESTRO_H_INCLUDED

#include <stdio.h>
#include "estructuras.h"
#include "trozadoArchTexto.h"

#define NOM_ARCH_SIN_STOCK "archSinStock.txt"
#define NOM_ARCH_PROD_INEX "archProdInex.bin"

//modos de apertura
#define LECTURA_TEXTO "rt"
#define ESCRITURA_TEXTO "wt"
#define LECTURA_BIN "rb"
#define ESCRITURA_BIN "wb"
#define LEC_ESC_BIN "r+b"

//longitudes variables
#define TAM_REG 100

//ok
#define TODO_OK 1


//errores
#define SIN_STOCK 2
#define PROD_INEX 3

#define ERROR 0
#define ERROR_NOV -1
#define ERROR_MAESTRO -2
#define ERROR_SSTOCK -3
#define ERROR_INEX -4

//otros
#define SEP_ARCH_NOV ';'
#define COMPRA 'C'
#define VENTA 'V'

int abrirArchivo(FILE** arch, const char* nomArch, const char* modoAp);
int aperturaMasiva(
        FILE** archNov, const char* nomArchNov, const char* modoAp1,
        FILE** archMaestro, const char* nomArchMaestro, const char* modoAp2,
        FILE** archSinSt, const char* nomArchSinSt, const char* modoAp3,
        FILE** archInexis, const char* nomArchInexis, const char* modoAp4
);
void cierreMasivo(FILE** arch1, FILE** arch2, FILE** arch3, FILE** arch4);

int crearArchMaestro(const char* nomArchMaestro);
void mostrarArchMaestro(const char* nomArchMaestro);
void mostrarProd(const tProd* prod);
int cargarNovEnMaestro(const char* nomArchNov, const char* nomArchMaestro);
int actProdEnMaestro(const tNov* nov, FILE* archMaestro);


#endif // OPMAESTRO_H_INCLUDED
