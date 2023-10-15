#include "ivan.h"

typedef struct _alumnos{
    int status;
    int matricula;
    char apellidoPaterno[30];
    char apellidoMaterno[30];
    char nombre[30];
    int edad;
    int sexo; } Talumno;

void nombres(Talumno reg[], int n);

void matricula(Talumno reg[], int n)
{
    int i, existe, num;
    int li=300000, ls=399999;
    int rango= (ls-li)+1;
    n=100;

    for(i=0; i<n; i++)
    {
        do{
            existe=0;
            // num = validacionNumero("dame tu matricula (ejemplo 313131)",300000, 399999);
            num = rand()%rango + li;
            existe = busquedaSecuencial(registro, n, num);
            if(existe != -1)
            {
                printf("esta matricula ya existe\n introduce otra matricula\n");
            }
        }while(existe != -1);
        registro[i].matricula = num;
    }
    for(i=0; i<n; i++)
    {
        printf("%d\n", registro[i].matricula);
    }
}

Talumno nombres(Talumno reg[], int n)
{
    int nom, i;
    n=10;
    // char nombre[10];
    char nombreMujer[10][10] =
        {
            "ANA",
            "JULIETA",
            "JOSEFINA",
            "DANIELA",
            "CARMEN",
            "SOFIA",
            "LAURA",
            "ANDREA",
            "ELENA",
            "ISABEl"};
    for(i=0; i<n; i++)
    {
        nom = rand()%10;
        strcpy(alumno[i].nombre, nombreMujer[nom]);
    }
    for(i=0; i<n; i++)
    {
        printf("%s\n", alumno[i].nombre);
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

int main()
{
    srand(time(NULL));
    int n=10;
    Talumno registro[n];
    // matricula(registro, n);
    nombres(registro, n);
    return 0;
}

