#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ivan.h"

int main()
{
    int n=20, numero, i;
    int vector[n];
    int li=10, ls=50;
    char cadena[n];

    validacionTexto("dame un escrito de maximo 20 espacios", cadena, n);
    printf("%s\n", cadena);
    numero = validacionNumero("dame un numero", li, ls);
    printf("%d\n", numero);
    vectorSinRepetir(vector, n, li, ls);
    for(i=0; i<n ;i++ )
    {
        printf("%d ", vector[i]);
    }
    return 0;
}