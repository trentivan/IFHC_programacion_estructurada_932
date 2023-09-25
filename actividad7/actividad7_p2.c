// Hernandez Ceseña Ivan Fernando  373077
// 24/09/23
// salidas de cadena de diferente forma
// NYP_ACT7_p1_932

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void msg(void);
int menu(void);
int repetir(void);
void validar(char []);

void mayusculas(char []);
void minusculas(char []);
void capital(char []);

int main()
{
    msg();
    return 0;
}

int menu()
{
    int op;

    printf("como quieres transcribir tu cadena?\n");
    printf("1) mayusculas\n");
    printf("2) minusculas\n");
    printf("3) capital\n");
    scanf("%d",& op);
    return op;
}

void msg()
{
    int op;
    char palabra[30];
    do
    {
        validar(palabra);
        op = menu();
        switch(op)
        {
            case 1:
            mayusculas(palabra);
            break;

            case 2:
            minusculas(palabra);
            break;

            case 3:
            capital(palabra);
            break;
        }
        op = repetir();
    } while (op != 0);
}

int repetir()
{
    int op;
    printf("\nquieres escribir otra palabra?\n");
    printf("1)si.\n0)no.\n");
    scanf("%d",& op);

    return op;
}

void validar(char palabra[])
{
    // char palabra[30];
    int i=-1, bandera=0;
    do
    {
        
        printf("dame una palabra (solo letras mayusculas y/o ,minusculas) (maximo 29 letras)\n");
        fflush(stdin);
        gets(palabra);

        for(int j=0;  palabra[i] != '\0' ; j++)
        {
            i++;
            // printf("%c \n", palabra[i]);
            if(palabra[i] == ' ')
            {
                if(palabra[i+1] == ' ')
                {
                    printf("valor invalido ingresa otra palabra\n");
                    bandera=1;
                }
            }
            if(palabra[i] < 65)
            {
                printf("valor invalido ingresa otra palabra\n");
                bandera=1;
            }
            if(palabra[i] > 64)
            {
                if(palabra[i] > 90)
                {
                    if(palabra[i] < 97)
                    {
                        printf("valor invalido ingresa otra palabra\n");
                        bandera = 1;
                    }
                    else
                    {
                        if(palabra[i] > 122)
                        {
                            printf("valor invalido ingresa otra palabra\n");
                            bandera = 1;
                        }
                    }
                }
            }
        }
        
    }while(bandera == 1);
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
        printf("%c", palabra[i]);
    }
}

void minusculas(char palabra[])
{
    
    for(int i=0; palabra[i] != '\0'; i++)
    {
        if(palabra[i] >= 'A')
        {
            if(palabra[i] <= 'Z')
            {
                palabra[i]= palabra[i] + 32;
            }
        }
        else
        {
            if(palabra[i] >= 'a')
            {
                if(palabra[i] <= 'a')
                {
                    palabra[i]=palabra[i];
                }
            }
        }
        printf("%c", palabra[i]);
    }
}

void capital(char palabra[])
{
    minusculas(palabra);

    for(int i=0; palabra[i] != '\0';i++)
    {
        if(i==0)
        {
            palabra[i]= palabra[i] -32;
        }

        if(palabra[i]==32)
        {
            palabra[i+1] = palabra[i+1]+32;
        }
        printf("%c", palabra[i]);
    }
}
