#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ivan.h"

void vectorSinRepetir(int vector[], int n, int li, int ls);

int main()
{
    int n=20, numero;
    int vector[n];
    int li=10, ls=20;
    char cadena[n];

    vectorSinRepetir(vector, n, li, ls);
    validacionTexto("dame una palabra", cadena, n);
    printf("%s\n", cadena);
    numero = validacionNumero("dame un numero", li, ls);
    printf("%d", numero);

    return 0;
}

