#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED


#define TAM_DESC 31
typedef struct
{
    int codProd;
    int cant;
    char tipoOp;
}tNov;

typedef struct
{
    int codProd;
    char desc[TAM_DESC];
    int cant;
    float precio;
}tProd;

#endif // ESTRUCTURAS_H_INCLUDED
