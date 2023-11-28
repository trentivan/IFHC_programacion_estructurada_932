// Hernandez Ceseña Ivan Fernando  373077
// 26/11/23
// 1.- AGREGAR
// 2.- ELIMINAR 
// 3.- BUSCAR 
// 4.- ORDENAR
// 5.- IMPRIMIR REGISTROS ARCHIVO ORIGINAL 
// 6.- IMPRIMIR REGISTROS ARCHIVO ORDENADO 
// 7.- GENERAR ARCHIVO TEXTO 
// 8.- EMPAQUETAR 
// 0.- SALIR
// HCIF_ACT14_932


#include "ivan.h"

typedef int Tkey;

typedef struct _work{
    int status;
    Tkey key;
    char nombre[30];
    char apPat[50];
    char apMat[50];
    char sexo[15];
    char puesto[30];
    char estado[30];
    int edad;
    Tkey celuar;
} Twrkr;

typedef struct index{
    Tkey llave;
    int  consecutivo;
} Tindex;

void menu(int n);
int cargar(Twrkr reg[], Tindex reg2[], int i);
void agregar(Twrkr reg[], Tindex reg2[], int posicion, int n);
void eliminar(Twrkr reg[], Tindex reg2[], int posicion, int ordenar);

void imprimir(Twrkr reg[], int posicion);
void imprimir1(Twrkr reg[], int posicion);
void imprimirReg2(Tindex reg[], int posicion);
void imprimirReg2_1(Tindex reg[], int posicion);

void sexo(Twrkr reg[], int i, int li, int ls);
void status(Twrkr reg[], int i);
void matricula(Twrkr reg[], Tindex reg2[], int li, int ls, int posicion);
void apellidoPaterno(Twrkr reg[], int i);
void apellidoMaterno(Twrkr reg[], int i);
void nombre(Twrkr reg[], int i);
void edad(Twrkr reg[], int i, int li, int ls);
void state(Twrkr reg[], int posicion, int li, int ls);
void jobPossition(Twrkr reg[], int posicion, int li, int ls);
int existeValor(Twrkr reg[], int n, int numero);
int existeValor2(Tindex reg2[], int n, int numero);
int busquedaBinaria(Tindex reg2[], int izquierda, int derecha);


int main()
{
    int contador =0; ///////
    char archivo[30]= "datos";
    char parametros[30];

    system("gcc.exe archivoExterno.c -o archivoExterno");
    sprintf(parametros, "archivoExterno.exe %s", archivo);
    contador = system(parametros);
    contador = contador * 1.25;
    menu(contador);
    return 0;
}

void msg()
{
    printf("MENU\n");
    printf("1) agregar\n");
    printf("2) eliminar\n");
    printf("3) buscar\n");
    printf("4) ordenar\n");
    printf("5) imprimir registro archivo original\n");
    printf("6) imprimir registro archivo original\n");
    printf("7) generar archivo de texto\n");
    printf("8) empaquetar\n");
    printf("9) salir\n");
}

void menu(int n)
{
    printf("%d\n", n);
    Twrkr reg[n];
    Tindex reg2[n];
    int posicion = 0;
    int op;
    int inc = 100;
    int ordenar = 0;

    posicion = cargar(reg, reg2, posicion);
    // imprimir(reg, posicion);
    imprimirReg2(reg2, posicion);

    do
    {
        msg();
        op = validacionNumero("elije una opcion", 1, 9);

        switch(op)
        {
            case 1:
            if(posicion + inc > n)
            {
                inc = n - posicion;
            }
            if(inc == 0)
            {
                printf("registro lleno\n");
            }
            else
            {
                agregar(reg, reg2, posicion, inc);
                // imprimir1(reg, posicion);
                imprimirReg2_1(reg2, posicion);
                posicion = posicion + inc;
            }
            break;

            case 2:
            eliminar(reg, reg2, posicion, ordenar);
            break;
        } 
    } while (op != 9);
}

int cargar(Twrkr reg[], Tindex reg2[], int i)
{
    FILE *archivo = fopen("datos.dat", "rb");
    Twrkr registro;

    if(archivo)
    {
        // Twrkr registro;
        while(fread(&registro, sizeof(Twrkr), 1, archivo))
        {
            reg[i] = registro;
            reg2[i].consecutivo = i;
            reg2[i].llave = registro.key;
            i++;
        }
    }
    else
    {
        printf("error al abrir el archivo\n");
    }
    fclose(archivo);
    return i;
}

