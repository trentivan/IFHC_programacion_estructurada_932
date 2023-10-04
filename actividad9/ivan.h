#include <stdio.h>
#include <stdlib.h>

int validarNumero(char msg[], int li, int ls)
{
    int num;
    char cadena[100];
    do{
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        num= atoi(cadena);
    }while(num<li || num>ls);
    return num;
}

void validarTexto(char palabra[])
{
    int i=-1, bandera;
    do
    {
        bandera=0;
        printf("dame una palabra (solo letras mayusculas y/o ,minusculas) (maximo 29 letras)\n");
        fflush(stdin);
        gets(palabra);
        printf("\n");

        for(int j=0;  palabra[j] != '\0' && bandera != 1 ; j++)
        {
            i++;
            
            if(palabra[i] < 65)
            {
                if( palabra[i] == ' ')
                {
                    if(palabra[i+1]== ' ')
                    {
                        printf("valor invalido ingresa otra palabra\n");
                        bandera=1;
                    }
                }
                else
                {
                    printf("valor invalido ingresa otra palabra\n");
                    bandera=1;
                }
            }
            else
            {
                if(palabra[i] > 64)
                {
                    if(palabra[i] > 90)
                    {
                        if(palabra[i] < 97)
                        {
                            printf("valor invalido ingresa otra palabra\n");
                            bandera = 1;
                            // espacio=0;
                        }
                        else
                        {
                            if(palabra[i] > 122)
                            {
                                printf("valor invalido ingresa otra palabra\n");
                                bandera = 1;
                                // espacio=0;
                            }
                            else
                            {
                                bandera=0;
                            }
                        }
                    }
                    else
                    {
                        bandera=0;
                    }
                }
            }
        }
        
    }while(bandera == 1);
}