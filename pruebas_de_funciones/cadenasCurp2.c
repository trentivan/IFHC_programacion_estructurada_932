




#include "ivan copy.h"


void menu();
int msge_menu();

void askNames(char name[], int n);
void askLastName1(char LastName1[], int n);
void askLastName2(char LastName2[], int n);
int askSex();
void askState(char state[]);
void printCURP(char firstFourLetters[], int day, int month, int year, int sex, char state[], char consonants[]);

// AUXILIAR FUNCTIONS
void displayStates(char state[]);
char getConsonant(char array[], int startPosition);
int nameCompound(char array[]);
void fourLetters(char name[], char LastName1[], char LastName2[], char firstFourLetters[5], int flagLastName1, int flagLastName2, char consonants[]);
char noVowelsApComp(char array[], int startPosition);
int Compound2(char array[], int n);
int antiSonant(char array[]);
int isLapYear(int year);
//**** MAIN FUNCTIONS ****
int main()
{
    menu();
    return 0;
}
//**** DEVELOPMENT PROTOTYPE FUNCTIONS ****
//**********
void menu()
{
    int op, n = 50, m = 30;
    char name[n], LastName1[m], LastName2[m];
    int day, month, year;
    int sex;
    char state[4];
    char firstFourLetters[5];
    char consonants[4];
    int flagName = 0;
    int flagLastName1 = 0;
    int flagLastName2 = 0;
    int flagBirthday = 0;
    int flagSex = 0;
    int flagState = 0;
    do
    {
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            askNames(name, n);
            printf("El nombre ha sido guardado correctamente\n");
            flagName = 1;
            break;
        case 2:
            if (validacionNumero("Tienes apellido paterno? (1.- Si, 0.- No): ", 0, 1))
            {
                askLastName1(LastName1, m);
                printf("El apellido ha sido guardado correctamente\n");
                flagLastName1 = 1;
            }
            break;
        case 3:
            if (validacionNumero("Tienes apellido materno? (1.- Si, 0.- No): ", 0, 1))
            {
                askLastName2(LastName2, m);
                printf("El apellido ha sido guardado correctamente\n");
                flagLastName2 = 1;
            }
            break;
        case 4:
            year = validacionNumero("Ingresa el anio de tu nacimiento: ", 1894, 2023);
            if (year == 2023)
            {
                month = validacionNumero("Ingresa el mes de tu nacimiento: ", 1, 10);
                if (month == 2)
                {
                    day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 28);
                }
                else
                {
                    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    {
                        day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 31);
                    }
                    else
                    {
                        day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 30);
                    }
                }
            }
            else
            {
                if (isLapYear(year))
                {
                    month = validacionNumero("Ingresa el mes de tu nacimiento: ", 1, 12);
                    if (month == 2)
                    {
                        day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 29);
                    }
                    else
                    {
                        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                        {
                            day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 31);
                        }
                        else
                        {
                            day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 30);
                        }
                    }
                }
                else
                {
                    month = validacionNumero("Ingresa el mes de tu nacimiento: ", 1, 12);
                    if (month == 2)
                    {
                        day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 28);
                    }
                    else
                    {
                        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                        {
                            day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 31);
                        }
                        else
                        {
                            day = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 30);
                        }
                    }
                }
            }

            printf("Se han guardado correctamente la fecha de nacimiento.\n");
            flagBirthday = 1;
            break;
        case 5:
            sex = askSex();
            flagSex = 1;
            break;
        case 6:
            askState(state);
            flagState = 1;
            break;
        case 7:
            if (flagName)
            {
                if (flagBirthday)
                {
                    if (flagSex)
                    {
                        if (flagState)
                        {
                            fourLetters(name, LastName1, LastName2, firstFourLetters, flagLastName1, flagLastName2, consonants);
                            printCURP(firstFourLetters, day, month, year, sex, state, consonants);
                            if (validacionNumero("\nImprimir una nueva CURP? (1.- Si, 0.- No): ", 0, 1))
                            {
                                flagName = 0;
                                flagLastName1 = 0;
                                flagLastName2 = 0;
                                flagBirthday = 0;
                                flagSex = 0;
                                flagState = 0;
                            }
                            else
                            {
                                op = 0;
                            }
                        }
                        else
                        {
                            printf("Hace falta lugar de nacimiento\n");
                        }
                    }
                    else
                    {
                        printf("Hace falta el sexo\n");
                    }
                }
                else
                {
                    printf("Hace falta el dia de tu nacimiento\n");
                }
            }
            else
            {
                printf("Hace falta tu nombre\n");
            }

            break;
        }
        system("PAUSE");
    } while (op != 0);
}

int msge_menu()
{
    int op;
    system("CLS");
    printf("INGRESA LOS SIGUIENTES DATOS PARA PODER OBTENER LA CURP\n");
    printf("1.- Ingresar Nombre\n");
    printf("2.- Ingresar Apellido Paterno\n");
    printf("3.- Ingresa Apellido Materno\n");
    printf("4.- Ingresa el Dia de Nacimiento\n");
    printf("5.- Seleccionar sexo\n");
    printf("6.- Lugar de nacimiento\n");
    printf("7.- Imprimir CURP\n");
    printf("0.- Salir\n");
    op = validacionNumero("Selecciona una opcion: ", 0, 7);
    return op;
}

