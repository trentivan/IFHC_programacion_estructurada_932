// Hernandez Ceseña Ivan Fernando  373077
// 08/10/23 /  10/10/23 / 14/10/23
// LLENAR VECTOR ALEATORIAMENTE SIN REPETIR VALORES ( RANGO 1-16)  
// LLENAR MATRIZ ALEATORIAMENTE SIN REPETIR VALORES (RANGO 100-200)
// IMPRIMIR VECTORES Y MATRICES ; ORDENAR VECTOR Y BUSCAR VALOR EN VECTOR
// VALIDACION TEXTO Y NUMERO
// HCIF_ACT10_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//   curp //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int validate(int ri, int rf);
int randomNumber(int ri, int rf);
bool validateString(char string[], int max_length);
void uppercaseString(char string[]);

int validate(int ri, int rf)
{
    char string[50];
    int num;

    do
    {
        fflush(stdin);
        gets(string);
        num = atoi(string);
        if (num < ri || num > rf)
        {
            printf("Out of range - Please enter a valid number: ");
        }
    } while (num < ri || num > rf);

    return num;
}

int randomNumber(int ri, int rf)
{
    int range = (rf - ri + 1);

    return rand() % range + ri;
}

void validateAlpha(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == 'Á' && string[i] == 'Ä' && string[i] == 'Â')
        {
            string[i] = 'A';
        }
        else
        {
            if (string[i] == 'É' && string[i] == 'Ë' && string[i] == 'Ê')
            {
                string[i] = 'E';
            }
            else
            {
                if (string[i] == 'Í' && string[i] == 'Ï' && string[i] == 'Î')
                {
                    string[i] = 'I';
                }
                else
                {
                    if (string[i] == 'Ó' && string[i] == 'Ö' && string[i] == 'Ô')
                    {
                        string[i] = 'O';
                    }
                    else
                    {
                        if (string[i] == 'Ú' && string[i] == 'Ü' && string[i] == 'Û')
                        {
                            string[i] = 'U';
                        }
                    }
                }
            }
        }
    }
}

bool validateString(char string[], int max_length)
{
    int invalid = 0;
    int i;

    do
    {
        invalid = 0;
        fflush(stdin);
        gets(string);
        validateAlpha(string);
        uppercaseString(string);

        if (string[0] == ' ')
        {
            invalid = 1;
        }

        for (i = 0; string[i] != '\0'; i++)
        {
            if (string[i] == ' ' && string[i + 1] == ' ')
            {
                invalid = 1;
                printf("The text cannot contain double spaces\n");
            }

            if (!isalpha(string[i]) && string[i] != ' ')
            {
                string[i] = 'X';
            }
        }

        if (i > max_length)
        {
            printf("The entered text has more than [%d] characters.\n", max_length);
            invalid = 1;
        }

        if (invalid == 1)
        {
            printf("Please write a different text: \n");
        }

    } while (invalid == 1);

    return true;
}

void uppercaseString(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }
}

void noSpacesString(char string[])
{
    int i, no_space_count = 0;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[no_space_count++] = string[i];
        }
    }

    string[no_space_count] = '\0';
}


//////////

int vocal(char cadena[], int posicion)
{
    int i;
    for (i = posicion + 1; array[i] != '\0'; i++)
    {
        if (array[i] == 'A')
        {
            return i;
        }
        if (array[i] == 'E')
        {
            return i;
        }
        if (array[i] == 'I')
        {
            return i;
        }
        if (array[i] == 'O')
        {
            return i;
        }
        if (array[i] == 'U')
        {
            return i;
        }
        if (array[i] == 'X')
        {
            return i;
        }
    }
    return -1;
}

char consonante(char cad[])
{
    int n, i;
    n = strlen(cad);
    i = 1;
    while (i < n)
    {
        if (cad[i] != 'A' && cad[i] != 'E' && cad[i] != 'I' && cad[i] != 'O' && cad[i] != 'U' && cad[i] != ' ')
        {   
            return cad[i];
        }
        i++;
    }
    return 'X';
}

//   funciones de matriz     /////////////////////////////////////////////////////////////////////////////////////////////

void imprimirMatriz(int matriz[][4], int m, int n, char nombre[]) // funcion para imprimir nuestra matriz
{
    int i,j;     
    printf("%s\n", nombre);    
    for(i=0; i<m; i++)        
    {
        for(j=0; j<n; j++)     
        {
            printf("[%d]\t", matriz[i][j]);
        }
        printf("\n");     
    }
}
// fin funciones de matriz      ///////////////////////////////////////////////////////////////////////////////////////////


// funciones de vectores    //////////////////////////////////////////////////////////////////////////////////////////////
int busquedaSecuencial(int vector[], int n, int numero)  // funcion para buscar un valor en un vector previamente enviado 
                                                         //( funciona para llenar vectores sin repetir datos)
{
    int i;   

    for(i = 0; i < n ; i++)    
    {
        if(vector[i] == numero)   
        {
            return i+1; 
        }
    }
    return -1;
}

void ordenarVectorAscendente(int vector[], int n)  // funcion para ordenar vector de menor a mayor
{
    int i, j, aux=0;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(vector[j]<vector[i])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void ordenarVectorDescendente(int vector[], int n)  // funcion para ordenar vector de mayor a menor
{
    int i, j, aux=0;  

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(vector[j]>vector[i])
            {
                aux = vector[i];
                vector[i] = vector[j];   
                vector[j] = aux;
            }
        }
    }
}

void vectorAleatorioSinRepetir(int vector[],int n, int li, int ls)  // funcion para llenar un vector aleatoriamente sin repetir valores
{
    srand(time(NULL));    
    int i, num;
    int rango = ls-li+1;

    for(i=0; i < n; i++)
    {
        do{
            num = (rand()% rango)+li;

        }while(busquedaSecuencial(vector, n, num) != -1);
        vector[i] = num;
    }
}

void imprimirVector(int vector[], int n, char nombre[])  // funcion que imprime el vector 
{
    int i;  
    printf("%s\n", nombre); 
    for(i=0; i<n; i++)
    {
        printf("[%d] ", vector[i]);
    }
    printf("\n"); 
}
// fin funciones de vectores     //////////////////////////////////////////////////////////////////////////////////////


// validaciones                 ///////////////////////////////////////////////////////////////////////////////////////
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

// fin funciones de validaciones                     /////////////////////////////////////////////////////////////////////////