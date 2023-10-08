#include <stdio.h>
#include <time.h>
#include "ivan.h"


void menu(void);
void msg(void);

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
    int li, ls;
    do{
        msg();
        op= validarNumero("elije unna opcion\n", 0, 6);
        switch(op)
        {
            case 1:
            li=100, ls=200;
            vectorAleatorioSinRepetir(vector, n, li, ls);
            break;

            case 2:
            matrizAleatoriaSinRepetir(matriz, m, p, li, ls);
            break;

            case 3:

        }
    }while(op!=0);
}

void msg()
{
    printf("MENU\n");
    printf("1) llenar vector\n");
    printf("2) llenar matriz\n");
    printf("3) imprimir vector\n");
    printf("4) imprimir matriz\n");
    printf("5) ordenar vector\n");
    printf("6) buscar valor en vector\n");
    printf("0) terminar programa\n");
}

