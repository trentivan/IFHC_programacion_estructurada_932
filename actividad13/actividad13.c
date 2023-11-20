// Hernandez Ceseña Ivan Fernando  373077
// 07/11/23
//  1.- AGREGAR REGISTROS (AUTOM 10 REGISTROS)
//  2.- AGREGAR REGISTRO MANUAL
//  3.- ELIMINAR REGISTRO (lógico)
//  4.- BUSCAR USUARIO DE REGISTRO (POR MATRICULA)
//  5.- ORDENAR REGISTROS
//  6.- IMPRIMIR REGISTROS
//  0.- TERMINAR PROGRAMA
// HCIF_ACT12_932

#include "ivan.h"

#define N 5000

typedef int Tkey;

typedef struct _alumnos{
    int status;
    Tkey key;
    char apellidoPaterno[30];
    char apellidoMaterno[30];
    char nombre[30];
    int edad;
    int sexo; } Talumns;


void menu(void);
void msg(void);

void registroAleatorio(Talumns reg[], int i, int numero);
void sexo(Talumns reg[], int i, int li, int ls);
void status(Talumns reg[], int i);
void matricula(Talumns reg[], int li, int ls, int i);
void apellidoPaterno(Talumns reg[], int i);
void apellidoMaterno(Talumns reg[], int i);
void nombre(Talumns reg[], int i);
void edad(Talumns reg[], int i, int li, int ls);
int existeValor(Talumns reg[], int n, int numero);
void eliminarRegistro(Talumns reg[], int posicion);
void buscarElemento(Talumns reg[], int posicion, int bandera);
void ordenarAscendente(Talumns reg[], int n);
int busquedaBinaria(Talumns reg[], int izquierda, int derecha);
void imprimirRegistro(Talumns reg[], int posicion);
void imprimirBuscado(Talumns reg[], int posicion);

void cambiar(Talumns reg[], int i, int j);
int particion(Talumns reg[], int menor, int mayor);
void quicksort(Talumns reg[], int menor, int mayor);
void archivoTexto(Talumns reg[], int posicion);
void numeroRegistros(void);
void generarTxt(Talumns reg[], int posicion);
void inactivos(Talumns reg[], int posicion);
void editarRegistro(Talumns reg[], int posicion, int bandera);

void mostrarArchivoTxt(int posicion, char archivo[]);
void imprimirRegistroTxt(Talumns reg[], int i, int posicion);
void crearArchivoBinario(Talumns reg[], int posicion);
int cargarArchivoBinario(Talumns reg[], int posicion, int maximo);



int main()
{
    srand(time(NULL));
    system("gcc.exe archivoExterno.c -o archivoExterno");
    menu();
}



void msg()
{
    printf("MENU\n");
    printf("1) agregar 100 registros aleatorios.\n");
    printf("2) editar registro.\n");
    printf("3) eliminar registro\n");
    printf("4) buscar.\n");
    printf("5) ordenar\n");
    printf("6) imprimir registros.\n");
    printf("7) generar archivo\n");
    printf("8) ver archivo de texto\n");
    printf("9) generar archivo binario\n");
    printf("10) cargar archivo binario\n");
    printf("11) mostrar eliminados\n");
    printf("12) salir\n");
}

void menu()
{
    int op;
    int posicion=0, bandera=0, cargar = 0;
    Talumns reg[N];
    char nombretxt[30];
    int numero = 100;
    
    
    do{
        system("cls");
        msg();
        op= validacionNumero("elije una opcion", 1, 12);
        switch(op)
        {
            case 1:
            if((posicion + numero) > N)
            {
                numero = N - posicion;
            }
            if(numero == 0)
            {
                printf("el registro esta lleno\n");
            }
            else
            {
                registroAleatorio(reg, posicion, numero);
                printf("llenado de 100 registros exitoso\n");
                posicion= posicion + numero;
                bandera = 0;
            }
            break;

            case 2:
            editarRegistro(reg, posicion, bandera);
            break;

            case 3:
            eliminarRegistro(reg, posicion);
            break;

            case 4:
            buscarElemento(reg, posicion, bandera);
            break;

            case 5:
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

            case 6:
            printf("registro\n");
            imprimirRegistro(reg, posicion);
            break;

            case 7:
            generarTxt(reg, posicion);
            break;

            case 8:
            validacionArchivo("dame el nombre del archivo que quieres leer", nombretxt, 30);
            mostrarArchivoTxt(posicion, nombretxt);
            break;
            
            case 9:
            crearArchivoBinario(reg, posicion);
            bandera = 0;
            break;

            case 10:
            if(cargar == 1)
            {
                printf("el archivo binario solo se puede cargar una vez");
            }
            else
            {
                posicion = cargarArchivoBinario(reg, posicion, N);
                cargar =1;
            }
            break;

            case 11:
            inactivos(reg, posicion);
            break;
        } 
        system("pause");
    }while(op != 12); 
}

