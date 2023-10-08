#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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
    for(i=0; i<n; i++)
    {
        printf("%d ", vector[i]);
    }
}

int main()
{
    int n=20, numero, i;
    int vector[n];
    int li=10, ls=20;
    char cadena[n];

    int n=10;
    int vect[n];
    int li=10, ls=20;

    vectorSinRepetir(vect, n, li, ls);
    return 0;
}