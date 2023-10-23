



#include "ivan copy.h"


void menu();
int msg();

void datosCurp(char curp[], char nom[], char apPat[], char apMat[], char consonantes[], int dia, int mes, int anio, int sexo, int estado, int  n, int m);
void imprimir(char curp[], char consonantes[]);
void inicioCurp(char curp[], char nom[], char apPat[], char apMat[], char consonantes[], int bap1, int bap2, int bnom);
void generarCurp();
void estados();
int bisiesto(int anio);
int compuesto(char array[]);
char vocalDespues(char array[], int startPosition);
char consonanteFinal(char array[], int startPosition);
int antisonantes(char array[]);
int compuestoAuxiliar(char array[], int n);

void apellidoPaterno(char apPat[], int m);
void apellidoMaterno(char apMat[], int m);
void nombre(char nom[], int n);
void fecha(int anio, int mes, int dia);
void sexo(int sex);
void estado(int est);

int main()
{
    menu();
    return 0;
}

int msg()
{
    int op;
    printf("INGRESA LOS SIGUIENTES DATOS PARA PODER OBTENER LA CURP\n");
    printf("1.- generar curp\n");
    printf("0.- Salir\n");
    op = validacionNumero("Selecciona una opcion: ", 1, 2);
    return op;
}

void menu()
{
    int op;
    int n = 50, m = 30;
    char nom[n], apPat[m], apMat[m], curp[18];
    char consonantes[4];
    int dia, mes, anio, estado, sexo;
    // char curp4letras[5];
    // char consonantes[4];
    // int flagName = 0;
    // int flagLastName1 = 0;
    // int flagLastName2 = 0;
    // int flagBirthday = 0;
    // int flagSex = 0;
    // int flagState = 0;
    char iniEstado[33][3] = 
    {"AS", "BC", "BS", "CC", "CS", 
    "CH", "CL", "CM", "DG", "GT", 
    "GR", "HG", "JC", "MC", "MN", 
    "MS", "NT", "NL", "OC", "PL", 
    "QT", "QR", "SP", "SL", "SR", 
    "TC", "TS", "TL", "VZ", "YN", 
    "ZS", "DF", "NE"};

    do
    {
        op = msg();
        switch(op)
        {
            case 1:
            datosCurp(curp, nom, apPat, apMat, consonantes, dia, mes, anio, sexo, estado, n, m);
            // apellidoPaterno(apPat, m);
            // apellidoMaterno(apMat, m);
            // nombre(nom, n);
            // fecha(anio, mes, dia);
            // sexo(sex);
            // estado(est);
            imprimir(curp, consonantes);
            break;
        }
    } while (op != 2);
    
}


void datosCurp(char curp[], char nom[], char apPat[], char apMat[], char consonantes[], int dia, int mes, int anio, int sexo, int estado, int  n, int m)
{
    int bnom = 0;
    int bap1 = 0;
    int bap2 = 0;
    int tiene1, tiene2, tiene3, anio2, random;
    char est[3], cRandom[2];
    // char consonantes[4];
    char canio[4], cmes[2], cdia[2];


    char iniEstado[33][3] = 
    {"AS", "BC", "BS", "CC", "CS", 
    "CH", "CL", "CM", "DG", "GT", 
    "GR", "HG", "JC", "MC", "MN", 
    "MS", "NT", "NL", "OC", "PL", 
    "QT", "QR", "SP", "SL", "SR", 
    "TC", "TS", "TL", "VZ", "YN", 
    "ZS", "DF", "NE"};


    tiene1 = validacionNumero("Tienes apellido paterno? (1.- Si, 0.- No): ", 1, 2);
    if(tiene1)
    {
        validacionTexto("dame tu apellido paterno", apPat, n);
        bap1 = 1;
    }
    tiene2 = validacionNumero("Tienes apellido materno? (1.- Si, 0.- No): ", 1, 2);
    if(tiene2)
    {
        validacionTexto("dame tu apellido materno", apMat, n);
        bap2 = 1;
    }

    tiene3 = validacionNumero("Tienes nombres? (1.- Si, 0.- No): ", 1, 2);
    {
        validacionTexto("dame tus nombres", nom, n);
        bnom = 1;
    }

    anio = validacionNumero("Ingresa el anio de tu nacimiento", 1894, 2023);
    
    sprintf(canio, "%d", anio);
    if(anio < 2000)
    {
        curp[4] = canio[2];
        curp[5] = canio[3];
        curp[16] = '0';
    }
    else
    {
        curp[4] = canio[2];
        curp[5] = canio[3];
        curp[16] = 'A';
    }

    if (anio == 2023)
    {
        mes = validacionNumero("Ingresa el mes de tu nacimiento: ", 1, 10);
        
        if (mes == 2)
        {
            dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 28);
        }
        else
        {
            if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            {
                dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 30);
            }
            else
            {
                if(mes == 10)
                {
                    dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 24);
                }
                else
                {
                    dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 31);
                }
            }
        }
    }
    else
    {
        anio2 = bisiesto(anio);
        if (anio2)
        {
            mes = validacionNumero("Ingresa el mes de tu nacimiento: ", 1, 12);
            
            if (mes == 2)
            {
                dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 29);
            }
            else
            {
                if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                {
                    dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 30);
                }
                else
                {
                    dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 31);
                }
            }
        }
        else
        {
            mes = validacionNumero("Ingresa el mes de tu nacimiento: ", 1, 12);
            
            if (mes == 2)
            {
                dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 28);
            }
            else
            {
                if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                {
                    dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 30);
                }
                else
                {
                    dia = validacionNumero("Ingresa el dia de tu nacimiento: ", 1, 31);
                }
            }
        }
    }

    sprintf(cmes, "%d", mes);
    if(mes < 10)
    {
        curp[6] = '0';
        curp[7] = cmes[0];
    }
    else
    {
        curp[6] = cmes[0];
        curp[7] = cmes[1];
    }
    sprintf(cdia, "%d", dia);
    if(dia < 10)
    {
        curp[8] = '0';
        curp[9] = cdia[0];
    }

    sexo = validacionNumero("dame tu sexo.\n1- hombre.\n0- mujer", 0, 1);
    if(sexo == 1)
    {
        curp[10] = 'H';
    }
    else
    {
        curp[10] = 'M';
    }
    

    estados();
    estado = validacionNumero("escribe el numero de tu estado.\nsi eres extranjero selecciona el No. 33.", 1, 33);
    strcpy(est, iniEstado[estado-1]);
    curp[11] = est[0];
    curp[12] = est[1];

    random = (rand()%9);
    cRandom[0] = random;
    curp[17] = random;

    inicioCurp(curp, nom, apPat, apMat, consonantes, bap1, bap2, bnom);
    // imprimir(nom, apPat, apMat, est, dia, mes, anio, sexo, n, m);

}

