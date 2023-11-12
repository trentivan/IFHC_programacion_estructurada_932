// Hernandez Ceseña Ivan Fernando  373077
// 08/10/23 /  10/10/23 / 14/10/23
// LLENAR VECTOR ALEATORIAMENTE SIN REPETIR VALORES ( RANGO 1-16)  
// LLENAR MATRIZ ALEATORIAMENTE SIN REPETIR VALORES (RANGO 100-200)
// IMPRIMIR VECTORES Y MATRICES ; ORDENAR VECTOR Y BUSCAR VALOR EN VECTOR
// VALIDACION TEXTO Y NUMERO
// HCIF_ACT10_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



//   funciones de matriz     /////////////////////////////////////////////////////////////////////////////////////////////

void imprimirMatriz(int matriz[][4], int m, int n, char nombre[]) // funcion para imprimir nuestra matriz
{
    int i,j;     // indices de nuestro ciclo 
    printf("%s\n", nombre);    // aqui se imprime el nombre de la matriz
    for(i=0; i<m; i++)        // ciclo que controla las filas de la matriz 
    {
        for(j=0; j<n; j++)     // ciclo que controla las columnas de la matriz
        {
            printf("[%d]\t", matriz[i][j]);     //aqui se imprime el valor que este en tal posicion de la matriz dependiendo los valores que tengan los indices  
        }
        printf("\n");     // un salto de linea para dar la forma caracteristica de la matriz
    }
}
// fin funciones de matriz      ///////////////////////////////////////////////////////////////////////////////////////////


// funciones de vectores    //////////////////////////////////////////////////////////////////////////////////////////////

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

int busquedaSecuencial(int vector[], int n, int numero)  // funcion para buscar un valor en un vector previamente enviado 
                                                         //( funciona para llenar vectores sin repetir datos)
{
    int i;   // indice que va a controlar las posiciones del vector

    for(i = 0; i < n ; i++)    // ciclo para recorrer las pocisiones del vector
    {
        if(vector[i] == numero)   //  comparacion del numero a comparar y el valor en la posicion del vector
        {
            return i+1;  // si se encuentra el valor se retorna la posicion +1
        }
    }
    return -1;   // si no se encuentra se retorna un numero que no es una posicion del vector
                // se hace para no tener conflicto con los tamanos de los vectores
}

