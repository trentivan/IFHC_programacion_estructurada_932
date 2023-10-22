#include "ivan.h"
// Hernandez Ceseña Ivan Fernando  373077
// 20/10/2023
//
// HCIF_ACT9_3/4_932

void msg(void);
void menu(void);

void generarCurp(void);
void datosCurp(char apellidoPaterno[], char apellidoMaterno[], char nombre1[], char nombre2[], char sexo[], int n);
void meses(void);
void estados(void);
void curpNombre(char curp [], int n, char apellidoPaterno[], char apellidoMaterno[], char nombre1[], char nombre2[]);
void curpFecha(char curp[], char cadenaDia[], char cadenaMes[], char cadenaAnio[], int dia, int mes, int anio);
void imprimirCurp(char curp[], int n);

int main()
{
    menu();

    return 0;
}

void msg()
{
    printf("MENU\n");
    printf("1) generar CURP\n");
    printf("2) terminar programa\n");
}

void menu()
{
    int op;

    do{
        msg();
        op= validacionNumero("elije una opcion", 1, 2);

        switch(op)
        {
            case 1:
            generarCurp();
            break;
        }

    }while(op != 0);
}

void generarCurp()
{
    int n=50, m=18;
    char apellidoPaterno[n];
    char apellidoMaterno[n];
    char nombre1[n];
    char nombre2[n];
    char sexo[6];
    char cadenaDia[3], cadenaMes[3], cadenaanio[5];
    char curp[m];

    for(int i=0; i<n; i++)
    {
        curp[i] = "0";
    }

    datosCurp(apellidoPaterno, apellidoMaterno, nombre1, nombre2, sexo, n);
    curpNombre(curp, m, apellidoPaterno, apellidoMaterno, nombre1, nombre2);
    imprimirCurp(curp, m);

}

void datosCurp(char apellidoPaterno[], char apellidoMaterno[], char nombre1[], char nombre2[], char sexo[], int n)
{
    int dia, mes, anio, sex;
    int cadenaDia[2], cadenaMes[2], cadenaAnio[4];
    int tener;

    char prepos[19][5] = 
    {"DA ", "DE ", "DI ", "DD ", "EL ", 
    "LA ", "LE ", "MC ", "DAS ", "DEL ", 
    "DER ", "DIE ", "LOS ", "LAS ", "LES ", 
    "MAC ", "VAN ", "VON ", "Y "};

    anio = validacionNumero("dame tu anio de nacimiento (cuatro digitos)",1910,2023);
    meses();
    mes = validacionNumero("dame tu mes de nacimiento", 1, 12);

    if(mes == 1)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 31);
    }

    if(((anio % 4 == 0) && anio / 100 != 0) || anio % 1000 == 0)
    {
        if(mes == 2)
        {
            dia = validacionNumero("dame tu dia de nacimiento", 1, 29);
        }
    }
    else
    {
        if(mes == 2)
        {
            dia = validacionNumero("dame tu dia de nacimiento",1, 28);
        }
    }
    if(mes == 3)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 31);
    }
    if(mes == 4)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 30);
    }
    if(mes == 5)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 31);
    }
    if(mes == 6)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 30);
    }
    if(mes ==7)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 31);
    }
    if(mes == 8)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 31);
    }
    if(mes == 9)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 30);
    }
    if(mes == 10)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 31);
    }
    if(mes == 11)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 30);
    }
    if(mes == 12)
    {
        dia = validacionNumero("dame tu dia de nacimiento", 1, 31);
    }

    tener = validacionNumero("tienes apellido paterno?\n1- si.\n2- no", 1, 2);
    if(tener == 1)
    {
        validacionTexto("dame tu apellido paterno", apellidoPaterno, n);
    }
    tener = validacionNumero("tienes apellido materno?\n1- si.\n2- no", 1, 2);
    if(tener == 1)
    {
        validacionTexto("dame tu apellido materno", apellidoMaterno, n);
    }
    validacionTexto("dame tu primer nombre", nombre1, n);
    tener = validacionNumero("tienes mas nombres?\n1- si.\n2- no.", 1, 2);
    if(tener == 1)
    {
        validacionTexto("dame tus demas nombre", nombre2, n);
    }
    
    sex = validacionNumero("selecciona tu sexo.\n1- hombre\n2- mujer", 1, 2);
    if(sex == 1)
    {
        strcpy(sexo, "hombre");
        // sexo[6] = "HOMBRE";
    }
    else
    {
        strcpy(sexo, "mujer");
        // sexo[6] = "MUJER";
    }

    sprintf(cadenaDia, "%02d", dia);
    sprintf(cadenaMes, "%02d", mes);

    printf("%20s %20s %21s %3s %3s %5s %6s\n", "apellido paterno", "apellido materno", "nombres", "dia", "mes", "anio", "sexo");
    printf("%20s %20s %10s %10s %3s %3s %2s %6s\n", apellidoPaterno, apellidoMaterno, nombre1, nombre2, cadenaDia, cadenaMes, cadenaAnio, sexo);
}

void meses()
{
    system("cls");
    printf("1. Enero\n");
    printf("2. Febrero\n");
    printf("3. Marzo\n");
    printf("4. Abril\n");
    printf("5. Mayo\n");
    printf("6. Junio\n");
    printf("7. Julio\n");
    printf("8. Agosto\n");
    printf("9. Septiembre\n");
    printf("10. Octubre\n");
    printf("11. Noviembre\n");
    printf("12. Diciembre\n");
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

void curpNombre(char curp [], int n, char apellidoPaterno[], char apellidoMaterno[], char nombre1[], char nombre2[])
{
    curp[0]= apellidoPaterno[0];
    curp[1]= apellidoPaterno[2];
    curp[2]= apellidoMaterno[1];
    curp[3]= nombre1[0];
}

void curpFecha(char curp[], char cadenaDia[], char cadenaMes[], char cadenaAnio[], int dia, int mes, int anio)
{
    itoa(dia, cadenaDia, 10);
    itoa(mes, cadenaMes, 10);
    itoa(anio, cadenaAnio, 10);
    if(dia < 10)
    {
        curp[4] = "0";
        curp[5] = cadenaDia[0];
    }
    else
    {
        curp[4] = cadenaDia[0];
        curp[4] = cadenaDia[1];
    }
    if(mes < 10)
    {
        curp[6] = "0";
        curp[7] = cadenaMes[0];
    }
    else
    {
        curp[4] = cadenaMes[0];
        curp[4] = cadenaMes[1];
    }
    if(anio >= 2000)
    {
        curp[16] = "A";
        curp[8] = cadenaAnio[2];
        curp[9] = cadenaAnio[3];
    }
    else
    {
        curp[16] = "0";
        curp[8] = cadenaAnio[2];
        curp[9] = cadenaAnio[3];
    }
}

void finalCurp()
{

}

void imprimirCurp(char curp[], int n)
{
    int i;
    printf("%s\n", curp);
}
