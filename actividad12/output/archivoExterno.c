#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg, char *args[])
{
    FILE *fa;

    int posicion = 0;
    char archivo[50];
    int num;
    int mat;
    int nombre[20];
    int apPat[20];
    int apMat[20];
    int edad;
    char sexo[10];

    strcpy(archivo, args[1]);
    strcat(archivo, ".txt");

    fa = fopen(archivo, "r");
    if(fa)
    {
        do
        {
            fscanf(fa, "%d.- %d %s %s %s %d %s", &num, &mat, nombre, apPat, apMat, &edad, sexo);
            posicion ++;
        } while (!feof(fa));
        fclose(fa);

        return posicion-1;
    }
    else
    {
        return -1;
    }

    return 0;
}