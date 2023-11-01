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
    char curp[18]; } Talumns;


int msg(void);
int menu2(void);
void imprimirAleatorio(Talumns reg[], int posicion, int n);
void imprimirUnAlumno(Talumns reg[], int posicion);
void registroAleatorio(Talumns reg[], int posicion, int n);
void sexo(Talumns reg[], int posicion, int li, int ls);
void status(Talumns reg[], int posicion);
void matricula(Talumns reg[], int li, int ls, int posicion);
void fapellidoPaterno(Talumns reg[], int posicion);
void fapellidoMaterno(Talumns reg[], int posicion);
void nombre(Talumns reg[], int posicion);
void edad(Talumns reg[], int posicion, int li, int ls);

void alumnoManual(Talumns reg[], int posicion);
int existeValor(Talumns reg[], int n, int numero);
void eliminarRegistro(Talumns reg[], int posicion);
void buscarElemento(Talumns reg[], int posicion, int bandera);
void imprimirRegistro(Talumns reg[], int posicion);
void ordenarAscendente(Talumns reg[], int n);
int busquedaBinaria(Talumns reg[], int izquierda, int derecha);
void generarCurpManual(Talumns reg[], int i, int n);

char primerVocal(char cadena[]);
char segundaConsonante(char cadena[]);
int bisiesto(int anio);
int antisonante(char cadena[], char antisonantes[][5], int numAntisonantes);
void omitirNombres(char nombre[], char partes[][7]);
void omitirPartes(char apellido[], char partes[][6]);


int main()
{
    srand(time(NULL));
    
    int op, op2, i=0, n=10;
    Talumns reg[n];
    
    do{
        
        op = msg();

        switch(op)
        {
            case 1:
            op2 = menu2();
            switch(op2)
            {
                case 1:
                
                break;

                case 2:

                break;
            }
            break;

            case 2:

            break;

        }
    }while(op != 2);

    return 0;
}

