#include <stdio.h>
#include <stdlib.h>

void readTxtFile(void);
void writeTxtFile(void);

int main()
{
    readTxtFile();
    writeTxtFile();
    return 0;
}

void readTxtFile()
{
    FILE *fa;
    FILE *fa2;
    char car;
    char car2;

    fa = fopen("cancion.txt", "r");
    fa2 = fopen("ensenada.txt", "r");

    if(fa)
    {
        do{
            car = fgetc(fa);

            printf("%c", car);

        }while(!feof(fa));
        fclose(fa);
    }
    if(fa2)
    {
        do{
            car2 = fgetc(fa2);

            printf("%c", car2);
        }while(!feof(fa2));
        fclose(fa2);
    }

}

void writeTxtFile()
{
    FILE *fa;

    fa = fopen("nombres.txt", "a");


    fprintf(fa, "hernandez cesena ivan fernando 19 nacido en ensenada\n");
    fclose(fa);
    
}