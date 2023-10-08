#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//   funciones de matriz     /////////////////////////////////////////////////////////////////////////////////////////////
void matrizAleatoriaSinRepetir(int matriz[][4], int m, int n, int li, int ls)
{
    int i, j, num;
    int rango= ls-li+1;
    srand(time(NULL));

    if(m*n > rango)
    {
        printf("no se puede llenar la matriz sin repetir datos\n");
    }

    for(i=0; i < m; i++)
    {
        for(j=0; j < n ; j++)
        {
            do{

                num = (rand()%rango) + li;

            }while(existeMatriz(matriz, m, n, num) != -1);

            matriz[i][j]= num;
            
        }
        
    }
    
}

int existeMatriz(int matriz[][4], int  m, int n, int num)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(num == matriz[i][j])
            {
                return i;
            }
        }
    }
    return -1;
}

void imprimirMatriz(int matriz[][4], int m, int n)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
// fin funciones de matriz      ///////////////////////////////////////////////////////////////////////////////////////////


// funciones de vectores    //////////////////////////////////////////////////////////////////////////////////////////////
int busquedaSecuencial(int vector[], int n, int numero)
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

void ordenarVectorAscendente(int vector[], int n)
{
    int i, j, aux=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
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

void ordenarVectorDescendiente(int vector[], int n)
{
    int i, j, aux=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
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

void vectorAleatorioSinRepetir(int vector[],int n, int li, int ls)
{
    
    srand(time(NULL));
    int i=0, j;
    if(n>(ls-li))
    {
        printf("no se puede ejecutar si la resta del limite inferior y superior es menor al tamano de tu vector\n");
        printf("fin de la funcion\n");
        return 0;
    }

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

    
}

void imprimirVector(int vector[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("[%d] ", vector[i]);
    }
    printf("\n");
}
// fin funciones de vectores     //////////////////////////////////////////////////////////////////////////////////////


// validaciones                 ///////////////////////////////////////////////////////////////////////////////////////
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
            printf("por favor, introduce otro numero\n");
            valido=1;
        }

    }while(valido==1);
    
    return numero;
}

void validacionTexto(char msg[], char cadena[], int n)
{
    int invalido=0;
    int i;

    do{
        invalido=0;
        printf("%s\n", msg);
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
}
// fin funciones de validaciones                     /////////////////////////////////////////////////////////////////////////