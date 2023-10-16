// Hernandez Ceseña Ivan Fernando  373077
// 10/10/23 / 15/10/23
//  1.- AGREGAR REGISTROS (AUTOM 10 REGISTROS)
//  2.- AGREGAR REGISTRO MANUAL
//  3.- ELIMINAR REGISTRO (lógico)
//  4.- BUSCAR USUARIO DE REGISTRO (POR MATRICULA)
//  5.- ORDENAR REGISTROS
//  6.- IMPRIMIR REGISTROS
//  0.- TERMINAR PROGRAMA
// HCIF_ACT10_932

#include "ivan.h"

#define N 500

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

void registroAleatorio(Talumns reg[], int i, int numero);
void imprimirAleatorio(Talumns reg[], int posicion, int n);
void imprimirUnAlumno(Talumns reg[], int posicion);
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
void buscarElemento(Talumns reg[], int posicion, int bandera);
void ordenarAscendente(Talumns reg[], int n);
int busquedaBinaria(Talumns reg[], int izquierda, int derecha);
void imprimirRegistro(Talumns reg[], int posicion);


int main()
{
    srand(time(NULL));
    menu();
}



void msg()
{
    printf("MENU\n");
    printf("1) agregar automaticamente registros.\n");
    printf("2) agregar manualmente.\n");
    printf("3) eliminar registro\n");
    printf("4) buscar.\n");
    printf("5) ordenar\n");
    printf("6) imprimir\n");
    printf("0) terminar programa\n");
}

void menu()
{
    int op;
    int posicion=0, bandera=0;
    Talumns reg[N];
    int numero = 10;
    
    
    do{
        system("cls");
        msg();
        op= validacionNumero("elije una opcion", 0, 6);
        switch(op)
        {
            case 1:
            if((posicion + numero) > N)
            {
                numero = N - posicion;
            }
            registroAleatorio(reg, posicion, numero);
            imprimirAleatorio(reg, posicion, numero);
            printf("llenado de 50 registros exitoso\n");
            posicion= posicion + numero;
            bandera = 0;
            break;

            case 2:
            if(posicion + 1 > N)
            {
                printf("el registro esta lleno\n");
            }
            else
            {
                alumnoManual(reg, posicion);
                imprimirUnAlumno(reg, posicion);
                posicion= posicion+1;
            }
            break;

            case 3:
            eliminarRegistro(reg, posicion);
            break;

            case 4:
            buscarElemento(reg, posicion, bandera);
            break;

            case 5:
            ordenarAscendente(reg, posicion);
            bandera = 1;
            break;

            case 6:
            printf("registro\n");
            imprimirRegistro(reg, posicion);
            break;
        } 
        system("pause");
    }while(op!=0); 
}

