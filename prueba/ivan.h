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

int validacionNumero(char msg[], int li, int ls)
{
    int numero, valido;
    char cadena[100];
    do{
        valido=0;
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);
        numero= atoi(cadena);
        if(numero < li || numero > ls)
        {
            printf("el numero debe estar dentro de este rango (%d-%d)\n", li, ls);
            printf("por favor, inttroduce otro numero\n");
            valido=1;
        }

    }while(valido==1);
    
    return numero;
}

void validacionTexto(char cadena[], int n)
{
    int invalido=0;
    int i;

    do{
        invalido=0;
        printf("Dame un texto\n");
        fflush(stdin);
        gets(cadena);

        for(i=0 ; cadena[i] != '\0'; i++);
        if(i > n)
        {
            printf("el texto escrito tiene mas de [%d] caracteres.\n", n);
            invalido=1;
        }

        for(i=0 ; cadena[i] != '\0'; i++)
        {
            if(cadena[i] > 90)
            {
                if(cadena[i] >= 97)
                {
                    if(cadena[i] > 122)
                    {
                        invalido=1;
                        printf("el texto no puede contener caracteres especiales como este que escribiste [%c]\n", cadena[i]);
                    }
                }
                else
                {
                    invalido=1;
                    printf("el texto no puede contener caracteres especiales como este que escribiste [%c]\n", cadena[i]);
                }
            }
            else
            {
                if(cadena[i] == 32)
                {
                    if(cadena[i+1] == 32)
                    {
                        invalido=1;
                        printf("el texto no puede contener dobles espacios\n");
                    }
                }
                else
                {
                    if(cadena[i] < 65)
                    {
                        invalido=1;
                        printf("el texto no puede contener caracteres especiales como este que escribiste [%c]\n", cadena[i]);
                    }
                }
            }
        }
        if(invalido==1)
        {
            printf("Por favor escribe otro texto.\n");
        }

    }while(invalido == 1);
    printf("%s", cadena);
}