// Hernandez Ceseña Ivan Fernando  373077
//  24/09/23
//  salidas de cadena de diferente forma
// NYP_ACT7_p1_932

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void msg(void);
int repetir(void);
void validar(char []);

void salidas(char *palabra);
void salida1(char *palabra);
void salida2(char *palabra);
void salida3(char *palabra);
void salida4(char *palabra);
void salida5(char *palabra);
void salida6(char *palabra);
void salida7(char *palabra);
void salida8(char *palabra);
void salida9(char *palabra);

void normal(char palabra[]);
void mayusculas(char palabra[]);

int main()
{
    msg();
    return 0;
}

void msg()
{
    int op;
    char palabra[30];
    do
    {
        validar(palabra);
        salidas(palabra);
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

void salidas(char palabra[])
{
    mayusculas(palabra);
    salida1(palabra);
    salida2(palabra);
    salida3(palabra);
    salida4(palabra);
    salida5(palabra);
    salida6(palabra);
    salida7(palabra);
    salida8(palabra);
    salida9(palabra);
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



void salida1(char palabra[])
{
    for(int i=0; palabra[i] !='\0'; i++)
    {
        printf("%c", palabra[i]);
    }
    printf("\n\n");
}

void salida2(char palabra[])
{
    int contador=0;
    for(int i=0; palabra[i] !='\0'; i++)
    {
        contador++;
    }
    
    for(int i= contador; i>=0; i--)
    {
        printf("%c", palabra[i]);
    }
    printf("\n\n");
}

void salida3(char palabra[])
{
    for(int i=0; palabra[i] !='\0'; i++)
    {
        printf("%c\n", palabra[i]);
    }
    printf("\n");
}

void salida4(char palabra[])
{
    int contador=0;
    for(int i=0; palabra[i] !='\0'; i++)
    {
        contador++;
    }
    
    for(int i= contador; i>=0; i--)
    {
        printf("%c\n", palabra[i]);
    }
    printf("\n");
}

void salida5(char palabra[])
{
    int contador=0;
    for(int i=0; palabra[i] !='\0'; i++)
    {
        contador++;
    }
    
    for(int i=1; i<=contador; i++)
    {
       for(int j=0; j <= contador-i; j++)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void salida6(char palabra[])
{
    int contador=0;
    for(int i=0; palabra[i] !='\0'; i++)
    {
        contador++;
    }
    
    for(int i=0; i<=contador; i++)
    {
       for(int j=contador; j >=i; j--)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void salida7(char palabra[])
{
    int contador=0;
    for(int i=0; palabra[i] !='\0'; i++)
    {
        contador++;
    }
    
    for(int i=0; i<=contador; i++)
    {
       for(int j=i; j <= contador; j++)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void salida8(char palabra[])
{
    int contador=0;
    for(int i=0; palabra[i] !='\0'; i++)
    {
        contador++;
    }
    
    for(int i=1; i<=contador; i++)
    {
       for(int j=contador-i; j >=0; j--)
        {
            printf("%c", palabra[j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void salida9(char palabra[])
{
    int contador=0;
    for(int i=0; palabra[i] !='\0'; i++)
    {
        contador++;
    }

    char vocales[contador];
    char resto[contador];
    for(int i=0; palabra[i] != '\0'; i++)
    {
        if(palabra[i]=='A' || palabra[i]=='E' || palabra[i]=='I' ||  palabra[i]=='O' ||  palabra[i]=='U')
        {
            vocales[i]= palabra[i];
            resto[i]=0;
        }
        else
        {
            resto[i]=palabra[i];
            vocales[i]=0;
        } 
    }
    for(int i=0; i<=contador; i++)
    {
        if(palabra[i]>=65 && palabra[i]<=90)
        {
            printf("%c", resto[i]);
        }
    }
    printf("\n");
    for(int i=0; i<= contador; i++)
    {
        if(palabra[i]>=65 && palabra[i]<=90)
        {
            printf("%c", vocales[i]);
        }
    }
    printf("\n");
}