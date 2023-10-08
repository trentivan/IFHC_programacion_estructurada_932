#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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

int main()
{
    int n=20;
    int vector[n];
    int li=10, ls=31;

    vectorAleatorioSinRepetir(vector, n, li, ls);
    return 0;
}