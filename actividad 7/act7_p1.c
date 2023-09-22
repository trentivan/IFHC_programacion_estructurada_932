

#include <stdio.h>
//#include <string.h>

void msg(void);
void menu(void);

void salidas(char *palabra);
void salida1(char *palabra);
void salida2(char *palabra);
void salida3(char *palabra);
void salida4(char *palabra);
void salida5(char *palabra);
void salida6(char *palabra);
void salida7(char *palabra);
void salida8(char *palabra);
void salida9(char *palabra);

char normal(char palabra[]);
char mayusculas(char palabra[]);

int main()
{
    menu();
    return 0;
}

void msg()
{
    int op;
    char palabra[30];
    do
    {
        printf("dame una palabra");
        gets(palabra);

        salidas(palabra);
    } while (op != 0);
    
}

void salidas(char *palabra)
{
    salida1(palabra);
    salida2(palabra);
    salida3(palabra);
    salida4(palabra);
    salida5(palabra);
    salida6(palabra);
    salida7(palabra);
    salida8(palabra);
    salida9(palabra);
    
}

char mayusculas(char *palabra)
{
    int i;
    for(i=0; palabra[i] != '\0'; i++)
    {
        if(palabra[i] >= 'a')
        {
            if(palabra[i]>= 'z')
            {
                palabra[i]= palabra[i] - 32;
            }
            
        }
        else
        {
            if(palabra[i] >= 'A')
            {
                if(palabra[i] <= 'Z')
                {
                    palabra[i]=palabra[i];
                }
                else
                {
                    
                }
            }
        }
    }
    
}

char normal(char *palabra)
{
    palabra[30]=mayusculas(palabra);
}

void salida1(char palabra[])
{
    palabra[]=normal(palabra);

}