void imprimirAleatorio(Talumns reg[], int posicion, int n)
{
    int i;
    printf("%3s %6s %10s %20s %20s %20s %4s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo");
    
    for(i=0; i < (posicion + n); i++)
    {
        printf("%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].nombre, reg[i].edad);
        if(reg[i].sexo == 1)
        {
            printf(" %8s\n", "HOMBRE");
        }
        else
        {
            printf(" %8s\n", "MUJER");
        }
    }
}

void imprimirUnAlumno(Talumns reg[], int posicion)
{
    printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
    printf("%3d %6d %10d %20s %20s %20s", posicion+1, reg[posicion].status, reg[posicion].matricula, reg[posicion].apellidoPaterno, reg[posicion].apellidoMaterno, reg[posicion].nombre);
    if(reg[posicion].sexo == 1)
    {
        printf(" %8s\n", "HOMBRE");
    }
    else
    {
        printf(" %8s\n", "MUJER");
    }
}

void registroAleatorio(Talumns reg[], int posicion, int n)
{
    int li, ls, i;

    for(i=posicion; i < (posicion + n); i++)
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
    estado= 1;
    reg[posicion].status = estado;
}

void matricula(Talumns reg[], int li, int ls, int posicion)
{
    int mat, rango= (ls-li) +1;
    int existe;
    do{
        mat = rand()% rango + li;
        existe = existeValor(reg, posicion, mat);
    }while(existe != -1);
    reg[posicion].matricula = mat;
}

void apellidoPaterno(Talumns reg[], int posicion)
{
    int numero;
    char apellidos[100][20] = {
    "GONZALEZ", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "PEREZ",
    "GOMEZ", "SANCHEZ", "FERNANDEZ", "RAMIREZ", "TORRES",
    "DIAZ", "HERNANDEZ", "VARGAS", "MORALES", "CASTILLO",
    "ORTEGA", "MENDOZA", "CRUZ", "RUIZ", "FLORES",
    "RIVERA", "GUTIERREZ", "RIOS", "NAVARRO", "SALAZAR",
    "ACOSTA", "SILVA", "MORA", "GUERRERO", "CAMPOS",
    "DELGADO", "VEGA", "GUERRA", "AGUILAR", "SUAREZ",
    "ROJAS", "SALAS", "PAREDES", "CABRERA", "PONCE",
    "VALENZUELA", "MIRANDA", "LARA", "SOLIS", "VILLANUEVA",
    "LUNA", "FIGUEROA", "MUNOZ", "BARRIOS", "JIMENEZ",
    "BUSTOS", "NUNEZ", "ZUNIGA", "LEAL", "CHAVEZ",
    "MEDINA", "PARRA", "BAEZ", "NAVARRETE", "AVILA",
    "VELASQUEZ", "FUENTES", "SOTO", "CONTRERAS", "CACERES",
    "VENEGAS", "RIQUELME", "ARAYA", "TOLEDO", "SEPULVEDA",
    "REYES", "ANDRADE", "VILLEGAS", "CASTRO", "DURAN",
    "ESPINOSA", "ARANEDA", "LAGOS", "POBLETE", "BECERRA",
    "MARTIN", "ROMERO", "FERNANDO", "TORRES", "GUTIERREZ",
    "ALVAREZ", "PEREIRA", "RUIZ", "VIDAL", "MORON",
    "CHACON", "SOTO", "BARRETO", "CAMACHO", "LIRA",
    "CACERES", "PALMA", "SILVESTRE", "MIERES", "GARRIDO"
    };

    numero = (rand()%99) +1;
    strcpy(reg[posicion].apellidoPaterno, apellidos[numero]);
}

void apellidoMaterno(Talumns reg[], int posicion)
{
    int numero;
    char apellidos[100][20] = {
    "GONZALEZ", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "PEREZ",
    "GOMEZ", "SANCHEZ", "FERNANDEZ", "RAMIREZ", "TORRES",
    "DIAZ", "HERNANDEZ", "VARGAS", "MORALES", "CASTILLO",
    "ORTEGA", "MENDOZA", "CRUZ", "RUIZ", "FLORES",
    "RIVERA", "GUTIERREZ", "RIOS", "NAVARRO", "SALAZAR",
    "ACOSTA", "SILVA", "MORA", "GUERRERO", "CAMPOS",
    "DELGADO", "VEGA", "GUERRA", "AGUILAR", "SUAREZ",
    "ROJAS", "SALAS", "PAREDES", "CABRERA", "PONCE",
    "VALENZUELA", "MIRANDA", "LARA", "SOLIS", "VILLANUEVA",
    "LUNA", "FIGUEROA", "MUNOZ", "BARRIOS", "JIMENEZ",
    "BUSTOS", "NUNEZ", "ZUNIGA", "LEAL", "CHAVEZ",
    "MEDINA", "PARRA", "BAEZ", "NAVARRETE", "AVILA",
    "VELASQUEZ", "FUENTES", "SOTO", "CONTRERAS", "CACERES",
    "VENEGAS", "RIQUELME", "ARAYA", "TOLEDO", "SEPULVEDA",
    "REYES", "ANDRADE", "VILLEGAS", "CASTRO", "DURAN",
    "ESPINOSA", "ARANEDA", "LAGOS", "POBLETE", "BECERRA",
    "MARTIN", "ROMERO", "FERNANDO", "TORRES", "GUTIERREZ",
    "ALVAREZ", "PEREIRA", "RUIZ", "VIDAL", "MORON",
    "CHACON", "SOTO", "BARRETO", "CAMACHO", "LIRA",
    "CACERES", "PALMA", "SILVESTRE", "MIERES", "GARRIDO"
    };

    numero = (rand()%99) +1;
    strcpy(reg[posicion].apellidoMaterno, apellidos[numero]);
}

void nombre(Talumns reg[], int posicion)
{
    int numero;
    char nombresHombre[50][20] = {
    "JUAN", "CARLOS", "MIGUEL", "ANDRES", "LUIS",
    "FERNANDO", "PEDRO", "JAVIER", "DIEGO", "RICARDO",
    "SERGIO", "ALEJANDRO", "HECTOR", "JOSE", "MARTIN",
    "RAUL", "GUSTAVO", "PABLO", "ROBERTO", "ANTONIO",
    "MANUEL", "ANGEL", "JORGE", "FELIX", "LUCAS",
    "PASCUAL", "BENJAMIN", "ALVARO", "ARTURO", "ADRIAN",
    "CESAR", "ENRIQUE", "FELIPE", "GERARDO", "IVAN",
    "NESTOR", "OLIVER", "PACO", "QUIRINO", "SAMUEL",
    "TOMAS", "ULISES", "VICENTE", "WILLIAM", "XAVIER",
    "YAGO", "ZACARIAS", "ABEL", "BARTOLOME", "MARCO"


    };
    char nombresMujer[50][20] = {
    "MARIA", "LAURA", "ANA", "CARMEN", "LUISA",
    "ISABEL", "RAQUEL", "SOFIA", "ELENA", "LETICIA",
    "MARTA", "MONICA", "BEATRIZ", "SILVIA", "INES",
    "SUSANA", "ROSA", "NATALIA", "OLGA", "TERESA",
    "IRENE", "PATRICIA", "PAULA", "ANDREA", "NADIA",
    "VANESSA", "SARA", "MIRIAM", "GLORIA", "VICTORIA",
    "ESTHER", "YOLANDA", "CLARA", "JUANA", "JULIA",
    "BELEN", "MARGARITA", "ADELA", "MANUELA", "CAROLINA",
    "ELVIRA", "MARINA", "ROSARIO", "DIANA", "LORENA",
    "CONSUELO", "ANGELA", "INMACULADA", "FELICIDAD", "CECILIA"
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

void buscarElemento(Talumns reg[], int posicion, int bandera)
{
    int mat, buscar;
    // mat = validacionNumero("que matricula buscas?", 300000, 399999);
    // buscar = existeValor(reg, posicion, mat);

    if(bandera == 0)
    {
        printf("busqueda secuencial\n");
        mat = validacionNumero("que matricula buscas?", 300000, 399999);
        buscar = existeValor(reg, posicion, mat);
    }
    else
    {
        printf("busqueda binaria\n");
        buscar = busquedaBinaria(reg, 0, posicion - 1);
    }

    if(buscar != -1)
    {
        imprimirUnAlumno(reg, buscar);
    }
}

void imprimirRegistro(Talumns reg[], int posicion)
{
    int i;
    printf("%3s %6s %10s %20s %20s %20s %4s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo");
    for(i=0; i<posicion; i++)
    {
        if(reg[i].status == 1)
        {
            printf("%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].nombre, reg[i].edad);
            if(reg[i].sexo == 1)
            {
                printf(" %8s\n", "HOMBRE");
            }
            else
            {
                printf(" %8s\n", "MUJER");
            }
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

int busquedaBinaria(Talumns reg[], int izquierda, int derecha)
{
    int mat;
    mat = validacionNumero("que matricula buscas?", 300000, 399999);
    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (reg[medio].matricula == mat)
        {
            return medio;
        }

        if (reg[medio].matricula < mat)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }

    return -1;
}
