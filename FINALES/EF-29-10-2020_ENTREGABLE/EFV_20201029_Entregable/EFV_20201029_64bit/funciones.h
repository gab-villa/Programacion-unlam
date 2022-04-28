/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER MODIFICACIÓN QUE HAGA NO SERÁ TENIDA EN CUENTA.      *//**/
/**//**//* SÓLO PARA CAMBIAR LAS CANTIDADES DE FILAS Y COLUMNAS           *//**/
/**//**//*      DURANTE SUS PRUEBAS                                       *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO_1 **/
/////////////////////////////////
/// PROBAR CON:
///     COL_TABLA  21 / 22 / 50 y sacar conclusiones /// 257
///     para   nroLote = 1;
#define COL_TABLA           257
///#define COL_TABLA           21
///#define COL_TABLA           22
///#define COL_TABLA           50
/////////////////////////////////

#define TAM_TEXTO           101

/** función de servicio **/
int cargarTablaReemp(char tabla[][COL_TABLA], int colum, unsigned nroLote);

/** PUNTO 1 A **/
int codificar(char *cadena, const char tabla[][COL_TABLA], int cantCol);

int codificar_MIO(char *cadena, const char tabla[][COL_TABLA], int cantCol);

/** PUNTO 1 B **/
char bienFormada(const char tabla[][COL_TABLA], int colTabla);

char bienFormada_MIO(const char tabla[][COL_TABLA], int colTabla);

/** PUNTO 1 C **/
int decodificar(char *cadena, const char tabla[][COL_TABLA], int cantCol);

int decodificar_MIO(char *cadena, const char tabla[][COL_TABLA], int cantCol);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO_2  **/
/**/

/** función de servicio **/
#define ARCH_TXT        "noveda.txt"
#define ARCH_BIN        "actual"

typedef struct
{
   long     dni;
   char     apynom[28];
   int      p1,
            r1,
            p2,
            r2,
            prom;
} tReg;

int crearArchivos(const char *archTxt, const char *archBin, int queArchivos);

int mostrarArchivos(const char *archTxt, const char *archBin, FILE *fpPantalla);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/** PUNTO 2 A **/
int actualizar(const char *archBin, const char *archTxt, FILE *fpPantalla,
               int(*leerTxtYActBin)(FILE *, FILE *, FILE *,
                                    int(*trozar)(tReg *, char *),
                                    int(*buscar)(FILE *, const tReg *)),
               int(*trozar)(tReg *, char *),
               int(*buscar)(FILE *, const tReg *));

int actualizar_MIO(const char *archBin, const char *archTxt, FILE *fpPantalla,
                   int(*leerTxtYActBin)(FILE *, FILE *, FILE *,
                                        int(*trozar)(tReg *, char *),
                                        int(*buscar)(FILE *, const tReg *)),
                   int(*trozar)(tReg *, char *),
                   int(*buscar)(FILE *, const tReg *));


/** PUNTO 2 B **/
int leerTxtYActualizarBin(FILE *fpBin, FILE *fpTxt, FILE *fpPantalla,
                          int (*trozar)(tReg *, char *),
                          int (*buscar)(FILE *, const tReg *));


int leerTxtYActualizarBin_MIO(FILE *fpBin, FILE *fpTxt, FILE *fpPantalla,
                              int (*trozar)(tReg *, char *),
                              int (*buscar)(FILE *, const tReg *));



/** PUNTO 2 C **/
#define FIN_PROMEDIO    93
#define TAM_NOTAS       2
#define POS_NOMBRE      41
#define POS_APELLIDO    15
#define POS_DNI         7

int trozarCampos(tReg *registro, char *linea);

int trozarCampos_MIO(tReg *registro, char *linea);


/** PUNTO 2 D **/
int buscarAlumno(FILE *fpBin, const tReg *registro);

int buscarAlumno_MIO(FILE *fpBin, const tReg *registro);



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#endif

