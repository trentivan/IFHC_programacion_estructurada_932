




#include <stdio.h>
#include <stdlib.h>

void menu(void);
int msg(void);
int reiniciar(void);
int validar(char [], int , int ); 

void vectorManual(int []);
void vectorAleatorio(int []);
void vectores(int [], int [], int []);
void imprimirVectores(int [], int [], int []);
void llenarMatriz(int [], int [], int [][3]);
void imprimirMattriz(int [][3]);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    do
    {
        fflush(stdin);
        op= msg();
        int vector1[10];
        int vector2[10];
        int vector3[10];
        int matriz[3][3];
        switch(op)
        {
            case 1:
            vectorManual(vector1);
            break;

            case 2:
            vectorAleatorio(vector2);
            break;

            case 3:
            vectores(vector1, vector2, vector3);
            break;

            case 4:
            imprimirVectores(vector1, vector2, vector3);
            break;

            case 5:
            llenarMatriz(vector1, vector2, matriz[3][3]);
            break;

            case 6:
            imprimirMattriz(matriz[3][3]);
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
    printf("5) llenar matriz 4 x 4");
    printf("6) llenar matriz.\n");
    printf("0) terminar programa.");
    op= validar("elige una opcion\n",0,6);

    return op;
}

int validar(char[30], li, ls)
{

}

void vectorManual(int vector1[])
{

}

void vectorAleatorio(int vector2[])
{

}

void vectores(int vector1[], int vector2[], int vector3[])
{

}

void imprimirVectores(int vector1[], int vector2[], int vector3[])
{

}

void llenarMatriz(int vector1[], int vector2[], int matriz[][3])
{

}

void imprimirMattriz(int matriz[][3])
{

}