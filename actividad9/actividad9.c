#include <stdio.h>
#include <time.h>
#include "ivan.h"


void menu(void);
void msg(void);




int validarNumero(char msg[], int li, int ls);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void menu()
{
    int op, n=15, m=4, p=4;
    int vector[n];
    int matriz[m][p];
    int li=100, ls=200;
    do{
        msg();
        op= validarNumero("elije unna opcion\n", 0, 6);
        switch(op)
        {
            case 1:
            vectorSinRepetir(vector, n, li, ls);
            break;

            case 2:
            matrizSinRepetir(matriz[][p], m, p,"matriz");
            break;
        }
    }while(op!=0);
}

void msg()
{
    printf("MENU\n");
    printf("1) imprimir opcion\n");
    printf("0) terminar programa\n");
}

