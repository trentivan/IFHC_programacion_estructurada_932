#include <stdio.h>
#include "ivan.h"


void matricula()
{
    int i, n=2, existe, num;
    Talumnos alumnos[n];
    int li=300000, ls=399999;
    int rango= (ls-li)+1;

    for(i=0; i<n; i++)
    {
        do{
            existe=0;
            // num = validacionNumero("dame tu matricula (ejemplo 313131)",300000, 399999);
            num = rand()%rango + li;
            existe = busquedaSecuencial(alumnos, n, num);
            if(existe != -1)
            {
                printf("esta matricula ya existe\n introduce otra matricula\n");
            }
        }while(existe != -1);
        alumnos[i].matricula = num;
    }
    for(i=0; i<n; i++)
    {
        printf("%d\n", alumnos[i].matricula);
    }
}

int main()
{
    matricula();
    return 0;
}

