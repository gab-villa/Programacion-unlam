#ifndef APAREODEARCHIVOS_H_INCLUDED
#define APAREODEARCHIVOS_H_INCLUDED

#include "estructuras.h"
#include <stdio.h>
#include <string.h>

#define TAM_REG 200

#define SEPARADOR ';'

#define ERROR_ARCH_BIN -1
#define ERROR_ARCH_TXT -2
#define ERROR_ARCH_FUS -3

#define ERROR 0
#define TODO_OK 1

int abrirArchivo(FILE** arch, const char* nomArch, const char* modoAp);
int crearArchBin(const char* nomArchBin);
void mostrarArchivoBin(const char* nomArch);
void mostrarArchivoBinProc(FILE* archBin);
void mostrarArchivoTxt(const char* nomArch);
void mostrarArchivoTxtProc(FILE* archTxt);
void mostrarProducto(const tProd* pro);
void mostrarProducto(const tProd* pro);

int apareoDeArchivos(const char* nomArchBin,
                     const char* nomArchTxt,
                     const char* nomArchFusion);
void apareoDeArchivosProc(FILE* archBin, FILE* archTxt, FILE* archFusion);
void parseoRegLV(char* reg, tProd* pro, char separador);


#endif // APAREODEARCHIVOS_H_INCLUDED