void ordenarVectorAscendente(int vector[], int n)  // funcion para ordenar vector de menor a mayor
{
    int i, j, aux=0;     // indices [i] y [j] sirven para comparar los valores del vector para que ordenarlos correctamente
                         // [aux] sirve para intercambiar los valores en caso de que un numero de posicion mas alta sea menor a otro de pocision mas baja

    for(i=0; i<n; i++)   // ciclo para recorrer los valores a comparar
    {
        for(j=i+1; j<n; j++)   // ciclo para comparar valores de posicion diferente a [i]. 
        {
            if(vector[j]<vector[i])   // condicion en la que se compara si el valor de la posicion [j] es mas grande que el de [i]
            {
                aux = vector[i];         // este bloque hace el intercambio con apoyo del auxiliar [aux]
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void ordenarVectorDescendente(int vector[], int n)  // funcion para ordenar vector de mayor a menor
{
    int i, j, aux=0;  // indices [i] y [j] sirven para comparar los valores del vector para que ordenarlos correctamente
                         // [aux] sirve para intercambiar los valores en caso de que un numero de posicion mas alta sea mayoyr a otro de pocision mas baja

    for(i=0; i<n; i++)   // ciclo para recorrer los valores a comparar
    {
        for(j=i+1; j<n; j++)  // ciclo para comparar valores de posicion diferente a [i]. 
        {
            if(vector[j]>vector[i])   // condicion en la que se compara si el valor de la posicion [j] es mas chico que el de [i]
            {
                aux = vector[i];        // este bloque hace el intercambio con apoyo del auxiliar [aux]
                vector[i] = vector[j];   
                vector[j] = aux;
            }
        }
    }
}

void vectorAleatorioSinRepetir(int vector[],int n, int li, int ls)  // funcion para llenar un vector aleatoriamente sin repetir valores
{
    srand(time(NULL));    // semilla para generar valores diferrentes
    int i, num;      // indice [i]para controlar posiciones del vector. [num] para guardar el numero generado aleatoriamente
    int rango = ls-li+1;   // el rango determina el limite de los numeros a generar

    for(i=0; i < n; i++)  // ciclo que recorre cada posicion del vector una por una hasta la penultima posicion
    {
        do{
            num = (rand()% rango)+li;   //  el numero generado se guarda en la variable num.

        }while(busquedaSecuencial(vector, n, num) != -1);  // en la condicion del ciclo do while se invocara la funcion busquedaSecuencial
                                                           // en la que se evaluaran valores y en caso de que uno se repita con [num] se regresara para generar otro numero
        vector[i] = num;
    }
}

void imprimirVector(int vector[], int n, char nombre[])  // funcion que imprime el vector 
{
    int i;  // indice para recorrer el vector
    printf("%s\n", nombre);  // se imprime el titulo del vector
    for(i=0; i<n; i++)   // ciclo que recorrera todo el vetor posicion por posicion
    {
        printf("[%d] ", vector[i]);  // se imprime el valor del vector
    }
    printf("\n");  // salto de linea para que no se vea abultado los datos
}
// fin funciones de vectores     //////////////////////////////////////////////////////////////////////////////////////


// validaciones                 ///////////////////////////////////////////////////////////////////////////////////////
int validacionNumero(char msg[], int li, int ls)  // funcion para que solo se acepten numeros
{
    int numero, valido;  // variables para guardar valor y retornar [numero] y bandera para usarlo como condicion [valido] 
    char cadena[100];  // declaracion de cadena para usarlo como valor de entrada
    do{
        valido=0;  // bandera inicializada en 0
        printf("%s\n", msg);  // se muestra el mensaje escrito previamente en la invocacion
        fflush(stdin);  // esta funcion limpia la entrada
        gets(cadena);   // funcion que guarda el valor ingresado
        numero= atoi(cadena);  // [numero] almacena los numeros ingresados. en caso de ingresarse una letra se guardaran los numeros antes de la primer letra 
        if(numero < li || numero > ls)  // condicion para evaluar si el numero dado esta fuera de los limites
        {
            printf("el numero debe estar dentro de este rango (%d-%d)\n", li, ls);  // si el numero esta fuera de los limites se muestra los mensajes y se activa la bandera
            printf("por favor, introduce otro numero\n");
            valido=1;
        }

    }while(valido==1);  // codicion que valida si la bandera se cumple
    
    return numero;  // si el numero cumple con los requisitos se retorna el mismo
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
    int invalido=0, contador=0;  // bandera
    int i;  //  indice
    do{
        invalido=0;  // inicializa bandera
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);  // se guarda el texto
        mayusculas(cadena);

        for(i=0 ; cadena[i] != '\0'; i++);  // ciclo para acceder a todas las posiciones de la cadena
        if(i > n)  // si se cumple la condicion se activa la bandera
        {
            printf("el texto escrito tiene mas de [%d] caracteres.\n", n);
            invalido=1;
        }

        for(i=0 ; cadena[i] != '\0'; i++, contador++)
        {
            
            if(cadena[i] > 90)  // si se cumple cualquier conjunto de condiciones se activa la bandera y se muestra los mensajes.
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

    }while(invalido == 1);  // aqui se evalua si la bandera se cumple 
}  // si no se cumple se termina la funcion.

void validacionArchivo(char msg[], char cadena[], int n)
{
    int invalido=0, contador=0;  // bandera
    int i;  //  indice
    do{
        invalido=0;  // inicializa bandera
        printf("%s\n", msg);
        fflush(stdin);
        gets(cadena);  // se guarda el texto

        for(i=0 ; cadena[i] != '\0'; i++);  // ciclo para acceder a todas las posiciones de la cadena
        if(i > n)  // si se cumple la condicion se activa la bandera
        {
            printf("el texto escrito tiene mas de [%d] caracteres.\n", n);
            invalido=1;
        }

        for(i=0 ; cadena[i] != '\0'; i++, contador++)
        {
            
            if(cadena[i] > 90)  // si se cumple cualquier conjunto de condiciones se activa la bandera y se muestra los mensajes.
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
// fin funciones de validaciones                     /////////////////////////////////////////////////////////////////////////