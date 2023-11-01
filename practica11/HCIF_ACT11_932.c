




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
    int estado;
    char curp[18]; } Talumns;


int msg(void);
int msg2(void);
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
void imprimirEncontrado(Talumns reg[], int buscar);
void imprimirRegistro(Talumns reg[], int posicion);
void ordenarAscendente(Talumns reg[], int n);
int busquedaBinaria(Talumns reg[], int izquierda, int derecha);
void generarCurpManual(Talumns reg[], int i);
void generarCurpAleatoria(Talumns reg[], int posicion, int n);
void archivoTexto(Talumns reg[], int posicion);

void quicksort(Talumns reg[], int menor, int mayor);
int particion(Talumns reg[], int menor, int mayor);
void cambiar(Talumns reg[], int i, int j);

char primerVocal(char cadena[]);
char segundaConsonante(char cadena[]);
int bisiesto(int anio);
// int antisonante(char cadena[], char antisonantes[][5], int numAntisonantes);
void omitirNombres(char nombre[], char partes[][7]);
void omitirPartes(char apellido[], char partes[][6]);


int main()
{
    srand(time(NULL));
    
    int op, op2, n=2000;
    int posicion = 0, aumentar;
    int bandera = 0;
    Talumns reg[n];
    
    do{
        
        op = msg();

        switch(op)
        {
            case 1:
            op2 = msg2();
            switch(op2)
            {
                case 1:
                aumentar = 1;
                if((posicion + aumentar) > n)
                {
                    aumentar = n - posicion;
                }
                if(aumentar == 0)
                {
                    printf("registro lleno.\n");
                }
                else
                {
                    generarCurpManual(reg, posicion);
                    posicion = posicion + aumentar;
                }
                break;

                case 2:
                aumentar = 300;
                if((posicion + aumentar) > n)
                {
                    aumentar = n - posicion;
                }
                if(aumentar == 0)
                {
                    printf("registro lleno.\n");
                }
                else
                {
                    generarCurpAleatoria(reg, posicion, aumentar);
                    posicion = posicion + aumentar;
                }
                break;
            }
            break;

            case 2:
            eliminarRegistro(reg, posicion);
            break;

            case 3:
            buscarElemento(reg, posicion, bandera);
            break;

            case 4:
            if(posicion > 500)
            {
                printf("quicksort\n");
                quicksort(reg, 0, posicion-1);
            }
            else
            {
                printf("bubblesort\n");
                ordenarAscendente(reg, posicion);
            }
            bandera = 1;
            break;

            case 5:
            imprimirRegistro(reg, posicion);
            break;

            case 6:
            archivoTexto(reg, posicion);
            break;
        }
    }while(op != 7);

    return 0;
}

int msg()
{
    int op;
    printf("MENU\n");
    printf("1.- generar curp\n");
    printf("2.- eliminar registro\n");
    printf("3.- buscar\n");
    printf("4.- ordenar\n");
    printf("5.- imprimir\n");
    printf("6.- archivo de texto\n");
    printf("7.- terminar\n");
    op = validacionNumero("Selecciona una opcion: ", 1, 7);
    return op;
}

int msg2()
{
    int op;
    printf("MENU\n");
    printf("1.- manual (1 registro)\n");
    printf("2.- automatico (100 registros)\n");
    printf("3) regresar\n");
    op = validacionNumero("Selecciona una opcion: ", 1, 3);
    return op;
}

