// Hernandez Ceseña Ivan Fernando  373077
// 22/10/23
// codigo que genera la clave unica de registro de poblacio (CURP)
// en base a las normativas
// HCIF_ACT9_3/4_932

#include "ivan.h"
#include "listas.h"


int msg();
char primerVocal(char *cadena);
char egundaConsonante(char cadena[]);
int bisiesto(int anio);
int antisonante(char cadena[], char antisonantes[][5], int numAntisonantes);
void omitirNombres(char nombre[], char partes[][7]);
void omitirPartes(char apellido[], char partes[][6]);


int main()
{
    srand(time(NULL));
    
    int op;
    char nombre[50];
    char apellidoPaterno[50];
    int opcion1;
    int opcion2;
    char apellidoMaterno[50];
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
    
    do{
        
        op = msg();

        if(op == 1)
        {
            validacionTexto("dame el nombre", nombre, sizeof(nombre));
            omitirNombres(nombre, nombresCortos);
            omitirNombres(nombre, nombresCortos);
            omitirPartes(nombre, partes);
            omitirPartes(nombre, partes);
            sinEspacio(nombre);
            
            opcion1 = validacionNumero("tienes apellido paterno?\n1- si\n2- no", 1, 2);
            if (opcion1 == 1)
            {
                validacionTexto("dame tu apellido paterno", apellidoPaterno, sizeof(apellidoPaterno));
                omitirPartes(apellidoPaterno, partes);
                omitirPartes(apellidoPaterno, partes);
                sinEspacio(apellidoPaterno);
            }
           
            opcion2 =  validacionNumero("tienes apellido materno?\n1- si\n2- no", 1, 2);
            if (opcion2 == 1)
            {
                validacionTexto("dame tu apellido materno", apellidoMaterno, sizeof(apellidoMaterno));
                omitirPartes(apellidoMaterno, partes);
                omitirPartes(apellidoMaterno, partes);
                sinEspacio(apellidoMaterno);
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
                curp[0] = toupper(apellidoPaterno[0]);
                curp[1] = primerVocal(apellidoPaterno);
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
                curp[2] = toupper(apellidoMaterno[0]);
            }
            else
            {
                if (opcion2 == 2)
                {
                    curp[2] = 'X';
                }
            }

            curp[3] = toupper(nombre[0]);
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
            if (!egundaConsonante(apellidoPaterno) || opcion1 == 2)
            {
                curp[13] = 'X';
            }
            else
            {
                curp[13] = egundaConsonante(apellidoPaterno);
            }
            if (!egundaConsonante(apellidoMaterno) || opcion2 == 2)
            {
                curp[14] = 'X';
            }
            else
            {
                curp[14] = egundaConsonante(apellidoMaterno);
            }

            if (!egundaConsonante(nombre))
            {
                curp[15] = 'X';
            }
            else
            {
                curp[15] = egundaConsonante(nombre);
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
    }while(op != 2);

    return 0;
}

int msg()
{
    int op;
    printf("INGRESA LOS SIGUIENTES DATOS PARA PODER OBTENER LA CURP\n");
    printf("1.- generar curp\n");
    printf("2.- Salir\n");
    op = validacionNumero("Selecciona una opcion: ", 1, 2);
    return op;
}

char primerVocal(char *cadena)
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

char egundaConsonante(char cadena[])
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