void inicioCurp(char curp[], char nom[], char apPat[], char apMat[], char consonantes[], int bap1, int bap2, int bnom)
{
    
    int ApellidoPat, ApellidoMat, Nombre, posNombresProhibidos;

    // Calcular las posiciones iniciales para los apellidos y el nombre.
    ApellidoPat = compuesto(apPat);
    ApellidoMat = compuesto(apMat);
    Nombre = compuesto(nom);

    if (bap1)
    {
        curp[0] = apPat[ApellidoPat];
        curp[1] = vocalDespues(apPat, ApellidoPat);
        consonantes[0] = consonanteFinal(apPat, ApellidoPat);
    }
    else
    {
        curp[0] = 'X';
        curp[1] = 'X';
        consonantes[0] = 'X';
    }

    if (bap2)
    {
        curp[2] = apMat[ApellidoMat];
        consonantes[1] = consonanteFinal(apMat, ApellidoMat);
    }
    else
    {
        curp[2] = 'X';
        consonantes[1] = 'X';
    }

    posNombresProhibidos = compuesto(nom);
    curp[3] = nom[posNombresProhibidos];

    // curp[4] = '\0';   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    consonantes[2] = consonanteFinal(nom, Nombre);

    consonantes[3] = '\0';

    if (antisonantes(curp))
    {
        curp[1] = 'X';
    }


}

char vocalDespues(char array[], int startPosition)
{
    int positionVowel;
    positionVowel = vocal(array, startPosition);
    if (positionVowel == -1)
    {
        return 'X';
    }
    return array[positionVowel];
}


int compuestoAuxiliar(char array[], int n)
{
    char contra[8][6] = {"MA", "MA.", "M.", "M", "JOSE ", "J.", "J", "MARIA"};
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

int compuesto(char array[])
{
    char contra2[27][6] = 
    {"DA", "DAS", "DE", "DEL", "DER", 
    "DI", "DIE", "DD", "EL", "LA", 
    "LOS", "LAS", "LE", "LES", "MAC", 
    "MC", "VAN", "VON", "Y", "MA", 
    "MA.", "M.", "M", "JOSE ", "J.", 
    "J", "MARIA"};

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

    num = compuestoAuxiliar(array, n);
    return num;
}

char consonanteFinal(char array[], int startPosition)
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

int antisonantes(char array[])
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
    "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", 
    "WUEY"};
    for (i = 0; i < 81; i++)
    {
        if (strcmp(array, antisonant[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}






void imprimir(char curp[], char consonantes [])
{
    char iniEstado[33][3] = 
    {"AS", "BC", "BS", "CC", "CS", 
    "CH", "CL", "CM", "DG", "GT", 
    "GR", "HG", "JC", "MC", "MN", 
    "MS", "NT", "NL", "OC", "PL", 
    "QT", "QR", "SP", "SL", "SR", 
    "TC", "TS", "TL", "VZ", "YN", 
    "ZS", "DF", "NE"};


    // printf("%s", curp);

    printf("%c", curp[0]);
    printf("%c", curp[1]);
    printf("%c", curp[2]);
    printf("%c", curp[3]);
    printf("%c", curp[4]);
    printf("%c", curp[5]);
    printf("%c", curp[6]);
    printf("%c", curp[7]);
    printf("%c", curp[8]);
    printf("%c", curp[9]);
    printf("%c", curp[10]);
    printf("%c", curp[11]);
    printf("%c", curp[12]); //
    printf("%c", consonantes[0]);
    printf("%c", consonantes[1]);
    printf("%c", consonantes[2]);
    printf("%c", curp[16]);
    printf("%c\n", curp[17]);
    
}

int bisiesto(int anio)
{
    if (anio % 4 == 0)
    {
        if (anio % 100 == 0)
        {
            if (anio % 400 == 0)
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

void estados()
{
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
}