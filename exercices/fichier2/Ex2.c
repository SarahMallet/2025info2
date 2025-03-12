#include <stdio.h>

int main() {
    FILE* f = fopen("Ex2.txt", "w");
    if (f == NULL)
        return -1;
    fprintf(f,"Bonjour\n");
    fclose(f);
    
    f = fopen("Ex2.txt", "a");
    if (f == NULL)
        return -1;
    fprintf(f, "Tout le monde.");
    fclose(f);

    f = fopen("Ex2.txt", "r");
    if (f == NULL)
        return -1;
    int nb_lignes = 0;
    char c;
    do  {
        if (c == '\n') {
            nb_lignes++;
        }
    } while ((c = fgetc(f)) != EOF);   
    fclose(f);
    printf("nb lignes : %d\n", nb_lignes+1);

    f = fopen("Ex2.txt", "r");
    if (f == NULL)
        return -1;
    char txt[30];
    while (fgets(txt, 30, f) != NULL) //Affichage avec fgets
    {
        printf("%s", txt);
    }
    printf("\n");
    fclose(f);

    f = fopen("Ex2.txt", "r");
    if (f == NULL)
        return -1;
    char txt1;
    while ((txt1 = fgetc(f)) != EOF) //Affichage avec fgetc
    {
        printf("%c", txt1);
    }
    printf("\n");
    fclose(f);
}