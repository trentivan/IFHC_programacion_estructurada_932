#include <stdio.h>
#include <time.h>
#include "ivan.h"


void menu(void);
void msg(void);

void llenarVector();


int validarNumero(char msg[], int li, int ls);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void menu()
{
    int op, n=15;
    int vector[n];
    do{
        msg();
        op= validarNumero("elije unna opcion\n", 0, 6);
        switch(op)
        {
            case 1:
            llenarVector(vector);
            break;

            case 2:
            llenarVector(vector);
            break
        }
    }while(op!=0);
}

void msg()
{
    printf("MENU\n");
    printf("1) imprimir opcion\n");
    printf("0) terminar programa\n");
}

void llenarVector(int vector[], int n)
{
    int i, ri=100, rf= 200;
    int rango= (rf-ri)+1, num;

    for(i=0; i<n; i++)
    {
        num=rand()%rango;
        vector[i]= num;
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void imprimirVector(int vector[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}