#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

void vectorSinRepetir(int vector[],int n, int li, int ls)
{
    srand(time(NULL));
    int i, j;

    for(i=0; i < n; i++)
    {
        int rango = ls-li+1;
        vector[i]= (rand()% rango)+li;

        for(j=0; j<i; j++)
        {
            if(vector[i]==vector[j])
            {
                i--;
            }
        }
    }
    
}

void imprimirVector(int vector[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("[%d] ", vector[i]);
    }
    printf("\n");
}

int main()
{
    int n=10, num, retorno;
    int vec[n];
    int li=10, ls=50;

    vectorSinRepetir(vec, n, li, ls);
    imprimirVector(vec, n);
    printf("numero a buscar\n");
    scanf("%d",& num);
    retorno = busquedaSecuencial(vec, n, num);
    if(retorno != -1)
    {
        printf("el numero %d esta en la posicion %d del vector\n", num, retorno);
    }
    else
    {
        printf("el numero %d no se encuentra en el vector\n", num);
    }

    return 0;
}