void generarCurpManual(Talumns reg[], int i)
{
    // char nombre[50];
    // char apellidoPaterno[50];
    
    int opcion1;
    int opcion2;
    // char apellidoMaterno[50];
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

void generarCurpAleatoria(Talumns reg[], int posicion, int n)
{
    int i;

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
    int ap, am, no, mat, nomgen;
    int rango, li, ls;
    
    for(i = posicion; i < (posicion + n); i++)
    {
        reg[i].status = 1;
        li = 300000, ls = 399999;
        rango = (ls - li) +1;
        do{
            mat = (rand()% rango) + li;
        }while(existeValor(reg, posicion, mat) != -1);

        reg[i].matricula = mat;
        
        nomgen = (rand()%2) +1;
        if(nomgen == 1)
        {
            no = (rand()%49)+1;
            strcpy(reg[i].nombres.nombre, nombresHombre[no]);
        }
        else
        {
            no = (rand()%49)+1;
            strcpy(reg[i].nombres.nombre, nombresMujer[no]);
        }

        omitirNombres(reg[i].nombres.nombre, nombresCortos);
        omitirNombres(reg[i].nombres.nombre, nombresCortos);
        omitirPartes(reg[i].nombres.nombre, partes);
        omitirPartes(reg[i].nombres.nombre, partes);
        sinEspacio(reg[i].nombres.nombre);
        
        opcion1 = 1;
        if (opcion1 == 1)
        {
            ap = (rand()%50)+1;
            
            strcpy(reg[i].nombres.apellidoPaterno, apellidos[ap]);

            omitirPartes(reg[i].nombres.apellidoPaterno, partes);
            omitirPartes(reg[i].nombres.apellidoPaterno, partes);
            sinEspacio(reg[i].nombres.apellidoPaterno);
        }
        
        opcion2 = 1;
        if (opcion2 == 1)
        {
            am = (rand()%50)+1;
            
            strcpy(reg[i].nombres.apellidoMaterno, apellidos[am]);
            
            omitirPartes(reg[i].nombres.apellidoMaterno, partes);
            omitirPartes(reg[i].nombres.apellidoMaterno, partes);
            sinEspacio(reg[i].nombres.apellidoMaterno);
        }

        anio = (rand()%(2024 - 1900)) +1900;
        
        sprintf(canio, "%d", anio);
        reg[i].fecha.anio = anio;
        

        mes = (rand()%12) +1;
        sprintf(Cmes, "%d", mes);
        reg[i].fecha.mes = mes;
        
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
        sprintf(Cdia, "%d", dia);
        reg[i].fecha.dia = dia;

        gen = nomgen;
        reg[i].sexo = gen;

        estado = (rand()%33) +1; 
    
        strcpy(est, iniEstado[estado-1]);
        reg[i].estado = estado;

        reg[i].edad = 2023 - anio;
        
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

        reg[i].curp[3] = reg[i].nombres.nombre[0];
        reg[i].curp[4] = canio[2];
        reg[i].curp[5] = canio[3];

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

        if (dia < 10)
        {
            reg[i].curp[8] = '0';
            reg[i].curp[9] = Cdia[0];
        }
        else
        {
            reg[i].curp[8] = Cdia[0];
            reg[i].curp[9] = Cdia[1];
        }

        if(gen == 1)
        {
            reg[i].curp[10] = 'H';
        }
        else
        {
            reg[i].curp[10] = 'M';
        }

        reg[i].curp[11] = est[0];
        reg[i].curp[12] = est[1];

        if (!segundaConsonante(reg[i].nombres.apellidoPaterno) || opcion1 == 2)
        {
            reg[i].curp[13] = 'X';
        }
        else
        {
            reg[i].curp[13] = segundaConsonante(reg[i].nombres.apellidoPaterno);
        }

        if (!segundaConsonante(reg[i].nombres.apellidoMaterno) || opcion2 == 2)
        {
            reg[i].curp[14] = 'X';
        }
        else
        {
            reg[i].curp[14] = segundaConsonante(reg[i].nombres.apellidoMaterno);
        }

        if (!segundaConsonante(reg[i].nombres.nombre))
        {
            reg[i].curp[15] = 'X';
        }
        else
        {
            reg[i].curp[15] = segundaConsonante(reg[i].nombres.nombre);
        }

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
        li= 0, ls=9;
        ultimoDigito = (rand()%rango);
        sprintf(cultimoDigito, "%d", ultimoDigito);
        reg[i].curp[17] = cultimoDigito[0];

        curp[18] = '\0';

        if (antisonante(curp, antisonantes, sizeof(antisonantes) / sizeof(antisonantes[0])))
        {
            curp[1] = 'X';
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
        imprimirEncontrado(reg, buscar);
    }
}

void imprimirEncontrado(Talumns reg[], int buscar)
{
    printf("matricula: ");
    printf("%d\n", reg[buscar].matricula);
    printf("nombre: ");
    printf("%s\n", reg[buscar].nombres.nombre);
    printf("apellido paterno: ");
    printf("%s\n", reg[buscar].nombres.apellidoPaterno);
    printf("apellido materno: ");
    printf("%s\n", reg[buscar].nombres.nombre);
    printf("fecha nacimiento: ");
    printf("%d-%d-%d\n", reg[buscar].fecha.dia, reg[buscar].fecha.mes, reg[buscar].fecha.anio);
    printf("edad: ");
    printf("%d\n", reg[buscar].edad);
    printf("sexo: ");
    if(reg[buscar].sexo == 1)
    {
        printf("hombre\n");
    }
    else
    {
        printf("mujer\n");
    }
    printf("lugar nac: ");
    printf("%s\n", iniEstado[reg[buscar].estado]);
    printf("curp: ");
    for(int j=0; j<18; j++)
    {
        printf("%c", reg[buscar].curp[j]);
    }
    printf("\n");
}

void imprimirRegistro(Talumns reg[], int posicion)
{
    int i;
    printf("%6s %6s %10s %20s %20s %20s %4s %8s %19s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo", "curp");
    for(i=0; i < posicion; i++)
    {
        if(reg[i].status == 1)
        {
            if(i % 40 == 0)
            {
                system("PAUSE");
            }
            printf("%6d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].nombres.apellidoPaterno, reg[i].nombres.apellidoMaterno, reg[i].nombres.nombre, reg[i].edad);
            if(reg[i].sexo == 1)
            {
                printf(" %8s ", "HOMBRE");
            }
            else
            {
                printf(" %8s ", "MUJER");
            }
            for(int j=0; j<18; j++)
            {
                printf("%c", reg[i].curp[j]);
            }
            printf("\n");
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

void cambiar(Talumns reg[], int i, int j)
{
    Talumns temp = reg[i];
    reg[i] = reg[j];
    reg[j] = temp;
}

int particion(Talumns reg[], int menor, int mayor)
{
    Talumns pivot;
    pivot.matricula = reg[mayor].matricula;
    int i = menor - 1;

    for (int j = menor; j <= mayor - 1; j++)
    {
        if (reg[j].matricula <= pivot.matricula)
        {
            i++;
            cambiar(reg, i, j);
        }
    }
    cambiar(reg, i + 1, mayor);
    return i + 1;
}

void quicksort(Talumns reg[], int menor, int mayor)
{
    if (menor < mayor)
    {
        int pi = particion(reg, menor, mayor);

        quicksort(reg, menor, pi - 1);
        quicksort(reg, pi + 1, mayor);
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

void archivoTexto(Talumns reg[], int posicion)
{
    FILE *texto = fopen("C:\\Users\\elvan\\Downloads\\uabc_3_sem\\programacion estructurada\\repositorio\\practica11\\registro.txt", "w");

    int i;
    fprintf(texto, "%3s %6s %10s %20s %20s %20s %4s %8s %19s\n", "No.", "status", "matricula", "apellido paterno", "apellido materno", "nombre", "edad", "sexo", "curp");
    for(i=0; i<posicion; i++)
    {
        if(reg[i].status == 1)
        {
            fprintf(texto, "%3d %6d %10d %20s %20s %20s %4d", i+1, reg[i].status, reg[i].matricula, reg[i].nombres.apellidoPaterno, reg[i].nombres.apellidoMaterno, reg[i].nombres.nombre, reg[i].edad);
            if(reg[i].sexo == 1)
            {
                fprintf(texto, " %8s ", "HOMBRE");
            }
            else
            {
                fprintf(texto, " %8s ", "MUJER");
            }
            for(int j=0; j<18; j++)
            {
                fprintf(texto, "%c", reg[i].curp[j]);
            }
            fprintf(texto, "\n");
        }
    }

    fclose(texto);

    return;
}
