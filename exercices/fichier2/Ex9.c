#include <stdio.h>
#include <stdlib.h>

int main(){
    double tab[] = {1.2, 4.5, 123.4, -12.893, 45.66, 56.5, 1, 2, 3};

    const int nbr_elem = sizeof(tab)/sizeof(double); // calcul du nombre d'éléments
    FILE* f = fopen("Ex9.txt", "w");
    if(f==NULL)
        return -1;
    fwrite(&tab, sizeof(double), nbr_elem, f);
    fclose(f);

    f = fopen("Ex9.txt", "r");
    if (f==NULL)
        return -1;
    double tab_r[100];
    fread(&tab_r, sizeof(double), nbr_elem, f);
    // Affichage des valeurs du tableau
    printf("Val : ");
    for(int i=0; i<nbr_elem; i++)
        printf(" %.2lf ", tab_r[i]);
    printf("\n");
    return 0;
}