// Hernandez Ceseña Ivan Fernando  373077
// 24/09/23
// convierte la cadena en mayusculas, minusculas, capital, da el numero de caracteres,
// numero de caracteres al reves, la cadena sin espacios, conjunto de varias opciones,
// compara si es un palindromo o no
// NYP_ACT7_p2_932

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void msg(void);
int menu(void);
int repetir(void);
void validar(char []);

int mayusculas(char []);
void minusculas(char []);

void fmayusculas(char []);
void fminusculas(char []);
void capital(char []);
void numero_caracteres(char []);
void caracteres_alreves(char []);
void sin_espacios(char []);
void comenzar_sinespacios(char []);
void conjunto_cadenas(char []);
void palindromo(char []);

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
    printf("4) numero de caracteres\n");
    printf("5) numero de caracteres al reves\n");
    printf("6) cadena sin espacios\n");
    printf("7) regla de cadena\n");
    printf("8) conjunto ( opciones 1,2,3,5,6)\n");
    printf("9) palindromo\n");
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
            fmayusculas(palabra);
            break;

            case 2:
            fminusculas(palabra);
            break;

            case 3:
            capital(palabra);
            break;

            case 4:
            numero_caracteres(palabra);
            break;

            case 5:
            caracteres_alreves(palabra);
            break;

            case 6:
            sin_espacios(palabra);
            printf("%s", palabra);
            break;

            case 7:
            comenzar_sinespacios(palabra);
            break;

            case 8:
            conjunto_cadenas(palabra);
            break;

            case 9:
            palindromo(palabra);
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

int mayusculas(char palabra[])
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
        // printf("%c", palabra[i]);
    }
    return palabra;
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
                if(palabra[i] <= 'z')
                {
                    palabra[i]=palabra[i];
                }
            }
        }
    }
}

void fmayusculas(char palabra[])
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

void fminusculas(char palabra[])
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
    int convertir=0;
    minusculas(palabra);

    for(int i=0; palabra[i] != '\0'; i++)
    {
        if(convertir==1)
        {
            if(palabra[i]>='a')
            {
                if(palabra[i]<= 'z')
                {
                    palabra[i]= palabra[i]-32;
                }
            }
            if(palabra[i] >= 'A')
            {
                if(palabra[i] <= 'Z')
                {
                    palabra[i]= palabra[i] + 32;
                }
                convertir = 0;
            }
        }
        else
        {
            convertir=1;
        }
    }

    for(int i=0; palabra[i] != '\0';i++)
    {
        if(i==0)
        {
            palabra[i]= palabra[i] -32;
        }

        if(palabra[i]==32)
        {
            palabra[i+1] = palabra[i+1]-32;
        }
        printf("%c", palabra[i]);
    }
}

void numero_caracteres(char palabra[])
{ 
    int contador;
    for(contador=0; palabra[contador] != '\0'; contador++);
    printf("%d", contador);
}

void caracteres_alreves(char palabra[])
{
    int contador, contador2;
    for(contador=0; palabra[contador] != '\0'; contador++);
    
    for(contador2= contador; contador2 >=0 ; contador2--)
    {
        printf("%d", contador2);
    }
}

void sin_espacios(char palabra[]) 
{
    int i, j = 0;

    for (i = 0; palabra[i] != '\0'; i++) {
        if (palabra[i] != ' ') {
            palabra[j] = palabra[i];
            j++;
        }
    }

    palabra[j] = '\0'; // Agrega el carácter nulo al final de la cadena resultante
}


void comenzar_sinespacios(char palabra[])
{
    int contador=0;
    for(contador=0; palabra[contador] != '\0';contador++)
    {
        contador++;
    }
    
    for(int i=0, contador; palabra[i] != '\0';i++)
    {
        if(i==0)
        {
            if(palabra[i] == ' ')
            {
                printf("la cadena no puede empezar con espacios\n");
                for(int i=0; palabra[i] != '\0';i++)
                {
                    if(palabra[i]== ' ')
                    {
                        palabra[i]=palabra[i+1];
                    }
                }
                
            }
        }
        if(i==contador)
        {
            if(palabra[i]==' ')
            {
                printf("la cadena no puede terminar con espacios\n");
                palabra[i]=0;
            }
        }
        // printf("%c", palabra[i]);
    }

    for(int i=0; palabra[i] != '\0';i++)
    {
        printf("%c", palabra[i]);
    }
}

void conjunto_cadenas(char palabra[])
{
    fmayusculas(palabra);
    printf("\n");
    fminusculas(palabra);
    printf("\n");
    capital(palabra);
    printf("\n");
    sin_espacios(palabra);
    printf("\n");
    caracteres_alreves(palabra);
    printf("\n");
}

void palindromo(char palabra[]) 
{
    sin_espacios(palabra);
    int contador;
    for (contador = 0; palabra[contador] != '\0'; contador++);

    int izquierda = 0, bandera = 1; // Inicializa bandera en 1 (asume que es un palíndromo)
    int derecha = contador - 1;
    
    while (izquierda < derecha) {
        // Convierte las letras a minúsculas antes de comparar
        char izq = mayusculas(palabra);
        char der = mayusculas(palabra);

        if (izq != der) {
            bandera = 0; // Si encuentra una diferencia, no es un palíndromo
            break;
        }
        izquierda++;
        derecha--;
    }

    if (bandera == 1) {
        printf("Es un palindromo\n");
    } else {
        printf("No es un palindromo\n");
    }
}