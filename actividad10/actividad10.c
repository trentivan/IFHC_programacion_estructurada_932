// Hernandez Ceseña Ivan Fernando  373077
// 10/10/23
// 
// 
// 
// NYP_ACT10_932


#include <stdio.h>
#include <time.h>
#include "ivan.h"

typedef struct _alumnos{
    int status;
    int matricula;
    char apellidoPaterno[30];
    char apellidoMaterno[30];
    char nombre[30];
    int edad;
    int sexo; } Talumns;


void menu(void);
void msg(void);

void registro(Talumns reg[], int i);
void sexo(Talumns reg[], int i, int li, int ls);
void status(Talumns reg[], int i);
void matricula(Talumns reg[], int li, int ls, int i);
void apellidoPaterno(Talumns reg[], int i);
void apellidoMaterno(Talumns reg[], int i);
void nombre(Talumns reg[], int i);
void edad(Talumns reg[], int i, int li, int ls);
void llenarManual(Talumns reg[], int i);
// void nombres(Talumns reg[], int i);

int main()
{
    srand(time(NULL));
    menu();
}



void msg()  //  aqui se muestran todas las opciones 
{
    // system("cls");
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
    int op;
    int n=50, i=0;
    Talumns reg[n];
    
    //  ciclo do while que controla el caso a ejecutar con ayuda de [op]
    do{
        msg();
        op= validacionNumero("elije una opcion", 0, 6);
        switch(op)
        {
            case 1:
            if((i + 10) > n)
            {
                printf("el registro esta lleno. No permite llenar 10 espacios\n");
            }
            else
            {
                printf("llenado de 10 registros exitoso\n");
                registro(reg, i);
                i= i +10;
            }
            break;

            case 2:
            llenarManual(reg, i);
            printf("%3s %6s %6s %10s %20s %20s %30s\n", "No.", "sexo", "status", "matricula", "apellido paterno", "apellido materno", "nombre");

            break;

            case 3:

            break;

            case 4:
            
            break;

            case 5:
            
            
            break;

            case 6:
            
            break;

        } 
    }while(op!=0);  //  condicion  que evalua si op [0] termina el programa
}

