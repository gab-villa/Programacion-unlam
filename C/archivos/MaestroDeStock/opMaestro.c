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
    if(!abrirArchivo(&archMaestro, nomArchMaestro, "wb"))
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
    tProd prod;
    if(!abrirArchivo(&archMaestro, nomArchMaestro, "rb"))
    {
        return;
    }
    mostrarProd(NULL);
    fread(&prod, sizeof(tProd), 1, archMaestro);
    while(!feof(archMaestro))
    {
        mostrarProd(&prod);
        fread(&prod, sizeof(tProd), 1, archMaestro);
    }

    fclose(archMaestro);
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
//devuelve un numero n < 0 si falla. Sino n >= 0 si sale bien siendo
// n bajo este contexto la cantidad de actualizados.
int cargarNovEnMaestro(const char* nomArchNov, const char* nomArchMaestro)
{
    int cantAct = 0, codAct;
    char reg[TAM_REG];
    tNov nov;
    FILE *archNov, *archMaestro;
    FILE *archSinStock, *archProdInex;
    if(!abrirArchivo(&archNov, nomArchNov, "rt"))
    {
        return ERROR_NOV;
    }
    if(!abrirArchivo(&archMaestro, nomArchMaestro, "r+b"))
    {
        fclose(archNov);
        return ERROR_MAESTRO;
    }
    if(!abrirArchivo(&archSinStock, NOM_ARCH_SIN_STOCK, "wt"))
    {
        fclose(archNov);
        fclose(archMaestro);
        return ERROR_SSTOCK;
    }
    if(!abrirArchivo(&archProdInex, NOM_ARCH_PROD_INEX, "wb"))
    {
        fclose(archNov);
        fclose(archMaestro);
        fclose(archSinStock);
        return ERROR_INEX;
    }

    while(fgets(reg, TAM_REG, archNov))
    {
        trozadoNovLV(reg, &nov, SEP_ARCH_NOV);
        codAct = actProdEnMaestro(&nov, archMaestro);
        if(codAct == SIN_STOCK)
        {
            fprintf(archSinStock, "%-5d%-7d%-1c\n",nov.codProd,
                                                   nov.cant,
                                                   nov.tipoOp);
        }
        else if(codAct == PROD_INEX)
        {
            fwrite(&nov, sizeof(tNov), 1, archProdInex);
        }
        else
        {
            ++cantAct;
        }
        rewind(archMaestro);
    }
    fclose(archMaestro);
    fclose(archNov);
    fclose(archProdInex);
    fclose(archSinStock);

    return cantAct;
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
            fseek(archMaestro, -1L*sizeof(tProd), SEEK_CUR);
            fwrite(&prod, sizeof(tProd), 1, archMaestro);
            return TODO_OK;
        }
        fread(&prod, sizeof(tProd), 1, archMaestro);
    }
    return PROD_INEX;
}
