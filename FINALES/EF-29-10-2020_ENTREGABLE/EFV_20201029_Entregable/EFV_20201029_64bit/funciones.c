/**//*        EN LOS SIGUIENTES MACROREEMPLAZOS INDIQUE:                  *//**/
/**//*    APELLIDO(S)     (COMPLETO)                                      *//**/
/**//*    NOMBRE(S)       (COMPLETO)                                      *//**/
/**//*    NÚMERO DE DNI   (con los puntos de millón y de mil              *//**/
/**//*    COMISIÓN                                                        *//**/
#define APELLIDO    "PÉREZ DEL RÍO"
#define NOMBRE      "Juan Manuel"
#define DOCUMENTO   "22.333.444"
#define COMISION    "07(2299)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/



/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

/** para  PUNTO 1 **/
/**       PUNTO 1 A **/
/**
int codificar_MIO(char *cadena, const char tabla[][COL_TABLA], int cantCol)
{

}
 **/
/**
int decodificar_MIO(char *cadena, const char tabla[][COL_TABLA], int cantCol)
{

}
 **/

/**       PUNTO 1 B **/
/**
char bienFormada_MIO(const char tabla[][COL_TABLA], int colTabla)
{

}
 **/

/**                  FIN de PUNTO 1 **/


/** PARA PUNTO 2 **/
/** PUNTO 2 A **/
/**
int actualizar_MIO(const char *archBin, const char *archTxt, FILE *fpPantalla,
                   int(*leerTxtYActBin)(FILE *, FILE *, FILE *,
                                        int(*trozar)(tReg *, char *),
                                        int(*buscar)(FILE *, const tReg *)),
                   int(*trozar)(tReg *, char *),
                   int(*buscar)(FILE *, const tReg *))
{

}
 **/

/** PUNTO 2 B **/
/**
int leerTxtYActualizarBin_MIO(FILE *fpBin, FILE *fpTxt, FILE *fpPantalla,
                              int (*trozar)(tReg *, char *),
                              int (*buscar)(FILE *, const tReg *))
{

}
 **/

/** PUNTO 2 c **/
/**
int trozarCampos_MIO(tReg *pReg, char *linea)
{

}
 **/

/** PUNTO 2 D **/
/**
int buscarAlumno_MIO(FILE *fpBin, const tReg *registro)
{

}
 **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

