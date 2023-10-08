#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

            }while(existeMatriz(matriz, m, n, num) == 1);

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
                return 1;
            }
        }
    }
    return 0;
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
    int li=1, ls=20;

    matrizSinRepetir(matriz, m, n, li, ls);
    imprimirMatriz(matriz, m, n);
    return 0;
}