int menuEditar()
{
    int op;
    printf("1) nombre\n");
    printf("2) apellido paterno\n");
    printf("3) apellido materno\n");
    printf("4) edad\n");
    printf("5) sexo\n");
    op = validacionNumero("elije la opcion que deseas modificar", 1, 5);
    return op;
}

void editarRegistro(Talumns reg[], int posicion, int bandera)
{
    int encontrado, editar, num;
    char nom[30];
    char apPat[30];
    char apMat[30];

    if(bandera == 1)
    {
        encontrado = busquedaBinaria(reg, 0, posicion - 1);
        printf("%d\n", encontrado);
    }
    else
    {
        num = validacionNumero("que matricula buscas?", 300000, 399999);
        encontrado = existeValor(reg, posicion, num);
    }

    if(encontrado == -1)
    {
        printf("el usuario no existe\n");
    }
    else
    {
        imprimirBuscado(reg, encontrado);
        editar = menuEditar();
        if(editar == 1)
        {
            validacionTexto("dame el nuevo nombre", nom, 30);
            strcpy(reg[encontrado].nombre, nom);
        }
        else
        {
            if(editar == 2)
            {
                validacionTexto("dame el nuevo apellido", apPat, 30);
                strcpy(reg[encontrado].apellidoPaterno, apPat);
            }
            else
            {
                if(editar == 3)
                {
                    validacionTexto("dame el nuevo nombre", apMat, 30);
                    strcpy(reg[encontrado].apellidoMaterno, apMat);
                }
                else
                {
                    if(editar == 4)
                    {
                        reg[encontrado].edad = validacionNumero("dame la edad", 15, 70);
                    }
                    else
                    {
                        printf("1) HOMBRE\n");
                        printf("2) MUJER\n");
                        reg[encontrado].sexo = validacionNumero("elije el sexo", 1, 2);
                    }
                }
            }
        }
    }
}

void crearArchivoBinario(Talumns reg[], int posicion)
{
    Talumns registro;
    int i;
    char nombre[30];
    FILE *fa;
    validacionArchivo("dame el nombre para tu archivo binario", nombre, 30);
    strcat(nombre, ".dll");
    fa = fopen(nombre, "ab");

    for(i=0; i<posicion; i++)
    {
        registro = reg[i];
        fwrite(&registro, sizeof(Talumns), 1, fa);
    }
    fclose(fa);
}

int cargarArchivoBinario(Talumns reg[], int posicion, int maximo)
{
    int i=0;
    Talumns registro;
    FILE *fa;
    char nombre[30];
    validacionArchivo("dame el nombre del archivo binario", nombre, 30);
    strcat(nombre, ".dll");
    fa = fopen(nombre, "rb");

    if(fa)
    {
        while(fread(&registro, sizeof(Talumns), 1, fa))
        {
            if(posicion + 1 > maximo)
            {
                printf("no se pudo cargar todo el archivo.\nsolo se cargaron %d registros\n", i);
                return posicion;
            }
            else
            {
                reg[posicion++] = registro;
                i++;
            }
        }
        fclose(fa);
    }
    return posicion;
}

