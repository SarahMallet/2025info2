#include <stdio.h>

int main() {
    FILE* f = fopen("Ex1.txt", "w");
    if (f == NULL)
        return -1;
    fprintf(f,"Bonjour");
    fclose(f);
    
    f = fopen("Ex1.txt", "a");
    if (f == NULL)
        return -1;
    fprintf(f, " tout le monde");
    fclose(f);

    f = fopen("Ex1.txt", "r");
    if (f == NULL)
        return -1;
    char txt[30];
    char* c = fgets(txt,30,f);
    fclose(f);

    printf("%s\n", c);
}