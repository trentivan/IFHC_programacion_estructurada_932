#include <stdio.h>
#include <stdlib.h>

int validacionNumero(char msg[], int li, int ls);

int main()
{
    int i, li, ls;
    int vec[5];
    i=0;
    
    printf("dame tu limite inferior\n");
    scanf("%d",& li);
    printf("dame tu limite superior\n");
    scanf("%d",& ls);

    for(i=0; i<5; i++)
    {
        vec[i] = validacionNumero("dame un numero", li, ls);
        printf("%d\n", vec[i]);
    }
    

    return 0;
}

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
            printf("por favor, inttroduce otro numero\n");
            valido=1;
        }

    }while(valido==1);
    
    return numero;
}