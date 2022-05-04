#include "opMaestro.h"

int abrirArchivo(FILE** arch, const char* nomArch, const char* modoAp)
{
    *arch = fopen(nomArch, modoAp);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s en modo %s",nomArch,
                                                                    modoAp);
        return ERROR;
    }
    return TODO_OK;
}
int crearArchMaestro(const char* nomArchMaestro)
{
    FILE* archMaestro;
    if(!abrirArchivo(&archMaestro, nomArchMaestro, ESCRITURA_BIN))
    {
        return ERROR;
    }

    tProd productos[10] =
    {
        {1, "arroz blanco", 400, 110.5},
        {2, "Caballa en aceite", 500, 360.5},
        {3, "Atun", 300, 260.5},
        {4, "Cafe molido", 1000, 500},
        {5, "Cafe instantaneo", 1000, 400},
        {6, "Cacao en polvo", 500, 420.5},
        {7, "Galletitas Dulces", 850, 250.99},
        {8, "Galletitas saladas", 950, 200.99},
        {9, "Leche en polvo", 300, 350},
        {10, "Yerba mate", 1500, 150.99}
    };

    fwrite(productos, sizeof(productos), 1, archMaestro);
    fclose(archMaestro);
    return TODO_OK;
}
void mostrarArchMaestro(const char* nomArchMaestro)
{
    FILE* archMaestro;
    if(!abrirArchivo(&archMaestro, nomArchMaestro, LECTURA_BIN))
    {
        return;
    }

    mostrarArchMaestroProc(archMaestro);

    fclose(archMaestro);
}
void mostrarArchInex(const char* nomArchInex)
{

    FILE* archInex;
    if(!abrirArchivo(&archInex, nomArchInex, LECTURA_BIN))
    {
        return;
    }

    mostrarProdInexProc(archInex);

    fclose(archInex);
}
void mostrarProdInexProc(FILE* archInex)
{
    tNov nov;

    fread(&nov, sizeof(tNov), 1, archInex);
    while(!feof(archInex))
    {
        printf("%d %d %c\n",nov.codProd, nov.cant, nov.tipoOp);
        fread(&nov, sizeof(tNov), 1, archInex);
    }
}
void mostrarArchMaestroProc(FILE* archMaestro)
{
    tProd prod;

    mostrarProd(NULL);
    fread(&prod, sizeof(tProd), 1, archMaestro);
    while(!feof(archMaestro))
    {
        mostrarProd(&prod);
        fread(&prod, sizeof(tProd), 1, archMaestro);
    }
}
void mostrarProd(const tProd* prod)
{
    if(prod == NULL)
    {
        printf("cod  Descripcion        cant  precio\n");
    }
    else
    {
        printf("%-4d%-20s%-6d%4.2f\n",prod->codProd,prod->desc,
                                      prod->cant,prod->precio);
    }
}
//funcion encargada unicamente de hacer aperturas, cierres,
//y llamar a otra funcion que se encargara del algoritmo
int cargarNovEnMaestro(const char* nomArchNov, const char* nomArchMaestro,
                       const char* nomArchSinStock, const char* nomArchInex)
{
    FILE *archNov, *archMaestro;
    FILE *archSinStock, *archProdInex;

    if(!abrirArchivo(&archNov, nomArchNov, LECTURA_TEXTO))
    {
        return ERROR_NOV;
    }
    if(!abrirArchivo(&archMaestro, nomArchMaestro, LEC_ESC_BIN))
    {
        fclose(archNov);
        return ERROR_MAESTRO;
    }
    if(!abrirArchivo(&archSinStock, nomArchSinStock, ESCRITURA_TEXTO))
    {
        fclose(archNov);
        fclose(archMaestro);
        return ERROR_SSTOCK;
    }
    if(!abrirArchivo(&archProdInex, nomArchInex, ESCRITURA_BIN))
    {
        fclose(archNov);
        fclose(archMaestro);
        fclose(archSinStock);
        return ERROR_INEX;
    }

    cargarNovEnMaestroProc(archNov, archMaestro, archSinStock, archProdInex);

    fclose(archNov);
    fclose(archMaestro);
    fclose(archSinStock);
    fclose(archProdInex);
    return TODO_OK;
}
//algoritmo de carga de novedades en maestro
void cargarNovEnMaestroProc(FILE* archNov, FILE* archMaestro,
                            FILE* archSinStock, FILE* archProdInex)
{
    int cod;
    char reg[TAM_REG];
    tNov nov;

    while(fgets(reg, TAM_REG, archNov))
    {
        trozadoNovLV(reg, &nov, SEP_ARCH_NOV);
        cod = actProdEnMaestro(&nov, archMaestro);
        if(cod == SIN_STOCK)
        {
            fprintf(archSinStock, "%-5d%-7d%-1c\n",nov.codProd,
                                                   nov.cant,
                                                   nov.tipoOp);
        }
        else if(cod == PROD_INEX)
        {
            fwrite(&nov, sizeof(tNov), 1, archProdInex);
        }
        rewind(archMaestro);
    }
}
int actProdEnMaestro(const tNov* nov, FILE* archMaestro)
{
    tProd prod;
    fread(&prod, sizeof(tProd), 1, archMaestro);
    while(!feof(archMaestro))
    {
        if(prod.codProd == nov->codProd)
        {
            if(nov->tipoOp == VENTA)
            {
                prod.cant -= nov->cant;
                if(prod.cant <  0)
                {
                    return SIN_STOCK;
                }
            }
            else if(nov->tipoOp == COMPRA)
            {
                prod.cant += nov->cant;
            }
            // en algunos compiladores mas 'paranoicos' no se puede
            // poner de argumento directamente el sizeof()
            // asi que se lo pasa a long
            fseek(archMaestro, (long)(-1*sizeof(tProd)), SEEK_CUR);
            fwrite(&prod, sizeof(tProd), 1, archMaestro);
            return TODO_OK;
        }
        fread(&prod, sizeof(tProd), 1, archMaestro);
    }
    return PROD_INEX;
}
