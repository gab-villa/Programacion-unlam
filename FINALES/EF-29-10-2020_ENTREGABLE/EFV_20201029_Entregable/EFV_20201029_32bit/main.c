/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                         *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR A SUS FUNCIONES                           *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"

int main()
{
    unsigned    nroLote = 1;  // 0=SuTabla  / 1=tablaBien  / 2=TablaMal
///                      ^^^        <-- puede modificar para sus pruebas
///                                     ver la especificación
    unsigned    queArchivos = 3; //  0 a 8
///                          ^^^    <-- puede modificar para sus pruebas

    FILE   *fpPantalla = fopen("pantalla.txt", "wt");

    if(fpPantalla == NULL)
        fpPantalla = stdout;
/// puede dejar comentadas la declaración de la variable "fpPantalla" además
///     del "if(fpPantalla == NULL)" para que la salida sea por consola

    punto_1(fpPantalla, nroLote);

    punto_2(fpPantalla, queArchivos);


    fclose(fpPantalla);

    system("start Notepad pantalla.txt");
    return 0;
}


/**
 **
 **/
void punto_1(FILE *fpPantalla, unsigned nroLote)
{
    char    cad[][TAM_TEXTO] =  {
        { "Es hora de tomar el toro por las astas, hasta capear el temporal." },
        { "Para abrir la puerta del patio." },
        { "Producto: Lata de provisiones, Precio: 1379,98, Existencias: -2" } },
            tablaDeReemplazos[][COL_TABLA] = {
        { "abpqrs" },
        { "rsabpq" } },
            letraDistinta;
    int     cant,
            ciclo,
            valorDevuelto;

    fprintf(fpPantalla,
            "********************************************\n"
            "* PUNTO-1: comienza a ejecutarse. (lote %u) *\n"
            "********************************************\n",
            nroLote);
    valorDevuelto = cargarTablaReemp(tablaDeReemplazos, COL_TABLA, nroLote);
    if(valorDevuelto)
        fprintf(fpPantalla, "Se cargó la tabla de reemplazos %d.\n", nroLote);
    else
        fprintf(fpPantalla, "Se utiliza la tabla de reemplazos declarada.\n");
    for(ciclo = 0; ciclo < sizeof(cad) / sizeof(cad[0]); ++ciclo)
    {
        fprintf(fpPantalla, "      Cadena a codificar:   \"%s\"\n", cad[ciclo]);

/** invoque acá su función  >> codificar_MIO  << */
        cant = codificar(cad[ciclo], tablaDeReemplazos, COL_TABLA);
///            ^^^^^^^^^
        fprintf(fpPantalla, "-Punto 1 a.-  Codificada:   \"%s\"\n", cad[ciclo]);
        fprintf(fpPantalla, "Se hicieron %d reemplazos.\n", cant);

/** invoque acá su función  >> decodificar_MIO  << */
        cant = decodificar(cad[ciclo], tablaDeReemplazos, COL_TABLA);
///            ^^^^^^^^^^^
        fprintf(fpPantalla, "-Punto 1 c.-  Decodificada: \"%s\"\n", cad[ciclo]);
        fprintf(fpPantalla, "Se hicieron %d reemplazos.\n\n", cant);
    }

/** invoque acá su función  >> bienFormada_MIO  << */
    letraDistinta = bienFormada(tablaDeReemplazos, COL_TABLA);
///                 ^^^^^^^^^^^
    fprintf(fpPantalla,
            "Punto 1 b.-  La \"Tabla de Reemplazos %s.\n"
            "                \"%s\"\n"
            "                \"%s\"\n",
            letraDistinta ? "está mal formada" : "es correcta",
            tablaDeReemplazos[0], tablaDeReemplazos[1]);
    if(letraDistinta)
        fprintf(fpPantalla,
                "             Tiene problemas con el carácter \'%c\'.\n",
                letraDistinta);
    fprintf(fpPantalla,
            "********************************************\n"
            "*           Fin ejecución PUNTO-1          *\n"
            "********************************************\n\n");
}

/**
 **
 **/
void punto_2(FILE *fpPantalla, unsigned queArchivos)
{
    int     valDevuelto;

    crearArchivos(ARCH_TXT, ARCH_BIN, queArchivos);
    fprintf(fpPantalla,
            "********************************************\n"
            "* PUNTO-2: comienza a ejecutarse.  (que %u) *\n"
            "********************************************\n",
            queArchivos);
    fprintf(fpPantalla, "***Mostrando los archivos.***\n");
    valDevuelto = mostrarArchivos(ARCH_TXT, ARCH_BIN, fpPantalla);
    fprintf(fpPantalla, "***Se mostraron %d archivos.***\n", valDevuelto);
/**  **/
    valDevuelto = actualizar(ARCH_BIN, ARCH_TXT, fpPantalla,
                             leerTxtYActualizarBin,
                             trozarCampos,
                             buscarAlumno); /**/

/** invoque accontinuación su función  >> actualizar_MIO  << */
/**
    valDevuelto = actualizar_MIO(ARCH_BIN, ARCH_TXT, fpPantalla,
                                 leerTxtYActualizarBin_MIO,
                                 trozarCampos_MIO,
                                 buscarAlumno_MIO);  / **/
///               ^^^^^^^^^^^^^^


    mostrarArchivos("", ARCH_BIN, fpPantalla);
    fprintf(fpPantalla, "La actualización devolvió %d.\n", valDevuelto);
    fprintf(fpPantalla,
            "********************************************\n"
            "*           Fin ejecución PUNTO-2          *\n"
            "********************************************\n\n");
}

