#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int tab[2] = {1,2};
    int* p = &a;
    int* ptab = tab; // &tab[0]
    int* ptab1 = &tab[1];
    printf("a = %d\n", a); // Affichage de la valeur de a
    printf("p = %p\n", p); // Affichage de l'adresse de a
    printf("*p = %d\n", *p); // Affichage de la valeur pointée par p
    printf("-----------------------------------------\n");

    //Tableau
    printf("ptab = %p\n", ptab); // Affichage adresse ptab

    printf("&tab[0] = %p\n", &tab[0]); // Affichage adresse ptab = &tab[0]
    ptab++;
    printf("ptab = %p\n", ptab); // Affichage adresse ptab = &tab[1]
    printf("&tab[1] = %p\n", &tab[1]); // Affichage adresse ptab = &tab[1]
    ptab++;
    printf("ptab = %p\n", ptab); // Affichage adresse ptab
    printf("&tab[2] = %p\n", &tab[2]); // Affichage adresse ptab = &tab[2]

    printf("ptab1 = %p\n", ptab1); // Affichage adresse ptab1 = &tab[1]
    printf("-----------------------------------------\n");

    //Chaine de caractère
    char* txt = "Bonjour"; // pointeur sur chaîne de caractères
    char* pc = txt; // &txt[0]
    printf("pc=%p\n",pc); // Affichage adresse pc
    printf("%s\n",pc); //Affichage texte a l'adresse pc -> à partir de txt[0]
    pc +=3;
    printf("%s\n",pc); ////Affichage texte a l'adresse pc -> à partir de txt[3]
    return 0;
}