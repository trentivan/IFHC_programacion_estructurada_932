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
int getIndexFile(Tindex reg[], int n);
int fillIndexRegister(/*Tindex index[]*/Twrkr reg[]);
void agregar(Twrkr reg[], Tindex reg2[], int posicion, int n);
void eliminar(Twrkr registro[], Tindex reg2[], int posicion, int ordenar);
void buscar(Twrkr registro[], Tindex reg2[], int posicion, int ordenar);
void ordenar(Tindex reg[], int posicion , int ordenado, int preordenado);
void imprimirOriginal(Tindex reg[], int posicion);
void imprimirOrdenado(Tindex reg[], int posicion, int ordenado, int preordenado);
void archivoTxt(Tindex reg[], int posicion, int ordenado, int preordenado);
void empaquetado();


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
void ordenarVectorAscendente(Tindex reg[], int n);
void cambiar(Tindex reg[], int i, int j);
int particion(Tindex reg[], int menor, int mayor);
void quicksort(Tindex reg[], int menor, int mayor);
void merge(Tindex arr[], int l, int m, int r);
void mergeSort(Tindex arr[], int l, int r);


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
    printf("6) imprimir registro archivo ordenado\n");
    printf("7) generar archivo de texto\n");
    printf("8) empaquetar\n");
    printf("9) salir\n");
}

void menu(int n)
{
    // printf("%d\n", n);
    Twrkr reg[n];
    Tindex reg2[n];
    int posicion = 0;
    int op;
    int inc = 1;
    int ordenado = 0;
    int preordenado = 0;

    posicion = getIndexFile(reg2, n); 
    //cargar(reg, reg2, posicion);//
    // imprimir(reg, posicion);
    // imprimirReg2(reg2, posicion);

    do
    {
        msg();
        op = validacionNumero("elije una opcion", 1, 9);

        switch(op)
        {
            case 1:
            // fillIndexRegister(/*reg2*/reg);
            
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
                // fillIndexRegister(/*reg2*/reg);
                // imprimir1(reg, posicion);
                // // imprimirReg2_1(reg2, posicion);
                posicion = posicion + inc;
                ordenado = 0;
                preordenado++;
                if(preordenado > 5)
                {
                    ordenado = 0;
                }
            }
            break;

            case 2:
            eliminar(reg, reg2, posicion, ordenado);
            break;

            case 3:
            buscar(reg, reg2, posicion, ordenado);
            break;

            case 4:
            ordenar(reg2, posicion, ordenado, preordenado);
            ordenado = 1;
            break;

            case 5:
            imprimirOriginal(reg2, posicion);
            break;

            case 6:
            imprimirOrdenado(reg2, posicion, ordenado, preordenado);
            break;

            case 7:
            archivoTxt(reg2, posicion, ordenado, preordenado);
            break;

            case 8:
            empaquetado();
            break;
        } 
    } while (op != 9);
}

int getIndexFile(Tindex reg[], int n)
{
    Tindex index[n];
    Twrkr registro;
    int i = 0;

    FILE *fa;
    FILE *pa;
    FILE *fb;

    fa = fopen("datos.dat", "rb");
    fb = fopen("datos2.dat", "wb");
    if (fa)
    {
        while (fread(&registro, sizeof(Twrkr), 1, fa))
        {
            reg[i].consecutivo = i;
            reg[i].llave = registro.key;
            // printf("indice = %d  llave = %d\n", reg[i].consecutivo /*i*/, reg[i].llave /*index[i].llave*/);
            i++;
            fwrite(&registro, sizeof(Twrkr), 1, fb);
            reg[i].consecutivo = i;
            reg[i].llave = registro.key;
        }
        fclose(fa);
        fclose(fb);

        pa = fopen("datos_index.dat", "wb");
        fwrite(index, sizeof(Tindex), i, pa);
        fclose(pa);
        return i;
    }
    else
    {
        printf("Archivno no encontrado\n");
        return -1;
    }
}

