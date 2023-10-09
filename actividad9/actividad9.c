// Hernandez Ceseña Ivan Fernando  373077
// 08/10/23
// LLENAR VECTOR ALEATORIAMENTE SIN REPETIR VALORES ( RANGO 1-16)  
// LLENAR MATRIZ ALEATORIAMENTE SIN REPETIR VALORES (RANGO 100-200)
// IMPRIMIR VECTORES Y MATRICES ; ORDENAR VECTOR Y BUSCAR VALOR EN VECTOR
// NYP_ACT9_932


#include <stdio.h>
#include <time.h>
#include "ivan.h"

// prototipos
void menu(void);
void msg(void);

void matrizAleatoria(int matriz[][4], int m, int n, int li, int ls);

int main() // funcion principal
{
    srand(time(NULL));  // semilla inicializada
    menu();  // funcion menu que controla todo el programa
    return 0;
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

void msg()  //  aqui se muestran todas las opciones 
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

void matrizAleatoria(int matriz[][4], int m, int n, int li, int ls)  // funcion para llenar la matriz aleatoria en basse a un vector
{
    int tam= 16;
    int vector2[tam];
    int filas, columnas, i=0;
    
    vectorAleatorioSinRepetir(vector2, tam, li, ls);

    for(filas=0; filas < m; filas++)
    {
        for(columnas=0; columnas < n; columnas++)
        {
            matriz[filas][columnas] = vector2[i];
            i++;
        }
    }
}

