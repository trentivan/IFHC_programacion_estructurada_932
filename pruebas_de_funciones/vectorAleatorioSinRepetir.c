#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void vectorAleatorioSinRepetir(int vector[],int n, int li, int ls)
{
    srand(time(NULL));
    int i, num;
    // int rango = ls-li+1;

    for(i=0; i < n; i++)
    {
        do{
            num = validacionNumero("dame un numero", li, ls);
            // num = (rand()% rango)+li;

        }while(busquedaSecuencial(vector, n, num) != -1);
        vector[i] = num;
    }
    for(i=0; i<n; i++)
    {
        printf("%d ", vector[i]);
    }
}

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

int validacionNumero(char msg[], int li, int ls)  // funcion para que solo se acepten numeros
{
    int numero, valido;  // variables para guardar valor y retornar [numero] y bandera para usarlo como condicion [valido] 
    char cadena[100];  // declaracion de cadena para usarlo como valor de entrada
    do{
        valido=0;  // bandera inicializada en 0
        printf("%s\n", msg);  // se muestra el mensaje escrito previamente en la invocacion
        fflush(stdin);  // esta funcion limpia la entrada
        gets(cadena);   // funcion que guarda el valor ingresado
        numero= atoi(cadena);  // [numero] almacena los numeros ingresados. en caso de ingresarse una letra se guardaran los numeros antes de la primer letra 
        if(numero < li || numero > ls)  // condicion para evaluar si el numero dado esta fuera de los limites
        {
            printf("el numero debe estar dentro de este rango (%d-%d)\n", li, ls);  // si el numero esta fuera de los limites se muestra los mensajes y se activa la bandera
            printf("por favor, introduce otro numero\n");
            valido=1;
        }

    }while(valido==1);  // codicion que valida si la bandera se cumple
    
    return numero;  // si el numero cumple con los requisitos se retorna el mismo
}

int main()
{
    int n=5;
    int vector[n];
    int li=10, ls=31;

    vectorAleatorioSinRepetir(vector, n, li, ls);
    return 0;
}