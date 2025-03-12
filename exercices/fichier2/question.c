#include <stdio.h>

int main() {
    printf("Q1---------------------------\n");
    FILE* f = fopen("question.txt", "r");
    if(f == NULL)           //Toujours testé ouverture fichier
        return -1;
    char c;
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(f);

    printf("Q2---------------------------\n");
    FILE* f2 = fopen("question.txt", "r");
    char c2  = fgetc(f2);
    c2  = fgetc(f2);
    c2  = fgetc(f2);
    printf("Val = %c\n", c2);    //Val = C
    fclose(f2);

    printf("Q3---------------------------\n");
    FILE* f3 = fopen("question.txt", "r");
    if( f3 != NULL)
    {
        char c3;
        while ((c3 = fgetc(f3)) != EOF)
        {
            printf("%c", c3);
        }
    }
    printf("\n");
    fclose(f3);//f3 = fopen("question.txt", "r");

    printf("Q4---------------------------\n");
    FILE* f4 = fopen("question.txt", "r");
    char txt[10];
    char c4;
    fgets(txt,10,f4); //fgets lit la ligne ou 10 caractères
    c4  = fgetc(f4);
    printf("Val = %c\n", c4); // Val = E
    fclose(f4);

    printf("Q5---------------------------\n");
    FILE* f5 = fopen("question.txt", "r");
    char txt5[10];
    char c5;
    fgets(txt5,10,f5);
    c5  = fgetc(f5);
    c5  = fgetc(f5);
    fgets(txt5,10,f5);
    c5  = fgetc(f5);
    printf("Val c5 = %c\n", c5); // Val = 1
    printf("Val txt5 = %s\n", txt5); //Val = GH
    fclose(f5);

}