#include <stdio.h>
#include <conio.h>
#define PAUSE printf("toca una tecla para continuar\n"); getch();


int main()
{
    char letra;
    for(int i=0; i<20; i++)
    {
        char letra;
        letra = getch();
        printf("%c = %d\n", letra, letra);
    }
    return 0;
}
