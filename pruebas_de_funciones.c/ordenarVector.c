#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ordenarVectorAscendente(int vector[], int n)
{
    int i, j, aux=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(vector[j]>vector[i])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void ordenarVectorDescendiente(int vector[], int n)
{
    int i, j, aux=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(vector[j]<vector[i])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
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
    int n=10;
    int vec[n];
    int li=10, ls=50;

    vectorSinRepetir(vec, n, li, ls);
    ordenarVectorAscendente(vec, n);
    imprimirVector(vec, n);
    ordenarVectorDescendiente(vec, n);
    imprimirVector(vec, n);

    return 0;
}