**********
void askNames(char name[], int n)
{
    validacionTexto("dame tu nombre", name, n);
}

void askLastName1(char LastName1[], int n)
{
    validacionTexto("dame tu apellido paterno", LastName1, n);
}

void askLastName2(char LastName2[], int n)
{
    validacionTexto("dame tu apellido materno", LastName2, n);
}

int askSex()
{
    int sex;
    sex = validacionNumero("dame tu sexo.\n1- hombre.\n0- mujer", 0, 1);
    return sex;
}

void askState(char state[])
{
    int isForeign;
    system("CLS");
    isForeign = validacionNumero("Eres extranjero? (1.- Si, 0.- No): ", 0, 1);

    if (isForeign)
    {
        strcpy(state, "NE");
    }
    else
    {
        system("CLS");
        displayStates(state);
    }
}

void printCURP(char firstFourLetters[], int day, int month, int year, int sex, char state[], char consonants[])
{
    int numero;
    printf("La CURP es: ");
    printf("%c", firstFourLetters[0]);
    printf("%c", firstFourLetters[1]);
    printf("%c", firstFourLetters[2]);
    printf("%c", firstFourLetters[3]);
    printf("%02d", year % 100);
    printf("%02d", month);
    printf("%02d", day);

    if (sex == 1)
    {
        printf("H");
    }
    else
    {
        printf("M");
    }
    printf("%s", state);
    printf("%s", consonants);
    if (year < 2000)
    {
        printf("0");
    }
    else
    {
        if (year >= 2000)
        {
            if (year <= 2009)
            {
                printf("A");
            }
            else
            {
                if (year >= 2010)
                {
                    if (year <= 2019)
                    {
                        printf("B");
                    }
                    else
                    {
                        printf("C");
                    }
                }
            }
        }
    }
    numero = (rand()% 9) +1;
    printf("%d", numero);
}

//***************************

//**** AUXILIAR FUNCTIONS *****
void displayStates(char state[])
{
    int i;
    int tempNum;
    char states[32][50] =
        {
            "Aguascalientes",
            "Baja California",
            "Baja California Sur",
            "Campeche",
            "Chiapas",
            "Chihuahua",
            "Coahuila de Zaragoza",
            "Colima",
            "Ciudad de Mexico",
            "Durango",
            "Guanajuato",
            "Guerrero",
            "Hidalgo",
            "Jalisco",
            "Mexico",
            "Michoacan de Ocampo",
            "Morelos",
            "Nayarit",
            "Nuevo Leon",
            "Oaxaca",
            "Puebla",
            "Queretaro",
            "Quintana Roo",
            "San Luis Potosi",
            "Sinaloa",
            "Sonora",
            "Tabasco",
            "Tamaulipas",
            "Tlaxcala",
            "Veracruz de Ignacio de la Llave",
            "Yucatan",
            "Zacatecas"};
    char twoLetterState[32][3] =
        {
            "AG", // Aguascalientes
            "BC", // Baja California
            "BS", // Baja California Sur
            "CC", // Campeche
            "CL", // Coahuila de Zaragoza
            "CM", // Colima
            "CS", // Chiapas
            "CH", // Chihuahua
            "DF", // Ciudad de México
            "DG", // Durango
            "GT", // Guanajuato
            "GR", // Guerrero
            "HG", // Hidalgo
            "JC", // Jalisco
            "MC", // México
            "MN", // Michoacán de Ocampo
            "MS", // Morelos
            "NT", // Nayarit
            "NL", // Nuevo León
            "OC", // Oaxaca
            "PL", // Puebla
            "QT", // Querétaro
            "QR", // Quintana Roo
            "SP", // San Luis Potosí
            "SL", // Sinaloa
            "SR", // Sonora
            "TC", // Tabasco
            "TS", // Tamaulipas
            "TL", // Tlaxcala
            "VZ", // Veracruz de Ignacio de la Llave
            "YN", // Yucatán
            "ZS"  // Zacatecas
        };

    printf("LISTA DE ESTADOS DE LOS ESTADOS UNIDOS MEXICANOS\n");
    for (i = 0; i < 32; i++)
    {
        printf("%d.- %s\n", i + 1, states[i]);
    }
    tempNum = validacionNumero("Introduce el estado en el que naciste: ", 1, 32);
    strcpy(state, twoLetterState[tempNum - 1]);
}

char getConsonant(char array[], int startPosition)
{
    int i;
    char tempword;
    for (i = startPosition + 1; array[i] != '\0'; i++)
    {
        tempword = array[i];

        if ((tempword != 'A') && (tempword != 'E') && (tempword != 'I') && (tempword != 'O') && (tempword != 'U'))
        {
            return tempword;
        }
    }

    return 'X';
}

