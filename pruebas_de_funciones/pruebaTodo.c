#include <stdio.h>
#include <string.h>
#include <time.h>
#include "listas.h"


typedef struct _names{
    char apellidoPaterno[30];
    char apellidoMaterno[30];
    char nombre[30];
} Tnamepeople;

typedef struct _fecha{
    int anio;
    int mes;
    int dia;
} Tdate;

typedef struct _alumnos{
    int status;
    int matricula;
    Tnamepeople  nombres;
    Tdate fecha;
    int edad;
    int sexo;
    char curp[18]; } Talumns;

int main()
{
    srand(time(NULL));
    int i=0, no, n=2;
    Talumns reg[n];

    no = (rand()%50)+1;
    printf("%d\n", no);
    strcpy(reg[i].nombres.nombre, nombresHombre[no]);

    printf("%s", reg[i].nombres.nombre);
}