#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrizAleatoria(int matriz[][4], int m, int n, int li, int ls)
{
    int vector2[16];
    int filas, columnas, i=0;
    int tam=16;
    vectorAleatorioSinRepetir(vector2, tam, li, ls);

    for(filas=0; filas < m; filas++)
    {
        for(columnas=0; columnas < n; columnas++)
        {
            matriz[filas][columnas] = vector2[i];
            i++;
        }
    }
}

void vectorAleatorioSinRepetir(int vector[],int n, int li, int ls)
{
    srand(time(NULL));
    int i, num;
    int rango = ls-li+1;

    for(i=0; i < n; i++)
    {
        do{
            num = (rand()% rango)+li;

        }while(busquedaSecuencial(vector, n, num) != -1);
        vector[i] = num;
    }
    for(i=0; i<n; i++)
    {
        printf("%d ", vector[i]);
    }
}

int busquedaSecuencial(int vector[], int n, int numero)
{
    int i;

    for(i = 0; i < n ; i++)
    {
        if(vector[i] == numero)
        {
            return i+1;
        }
    }
    return -1;
}

void imprimirMatriz(int matriz[][4], int m, int n, char nombre[])
{
    int i,j;
    printf("%s\n", nombre);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("[%d]\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m=4, n=4;
    int matriz[m][n];
    int li=1, ls=16;

    matrizAleatoria(matriz, m, n, li, ls);
    imprimirMatriz(matriz, m, n, "matriz sin repetir");

    return 0;
}