void mostrarArchivoTxt(int posicion, char archivo[])
{
    FILE *fa;
    Talumns registro;
    int num;
    char sex[10]; 
    strcat(archivo, ".txt");
    fa = fopen(archivo, "r");
    if(fa)
    {
        while(!feof(fa))
        {
            fscanf(fa, "%d.- %d %s %s %s %d %s", &num, &registro.key, registro.nombre, registro.apellidoPaterno, registro.apellidoMaterno, &registro.edad, sex);
            registro.status = 1;
            if(strcmp(sex, "HOMBRE") == 0)
            {
                registro.sexo = 1;
            }
            else
            {
                if(strcmp(sex, "MASCULINO") == 0)
                {
                    registro.sexo = 1;
                }
                else
                {
                    if(strcmp(sex, "MUJER") == 0)
                    {
                        registro.sexo = 2;
                    }
                    else
                    {
                        if(strcmp(sex, "FEMENINO") == 0)
                        {
                            registro.sexo = 2;
                        }
                    }
                }
            }
            printf("%3d %10d %20s %20s %20s %4d", num, registro.key, registro.nombre, registro.apellidoPaterno, registro.apellidoMaterno, registro.edad);
            if(registro.sexo == 1)
            {
                printf(" %8s\n", "HOMBRE");
            }
            else
            {
                printf(" %8s\n", "MUJER");
            }
            posicion++;
        }
    }
    else
    {
        printf("el archivo no existe\n");
    }
}

void imprimirRegistroTxt(Talumns reg[], int i, int posicion)
{
    printf("%3s %10s %20s %20s %20s %4s %8s\n", "No.", "empleado", "nombre", "apellido paterno", "apellido materno", "edad", "sexo");
    for(i=0; i<posicion; i++)
    {
        if(reg[i].status == 1)
        {
            printf("%3d %10d %20s %20s %20s %4d", i+1, reg[i].key, reg[i].nombre, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].edad);
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

void numeroRegistros()
{
    int contador;
    char archivo[50];
    char parametros[50];

    validacionArchivo("ingresa el nombre del archivo que quieres evaluar:", archivo, 50);

    sprintf(parametros, "archivoExterno.exe %s", archivo);
    contador = system(parametros);

    if(contador != -1)
    {
        printf("el archivo %s tiene %d registros", archivo, contador);
    }
    else
    {
        printf("el archivo no se encontro");
    }
}

void generarTxt(Talumns reg[], int posicion)
{
    int i;
    FILE *fa;
    char archivo[30];
    
    validacionArchivo("escribe como quieres nombrar tu archivo", archivo, 30);

    strcat(archivo, ".txt");
    fa = fopen(archivo, "w");

    for(i =0; i<posicion; i++)
    {
        if(reg[i].status == 1)
        {
            fprintf(fa, "%6d.- %10d %10s %15s %15s %5d", i+1, reg[i].key, reg[i].nombre, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].edad);
            if(reg[i].sexo == 1)
            {
                fprintf(fa, " %8s\n", "HOMBRE");
            }
            else
            {
                fprintf(fa, " %8s\n", "MUJER");
            }
        }
    }

    fclose(fa);
    printf("archivo generado\n");
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
        apellidoPaterno(reg, i);
        apellidoMaterno(reg, i);
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
    int numeroUsuario, rango= (ls-li) +1;
    int existe;
    do{
        numeroUsuario = rand()% rango + li;
        existe = existeValor(reg, posicion, numeroUsuario);
    }while(existe != -1);
    reg[posicion].key = numeroUsuario;
}

void apellidoPaterno(Talumns reg[], int posicion)
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
    strcpy(reg[posicion].apellidoPaterno, apellidos[numero]);
}

void apellidoMaterno(Talumns reg[], int posicion)
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
    strcpy(reg[posicion].apellidoMaterno, apellidos[numero]);
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
        strcpy(reg[posicion].nombre, nombresHombre[numero]);
    }
    else
    {
        numero = (rand()%49) +1;
        strcpy(reg[posicion].nombre, nombresMujer[numero]);
    }
    
}

void edad(Talumns reg[], int posicion, int li, int ls)
{
    int rango= (ls-li)+1;
    reg[posicion].edad = (rand()%rango)+li;
}

int existeValor(Talumns reg[], int n, int numero)
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

