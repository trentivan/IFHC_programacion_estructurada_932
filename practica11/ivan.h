#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>



int validacionNumero(char msg[], int li, int ls);
void validacionTexto(char msg[], char cadena[], int n);
int numeroAleatorio(int ri, int rf);
void mayusculas(char palabra[]);
void validarAcentos(char cadena[]);




// char primerVocal(char *cadena);
// char segundaConsonante(char cadena[]);
// int bisiesto(int anio);
// int antisonante(char cadena[], char antisonantes[][5], int numAntisonantes);
// void omitirNombres(char nombre[], char partes[][7]);
// void omitirPartes(char apellido[], char partes[][6]);



void sinEspacio(char cadena[])
{
    int i, no_space_count = 0;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            cadena[no_space_count++] = cadena[i];
        }
    }

    cadena[no_space_count] = '\0';
}

int numeroAleatorio(int ri, int rf)
{
    int range = (rf - ri + 1);

    return rand() % range + ri;
}

int validacionNumero(char msg[], int li, int ls)  // funcion para que solo se acepten numeros
{
    int numero, valido;
    char cadena[100];
    do{
        valido=0;
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);
        numero= atoi(cadena);
        if(numero < li || numero > ls)
        {
            printf("el numero debe estar dentro de este rango (%d-%d)\n", li, ls); 
            printf("por favor, introduce otro numero\n");
            valido=1;
        }

    }while(valido==1);  
    
    return numero;
}

void mayusculas(char palabra[])
{
    int i;
    for(i=0; palabra[i] != '\0'; i++)
    {
        if(palabra[i] >= 'a')
        {
            if(palabra[i] <= 'z')
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
            }
        }
    }
}

void validarAcentos(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == -92 || cadena[i] == -91 || cadena[i] == '/' || cadena[i] == '-')
            {
                cadena[i] = 'X';
            }
            if (cadena[i] == -93 || cadena[i] == -23 || cadena[i] == -127 || cadena[i] == -102)
            {
                cadena[i] = 'U';
            }
            if (cadena[i] == -96 || cadena[i] == -75 || cadena[i] == -114 || cadena[i] == -124)
            {
                cadena[i] = 'A';
            }
            if (cadena[i] == -126 || cadena[i] == -112 || cadena[i] == -45 || cadena[i] == -119)
            {
                cadena[i] = 'E';
            }
            if (cadena[i] == -95 || cadena[i] == -42 || cadena[i] == -40 || cadena[i] == -117)
            {
                cadena[i] = 'i';
            }
            if (cadena[i] == -94 || cadena[i] == -32 || cadena[i] == -108)
            {
                cadena[i] = 'O';
            }

        // if (cadena[i] == 'Á' && cadena[i] == -124)
        // {
        //     cadena[i] = 'A';
        // }
        // else
        // {
        //     if (cadena[i] == -119 || cadena[i] == -119 )
        //     {
        //         cadena[i] = 'E';
        //     }
        //     else
        //     {
        //         if (cadena[i] == 'Í' || cadena[i] == -117)
        //         {
        //             cadena[i] = 'I';
        //         }
        //         else
        //         {
        //             if (cadena[i] == 'Ó' || cadena[i] == -108)
        //             {
        //                 cadena[i] = 'O';
        //             }
        //             else
        //             {
        //                 if (cadena[i] == 'Ú' || cadena[i] == -127)
        //                 {
        //                     cadena[i] = 'U';
        //                 }
        //             }
        //         }
        //     }
        // }
    }
}


