#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _alumno {
    int status;
    int matricula;
    char apellidoPaterno[30];
    char apellidoMaterno[30];
    char nombre[30];
    int edad;
    int sexo;
} Talumno;

// int busquedaSecuencial(Talumno reg[], int n, int numero) {
//     for (int i = 0; i < n; i++) {
//         if (reg[i].nombre == numero) {
//             return i;
//         }
//     }
//     return -1;
// }

void nombres(Talumno reg[], int n) 
{
    int nom;
    char nombre[10];
    char nombreMujer[10][10] = {
        "ANA",
        "JULIETA",
        "JOSEFINA",
        "DANIELA",
        "CARMEN",
        "SOFIA",
        "LAURA",
        "ANDREA",
        "ELENA",
        "ISABEL"
    };

    for (int i = 0; i < n; i++) 
    {
        nom = rand() % 10;
        strcpy(nombre, nombreMujer[nom]);
        strcpy(reg[i].nombre, nombre);
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", reg[i].nombre);
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    Talumno reg[n];
    nombres(reg, n);
    return 0;
}
