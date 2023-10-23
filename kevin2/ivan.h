#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int validacionNumero(char msg[], int li, int ls);
void validacionTexto(char msg[], char cadena[], int n);
int numeroAleatorio(int ri, int rf);
void mayusculas(char palabra[]);
void validarAcentos(char cadena[]);



void sinEspacio(char cadena[])
{
    int i, no_space_count = 0;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            cadena[no_space_count++] = cadena[i];
        }
    }

    cadena[no_space_count] = '\0';
}

int numeroAleatorio(int ri, int rf)
{
    int range = (rf - ri + 1);

    return rand() % range + ri;
}

int validacionNumero(char msg[], int li, int ls)  // funcion para que solo se acepten numeros
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
            printf("por favor, introduce otro numero\n");
            valido=1;
        }

    }while(valido==1);  
    
    return numero;
}

void mayusculas(char palabra[])
{
    int i;
    for(i=0; palabra[i] != '\0'; i++)
    {
        if(palabra[i] >= 'a')
        {
            if(palabra[i] <= 'z')
            {
                palabra[i]= palabra[i] - 32;
            }
        }
        else
        {
            if(palabra[i] >= 'A')
            {
                if(palabra[i] <= 'Z')
                {
                    palabra[i]=palabra[i];
                }
            }
        }
    }
}

void validarAcentos(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == -92 || cadena[i] == -91 || cadena[i] == '/' || cadena[i] == '-')
            {
                cadena[i] = 'X';
            }
            if (cadena[i] == -93 || cadena[i] == -23 || cadena[i] == -127 || cadena[i] == -102)
            {
                cadena[i] = 'U';
            }
            if (cadena[i] == -96 || cadena[i] == -75 || cadena[i] == -114 || cadena[i] == -124)
            {
                cadena[i] = 'A';
            }
            if (cadena[i] == -126 || cadena[i] == -112 || cadena[i] == -45 || cadena[i] == -119)
            {
                cadena[i] = 'E';
            }
            if (cadena[i] == -95 || cadena[i] == -42 || cadena[i] == -40 || cadena[i] == -117)
            {
                cadena[i] = 'i';
            }
            if (cadena[i] == -94 || cadena[i] == -32 || cadena[i] == -108)
            {
                cadena[i] = 'O';
            }

        if (cadena[i] == 'Á' && cadena[i] == -124)
        {
            cadena[i] = 'A';
        }
        else
        {
            if (cadena[i] == -119 || cadena[i] == -119 )
            {
                cadena[i] = 'E';
            }
            else
            {
                if (cadena[i] == 'Í' || cadena[i] == -117)
                {
                    cadena[i] = 'I';
                }
                else
                {
                    if (cadena[i] == 'Ó' || cadena[i] == -108)
                    {
                        cadena[i] = 'O';
                    }
                    else
                    {
                        if (cadena[i] == 'Ú' || cadena[i] == -127)
                        {
                            cadena[i] = 'U';
                        }
                    }
                }
            }
        }
    }
}


void validacionTexto(char msg[], char cadena[], int n)  // funcion para validar texto
{
    int invalido=0, contador=0;
    int i;
    do{
        invalido=0;
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);
        validarAcentos(cadena);
        mayusculas(cadena);

        for(i=0 ; cadena[i] != '\0'; i++);
        if(i > n)
        {
            printf("el texto escrito tiene mas de [%d] caracteres.\n", n);
            invalido=1;
        }

        for(i=0 ; cadena[i] != '\0'; i++, contador++)
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
        if(cadena[0] == '\0')
        {
            invalido=1;
            printf("escribe un texto por favor\n");
        }
        if (cadena[0] == ' ')
        {
            invalido=1;
            printf("no se puede tener espacios al inicio del texto\n");
        }
        if(cadena[contador-1] == ' ')
        {
            invalido=1;
            printf("no se puede tener espacios al final del texto\n");
        }
        if(invalido==1)
        {
            printf("Por favor escribe otro texto.\n");
        }

    }while(invalido == 1);
}