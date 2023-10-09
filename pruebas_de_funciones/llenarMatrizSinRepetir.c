#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main()
{
    int m=4, n=4;
    int matriz[m][n];
    int li=1, ls=16, op;
    do{
        printf("1) llenar matriz\n");
        printf("0) terminar programa\n");
        op= validacionNumero("opcion", 0, 1);
        switch(op)
        {
            case 1:
            matrizAleatoriaSinRepetir(matriz, m, n, li, ls);
            imprimirMatriz(matriz, m, n);
            break;
        }
    }while(op!=0);    
    return 0;
}