int fillIndexRegister(/*Tindex index[]*/Twrkr reg[])
{
    FILE *fa;

    int i=0;
    fa = fopen("datos2.dat", "rb");
    if(fa)
    {
        while(fread(&reg[i], sizeof(Twrkr), 1, fa))
        {
            printf("%6d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", 
            i, reg[i].status, reg[i].key, reg[i].nombre, 
            reg[i].apPat, reg[i].apMat, reg[i].sexo, reg[i].puesto, 
            reg[i].estado, reg[i].edad);
            i++;
        }
        fclose(fa);
        return i;
    }
    else
    {
        printf("el archivo no existe\n");
    }
    return 0;
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

    for(i=posicion; i < (posicion + 1); i++)
    {
        printf("%6d %10d\n", reg[i].consecutivo, reg[i].llave);
    }
}

void imprimirReg2(Tindex reg[], int posicion)
{
    int i;

    for(i=0; i < posicion; i++)
    {
        printf("indice = %d  llave = %d\n", reg[i].consecutivo, reg[i].llave);
    }
}

void agregar(Twrkr reg[], Tindex reg2[], int posicion, int n)
{
    Twrkr registro;
    int li, ls, i = posicion;
    
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

    reg2[posicion].consecutivo = posicion; 

    registro = reg[posicion];

    FILE *fb = fopen("datos2.dat", "ab");

    fwrite(&registro, sizeof(Twrkr), 1, fb);

    fclose(fb);

    
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

void eliminar(Twrkr registro[], Tindex reg2[], int posicion, int ordenar)
{
    Twrkr reg;
    int encontrado, elim;
    if(ordenar == 1)
    {
        encontrado = busquedaBinaria(reg2, 0, posicion-1);

        if(encontrado != -1)
        {
            FILE *fa = fopen("datos2.dat", "r+");

            if(fa)
            {
                if(fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET) == 0)
                {
                    fread(&reg, sizeof(Twrkr), 1, fa);
                    printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", encontrado,
                    reg.status, reg.key, reg.nombre, 
                    reg.apPat, reg.apMat, reg.sexo, 
                    reg.puesto, reg.estado, reg.edad);
                    elim = validacionNumero("quieres eliminar el registro?\n1) si.\n2) no.", 1, 2);
                    if(elim == 1)
                    {
                        // fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET);
                        // Twrkr registro;
                        // fread(&registro, sizeof(Twrkr), 1, fa);
                        reg.status = 0;
                        fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET);
                        fwrite(&reg, sizeof(Twrkr), 1, fa);
                        // printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", encontrado,
                        // reg.status, reg.key, reg.nombre, 
                        // reg.apPat, reg.apMat, reg.sexo, 
                        // reg.puesto, reg.estado, reg.edad);
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
            fclose(fa);
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
            FILE *fa = fopen("datos2.dat", "r+");

            if(fa)
            {
                if(fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET) == 0)
                {
                    fread(&reg, sizeof(Twrkr), 1, fa);
                    printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", encontrado,
                    reg.status, reg.key, reg.nombre, 
                    reg.apPat, reg.apMat, reg.sexo, 
                    reg.puesto, reg.estado, reg.edad);
                    elim = validacionNumero("quieres eliminar el registro?\n1) si.\n2) no.", 1, 2);
                    if(elim == 1)
                    {
                        // fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET);
                        // Twrkr registro;
                        // fread(&registro, sizeof(Twrkr), 1, fa);
                        reg.status = 0;
                        fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET);
                        fwrite(&reg, sizeof(Twrkr), 1, fa);
                        // printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", encontrado,
                        // reg.status, reg.key, reg.nombre, 
                        // reg.apPat, reg.apMat, reg.sexo, 
                        // reg.puesto, reg.estado, reg.edad);
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
            fclose(fa);
        }
        else
        {
            printf("la matricula no existe\n");
        }
    }
} 

void buscar(Twrkr registro[], Tindex reg2[], int posicion, int ordenar)
{
    Twrkr reg;
    int encontrado;
    if(ordenar == 1)
    {
        encontrado = busquedaBinaria(reg2, 0, posicion-1);

        if(encontrado != -1)
        {
            FILE *fa = fopen("datos2.dat", "r+");

            if(fa)
            {
                if(fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET) == 0)
                {
                    fread(&reg, sizeof(Twrkr), 1, fa);
                    printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", encontrado,
                    reg.status, reg.key, reg.nombre, 
                    reg.apPat, reg.apMat, reg.sexo, 
                    reg.puesto, reg.estado, reg.edad);
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
    else
    {
        int num;
        num = validacionNumero("que matricula buscas\n", 300000, 399999);
        encontrado = existeValor2(reg2, posicion, num);

        if(encontrado != -1)
        {
            FILE *fa = fopen("datos2.dat", "r+");

            if(fa)
            {
                if(fseek(fa, (encontrado) * sizeof(Twrkr), SEEK_SET) == 0)
                {
                    fread(&reg, sizeof(Twrkr), 1, fa);
                    printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", encontrado,
                    reg.status, reg.key, reg.nombre, 
                    reg.apPat, reg.apMat, reg.sexo, 
                    reg.puesto, reg.estado, reg.edad);
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

void ordenar(Tindex reg[], int posicion , int ordenado, int preordenado)
{
    int i;
    if(ordenado)
    {
        ordenarVectorAscendente(reg, posicion); 
    }
    else
    {
        if(preordenado > 5)
        {
            quicksort(reg, 0, posicion-1);
            // for()
        }
        else
        {
            ordenarVectorAscendente(reg, posicion);
        }
    }
}

void imprimirOriginal(Tindex reg[], int posicion)
{
    int i;

    Twrkr reg2;
    FILE *fa;
    fa = fopen("datos2.dat", "rb");

    if(fa)
    {
        for(i=0; i<posicion; i++)
        {
            if(fseek(fa, i * sizeof(Twrkr), SEEK_SET) == 0)
            {
                fread(&reg2, sizeof(Twrkr), 1, fa);
                printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", i,
                reg2.status, reg2.key, reg2.nombre, 
                reg2.apPat, reg2.apMat, reg2.sexo, 
                reg2.puesto, reg2.estado, reg2.edad);
            }
        }
    }
    else
    {
        printf("error al abrir el archivo\n");
    }
    fclose(fa);
}

void imprimirOrdenado(Tindex reg[], int posicion, int ordenado, int preordenado)
{
    int i;

    ordenar(reg, posicion, ordenado, preordenado);
    Twrkr reg2;
    FILE *fa;
    fa = fopen("datos2.dat", "rb");

    if(fa)
    {
        for(i=0; i<posicion; i++)
        {
            fseek(fa, reg[i].consecutivo * sizeof(Twrkr), SEEK_SET);
            
            fread(&reg2, sizeof(Twrkr), 1, fa);
            printf("%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", i,
            reg2.status, reg2.key, reg2.nombre, 
            reg2.apPat, reg2.apMat, reg2.sexo, 
            reg2.puesto, reg2.estado, reg2.edad);
        }
    }
    else
    {
        printf("error al abrir el archivo\n");
    }
    fclose(fa);
}

void archivoTxt(Tindex reg[], int posicion, int ordenado, int preordenado)
{
    Twrkr reg2;
    int i, op;
    char archivo[30];
    FILE *fa;
    FILE *fb;
    fa = fopen("datos2.dat", "rb");

    if(fa)
    {
        validacionArchivo("dame el nobrede tu archivo de texto", archivo, 30);
        strcat(archivo, ".txt");
        fb = fopen(archivo, "w");
        op = validacionNumero("quieres el archivo con registros ordenados?\n1)\n2)no\n", 1, 2);
        if(op == 1)
        {
            ordenar(reg, posicion, ordenado, preordenado);
            for(i=0; i<posicion; i++)
            {
                fseek(fa, reg[i].consecutivo * sizeof(Twrkr), SEEK_SET);
                
                fread(&reg2, sizeof(Twrkr), 1, fa);
                fprintf(fb, "%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", i,
                reg2.status, reg2.key, reg2.nombre, 
                reg2.apPat, reg2.apMat, reg2.sexo, 
                reg2.puesto, reg2.estado, reg2.edad);
            }
        }
        else
        {
            if(fb)
            {
                while(fread(&reg2, sizeof(Twrkr), 1, fa))
                {
                    if(i < posicion)
                    {
                        fprintf(fb, "%5d %2d %8d %20s %20s %20s %15s %20s %20s %4d\n", i,
                        reg2.status, reg2.key, reg2.nombre, 
                        reg2.apPat, reg2.apMat, reg2.sexo, 
                        reg2.puesto, reg2.estado, reg2.edad);
                        i++;
                    }
                }
            }
            else
            {
                printf("error al abrir el archivo data.txt\n");
            }
        }
    }
    else
    {
        printf("error al abrir archivo datos2.dat\n");
    }
    fclose(fa);
    fclose(fb);
}

void empaquetado()
{
    int i;
    Twrkr reg;

    FILE *fa = fopen("datos2.dat", "r");
    FILE *fb = fopen("datos.bak", "w");

    if(fa)
    {
        if(fb)
        {
            while(fread(&reg, sizeof(Twrkr), 1, fa))
            {
                fwrite(&reg, sizeof(Twrkr), 1, fb);
            }
        }
    }
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
    // FILE *fa;
    // fa = fopen("datos_index.dat", "rb"); 
    for(i = 0; i < n ; i++)    
    {
        // fread(&registro, sizeof(Tindex), 1, fa);
        if(reg2[i].llave == numero)
        {
            // fclose(fa);
            return i;
        }
    }
    // fclose(fa);
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

void cambiar(Tindex reg[], int i, int j)
{
    Tindex temp = reg[i];
    reg[i] = reg[j];
    reg[j] = temp;
}

int particion(Tindex reg[], int menor, int mayor)
{
    Tindex pivot;
    pivot.llave = reg[mayor].llave;
    int i = menor - 1;

    for (int j = menor; j <= mayor - 1; j++)
    {
        if (reg[j].llave <= pivot.llave)
        {
            i++;
            cambiar(reg, i, j);
        }
    }
    cambiar(reg, i + 1, mayor);
    return i + 1;
}

void quicksort(Tindex reg[], int menor, int mayor)
{
    if (menor < mayor)
    {
        int pi = particion(reg, menor, mayor);

        quicksort(reg, menor, pi - 1);
        quicksort(reg, pi + 1, mayor);
    }
}

void ordenarVectorAscendente(Tindex reg[], int n)  
{
    Tindex aux;
    int i, j;

    for(i=0; i<n; i++)  
    {
        for(j=i+1; j<n; j++)   
        {
            if(reg[j].llave<reg[i].llave)   
            {
                aux = reg[i];         
                reg[i] = reg[j];
                reg[j] = aux;
            }
        }
    }
}

void merge(Tindex arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i].llave;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j].llave;

    // Fusionar los arreglos temporales de vuelta en arr[l..r]
    i = 0; // Índice inicial del primer subarreglo
    j = 0; // Índice inicial del segundo subarreglo
    k = l; // Índice inicial del arreglo fusionado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k].llave = L[i];
            i++;
        } else {
            arr[k].llave = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k].llave = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k].llave = R[j];
        j++;
        k++;
    }
}

// Función recursiva que implementa el algoritmo Merge Sort
void mergeSort(Tindex arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2; // Encuentra el punto medio

        // Ordena la primera y la segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Fusiona las mitades ordenadas
        merge(arr, l, m, r);
    }
}