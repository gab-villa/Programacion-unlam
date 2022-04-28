#ifndef OPMAESTRO_H_INCLUDED
#define OPMAESTRO_H_INCLUDED

#include <stdio.h>
#include "estructuras.h"
#include "trozadoArchTexto.h"

#define NOM_ARCH_SIN_STOCK "archSinStock.txt"
#define NOM_ARCH_PROD_INEX "archProdInex.bin"

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
int crearArchMaestro(const char* nomArchMaestro);
void mostrarArchMaestro(const char* nomArchMaestro);
void mostrarProd(const tProd* prod);
int cargarNovEnMaestro(const char* nomArchNov, const char* nomArchMaestro);
int actProdEnMaestro(const tNov* nov, FILE* archMaestro);


#endif // OPMAESTRO_H_INCLUDED