void registro(Talumns reg[], int i)
{
    system("cls");
    // int i, li, ls;
    int li, ls, n=10;
    // Talumnos reg[n];
    printf("%3s %6s %6s %10s %20s %20s %30s %4s\n", "No.", "sexo", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad");
    for(i=0; i<n; i++)
    {
        // nombres(reg, i);
        li=1, ls=2;
        printf("%3d", i+1);
        sexo(reg, i, li, ls);
        printf("%6d", reg[i].sexo);
        status(reg, i);
        printf(" %6d", reg[i].status);
        li=300000;
        ls=399999;
        matricula(reg, li, ls, i);
        printf(" %10d", reg[i].matricula);
        li= 1, ls= 50;
        apellidoPaterno(reg, i);
        printf(" %20s", reg[i].apellidoPaterno);
        apellidoMaterno(reg, i);
        printf(" %20s", reg[i].apellidoMaterno);
        nombre(reg, i);
        printf(" %30s", reg[i].nombre);
        li=17, ls=50;
        edad(reg, i, li, ls);
        printf("%4d", reg[i].edad);
        
        printf("\n");
    }
    system("pause");
}

void sexo(Talumns reg[], int i, int li, int ls)
{
    int sexo;
    sexo= (rand()%ls) +li;
    reg[i].sexo = sexo;
}

void status(Talumns reg[], int i)
{
    int estado;
    estado= ((rand()%2) +1)-1;
    reg[i].status = estado;
}

void matricula(Talumns reg[], int li, int ls, int i)
{
    int matricula, rango= (ls-li) +1;;
    matricula=rand()% rango + li;
    reg[i].matricula = matricula;
}

void apellidoPaterno(Talumns reg[], int i)
{
    int numero;
    char apellidos[100][20] = {
    "Gonzalez", "Rodriguez", "Lopez", "Martinez", "Perez",
    "Gomez", "Sanchez", "Fernandez", "Ramirez", "Torres",
    "Diaz", "Hernandez", "Vargas", "Morales", "Castillo",
    "Ortega", "Mendoza", "Cruz", "Ruiz", "Flores",
    "Rivera", "Gutierrez", "Rios", "Navarro", "Salazar",
    "Acosta", "Silva", "Mora", "Guerrero", "Campos",
    "Delgado", "Vega", "Guerra", "Aguilar", "Suarez",
    "Rojas", "Salas", "Paredes", "Cabrera", "Ponce",
    "Valenzuela", "Miranda", "Lara", "Solis", "Villanueva",
    "Luna", "Figueroa", "Munoz", "Barrios", "Jimenez",
    "Bustos", "Nunez", "Zuniga", "Leal", "Chavez",
    "Medina", "Parra", "Baez", "Navarrete", "Avila",
    "Velasquez", "Fuentes", "Soto", "Contreras", "Caceres",
    "Venegas", "Riquelme", "Araya", "Toledo", "Sepulveda",
    "Reyes", "Andrade", "Villegas", "Castro", "Duran",
    "Espinoza", "Araneda", "Lagos", "Poblete", "Becerra",
    "Martin", "Romero", "Fernando", "Torres", "Gutierrez",
    "Alvarez", "Pereira", "Ruiz", "Vidal", "Moron",
    "Chacon", "Soto", "Barreto", "Camacho", "Lira",
    "Caceres", "Palma", "Silvestre", "Mieres", "Garrido"
    };

    numero = (rand()%99) +1;
    strcpy(reg[i].apellidoPaterno, apellidos[numero]);
}

void apellidoMaterno(Talumns reg[], int i)
{
    int numero;
    char apellidos[100][20] = {
    "Gonzalez", "Rodriguez", "Lopez", "Martinez", "Perez",
    "Gomez", "Sanchez", "Fernandez", "Ramirez", "Torres",
    "Diaz", "Hernandez", "Vargas", "Morales", "Castillo",
    "Ortega", "Mendoza", "Cruz", "Ruiz", "Flores",
    "Rivera", "Gutierrez", "Rios", "Navarro", "Salazar",
    "Acosta", "Silva", "Mora", "Guerrero", "Campos",
    "Delgado", "Vega", "Guerra", "Aguilar", "Suarez",
    "Rojas", "Salas", "Paredes", "Cabrera", "Ponce",
    "Valenzuela", "Miranda", "Lara", "Solis", "Villanueva",
    "Luna", "Figueroa", "Munoz", "Barrios", "Jimenez",
    "Bustos", "Nunez", "Zuniga", "Leal", "Chavez",
    "Medina", "Parra", "Baez", "Navarrete", "Avila",
    "Velasquez", "Fuentes", "Soto", "Contreras", "Caceres",
    "Venegas", "Riquelme", "Araya", "Toledo", "Sepulveda",
    "Reyes", "Andrade", "Villegas", "Castro", "Duran",
    "Espinoza", "Araneda", "Lagos", "Poblete", "Becerra",
    "Martin", "Romero", "Fernando", "Torres", "Gutierrez",
    "Alvarez", "Pereira", "Ruiz", "Vidal", "Moron",
    "Chacon", "Soto", "Barreto", "Camacho", "Lira",
    "Caceres", "Palma", "Silvestre", "Mieres", "Garrido"
    };

    numero = (rand()%99) +1;
    strcpy(reg[i].apellidoMaterno, apellidos[numero]);
}

void nombre(Talumns reg[], int i)
{
    int numero;
    char nombres[50][20] = {
    "Juan", "Carlos", "Miguel", "Andres", "Luis",
    "Fernando", "Pedro", "Javier", "Diego", "Ricardo",
    "Sergio", "Alejandro", "Hector", "Jose", "Martin",
    "Raul", "Gustavo", "Pablo", "Roberto", "Antonio",
    "Manuel", "Angel", "Jorge", "Felix", "Lucas",
    "Pascual", "Benjamin", "Alvaro", "Arturo", "Adrian",
    "Cesar", "Enrique", "Felipe", "Gerardo", "Ivan",
    "Nestor", "Oliver", "Paco", "Quirino", "Samuel",
    "Tomas", "Ulises", "Vicente", "William", "Xavier",
    "Yago", "Zacarias", "Abel", "Bartolome", "Marco"
    };

    numero = (rand()%49) +1;
    strcpy(reg[i].nombre, nombres[numero]);
}

void edad(Talumns reg[], int i, int li, int ls)
{
    int rango= (ls-li)+1;
    reg[i].edad = (rand()%rango)+li;
}

void llenarManual(Talumns reg[], int i)
{
    char paterno[20];
    char materno[20];
    reg[i].status= ((rand()%2)+1)-1;
    reg[i].matricula = validacionNumero("dame tu matricula", 300000, 399999);
    validacionTexto("dame tu apellido paterno", paterno, 20);
    strcpy(reg[i].apellidoPaterno, paterno);
    validacionTexto("dame tu apellido paterno", materno, 20);
    strcpy(reg[i].apellidoMaterno, materno);
}
