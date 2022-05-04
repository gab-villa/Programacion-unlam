#include "ApareoDeArchivos.h"

int abrirArchivo(FILE** arch, const char* nomArch, const char* modoAp)
{
    *arch = fopen(nomArch, modoAp);
    if(*arch == NULL)
    {
        fprintf(stderr, "No se pudo abrir el arch %s en modo %s.", nomArch
                                                                 , modoAp);
        return ERROR;
    }
    return TODO_OK;
}
int crearArchBin(const char* nomArchBin)
{
    FILE* archBin;
    if(!abrirArchivo(&archBin, nomArchBin, "wb"))
    {
        return ERROR;
    }
    tProd productos[10] =
    {
        {1, "arroz blanco", 400, 110.5},
        {10, "Caballa en aceite", 500, 360.5},
        {30, "Atun", 300, 260.5},
        {40, "Cafe molido", 1000, 500},
        {50, "Cafe instantaneo", 1000, 400},
        {60, "Cacao en polvo", 500, 420.5},
        {70, "Galletitas Dulces", 850, 250.99},
        {80, "Galletitas saladas", 950, 200.99},
        {90, "Leche en polvo", 300, 350},
        {100, "Yerba mate", 1500, 150.99}
    };
    fwrite(productos, sizeof(productos), 1, archBin);
    fclose(archBin);
    return TODO_OK;
}
int apareoDeArchivos(const char* nomArchBin,
                     const char* nomArchTxt,
                     const char* nomArchFus)
{
    FILE* archBin, *archTxt, *archFusion;
    if(!abrirArchivo(&archBin, nomArchBin, "rb"))
    {
        return ERROR_ARCH_BIN;
    }
    if(!abrirArchivo(&archTxt, nomArchTxt, "rt"))
    {
        fclose(archBin);
        return ERROR_ARCH_TXT;
    }
    if(!abrirArchivo(&archFusion, nomArchFus, "wb"))
    {
        fclose(archBin);
        fclose(archTxt);
        return ERROR_ARCH_FUS;
    }
    apareoDeArchivosProc(archBin, archTxt, archFusion);

    fclose(archBin);
    fclose(archTxt);
    fclose(archFusion);
    return TODO_OK;
}
void apareoDeArchivosProc(FILE* archBin, FILE* archTxt, FILE* archFus)
{
    char* exReg; //guarda el estado de fgets (si hay registro)
    char reg[TAM_REG];
    tProd proB, proT;

    fread(&proB, sizeof(tProd), 1, archBin);
    exReg = fgets(reg, TAM_REG, archTxt);
    parseoRegLV(reg, &proT, SEPARADOR);

    while(!feof(archBin) && exReg != NULL)
    {
        if(proB.codProd < proT.codProd)
        {
            fwrite(&proB, sizeof(tProd),1, archFus);
            fread(&proB, sizeof(tProd), 1, archBin);
        }
        else if(proT.codProd < proB.codProd)
        {
            fwrite(&proT, sizeof(tProd), 1, archFus);
            exReg = fgets(reg, TAM_REG, archTxt);
            parseoRegLV(reg, &proT, SEPARADOR);
        }
        else
        {
            fwrite(&proB, sizeof(tProd),1, archFus);
            fwrite(&proT, sizeof(tProd),1, archFus);

            fread(&proB, sizeof(tProd), 1, archBin);
            exReg = fgets(reg, TAM_REG, archTxt);
            parseoRegLV(reg, &proT, SEPARADOR);
        }
    }
    while(!feof(archBin))
    {
        fwrite(&proB, sizeof(tProd),1, archFus);
        fread(&proB, sizeof(tProd), 1, archBin);
    }
    while(exReg != NULL)
    {
        fwrite(&proT, sizeof(tProd),1, archFus);
        exReg = fgets(reg, TAM_REG, archTxt);
        parseoRegLV(reg, &proT, SEPARADOR);
    }
}
void mostrarArchivoBin(const char* nomArch)
{
    FILE* archBin;
    if(!abrirArchivo(&archBin, nomArch, "rb"))
    {
        return;
    }

    mostrarArchivoBinProc(archBin);

    fclose(archBin);
}
void mostrarArchivoBinProc(FILE* archBin)
{
    tProd pro;
    mostrarProducto(NULL);
    fread(&pro, sizeof(tProd),1,archBin);
    while(!feof(archBin))
    {
        mostrarProducto(&pro);
        fread(&pro, sizeof(tProd),1,archBin);
    }
}
void mostrarArchivoTxt(const char* nomArch)
{
    FILE* archTxt;
    if(!abrirArchivo(&archTxt, nomArch, "rt"))
    {
        return;
    }

    mostrarArchivoTxtProc(archTxt);

    fclose(archTxt);
}
void mostrarArchivoTxtProc(FILE* archTxt)
{
    char reg[TAM_REG];
    tProd pro;
    mostrarProducto(NULL);
    while(fgets(reg, TAM_REG, archTxt))
    {
        parseoRegLV(reg, &pro, SEPARADOR);
        mostrarProducto(&pro);
    }
}
void mostrarProducto(const tProd* pro)
{
    if(pro == NULL)
    {
        printf("COD DESCRIPCION              CANT PRECIO\n");
    }
    else
    {
        printf("%-4d%-25s%-5d%-5.2f\n",pro->codProd, pro->desc
                                 ,pro->cant, pro->precio);
    }
}

//Esta funcion de parseo, a pesar de poseer un return, no retorna
//valores porque a la funcion que la llama, no le interesa
//saber que ocurrio durante el proceso
void parseoRegLV(char* reg, tProd* pro, char separador)
{
    char* aux = reg;

    //strchr retorna NULL si no lo encuentra
    aux = strchr(reg, '\n');

    //en caso de que reg no sea un registro
    if(aux == NULL)
    {
        return;
    }
    *aux = '\0';

    aux = strrchr(reg, separador);
    sscanf(aux+1, "%f", &pro->precio);
    *aux = '\0';

    aux = strrchr(reg, separador);
    sscanf(aux+1, "%d", &pro->cant);
    *aux = '\0';

    aux = strrchr(reg, separador);
    strcpy(pro->desc, aux+1);
    *aux = '\0';

    sscanf(reg, "%d", &pro->codProd);
}