void eliminarRegistro(Talumns reg[], int posicion)
{
    int eliminar, numeroUsuario;
    numeroUsuario = validacionNumero("dame la matricula que quieres eliminar", 300000, 399999);
    eliminar = existeValor(reg, posicion-1, numeroUsuario);
    if(eliminar != -1)
    {
        if(reg[eliminar].status == 1)
        {
            reg[eliminar].status = 0;
            printf("estudiante dado de baja\n");
            imprimirBuscado(reg, eliminar);
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
    int numeroUsuario, buscar;

    if(bandera == 0)
    {
        printf("busqueda secuencial\n");
        numeroUsuario = validacionNumero("que matricula buscas?", 300000, 399999);
        buscar = existeValor(reg, posicion, numeroUsuario);
    }
    else
    {
        printf("busqueda binaria\n");
        buscar = busquedaBinaria(reg, 0, posicion - 1);
    }

    if(buscar != -1)
    {
        imprimirBuscado(reg, buscar);
    }
}

void imprimirRegistro(Talumns reg[], int posicion)
{
    int i;
    printf("%3s %10s %20s %20s %20s %4s %8s\n", "No.", "empleado", "nombre", "apellido paterno", "apellido materno", "edad", "sexo");
    for(i=0; i<posicion; i++)
    {
        if(reg[i].status == 1)
        {
            printf("%3d %10d %20s %20s %20s %4d", i+1, reg[i].key, reg[i].nombre, reg[i].apellidoPaterno, reg[i].apellidoMaterno, reg[i].edad);
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

void imprimirBuscado(Talumns reg[], int posicion)
{
    printf("numero de registro: ");
    printf("%d\n", posicion + 1);
    printf("empleado: ");
    printf("%d\n", reg[posicion].key);
    printf("nombre: ");
    printf("%s\n", reg[posicion].nombre);
    printf("apellido paterno: ");
    printf("%s\n", reg[posicion].apellidoPaterno);
    printf("apellido materno: ");
    printf("%s\n", reg[posicion].apellidoMaterno);
    printf("edad: ");
    printf("%d\n", reg[posicion].edad);
    printf("sexo: ");
    if(reg[posicion].sexo == 1)
    {
        printf("hombre\n");
    }
    else
    {
        printf("mujer\n");
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
            if(reg[j].key <reg[i].key)   
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
    int numeroUsuario;
    numeroUsuario = validacionNumero("que matricula buscas?", 300000, 399999);
    
    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (reg[medio].key == numeroUsuario)
        {
            printf("%d\n", medio);
            return medio;
        }

        if (reg[medio].key < numeroUsuario)
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

void cambiar(Talumns reg[], int i, int j)
{
    Talumns temp = reg[i];
    reg[i] = reg[j];
    reg[j] = temp;
}

int particion(Talumns reg[], int menor, int mayor)
{
    Talumns pivot;
    pivot.key = reg[mayor].key;
    int i = menor - 1;

    for (int j = menor; j <= mayor - 1; j++)
    {
        if (reg[j].key <= pivot.key)
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

void inactivos(Talumns reg[], int posicion)
{
    int j;
    char archivo[30];
    FILE *fb;
    validacionArchivo("escribe como quieres nombrar tu archivo", archivo, 30);

    strcat(archivo, ".txt");
    fb = fopen(archivo, "w");

    for(j=0; j<posicion; j++)
    {
        if(reg[j].status == 0)
        {
            fprintf(fb, "%3d %10d %10s %15s %15s %4d", j+1, reg[j].key, reg[j].nombre, reg[j].apellidoPaterno, reg[j].apellidoMaterno, reg[j].edad);
            printf("%3d %10d %10s %15s %15s %4d", j+1, reg[j].key, reg[j].nombre, reg[j].apellidoPaterno, reg[j].apellidoMaterno, reg[j].edad);
            if(reg[j].sexo == 1)
            {
                fprintf(fb, " %8s ", "HOMBRE");
                printf(" %8s", "HOMBRE");
            }
            else
            {
                fprintf(fb, " %8s", "MUJER");
                printf(" %8s \n", "MUJER");
            }
            fprintf(fb, "\n");
            printf("\n");
            j++;
        }
    }
    fclose(fb);
}