void generarCurpManual(Talumns reg[], int i, int n)
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

    validacionTexto("dame tus nombres (no apellidos)", reg[i].nombres.nombre, sizeof(reg[i].nombres.nombre));
        omitirNombres(reg[i].nombres.nombre, nombresCortos);
        omitirNombres(reg[i].nombres.nombre, nombresCortos);
        omitirPartes(reg[i].nombres.nombre, partes);
        omitirPartes(reg[i].nombres.nombre, partes);
        sinEspacio(reg[i].nombres.nombre);
        
        opcion1 = validacionNumero("tienes apellido paterno?\n1- si\n2- no", 1, 2);
        if (opcion1 == 1)
        {
            validacionTexto("dame tu apellido paterno", reg[i].nombres.apellidoPaterno, sizeof(reg[i].nombres.apellidoPaterno));
            omitirPartes(reg[i].nombres.apellidoPaterno, partes);
            omitirPartes(reg[i].nombres.apellidoPaterno, partes);
            sinEspacio(reg[i].nombres.apellidoPaterno);
        }
        
        opcion2 =  validacionNumero("tienes apellido materno?\n1- si\n2- no", 1, 2);
        if (opcion2 == 1)
        {
            validacionTexto("dame tu apellido materno", reg[i].nombres.apellidoMaterno, sizeof(reg[i].nombres.apellidoMaterno));
            omitirPartes(reg[i].nombres.apellidoMaterno, partes);
            omitirPartes(reg[i].nombres.apellidoMaterno, partes);
            sinEspacio(reg[i].nombres.apellidoMaterno);
        }
        anio = validacionNumero("escribe tu anio de nacimiento (4 digitos)", 1910, 2023);
        sprintf(canio, "%d", anio);

        mes = validacionNumero("escribe tu mes de nacimiento", 1, 12);
        sprintf(Cmes, "%d", mes);
        

        
        if (mes == 2 && bisiesto(anio) == 1)
        {
            dia = validacionNumero("escribe tu dia de nacimiento", 1, 29);
        }
        else
        {
            if (mes == 2 && bisiesto(anio) == 0)
            {
                dia = validacionNumero("escribe tu dia de nacimiento", 1, 28);
            }
            else
            {
                if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                {
                    dia = validacionNumero("escribe tu dia de nacimiento", 1, 31);
                }
                else
                {
                    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                    {
                        dia = validacionNumero("escribe tu dia de nacimiento", 1, 30);
                    }
                }
            }
        }
        sprintf(Cdia, "%d", dia);

        gen = validacionNumero("dame tu genero\n1- hombre.\n2- mujer", 1, 2);

        printf("1. Aguascalientes\n");
        printf("2. Baja California\n");
        printf("3. Baja California Sur\n");
        printf("4. Campeche\n");
        printf("5. Chiapas\n");
        printf("6. Chihuaha\n");
        printf("7. Coahuila\n");
        printf("8. Colima\n");
        printf("9. Durango\n");
        printf("10. Guanajuato\n");
        printf("11. Guerrero\n");
        printf("12. Hidalgo\n");
        printf("13. Jalisco\n");
        printf("14. Estado de Mexico\n");
        printf("15. Michoacan\n");
        printf("16. Morelos\n");
        printf("17. Nayarit\n");
        printf("18. Nuevo Leon\n");
        printf("19. Oaxaca\n");
        printf("20. Puebla\n");
        printf("21. Queretaro\n");
        printf("22. Quintana Roo\n");
        printf("23. San Luis Potosi\n");
        printf("24. Sinaloa\n");
        printf("25. Sonora\n");
        printf("26. Tabasco \n");
        printf("27. Tamaulipas\n");
        printf("28. Tlaxcala\n");
        printf("29. Veracruz\n");
        printf("30. Yucatan\n");
        printf("31. Zacatecas\n");
        printf("32. Ciudad de Mexico\n");
        printf("33. Extranjero\n");
        estado = validacionNumero("escribe el numero de tu estado.\nsi eres extranjero selecciona el No. 33.", 1, 33);
        strcpy(est, iniEstado[estado-1]);
        curp[11] = est[0];
        curp[12] = est[1];
        

        if (opcion1 == 1)
        {
            curp[0] = toupper(reg[i].nombres.apellidoPaterno[0]);
            curp[1] = primerVocal(reg[i].nombres.apellidoPaterno);
        }
        else
        {
            if (opcion1 == 2)
            {
                curp[0] = 'X';
                curp[1] = 'X';
            }
        }
        if (opcion2 == 1)
        {
            curp[2] = toupper(reg[i].nombres.apellidoMaterno[0]);
        }
        else
        {
            if (opcion2 == 2)
            {
                curp[2] = 'X';
            }
        }

        curp[3] = toupper(reg[i].nombres.nombre[0]);
        curp[4] = canio[2];
        curp[5] = canio[3];
        if (mes < 10)
        {
            curp[6] = '0';
            curp[7] = Cmes[0];
        }
        else
        {
            curp[6] = Cmes[0];
            curp[7] = Cmes[1];
        }
        if (dia < 10)
        {
            curp[8] = '0';
            curp[9] = Cdia[0];
        }
        else
        {
            curp[8] = Cdia[0];
            curp[9] = Cdia[1];
        }

        if(gen == 1)
        {
            curp[10] = 'H';
        }
        else
        {
            curp[10] = 'H';
        }
        if (!segundaConsonante(reg[i].nombres.apellidoPaterno) || opcion1 == 2)
        {
            curp[13] = 'X';
        }
        else
        {
            curp[13] = segundaConsonante(reg[i].nombres.apellidoPaterno);
        }
        if (!segundaConsonante(reg[i].nombres.apellidoMaterno) || opcion2 == 2)
        {
            curp[14] = 'X';
        }
        else
        {
            curp[14] = segundaConsonante(reg[i].nombres.apellidoMaterno);
        }

        if (!segundaConsonante(reg[i].nombres.nombre))
        {
            curp[15] = 'X';
        }
        else
        {
            curp[15] = segundaConsonante(reg[i].nombres.nombre);
        }
        if (anio < 2000)
        {
            curp[16] = '0';
        }
        else
        {
            if (anio >= 2000 && anio < 2010)
            {
                curp[16] = 'A';
            }
            else
            {
                if (anio >= 2010)
                {
                    curp[16] = 'B';
                }
            }
        }
        ultimoDigito = numeroAleatorio(0, 9);
        sprintf(cultimoDigito, "%d", ultimoDigito);
        curp[17] = cultimoDigito[0];
        curp[18] = '\0';

        if (antisonante(curp, antisonantes, sizeof(antisonantes) / sizeof(antisonantes[0])))
        {
            curp[1] = 'X';
        }

        printf("La CURP generada es: %s\n", curp);
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

