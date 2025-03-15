#include <stdio.h>

int main() {
    FILE* f = fopen("name.txt", "r");

    char name[20];
    if (f != NULL)
    {
        fgets(name, 20, f);
        fprintf(stdout, "Bonjour : %s\n", name);
    }
    else
    {
        printf("Veuillez entrer votre nom : > ");
        scanf("%[^\n]s", name);
        f = fopen("name.txt", "w+");
        fputs(name, f);
    }

    fclose(f);
}