void imprimir(Twrkr reg[], int posicion)
{
    int i;

    for(i = 0; i < posicion; i++)
    {
        printf("%6d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", 
        i, reg[i].status, reg[i].key, reg[i].nombre, 
        reg[i].apPat, reg[i].apMat, reg[i].sexo, reg[i].puesto, 
        reg[i].estado, reg[i].edad);
    }
}

void imprimir1(Twrkr reg[], int posicion)
{
    int i;

    for(i = posicion; i < posicion + 100 ; i++)
    {
        printf("%6d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", 
        i, reg[i].status, reg[i].key, reg[i].nombre, 
        reg[i].apPat, reg[i].apMat, reg[i].sexo, reg[i].puesto, 
        reg[i].estado, reg[i].edad);
    }
}

void imprimirReg2_1(Tindex reg[], int posicion)
{
    int i;

    for(i=posicion; i < (posicion + 100); i++)
    {
        printf("%6d %10d\n", reg[i].consecutivo, reg[i].llave);
    }
}

void imprimirReg2(Tindex reg[], int posicion)
{
    int i;

    for(i=0; i < posicion; i++)
    {
        printf("%6d %10d\n", reg[i].consecutivo, reg[i].llave);
    }
}

void eliminar(Twrkr reg[], Tindex reg2[], int posicion, int ordenar)
{
    int encontrado, elim;
    if(ordenar == 1)
    {
        encontrado = busquedaBinaria(reg2, 0, posicion-1);

        if(encontrado != -1)
        {
            FILE *fa = fopen("datos.dat", "r+");

            if(fa)
            {
                if(fseek(fa, (encontrado-1) * sizeof(Twrkr), SEEK_SET) == 0)
                {
                    printf("%2d %8d %20s %20s %20s %15s %20s %20s %4d\n", 
                    reg[encontrado].status, reg[encontrado].key, reg[encontrado].nombre, 
                    reg[encontrado].apPat, reg[encontrado].apMat, reg[encontrado].sexo, reg[encontrado].puesto, 
                    reg[encontrado].estado, reg[encontrado].edad);
                    elim = validacionNumero("quieres eliminar el registro?\n1) si.\n2) no.", 1, 2);
                    if(elim == 1)
                    {
                        fseek(fa, (encontrado-1) * sizeof(Twrkr), SEEK_SET);
                        Twrkr registro;
                        fread(&registro, sizeof(Twrkr), 1, fa);
                        registro.status = 0;
                        fseek(fa, (encontrado-1) * sizeof(Twrkr), SEEK_SET);
                        fwrite(&registro, sizeof(Twrkr), 1, fa);
                    }
                }
                else
                {
                    printf("erro al mover el puntero de archivo\n");
                }
            }
            else
            {
                printf("error al abrir el archivo\n");
            }
        }
        else
        {
            printf("la matricula no existe\n");
        }
    }
    else
    {
        int num;
        num = validacionNumero("que matricula buscas\n", 300000, 399999);
        encontrado = existeValor2(reg2, posicion, num);

        if(encontrado != -1)
        {
            FILE *fa = fopen("datos.dat", "r+");

            if(fa)
            {
                if(fseek(fa, (encontrado-1) * sizeof(Twrkr), SEEK_SET) == 0)
                {
                    printf("%2d %8d %20s %20s %20s %15s %20s %20s %4d\n", 
                    reg[encontrado].status, reg[encontrado].key, reg[encontrado].nombre, 
                    reg[encontrado].apPat, reg[encontrado].apMat, reg[encontrado].sexo, reg[encontrado].puesto, 
                    reg[encontrado].estado, reg[encontrado].edad);
                    elim = validacionNumero("quieres eliminar el registro?\n1) si.\n2) no.", 1, 2);
                    if(elim == 1)
                    {
                        fseek(fa, (encontrado-1) * sizeof(Twrkr), SEEK_SET);
                        Twrkr registro;
                        fread(&registro, sizeof(Twrkr), 1, fa);
                        registro.status = 0;
                        fseek(fa, (encontrado-1) * sizeof(Twrkr), SEEK_SET);
                        fwrite(&registro, sizeof(Twrkr), 1, fa);
                    }
                }
                else
                {
                    printf("error al mover el puntero de archivo\n");
                }
            }
            else
            {
                printf("error al abrir el archivo\n");
            }
        }
        else
        {
            printf("la matricula no existe\n");
        }
    }
} 