int menu2()
{
    int op;
    printf("1) manual (1 registro)\n");
    printf("2) automatico (100 registros)\n");
    printf("3) regresar\n");
    op = validacionNumero("elige una opcion", 1, 3);
    return op;
}

void imprimirAleatorio(Talumns reg[], int posicion, int n)
{
    int i;
    printf("%3s %6s %10s %20s %20s %20s %4s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo");
    
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
    }
}

void imprimirUnAlumno(Talumns reg[], int posicion)
{
    printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
    printf("%3d %6d %10d %20s %20s %20s", posicion+1, reg[posicion].status, reg[posicion].matricula, reg[posicion].nombres.apellidoPaterno, reg[posicion].nombres.apellidoMaterno, reg[posicion].nombres.nombre);
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
    strcpy(reg[posicion].nombres.apellidoPaterno, paterno);

    validacionTexto("dame tu apellido paterno", materno, 20);
    strcpy(reg[posicion].nombres.apellidoMaterno, materno);

    validacionTexto("dame tu nombre", nombre, 20);
    strcpy(reg[posicion].nombres.nombre, nombre);

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
            printf("%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].nombres.apellidoPaterno, reg[i].nombres.apellidoMaterno, reg[i].nombres.nombre, reg[i].edad);
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char primerVocal(char cadena[])
{
    char vocal;

    char primeraLetra = cadena[0];

    cadena++;

    while (*cadena)
    {
        if (strchr("AEIOU", *cadena))
        {
            vocal = toupper(*cadena);
            return vocal;
        }
        cadena++;
    }
    return 'X';
}

char segundaConsonante(char cadena[])
{
    char primeraLetra = cadena[0];
    int i = 1;

    while (cadena[i] != '\0')
    {
        char caracter = cadena[i];
        if (!strchr("AEIOUaeiou", caracter))
        {
            return caracter;
        }
        i++;
    }
    return '\0';
}

int bisiesto(int anio)
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int antisonante(char cadena[], char antisonantes[][5], int numAntisonantes)
{
    char subcadena[5];

    strncpy(subcadena, cadena, 4);
    subcadena[4] = '\0';

    for (int i = 0; i < numAntisonantes; i++)
    {
        if (strcmp(subcadena, antisonantes[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void omitirNombres(char nombre[], char partes[][7])
{
    for (int i = 0; partes[i][0] != '\0'; i++)
    {
        char *encontrado = strstr(nombre, partes[i]);
        while (encontrado != NULL)
        {
            int longitudParte = strlen(partes[i]);
            int longitudRestante = strlen(encontrado + longitudParte);

            for (int j = 0; j <= longitudRestante; j++)
            {
                encontrado[j] = encontrado[j + longitudParte];
            }

            encontrado = strstr(encontrado, partes[i]);
        }
    }
}

void omitirPartes(char apellido[], char partes[][6])
{
    for (int i = 0; partes[i][0] != '\0'; i++)
    {
        char *encontrado = strstr(apellido, partes[i]);
        while (encontrado != NULL)
        {
            int longitudParte = strlen(partes[i]);
            int longitudRestante = strlen(encontrado + longitudParte);

            for (int j = 0; j <= longitudRestante; j++)
            {
                encontrado[j] = encontrado[j + longitudParte];
            }

            encontrado = strstr(encontrado, partes[i]);
        }
    }
}