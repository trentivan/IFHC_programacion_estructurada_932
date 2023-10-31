#include "ivan.h"
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
    char curp[19]; } Talumns;


int msg(void);


// void alumnoManual(Talumns reg[], int posicion);
int existeValor(Talumns reg[], int n, int numero);
// void eliminarRegistro(Talumns reg[], int posicion);
// void buscarElemento(Talumns reg[], int posicion, int bandera);
// void imprimirRegistro(Talumns reg[], int posicion);
// void ordenarAscendente(Talumns reg[], int n);
// int busquedaBinaria(Talumns reg[], int izquierda, int derecha);
// void generarCurpManual(Talumns reg[], int i, int n);

void generarCurpAleatoria(Talumns reg[], int posicion, int n);

char primerVocal(char cadena[]);
// char segundaConsonante(char cadena[]);
int bisiesto(int anio);
int antisonante(char cadena[], char antisonantes[][5], int numAntisonantes);
void omitirNombres(char nombre[], char partes[][7]);
void omitirPartes(char apellido[], char partes[][6]);

void sexo(Talumns reg[], int posicion, int li, int ls);
void status(Talumns reg[], int posicion);
void matricula(Talumns reg[], int li, int ls, int posicion);
void fapellidoPaterno(Talumns reg[], int posicion);
void fapellidoMaterno(Talumns reg[], int posicion);
void nombre(Talumns reg[], int posicion);
void edad(Talumns reg[], int posicion, int li, int ls);




int main()
{
    srand(time(NULL));
    
    int op, n=10, numero = 5, posicion = 0;
    Talumns reg[n];
    
    do{
        
        op = msg();

        switch(op)
        {
            case 1:
            if((posicion + numero) > n)
            {
                numero = n - posicion;
            }
            generarCurpAleatoria(reg, posicion, numero);
            posicion = posicion + numero;
            break;

        }
    }while(op != 2);

    return 0;
}

