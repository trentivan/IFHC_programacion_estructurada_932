#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Tkey;

typedef struct _work{
    int status;
    Tkey matricula;
    char nombre[30];
    char apPat[50];
    char apMat[50];
    char sexo[15];
    char puesto[30];
    char estado[30];
    int edad;
    Tkey celuar;
} Twrkr;

int main(int arg, char *args[])
{
    FILE *fa;
    char archivo[50];
    int num;
    

    strcpy(archivo, args[1]);
    strcat(archivo, ".dat");

    fa = fopen(archivo, "r");
    if(fa)
    {
        fseek(fa, 0, SEEK_END);
        int tamano = ftell(fa);
        num = tamano / sizeof(Twrkr);
        fclose(fa);
        
        return num;
    }
    else
    {
        printf("no se encontro el archivo %s.dat\n", args[1]);
    }

    return 0;
}