void validacionTexto(char msg[], char cadena[], int n)  // funcion para validar texto
{
    int invalido=0, contador=0;
    int i;
    do{
        invalido=0;
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);
        validarAcentos(cadena);
        mayusculas(cadena);

        for(i=0 ; cadena[i] != '\0'; i++);
        if(i > n)
        {
            printf("el texto escrito tiene mas de [%d] caracteres.\n", n);
            invalido=1;
        }

        for(i=0 ; cadena[i] != '\0'; i++, contador++)
        {
            if(cadena[i] > 90)
            {
                if(cadena[i] >= 97)
                {
                    if(cadena[i] > 122)
                    {
                        invalido=1;
                        printf("el texto no puede contener caracteres especiales como este que escribiste [%c]\n", cadena[i]);
                    }
                }
                else
                {
                    invalido=1;
                    printf("el texto no puede contener caracteres especiales como este que escribiste [%c]\n", cadena[i]);
                }
            }
            else
            {
                if(cadena[i] == 32)
                {
                    if(cadena[i+1] == 32)
                    {
                        invalido=1;
                        printf("el texto no puede contener dobles espacios\n");
                    }
                }
                else
                {
                    if(cadena[i] < 65)
                    {
                        invalido=1;
                        printf("el texto no puede contener caracteres especiales como este que escribiste [%c]\n", cadena[i]);
                    }
                }
            }
        }
        if(cadena[0] == '\0')
        {
            invalido=1;
            printf("escribe un texto por favor\n");
        }
        if (cadena[0] == ' ')
        {
            invalido=1;
            printf("no se puede tener espacios al inicio del texto\n");
        }
        if(cadena[contador-1] == ' ')
        {
            invalido=1;
            printf("no se puede tener espacios al final del texto\n");
        }
        if(invalido==1)
        {
            printf("Por favor escribe otro texto.\n");
        }

    }while(invalido == 1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

// char primerVocal(char *cadena)
// {
//     char vocal;

//     char primeraLetra = cadena[0];

//     cadena++;

//     while (*cadena)
//     {
//         if (strchr("AEIOU", *cadena))
//         {
//             vocal = toupper(*cadena);
//             return vocal;
//         }
//         cadena++;
//     }
//     return 'X';
// }

// char segundaConsonante(char cadena[])
// {
//     char primeraLetra = cadena[0];
//     int i = 1;

//     while (cadena[i] != '\0')
//     {
//         char caracter = cadena[i];
//         if (!strchr("AEIOUaeiou", caracter))
//         {
//             return caracter;
//         }
//         i++;
//     }
//     return '\0';
// }

// int bisiesto(int anio)
// {
//     if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int antisonante(char cadena[], char antisonantes[][5], int numAntisonantes)
// {
//     char subcadena[5];

//     strncpy(subcadena, cadena, 4);
//     subcadena[4] = '\0';

//     for (int i = 0; i < numAntisonantes; i++)
//     {
//         if (strcmp(subcadena, antisonantes[i]) == 0)
//         {
//             return 1;
//         }
//     }

//     return 0;
// }

// void omitirNombres(char nombre[], char partes[][7])
// {
//     for (int i = 0; partes[i][0] != '\0'; i++)
//     {
//         char *encontrado = strstr(nombre, partes[i]);
//         while (encontrado != NULL)
//         {
//             int longitudParte = strlen(partes[i]);
//             int longitudRestante = strlen(encontrado + longitudParte);

//             for (int j = 0; j <= longitudRestante; j++)
//             {
//                 encontrado[j] = encontrado[j + longitudParte];
//             }

//             encontrado = strstr(encontrado, partes[i]);
//         }
//     }
// }

// void omitirPartes(char apellido[], char partes[][6])
// {
//     for (int i = 0; partes[i][0] != '\0'; i++)
//     {
//         char *encontrado = strstr(apellido, partes[i]);
//         while (encontrado != NULL)
//         {
//             int longitudParte = strlen(partes[i]);
//             int longitudRestante = strlen(encontrado + longitudParte);

//             for (int j = 0; j <= longitudRestante; j++)
//             {
//                 encontrado[j] = encontrado[j + longitudParte];
//             }

//             encontrado = strstr(encontrado, partes[i]);
//         }
//     }
// }

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void imprimirAleatorio(Talumns reg[], int posicion, int n)
// {
//     int i;
//     printf("%3s %6s %10s %20s %20s %20s %4s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo");
    
//     for(i=0; i < (posicion + n); i++)
//     {
//         printf("%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].nombres.apellidoPaterno, reg[i].nombres.apellidoMaterno, reg[i].nombres.nombre, reg[i].edad);
//         if(reg[i].sexo == 1)
//         {
//             printf(" %8s\n", "HOMBRE");
//         }
//         else
//         {
//             printf(" %8s\n", "MUJER");
//         }
//     }
// }

// void imprimirUnAlumno(Talumns reg[], int posicion)
// {
//     printf("%3s %6s %10s %20s %20s %20s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "sexo");
//     printf("%3d %6d %10d %20s %20s %20s", posicion+1, reg[posicion].status, reg[posicion].matricula, reg[posicion].nombres.apellidoPaterno, reg[posicion].nombres.apellidoMaterno, reg[posicion].nombres.nombre);
//     if(reg[posicion].sexo == 1)
//     {
//         printf(" %8s\n", "HOMBRE");
//     }
//     else
//     {
//         printf(" %8s\n", "MUJER");
//     }
// }

// void registroAleatorio(Talumns reg[], int posicion, int n)
// {
//     int li, ls, i;

//     for(i=posicion; i < (posicion + n); i++)
//     {
//         li=1, ls=2;
//         sexo(reg, i, li, ls);
//         status(reg, i);
//         li=300000;
//         ls=399999;
//         matricula(reg, li, ls, i);
//         li= 1, ls= 50;
//         apellidoPaterno(reg, i);
//         apellidoMaterno(reg, i);
//         nombre(reg, i);
//         li=17, ls=50;
//         edad(reg, i, li, ls);
//     }
// }

// void sexo(Talumns reg[], int posicion, int li, int ls)
// {
//     int sexo;
//     sexo= (rand()%ls) +li;
//     reg[posicion].sexo = sexo;
// }

// void status(Talumns reg[], int posicion)
// {
//     int estado;
//     estado= 1;
//     reg[posicion].status = estado;
// }

// void matricula(Talumns reg[], int li, int ls, int posicion)
// {
//     int mat, rango= (ls-li) +1;
//     int existe;
//     do{
//         mat = rand()% rango + li;
//         existe = existeValor(reg, posicion, mat);
//     }while(existe != -1);
//     reg[posicion].matricula = mat;
// }

// void apellidoPaterno(Talumns reg[], int posicion)
// {
//     int numero;
//     char apellidos[100][20] = {
//     "GONZALEZ", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "PEREZ",
//     "GOMEZ", "SANCHEZ", "FERNANDEZ", "RAMIREZ", "TORRES",
//     "DIAZ", "HERNANDEZ", "VARGAS", "MORALES", "CASTILLO",
//     "ORTEGA", "MENDOZA", "CRUZ", "RUIZ", "FLORES",
//     "RIVERA", "GUTIERREZ", "RIOS", "NAVARRO", "SALAZAR",
//     "ACOSTA", "SILVA", "MORA", "GUERRERO", "CAMPOS",
//     "DELGADO", "VEGA", "GUERRA", "AGUILAR", "SUAREZ",
//     "ROJAS", "SALAS", "PAREDES", "CABRERA", "PONCE",
//     "VALENZUELA", "MIRANDA", "LARA", "SOLIS", "VILLANUEVA",
//     "LUNA", "FIGUEROA", "MUNOZ", "BARRIOS", "JIMENEZ",
//     "BUSTOS", "NUNEZ", "ZUNIGA", "LEAL", "CHAVEZ",
//     "MEDINA", "PARRA", "BAEZ", "NAVARRETE", "AVILA",
//     "VELASQUEZ", "FUENTES", "SOTO", "CONTRERAS", "CACERES",
//     "VENEGAS", "RIQUELME", "ARAYA", "TOLEDO", "SEPULVEDA",
//     "REYES", "ANDRADE", "VILLEGAS", "CASTRO", "DURAN",
//     "ESPINOSA", "ARANEDA", "LAGOS", "POBLETE", "BECERRA",
//     "MARTIN", "ROMERO", "FERNANDO", "TORRES", "GUTIERREZ",
//     "ALVAREZ", "PEREIRA", "RUIZ", "VIDAL", "MORON",
//     "CHACON", "SOTO", "BARRETO", "CAMACHO", "LIRA",
//     "CACERES", "PALMA", "SILVESTRE", "MIERES", "GARRIDO"
//     };

//     numero = (rand()%99) +1;
//     strcpy(reg[posicion].nombres.apellidoPaterno, apellidos[numero]);
// }

// void apellidoMaterno(Talumns reg[], int posicion)
// {
//     int numero;
//     char apellidos[100][20] = {
//     "GONZALEZ", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "PEREZ",
//     "GOMEZ", "SANCHEZ", "FERNANDEZ", "RAMIREZ", "TORRES",
//     "DIAZ", "HERNANDEZ", "VARGAS", "MORALES", "CASTILLO",
//     "ORTEGA", "MENDOZA", "CRUZ", "RUIZ", "FLORES",
//     "RIVERA", "GUTIERREZ", "RIOS", "NAVARRO", "SALAZAR",
//     "ACOSTA", "SILVA", "MORA", "GUERRERO", "CAMPOS",
//     "DELGADO", "VEGA", "GUERRA", "AGUILAR", "SUAREZ",
//     "ROJAS", "SALAS", "PAREDES", "CABRERA", "PONCE",
//     "VALENZUELA", "MIRANDA", "LARA", "SOLIS", "VILLANUEVA",
//     "LUNA", "FIGUEROA", "MUNOZ", "BARRIOS", "JIMENEZ",
//     "BUSTOS", "NUNEZ", "ZUNIGA", "LEAL", "CHAVEZ",
//     "MEDINA", "PARRA", "BAEZ", "NAVARRETE", "AVILA",
//     "VELASQUEZ", "FUENTES", "SOTO", "CONTRERAS", "CACERES",
//     "VENEGAS", "RIQUELME", "ARAYA", "TOLEDO", "SEPULVEDA",
//     "REYES", "ANDRADE", "VILLEGAS", "CASTRO", "DURAN",
//     "ESPINOSA", "ARANEDA", "LAGOS", "POBLETE", "BECERRA",
//     "MARTIN", "ROMERO", "FERNANDO", "TORRES", "GUTIERREZ",
//     "ALVAREZ", "PEREIRA", "RUIZ", "VIDAL", "MORON",
//     "CHACON", "SOTO", "BARRETO", "CAMACHO", "LIRA",
//     "CACERES", "PALMA", "SILVESTRE", "MIERES", "GARRIDO"
//     };

//     numero = (rand()%99) +1;
//     strcpy(reg[posicion].nombres.apellidoMaterno, apellidos[numero]);
// }

// void nombre(Talumns reg[], int posicion)
// {
//     int numero;
//     char nombresHombre[50][20] = {
//     "JUAN", "CARLOS", "MIGUEL", "ANDRES", "LUIS",
//     "FERNANDO", "PEDRO", "JAVIER", "DIEGO", "RICARDO",
//     "SERGIO", "ALEJANDRO", "HECTOR", "JOSE", "MARTIN",
//     "RAUL", "GUSTAVO", "PABLO", "ROBERTO", "ANTONIO",
//     "MANUEL", "ANGEL", "JORGE", "FELIX", "LUCAS",
//     "PASCUAL", "BENJAMIN", "ALVARO", "ARTURO", "ADRIAN",
//     "CESAR", "ENRIQUE", "FELIPE", "GERARDO", "IVAN",
//     "NESTOR", "OLIVER", "PACO", "QUIRINO", "SAMUEL",
//     "TOMAS", "ULISES", "VICENTE", "WILLIAM", "XAVIER",
//     "YAGO", "ZACARIAS", "ABEL", "BARTOLOME", "MARCO"


//     };
//     char nombresMujer[50][20] = {
//     "MARIA", "LAURA", "ANA", "CARMEN", "LUISA",
//     "ISABEL", "RAQUEL", "SOFIA", "ELENA", "LETICIA",
//     "MARTA", "MONICA", "BEATRIZ", "SILVIA", "INES",
//     "SUSANA", "ROSA", "NATALIA", "OLGA", "TERESA",
//     "IRENE", "PATRICIA", "PAULA", "ANDREA", "NADIA",
//     "VANESSA", "SARA", "MIRIAM", "GLORIA", "VICTORIA",
//     "ESTHER", "YOLANDA", "CLARA", "JUANA", "JULIA",
//     "BELEN", "MARGARITA", "ADELA", "MANUELA", "CAROLINA",
//     "ELVIRA", "MARINA", "ROSARIO", "DIANA", "LORENA",
//     "CONSUELO", "ANGELA", "INMACULADA", "FELICIDAD", "CECILIA"
//     };

//     if(reg[posicion].sexo == 1)
//     {
//         numero = (rand()%49) +1;
//         strcpy(reg[posicion].nombres.nombre, nombresHombre[numero]);
//     }
//     else
//     {
//         numero = (rand()%49) +1;
//         strcpy(reg[posicion].nombres.nombre, nombresMujer[numero]);
//     }
    
// }

// void edad(Talumns reg[], int posicion, int li, int ls)
// {
//     int rango= (ls-li)+1;
//     reg[posicion].edad = (rand()%rango)+li;
// }

// void alumnoManual(Talumns reg[], int posicion)
// {
//     int existe;
//     char paterno[20];
//     char materno[20];
//     char nombre[20];

//     reg[posicion].status= 1;
//     do{
//     reg[posicion].matricula = validacionNumero("dame tu matricula", 300000, 399999);
//     existe = existeValor(reg, posicion, reg[posicion].matricula);
//     if(existe != -1)
//     {
//         printf("la matricula ya existe.\npor favor introduce otra\n");
//     }
//     }while(existe != -1);
    
//     validacionTexto("dame tu apellido paterno", paterno, 20);
//     strcpy(reg[posicion].nombres.apellidoPaterno, paterno);

//     validacionTexto("dame tu apellido paterno", materno, 20);
//     strcpy(reg[posicion].nombres.apellidoMaterno, materno);

//     validacionTexto("dame tu nombre", nombre, 20);
//     strcpy(reg[posicion].nombres.nombre, nombre);

//     reg[posicion].edad = validacionNumero("dame tu edad", 17, 50);
//     reg[posicion].sexo = validacionNumero("dame tu sexo (1- hombre. 2- mujer)", 1, 2);
// }



// void eliminarRegistro(Talumns reg[], int posicion)
// {
//     int eliminar, mat;
//     mat = validacionNumero("dame la matricula que quieres eliminar", 300000, 399999);
//     eliminar= existeValor(reg, posicion, mat);
//     if(eliminar != -1)
//     {
//         if(reg[eliminar].status == 1)
//         {
//             reg[eliminar].status = 0;
//             printf("estudiante dado de baja\n");
//         }
//         else
//         {
//             printf("la matricula ya estaba dada de baja\n");
//         }
//     }
//     else
//     {
//         printf("esta matricula no esta en el registro\n");
//     }
// }

// void buscarElemento(Talumns reg[], int posicion, int bandera)
// {
//     int mat, buscar;
//     // mat = validacionNumero("que matricula buscas?", 300000, 399999);
//     // buscar = existeValor(reg, posicion, mat);

//     if(bandera == 0)
//     {
//         printf("busqueda secuencial\n");
//         mat = validacionNumero("que matricula buscas?", 300000, 399999);
//         buscar = existeValor(reg, posicion, mat);
//     }
//     else
//     {
//         printf("busqueda binaria\n");
//         buscar = busquedaBinaria(reg, 0, posicion - 1);
//     }

//     if(buscar != -1)
//     {
//         imprimirUnAlumno(reg, buscar);
//     }
// }

// void imprimirRegistro(Talumns reg[], int posicion)
// {
//     int i;
//     printf("%3s %6s %10s %20s %20s %20s %4s %8s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo");
//     for(i=0; i<posicion; i++)
//     {
//         if(reg[i].status == 1)
//         {
//             printf("%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].nombres.apellidoPaterno, reg[i].nombres.apellidoMaterno, reg[i].nombres.nombre, reg[i].edad);
//             if(reg[i].sexo == 1)
//             {
//                 printf(" %8s\n", "HOMBRE");
//             }
//             else
//             {
//                 printf(" %8s\n", "MUJER");
//             }
//         }
//     }
// }

// void ordenarAscendente(Talumns reg[], int n)
// {
//     int i, j;    
//     Talumns aux;
//     for(i=0; i<n; i++)  
//     {
//         for(j=i+1; j<n; j++)   
//         {
//             if(reg[j].matricula <reg[i].matricula)   
//             {
//                 aux = reg[i];         
//                 reg[i] = reg[j];
//                 reg[j] = aux;
//             }
//         }
//     }
// }

// int busquedaBinaria(Talumns reg[], int izquierda, int derecha)
// {
//     int mat;
//     mat = validacionNumero("que matricula buscas?", 300000, 399999);
//     while (izquierda <= derecha)
//     {
//         int medio = izquierda + (derecha - izquierda) / 2;

//         if (reg[medio].matricula == mat)
//         {
//             return medio;
//         }

//         if (reg[medio].matricula < mat)
//         {
//             izquierda = medio + 1;
//         }
//         else
//         {
//             derecha = medio - 1;
//         }
//     }

//     return -1;
// }