void generarCurpAleatoria(Talumns reg[], int posicion, int n)
{
    
    int opcion1;
    int opcion2;
    int dia;
    char Cdia[3];
    int mes;
    char Cmes[3];
    int anio;
    char canio[6];
    char gen;
    char est[3], estado;
    int ultimoDigito;
    char cultimoDigito[1];
    char curp[19];
    int ap, am, no, mat, nomgen, i=0;
    int rango, li, ls;
    rango = (ls - li) +1;
    // for(i = posicion; i < (posicion + n); i++)
    // {
        reg[i].status = 1;
        li = 300000, ls = 399999;
        mat = rand()% rango + li;
        reg[i].matricula = mat;
        // validacionTexto("dame tus nombres (no apellidos)", reg[i].nombres.nombre, sizeof(reg[i].nombres.nombre));
        // nomgen = (rand()%2) +1;
        nomgen = 1;
        if(nomgen == 1)
        {
            no = (rand()%50)+1;
            printf("numero de nombre: %d\n", no);
            strcpy(reg[i].nombres.nombre, nombresHombre[no]);
            printf("%s\n", reg[i].nombres.nombre);
        }

        omitirNombres(reg[i].nombres.nombre, nombresCortos);
        omitirNombres(reg[i].nombres.nombre, nombresCortos);
        omitirPartes(reg[i].nombres.nombre, partes);
        omitirPartes(reg[i].nombres.nombre, partes);
        sinEspacio(reg[i].nombres.nombre);
        printf("%s\n\n", reg[i].nombres.nombre);
            
        // opcion1 = validacionNumero("tienes apellido paterno?\n1- si\n2- no", 1, 2);
        // opcion1 = (rand()%2) +1;
        opcion1 = 1;
        if (opcion1 == 1)
        {
            ap = (rand()%50)+1;
            printf("numero de apellido paterno: %d\n");
            strcpy(reg[i].nombres.apellidoPaterno, apellidos[ap]);
            printf("%s\n", reg[i].nombres.apellidoPaterno);

            omitirPartes(reg[i].nombres.apellidoPaterno, partes);
            omitirPartes(reg[i].nombres.apellidoPaterno, partes);
            sinEspacio(reg[i].nombres.apellidoPaterno);
        }
        printf("%s\n\n", reg[i].nombres.apellidoPaterno);

        // opcion2 = (rand()%2) +1;
        opcion2 = 1;
        if (opcion2 == 1)
        {
            am = (rand()%50)+1;
            printf("numero de apellido materno: %d\n", am);
            strcpy(reg[i].nombres.apellidoMaterno, apellidos[am]);
            printf("%s\n", reg[i].nombres.apellidoMaterno);
            omitirPartes(reg[i].nombres.apellidoMaterno, partes);
            omitirPartes(reg[i].nombres.apellidoMaterno, partes);
            sinEspacio(reg[i].nombres.apellidoMaterno);
        }
        printf("%s\n\n", reg[i].nombres.apellidoMaterno);

        anio = (rand()%(2024 - 1900)) +1900;
        printf("anio entero: %d\n", anio);
        // validacionNumero("escribe tu anio de nacimiento (4 digitos)", 1910, 2023);
        sprintf(canio, "%d", anio);
        printf("anio cadena: %s\n\n", canio);

        mes = (rand()%12) +1;
        printf("mes entero: %d\n", mes);
        sprintf(Cmes, "%d", mes);
        printf("mes cadena: %s\n\n", Cmes);
        

        
        if (mes == 2 && bisiesto(anio) == 1)
        {
            dia = (rand()%29) +1; 
        }
        else
        {
            if (mes == 2 && bisiesto(anio) == 0)
            {
                dia = (rand()%28) +1; 
            }
            else
            {
                if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                {
                    dia = (rand()%31) +1; 
                }
                else
                {
                    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                    {
                        dia = (rand()%30) +1; 
                    }
                }
            }
        }
        printf("dia entero: %d\n", dia);
        sprintf(Cdia, "%d", dia);
        printf("dia cadena: %s\n\n", Cdia);

        gen = nomgen;
        printf("genero numero: %d\n\n", gen); 


        estado = (rand()%33) +1; 
        printf("estado numero: %d\n", estado);
        strcpy(est, iniEstado[estado-1]);
        printf("estado cadena: %s\n\n", est);

        reg[i].edad = 2023 - anio;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        

        if (opcion1 == 1)
        {
            reg[i].curp[0] = toupper(reg[i].nombres.apellidoPaterno[0]);
            reg[i].curp[1] = primerVocal(reg[i].nombres.apellidoPaterno);
        }
        else
        {
            if (opcion1 == 2)
            {
                reg[i].curp[0] = 'X';
                reg[i].curp[1] = 'X';
            }
        }
        printf("[0] %c\n", reg[i].curp[0]);
        printf("[1] %c\n", reg[i].curp[1]);

        if (opcion2 == 1)
        {
            reg[i].curp[2] = toupper(reg[i].nombres.apellidoMaterno[0]);
        }
        else
        {
            if (opcion2 == 2)
            {
                reg[i].curp[2] = 'X';
            }
        }
        printf("[2] %c\n", reg[i].curp[2]);

        reg[i].curp[3] = reg[i].nombres.nombre[0];
        printf("[3] %c\n", reg[i].curp[3]);
        reg[i].curp[4] = canio[2];
        printf("[4] %c\n", reg[i].curp[4]);
        reg[i].curp[5] = canio[3];
        printf("[5] %c\n", reg[i].curp[5]);
        if (mes < 10)
        {
            reg[i].curp[6] = '0';
            reg[i].curp[7] = Cmes[0];
        }
        else
        {
            reg[i].curp[6] = Cmes[0];
            reg[i].curp[7] = Cmes[1];
        }
        printf("[6] %c\n", reg[i].curp[6]);
        printf("[7] %c\n", reg[i].curp[7]);

        if (dia < 10)
        {
            // printf("\n1) %s\n", Cdia);
            // printf("\n1) %d\n", dia);
            reg[i].curp[8] = '0';
            reg[i].curp[9] = Cdia[0];
        }
        else
        {
            // printf("\n2) %s\n", Cdia);
            // printf("\n2) %d\n", dia);
            reg[i].curp[8] = Cdia[0];
            reg[i].curp[9] = Cdia[1];
        }
        printf("[8] %c\n", reg[i].curp[8]);
        printf("[9] %c\n", reg[i].curp[9]);

        if(gen == 1)
        {
            reg[i].curp[10] = 'H';
        }
        else
        {
            reg[i].curp[10] = 'H';
        }
        printf("[10] %c\n", reg[i].curp[10]);

        reg[i].curp[11] = est[0];
        printf("[11] %c\n", reg[i].curp[11]);
        reg[i].curp[12] = est[1];
        printf("[12] %c\n", reg[i].curp[12]);

        if (!segundaConsonante(reg[i].nombres.apellidoPaterno) || opcion1 == 2)
        {
            reg[i].curp[13] = 'X';
        }
        else
        {
            reg[i].curp[13] = segundaConsonante(reg[i].nombres.apellidoPaterno);
        }
        printf("[13] %c\n", reg[i].curp[13]);

        if (!segundaConsonante(reg[i].nombres.apellidoMaterno) || opcion2 == 2)
        {
            reg[i].curp[14] = 'X';
        }
        else
        {
            reg[i].curp[14] = segundaConsonante(reg[i].nombres.apellidoMaterno);
        }
        printf("[14] %c\n", reg[i].curp[14]);

        if (!segundaConsonante(reg[i].nombres.nombre))
        {
            reg[i].curp[15] = 'X';
        }
        else
        {
            reg[i].curp[15] = segundaConsonante(reg[i].nombres.nombre);
        }
        printf("[15] %c\n", reg[i].curp[15]);

        if (anio < 2000)
        {
            reg[i].curp[16] = '0';
        }
        else
        {
            if (anio >= 2000 && anio < 2010)
            {
                reg[i].curp[16] = 'A';
            }
            else
            {
                if (anio >= 2010)
                {
                    reg[i].curp[16] = 'B';
                }
            }
        }
        printf("[16] %c\n", reg[i].curp[16]);
        li= 0, ls=9;
        ultimoDigito = (rand()%rango);
        sprintf(cultimoDigito, "%d", ultimoDigito);
        reg[i].curp[17] = cultimoDigito[0];
        printf("[17] %c\n", reg[i].curp[17]);
        printf("%s\n", reg[i].curp);

        curp[18] = '\0';

        if (antisonante(curp, antisonantes, sizeof(antisonantes) / sizeof(antisonantes[0])))
        {
            curp[1] = 'X';
        }

        printf("%3s %6s %10s %20s %20s %20s %4s %8s %21s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo", "curp");
        printf("%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].nombres.apellidoPaterno, reg[i].nombres.apellidoMaterno, reg[i].nombres.nombre, reg[i].edad);
        if(reg[i].sexo == 1)
        {
            printf(" %8s\n", "HOMBRE");
        }
        else
        {
            printf(" %8s\n", "MUJER");
        }
        printf(" %19s", reg[i].curp);
}

void imprimirAleatorio(Talumns reg[], int posicion, int n)
{
    int i;
    printf("%3s %6s %10s %20s %20s %20s %4s %8s %19s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo", "curp");
    
    for(i=0; i < (posicion + n); i++)
    {
        printf("%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].nombres.apellidoPaterno, reg[i].nombres.apellidoMaterno, reg[i].nombres.nombre, reg[i].edad);
        if(reg[i].sexo == 1)
        {
            printf(" %8s\n", "HOMBRE");
        }
        else
        {
            printf(" %8s\n", "MUJER");
        }
        printf(" %s\n", reg[i].curp);
    }
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

int msg()
{
    int op;
    printf("MENU\n");
    printf("1.- generar curp\n");
    printf("2.- Salir\n");
    op = validacionNumero("Selecciona una opcion: ", 1, 2);
    return op;
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
        fapellidoPaterno(reg, i);
        fapellidoMaterno(reg, i);
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

void fapellidoPaterno(Talumns reg[], int posicion)
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
    strcpy(reg[posicion].nombres.apellidoPaterno, apellidos[numero]);
}

void fapellidoMaterno(Talumns reg[], int posicion)
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
    strcpy(reg[posicion].nombres.apellidoMaterno, apellidos[numero]);
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
        strcpy(reg[posicion].nombres.nombre, nombresHombre[numero]);
    }
    else
    {
        numero = (rand()%49) +1;
        strcpy(reg[posicion].nombres.nombre, nombresMujer[numero]);
    }
    
}

void edad(Talumns reg[], int posicion, int li, int ls)
{
    int rango= (ls-li)+1;
    reg[posicion].edad = (rand()%rango)+li;
}