void agregar(Twrkr reg[], Tindex reg2[], int posicion, int n)
{
    int li, ls, i;

    for(i=posicion; i < (posicion + n); i++)
    {
        li=1, ls=2;
        sexo(reg, i, li, ls);
        status(reg, i);
        li=300000;
        ls=399999;
        matricula(reg, reg2, li, ls, i);
        li= 1, ls= 50;
        apellidoPaterno(reg, i);
        apellidoMaterno(reg, i);
        nombre(reg, i);
        li=17, ls=70;
        edad(reg, i, li, ls);
        ls=33;
        li=1;
        state(reg, i, li, ls);
        ls=30;
        li=1;
        jobPossition(reg, i, li, ls);

        reg2[i].consecutivo = i;

        // printf("%4d %7s %3d %8d %10s %10s %10s %3d %3s %13s\n", i+1, reg[i].sexo, reg[i].status, reg[i].key, reg[i].apPat, reg[i].apMat, reg[i].nombre, reg[i].edad, reg[i].estado, reg[i].puesto);
    }
}

void sexo(Twrkr reg[], int posicion, int li, int ls)
{
    int sex;
    sex= (rand()%ls) +li;
    if(sex == 1)
    {
        strcpy(reg[posicion].sexo, "HOMBRE");
    }
    else
    {
        strcpy(reg[posicion].sexo, "MUJER");
    }
    // printf("%s\n", reg[posicion].sexo);
    // reg[posicion].sexo = sexo;
}

void status(Twrkr reg[], int posicion)
{
    int estado;
    estado= 1;
    reg[posicion].status = estado;
}

void matricula(Twrkr reg[], Tindex reg2[], int li, int ls, int posicion)
{
    int numeroUsuario, rango= (ls-li) +1;
    int existe;
    do{
        numeroUsuario = rand()% rango + li;
        existe = existeValor(reg, posicion, numeroUsuario);
    }while(existe != -1);
    reg[posicion].key = numeroUsuario;
    reg2[posicion].llave = numeroUsuario;

}

void apellidoPaterno(Twrkr reg[], int posicion)
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
    strcpy(reg[posicion].apPat, apellidos[numero]);
}

void apellidoMaterno(Twrkr reg[], int posicion)
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
    strcpy(reg[posicion].apMat, apellidos[numero]);
}

void nombre(Twrkr reg[], int posicion)
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

    if(strcmp(reg[posicion].sexo, "HOMBRE") == 0)
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

void edad(Twrkr reg[], int posicion, int li, int ls)
{
    int rango= (ls-li)+1;
    reg[posicion].edad = (rand()%rango)+li;
}

void state(Twrkr reg[], int posicion, int li, int ls)
{
    int est;
    int rango = (ls-li);

    char iniEstado[][3] = 
    {"AS", "BC", "BS", "CC", "CS", 
    "CH", "CL", "CM", "DG", "GT", 
    "GR", "HG", "JC", "MC", "MN", 
    "MS", "NT", "NL", "OC", "PL", 
    "QT", "QR", "SP", "SL", "SR", 
    "TC", "TS", "TL", "VZ", "YN", 
    "ZS", "DF", "NE"};

    est = (rand()% rango) +1;
    strcpy(reg[posicion].estado, iniEstado[est-1]);
}

void jobPossition(Twrkr reg[], int posicion, int li, int ls)
{
    int job;
    int rango = (ls-li) +1;

    char jobs[][12] = {
        "Medico",
        "Enfermero",
        "Maestro",
        "Chef",
        "Disenador",
        "Tecnico",
        "Carpintero",
        "Electrico",
        "Mecanico",
        "Farmaceutico", 
        "Piloto",
        "Actor",
        "Gerente",
        "Vendedor",
        "Analista",
        "Conductor",
        "Abogado",
        "Jardinero",
        "Artista",
        "Oficial",
        "Chofer",
        "Guardia",
        "Bombero",
        "Cantante",
        "Escritor",
        "Modelo",
        "Barbero",
        "Camarero",
        "Editor",
        "Astronomo"
    };

    job = (rand()% rango) +li;
    strcpy(reg[posicion].puesto, jobs[job-1]);
}

int existeValor(Twrkr reg[], int n, int numero)
{
    int i; 
    for(i = 0; i < n ; i++)    
    {
        if(reg[i].key == numero)
        {
            return i;
        }
    }
    return -1;
}

int existeValor2(Tindex reg2[], int n, int numero)
{
    int i; 
    for(i = 0; i < n ; i++)    
    {
        if(reg2[i].llave == numero)
        {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(Tindex reg2[], int izquierda, int derecha)
{
    int numeroUsuario;
    numeroUsuario = validacionNumero("que matricula buscas?", 300000, 399999);
    
    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (reg2[medio].llave == numeroUsuario)
        {
            printf("%d\n", medio);
            return medio;
        }

        if (reg2[medio].llave < numeroUsuario)
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