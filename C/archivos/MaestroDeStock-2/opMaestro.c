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
    tProd prod;
    if(!abrirArchivo(&archMaestro, nomArchMaestro, LECTURA_BIN))
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
    int cantAct = 0, cod;
    char reg[TAM_REG];
    tNov nov;
    FILE *archNov, *archMaestro;
    FILE *archSinStock, *archProdInex;

    cod = aperturaMasiva(&archNov, nomArchNov, LECTURA_TEXTO,
                         &archMaestro, nomArchMaestro, LEC_ESC_BIN,
                         &archSinStock, NOM_ARCH_SIN_STOCK, ESCRITURA_TEXTO,
                         &archProdInex, NOM_ARCH_PROD_INEX, ESCRITURA_BIN);
    if(cod != TODO_OK)
    {
        return cod;
    }

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
        else
        {
            ++cantAct;
        }
        rewind(archMaestro);
    }

    cierreMasivo(&archNov, &archMaestro, &archSinStock, &archProdInex);
    return cantAct;
}
//se tienen que especificar los nombres ya que segun que archivo fallo,
//se retornan codigos de error diferentes
int aperturaMasiva(FILE** archNov, const char* nomArchNov, const char* modoAp1,
                   FILE** archMae, const char* nomArchMae, const char* modoAp2,
                   FILE** archSst, const char* nomArchSst, const char* modoAp3,
                   FILE** archIne, const char* nomArchIne, const char* modoAp4)
{
    if(!abrirArchivo(archNov, nomArchNov, modoAp1))
    {
        return ERROR_NOV;
    }
    if(!abrirArchivo(archMae, nomArchMae, modoAp2))
    {
        fclose(*archNov);
        return ERROR_MAESTRO;
    }
    if(!abrirArchivo(archSst, nomArchSst, modoAp3))
    {
        fclose(*archNov);
        fclose(*archMae);
        return ERROR_SSTOCK;
    }
    if(!abrirArchivo(archIne, nomArchIne, modoAp4))
    {
        fclose(*archNov);
        fclose(*archMae);
        fclose(*archSst);
        return ERROR_INEX;
    }
    return TODO_OK;
}
//da igual el orden asi que no hace falta ser especifico con los archivos
void cierreMasivo(FILE** arch1, FILE** arch2, FILE** arch3, FILE** arch4)
{
    fclose(*arch1);
    fclose(*arch2);
    fclose(*arch3);
    fclose(*arch4);
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
