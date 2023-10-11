// Hernandez Ceseña Ivan Fernando  373077
// 10/10/23
// 
// 
// 
// NYP_ACT10_932


#include <stdio.h>
#include <time.h>
#include "ivan.h"

void menu(void);
void msg(void);

int main()
{
    Talumnos vector[10];

    menu();
}



void msg()  //  aqui se muestran todas las opciones 
{
    printf("MENU\n");
    printf("1) agregar automaticamente registros.\n");
    printf("2) agregar manualmente.\n");
    printf("3) eliminar registro\n");
    printf("4) buscar.\n");
    printf("5) ordenar\n");
    printf("6) imprimir\n");
    printf("0) terminar programa\n");
}

void menu()  // funcion menu
{
    int op, n=15, m=4, p=4;  // [op] que controla el switch, las demas variables definen tamano de vector y matriz 
    int vector[n];  // declaracion de vector
    int matriz[m][p];  // declaracion de matriz
    int li, ls;   // limite inferior [li], limite superior [ls]
    int buscar, num;   // variables para el caso 6
    
    //  ciclo do while que controla el caso a ejecutar con ayuda de [op]
    do{
        msg();
        op= validacionNumero("elije una opcion", 0, 6);
        switch(op)
        {
            case 1:
            li=100, ls=200;
            vectorAleatorioSinRepetir(vector, n, li, ls);
            break;

            case 2:
            li=1, ls=16;
            matrizAleatoria(matriz, m, p, li, ls);
            break;

            case 3:
            imprimirVector(vector, n, "vector de numeros sin repetir");
            break;

            case 4:
            imprimirMatriz(matriz, m, p, "matriz de numeros sin repetir");
            break;

            case 5:
            ordenarVectorAscendente(vector, n);
            for(int i=0; i < n; i++)
            {
                printf("%d ", vector[i]);
            }
            printf("\n");
            break;

            case 6:
            li=100, ls=200;

            imprimirVector(vector, n, "busqueda de numero en vector");
            num = validacionNumero("dame el numero a buscar en el vector", li, ls);
            buscar = busquedaSecuencial(vector, n, num);

            if(buscar != -1)
            {
                printf("el numero %d se encuentra en la posicion %d\n", num, buscar);
            }
            else
            {
                printf("el numero no se encuentra en el vector\n");
            }
            break;

        } 
    }while(op!=0);  //  condicion  que evalua si op [0] termina el programa
}