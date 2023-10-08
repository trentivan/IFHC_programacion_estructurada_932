#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ivan.h"

int main()
{
    int n=20, numero;
    int vector[n];
    int li=10, ls=20;
    char cadena[n];

    validacionTexto("dame un escrito de maximo 20 espacios", cadena, n);
    printf("%s\n", cadena);
    numero = validacionNumero("dame un numero", li, ls);
    printf("%d\n", numero);
    vectorSinRepetir(vector, n, li, ls);
    return 0;
}