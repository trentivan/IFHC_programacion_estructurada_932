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

void registroAleatorio(Talumns reg[], int i);
void imprimirAleatorio(Talumns reg[], int posicion);
void sexo(Talumns reg[], int i, int li, int ls);
void status(Talumns reg[], int i);
void matricula(Talumns reg[], int li, int ls, int i);
void apellidoPaterno(Talumns reg[], int i);
void apellidoMaterno(Talumns reg[], int i);
void nombre(Talumns reg[], int i);
void edad(Talumns reg[], int i, int li, int ls);
void alumnoManual(Talumns reg[], int i);
int existeValor(Talumns reg[], int n, int numero);
void eliminarRegistro(Talumns reg[], int posicion);
void buscarElemento(Talumns reg[], int posicion);
void ordenarAscendente(Talumns reg[], int n);

void imprimirRegistro(Talumns reg[], int posicion);


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
    int n=500, posicion=0;
    Talumns reg[n];
    
    //  ciclo do while que controla el caso a ejecutar con ayuda de [op]
    do{
        // system("cls");
        msg();
        op= validacionNumero("elije una opcion", 0, 6);
        switch(op)
        {
            case 1:
            if((posicion + 50) > n)
            {
                printf("el registro esta lleno. No permite llenar 10 espacios\n");
            }
            else
            {
                registroAleatorio(reg, posicion);
                imprimirAleatorio(reg, posicion);
                printf("llenado de 50 registros exitoso\n");
                posicion= posicion+50;
            }
            break;

            case 2:
            if(posicion + 1 > n)
            {
                printf("el registro esta lleno\n");
            }
            else
            {
                alumnoManual(reg, posicion);
                printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
                printf("%3d %6d %10d %20s %20s %20s", posicion+1, reg[posicion].status, reg[posicion].matricula, reg[posicion].apellidoPaterno, reg[posicion].apellidoMaterno, reg[posicion].nombre);
                if(reg[posicion].sexo == 1)
                {
                    printf(" %8s\n", "Hombre");
                    posicion= posicion+1;
                }
                else
                {
                    printf(" %8s\n", "Mujer");
                    posicion= posicion+1;
                }
            }
            break;

            case 3:
            eliminarRegistro(reg, posicion);
            break;

            case 4:
            buscarElemento(reg, posicion);
            break;

            case 5:
            ordenarAscendente(reg, posicion);
            
            break;

            case 6:
            printf("registro\n");
            imprimirRegistro(reg, posicion);
            break;
        } 
        // system("pause");
    }while(op!=0);  //  condicion  que evalua si op [0] termina el programa
}

void imprimirAleatorio(Talumns reg[], int posicion)
{
    int i;
    printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
    for(i=posicion; i < posicion + 50; i++)
    {
        printf("%3d %6d %10d %20s %20s %20s", i+1, reg[i].status, reg[i].matricula, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].nombre);
        if(reg[i].sexo == 1)
        {
            printf(" %8s\n", "Hombre");
        }
        else
        {
            printf(" %8s\n", "Mujer");
        }
    }
}

void imprimirAlumno(Talumns reg[], int posicion)
{
    int i;
    for(i=0; i < posicion; i++)
    {
        printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
        printf("%3d %6d %10d %20s %20s %20s", i+1, reg[i].status, reg[i].matricula, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].nombre);
        if(reg[i].sexo == 1)
        {
            printf(" %8s\n", "Hombre");
            // posicion= posicion+1;
        }
        else
        {
            printf(" %8s\n", "Mujer");
            // posicion= posicion+1;
        }
    }
}

void imprimirUnAlumno(Talumns reg[], int posicion)
{
    printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
    printf("%3d %6d %10d %20s %20s %20s", posicion+1, reg[posicion].status, reg[posicion].matricula, reg[posicion].apellidoPaterno, reg[posicion].apellidoMaterno, reg[posicion].nombre);
    if(reg[posicion].sexo == 1)
    {
        printf(" %8s\n", "Hombre");
        // posicion= posicion+1;
    }
    else
    {
        printf(" %8s\n", "Mujer");
        // posicion= posicion+1;
    }
}

void registroAleatorio(Talumns reg[], int posicion)
{
    int li, ls, i;

    for(i=posicion; i < posicion +50; i++)
    {
        li=1, ls=2;
        sexo(reg, i, li, ls);
        status(reg, i);
        li=300000;
        ls=399999;
        matricula(reg, li, ls, i);
        li= 1, ls= 50;
        apellidoPaterno(reg, i);
        apellidoMaterno(reg, i);
        nombre(reg, i);
        li=17, ls=50;
        edad(reg, i, li, ls);
    }
}

void sexo(Talumns reg[], int posicion, int li, int ls)
{
    int sexo;
    sexo= (rand()%ls) +li;
    reg[posicion].sexo = sexo;
}

void status(Talumns reg[], int posicion)
{
    int estado;
    estado= ((rand()%2) +1)-1;
    reg[posicion].status = estado;
}

