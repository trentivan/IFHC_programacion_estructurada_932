// Hernandez Ceseña Ivan Fernando  373077
// 01/10/23
// LLENAR VECTOR 1 (MANUALMENTE) ; LLENAR VECTOR 2 ALEATORIAMENTE  
// LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2) ; IMPRIMIR VECTORES
// LLENA MATRIZ 4 X 4 ; IMPRIMIR MATRIZ
// NYP_ACT7_p2_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menu(void);
int msg(void);
int reiniciar(void);
int validar(char [], int li, int ls); 

void vectorManual(int vector1[], int n);
void vectorAleatorio(int vector2[], int n);
void vectores(int vector1[], int vector2[], int vector3[], int n);
void imprimirVectores(int *vector1, int n);
void llenarMatriz(int *vector1, int *vector2, int matriz[][3]);
void imprimirMatriz(int matriz[][3], int m);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    int n=10;
    int m=4;
    int vector1[n];
    int vector2[n];
    int vector3[n+n];
    int matriz[m][m];
    // n=10;
    do
    {
    //     fflush(stdin);
    //     gets(op);
        // int vector1[n];
        // int vector2[n];
        // int vector3[n+n];
        // int matriz[3][3];
        fflush(stdin);
        op= msg();
        switch(op)
        {
            // fflush(stdin);
            // op= msg();
            case 1:
            vectorManual(vector1, n);
            break;

            case 2:
            vectorAleatorio(vector2, n);
            break;

            case 3:
            vectores(vector1, vector2, vector3, n);
            break;

            case 4:
            printf("vector 1 (llenado manualmente)\n");
            imprimirVectores(vector1, 10);
            printf("vector 2 llenado aleatoriamente\n");
            imprimirVectores(vector2, 10);
            printf("vector 3 (llenado a base de los vectores 1 y 2)\n");
            imprimirVectores(vector3, 20);
            break;

            case 5:
            llenarMatriz(vector1, vector2, matriz);
            break;

            case 6:
            imprimirMatriz(matriz, m);
            break;
        }

    } while (op != 0);
}

int msg()
{
    int op;
    printf("MENU\n");
    printf("1) llenar menu manualmente.\n");
    printf("2) llenarvector automaticamente.\n");
    printf("3) llenar vector en base a opcion 1 y 2.\n");
    printf("4) imprimir vectores.\n");
    printf("5) llenar matriz 4 x 4\n");
    printf("6) llenar matriz.\n");
    printf("0) terminar programa.\n");
    op= validar("elige una opcion\n",0,6);

    return op;
}

int validar(char mensaje[30],int  li,int ls)
{
    int num;
    printf("%s", mensaje);
    scanf("%d",& num);
    while(num<li || num>ls)
    {
        printf("opcion invalida. introduce una opcion entre %d y %d\n", li, ls);
        scanf("%d",& num);
    }
    return num;
}

void vectorManual(int vector1[], int n)
{
    int num;
    for(int i=0; i<n; i++)
    {
        // printf( "dame un numero entre 30 y 70: \n");

        vector1[i]= num=validar("dame un numero entre 30 y 70\n", 30, 70);
    }
}

void vectorAleatorio(int vector2[], int n)
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        vector2[i]= (rand()% 20)+1;   
    }
}

void vectores(int vector1[], int vector2[], int vector3[], int n)
{
    for(int i=0; i<n; i++)
    {
        vector3[i]= vector1[i];
        vector3[i+n]= vector2[i];
    }
}

void imprimirVectores(int *vector, int n)
{
    
    for(int i=0; i<n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void llenarMatriz(int vector1[], int vector2[], int matriz[][3])
{
    int pos=0, i, j;
    for( i=0; i<4; i++)
    {
        for( j=0; j<4; j++)
        {
            if(pos<10)
            {
                matriz[i][j]= vector1[pos];
            }
            else
            {
                matriz[i][j]= vector2[pos-10];
            }
            pos++;
        }
    }
}

void imprimirMatriz(int matriz[][3], int m)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}