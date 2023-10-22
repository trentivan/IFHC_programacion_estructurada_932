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

void validacionTexto(char msg[], char cadena[], int n)  // funcion para validar texto
{
    int invalido=0, contador=0;
    int i;
    do{
        invalido=0;
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);
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

void validacionEnie(char cadena[])
{
    int i, n;
    n = strlen(cadena);

    for (i = 0; i < n; i++)
    {
        if (cadena[i] == -92 || cadena[i] == -91)
        {
            cadena[i] = 'X';
        }
    }
}

void eliminarPreposiciones(char cadena[], char preposiciones[][5])
{
    int i, n;
    for (i = 0; i < 19; i++)
    {
        char *prepos = preposiciones[i];
        n = strlen(prepos);

        if (strncmp(cadena, prepos, n) == 0)
        {
            memmove(cadena, cadena + n, strlen(cadena) - n + 1); // Mueve el resto de la cadena
        }
    }
}
// fin funciones de validaciones                     /////////////////////////////////////////////////////////////////////////