void matricula(Talumns reg[], int li, int ls, int posicion)
{
    int matricula, rango= (ls-li) +1;;
    matricula=rand()% rango + li;
    reg[posicion].matricula = matricula;
}

void apellidoPaterno(Talumns reg[], int posicion)
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
    strcpy(reg[posicion].apellidoPaterno, apellidos[numero]);
}

void apellidoMaterno(Talumns reg[], int posicion)
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
    strcpy(reg[posicion].apellidoMaterno, apellidos[numero]);
}

void nombre(Talumns reg[], int posicion)
{
    int numero;
    char nombresHombre[50][20] = {
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
    char nombresMujer[50][20] = {
    "Maria", "Laura", "Ana", "Carmen", "Luisa",
    "Isabel", "Raquel", "Sofia", "Elena", "Leticia",
    "Marta", "Monica", "Beatriz", "Silvia", "Ines",
    "Susana", "Rosa", "Natalia", "Olga", "Teresa",
    "Irene", "Patricia", "Paula", "Andrea", "Nadia",
    "Vanessa", "Sara", "Miriam", "Gloria", "Victoria",
    "Esther", "Yolanda", "Clara", "Juana", "Julia",
    "Belen", "Margarita", "Adela", "Manuela", "Carolina",
    "Elvira", "Marina", "Rosario", "Diana", "Lorena",
    "Consuelo", "Angela", "Inmaculada", "Felicidad", "Cecilia"
    };

    if(reg[posicion].sexo == 1)
    {
        numero = (rand()%49) +1;
        strcpy(reg[posicion].nombre, nombresHombre[numero]);
    }
    else
    {
        numero = (rand()%49) +1;
        strcpy(reg[posicion].nombre, nombresMujer[numero]);
    }
    
}

void edad(Talumns reg[], int posicion, int li, int ls)
{
    int rango= (ls-li)+1;
    reg[posicion].edad = (rand()%rango)+li;
}

void alumnoManual(Talumns reg[], int posicion)
{
    int existe;
    char paterno[20];
    char materno[20];
    char nombre[20];

    reg[posicion].status= 1;
    do{
    reg[posicion].matricula = validacionNumero("dame tu matricula", 300000, 399999);
    existe = existeValor(reg, posicion, reg[posicion].matricula);
    if(existe != -1)
    {
        printf("la matricula ya existe.\npor favor introduce otra\n");
    }
    }while(existe != -1);

    validacionTexto("dame tu apellido paterno", paterno, 20);
    strcpy(reg[posicion].apellidoPaterno, paterno);

    validacionTexto("dame tu apellido paterno", materno, 20);
    strcpy(reg[posicion].apellidoMaterno, materno);

    validacionTexto("dame tu nombre", nombre, 20);
    strcpy(reg[posicion].nombre, nombre);

    reg[posicion].edad = validacionNumero("dame tu edad", 17, 50);
    reg[posicion].sexo = validacionNumero("dame tu sexo (1- hombre. 2- mujer)", 1, 2);
}

int existeValor(Talumns reg[], int n, int numero)
{
    int i; 
    for(i = 0; i < n ; i++)    
    {
        if(reg[i].matricula == numero)
        {
            return i;
        }
    }
    return -1;
}

void eliminarRegistro(Talumns reg[], int posicion)
{
    int eliminar, mat;
    mat = validacionNumero("dame la matricula que quieres eliminar", 300000, 399999);
    eliminar= existeValor(reg, posicion, mat);
    if(eliminar != -1)
    {
        if(reg[eliminar].status == 1)
        {
            reg[eliminar].status = 0;
            printf("estudiante dado de baja\n");
        }
        else
        {
            printf("la matricula ya estaba dada de baja\n");
        }
    }
    else
    {
        printf("esta matricula no esta en el registro\n");
    }
}

void buscarElemento(Talumns reg[], int posicion)
{
    int mat, buscar;
    mat = validacionNumero("que matricula buscas?", 300000, 399999);
    buscar = existeValor(reg, posicion, mat);
    if(buscar != -1)
    {
        imprimirUnAlumno(reg, buscar);
    }
}

void imprimirRegistro(Talumns reg[], int posicion)
{
    int i;
    printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
    for(i=0; i<posicion; i++)
    {
        printf("%3d %6d %10d %20s %20s %20s", i+1, reg[i].status, reg[i].matricula, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].nombre);
        if(reg[i].sexo == 1)
        {
            printf(" %8s\n", "Hombre");
        }
        else
        {
            printf(" %8s\n", "Mujer");
        }
    }
}

void ordenarAscendente(Talumns reg[], int n)
{
    int i, j;    
    Talumns aux;
    for(i=0; i<n; i++)  
    {
        for(j=i+1; j<n; j++)   
        {
            if(reg[j].matricula <reg[i].matricula)   
            {
                aux = reg[i];         
                reg[i] = reg[j];
                reg[j] = aux;
            }
        }
    }
}