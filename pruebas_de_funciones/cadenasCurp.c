#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char vocal(char cad[])
{
    int i = 1, n;
    n = strlen(cad);
    while (i < n)
    {
        if (cad[i] == 'A' || cad[i] == 'E' || cad[i] == 'I' || cad[i] == 'O' || cad[i] == 'U' || cad[i] == '/' || cad[i] == '-' || cad[i] == '.')
        {
            return cad[i];
        }
        i++;
    }
    return 'X';
}

char consonante(char cad[])
{
    int n, i;
    n = strlen(cad);
    i = 1;
    while (i < n)
    {
        if (cad[i] != 'A' && cad[i] != 'E' && cad[i] != 'I' && cad[i] != 'O' && cad[i] != 'U' && cad[i] != ' ')
        {   
            return cad[i];
        }
        i++;
    }
    return 'X';
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

void validacionTexto(char msg[], char cadena[], int n)  // funcion para validar texto
{
    int invalido=0, contador=0;
    int i;
    do{
        invalido=0;
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);
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

int main()
{
    // int dia = 10;
    // char cadenaDia[2];
    int n=20, m=18;
    char apellidoPaterno[n];
    char apellidoMaterno[n];
    char nombre1[n];
    char nombre2[n];
    int ap, am, nom2, sexo, est;
    char curp[m];

    char iniEstado[33][3] = 
    {"AS", "BC", "BS", "CC", "CS", 
    "CH", "CL", "CM", "DG", "GT", 
    "GR", "HG", "JC", "MC", "MN", 
    "MS", "NT", "NL", "OC", "PL", 
    "QT", "QR", "SP", "SL", "SR", 
    "TC", "TS", "TL", "VZ", "YN", 
    "ZS", "DF", "NE"};

    ap = validacionNumero("tienes apellido paterno?\n1- si\n2- no", 1, 2);
    if(ap ==1)
    {
        validacionTexto("dame tu apellido paterno", apellidoPaterno, n);
        curp[0] = apellidoPaterno[0];
        curp[1] = vocal(apellidoPaterno);
        curp[13] = consonante(apellidoPaterno);
    }
    else
    {
        curp[0] = 'X';
        curp[1] = 'X';
        curp[13] = 'X';
    }
    am=validacionNumero("tienes apellido materno?\n1- si\n2- no", 1, 2);
    if(am == 1)
    {
        validacionTexto("dame tu apellido materno", apellidoMaterno, n);
        curp[2] = apellidoMaterno[0];
        curp[14] = consonante(apellidoMaterno);
    }
    else
    {
        curp[2] = 'X';
        curp[14] = 'x';
    }
    validacionTexto("dame tu primer nombre", nombre1, n);
    curp[3] = nombre1[0];
    curp[15] = consonante(nombre1);

    nom2 = validacionNumero("tienes mas nombres?\n1- si\n2- no", 1, 2);
    if(nom2 == 1)
    {
        validacionTexto("dame tus demas nombres", nombre2, n);
    }

    sexo = validacionNumero("dame tu sexo\n1-hombre\n2- mujer", 1, 2);
    if(sexo == 1)
    {
        curp[10] = 'H';
    }
    else
    {
        curp[10] = 'M';
    }

    estados();
    est = validacionNumero("dame tu estado (numero)\n en caso de ser extranjero numero 33", 1, 33);
    curp[11] = iniEstado[est-1][0];
    curp[12] = iniEstado[est-1][1];


    printf("%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c\n%c", curp[0], curp[1], curp[2], curp[3], curp[10], curp[11], curp[12], curp[13], curp[14], curp[15]);

    return 0;
}