int Compound2(char array[], int n)
{
    char contra[8][6] = {"MA", "MA.", "M.", "M", "JOSE", "J.", "J", "MARIA"};
    char temp[20];
    int i = n;
    int k = n;
    int flag = 1;
    int j;
    int found = 0;
    while (array[i] != '\0' && flag == 1)
    {
        j = 0;
        while (array[k] != ' ' && array[k] != '\0')
        {
            temp[j] = array[k];
            j++;
            k++;
        }
        temp[j] = '\0';

        flag = 0;
        found = 0;

        for (int l = 0; l < 8; l++)
        {
            if (strcmp(temp, contra[l]) == 0)
            {
                n = k + 1;
                flag = 1;
                found = 1;
            }
        }

        if (!found)
        {
            k++;
            i++;
        }
    }

    return n;
}

int nameCompound(char array[])
{
    char contra2[27][6] = 
    {"DA", "DAS", "DE", "DEL", "DER", 
    "DI", "DIE", "DD", "EL", "LA", 
    "LOS", "LAS", "LE", "LES", "MAC", 
    "MC", "VAN", "VON", "Y", "MA", 
    "MA.", "M.", "M", "JOSE", "J.", "J", "MARIA"};
    char temp[20];
    int num;
    int i = 0;
    int k = 0;
    int n = 0;
    int l = 0;
    int flag = 1;
    int found = 0;
    int j;

    while (array[i] != '\0' && (flag == 1))
    {
        j = 0;
        while (array[k] != ' ' && array[k] != '\0')
        {
            temp[j] = array[k];
            j++;
            k++;
        }
        temp[j] = '\0';

        flag = 0;
        found = 0;

        for (l = 0; l < 27; l++)
        {
            if (strcmp(temp, contra2[l]) == 0)
            {
                n += strlen(temp) + 1;
                flag = 1;
                found = 1;
            }
        }

        if (found == 0)
        {
            k++;
        }
        k++;
        i++;
    }

    num = Compound2(array, n);
    return num;
}

void fourLetters(char name[], char LastName1[], char LastName2[], char firstFourLetters[5], int flagLastName1, int flagLastName2, char consonants[])
{
    int startPosition, startPosition2, startPosition3;
    startPosition = nameCompound(LastName1);
    startPosition2 = nameCompound(LastName2);
    startPosition3 = nameCompound(name);
    if (flagLastName1)
    {
        firstFourLetters[0] = LastName1[startPosition];
        firstFourLetters[1] = noVowelsApComp(LastName1, startPosition);
        consonants[0] = getConsonant(LastName1, startPosition);
    }
    else
    {
        printf("No ingresaste apellido paterno\n");
        firstFourLetters[0] = 'X';
        firstFourLetters[1] = 'X';
        consonants[0] = 'X';
    }
    if (flagLastName2)
    {
        firstFourLetters[2] = LastName2[startPosition2];
        consonants[1] = getConsonant(LastName2, startPosition2);
    }
    else
    {
        printf("No ingresaste apellido materno\n");
        firstFourLetters[2] = 'X';
        consonants[1] = 'X';
    }
    firstFourLetters[3] = name[nameCompound(name)];
    firstFourLetters[4] = '\0';

    consonants[2] = getConsonant(name, startPosition3);
    consonants[3] = '\0';
    if (antiSonant(firstFourLetters))
    {
        firstFourLetters[1] = 'X';
    }
}

char noVowelsApComp(char array[], int startPosition)
{
    int positionVowel;
    positionVowel = vocal(array, startPosition);
    if (positionVowel == -1)
    {
        return 'X';
    }
    return array[positionVowel];
}

int antiSonant(char array[])
{
    int i;
    char antisonant[81][5] = 
    {"BACA", "BAKA", "BUEI", "BUEY", "CACA", 
    "CACO", "CAGA", "CAGO", "CAKA", "CAKO", 
    "COGE", "COGI", "COJA", "COJE", "COJI", 
    "COJO", "COLA", "CULO", "FALO", "FETO", 
    "GETA", "GUEI", "GUEY", "JETA", "JOTO", 
    "KACA", "KACO", "KAGA", "KAGO", "KAKA", 
    "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", 
    "KOJI", "KOJO", "KOLA", "KULO", "LILO", 
    "LOCA", "LOCO", "LOKA", "LOKO", "MAME", 
    "MAMO", "MEAR", "MEAS", "MEON", "MIAR", 
    "MION", "MOCO", "MOKO", "MULA", "MULO", 
    "NACA", "NACO", "PEDA", "PEDO", "PENE", 
    "PIPI", "PITO", "POPO", "PUTA", "PUTO", 
    "QULO", "RATA", "ROBA", "ROBE", "ROBO", 
    "RUIN", "SENO", "TETA", "VACA", "VAGA", 
    "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    for (i = 0; i < 81; i++)
    {
        if (strcmp(array, antisonant[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isLapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}