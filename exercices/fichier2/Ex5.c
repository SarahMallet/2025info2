#include <stdio.h>
#include <math.h>

void process_data(FILE* f, int nb){
    for(int i = 1;i<=nb;i++){
        int nombre = i;
        int square = i*i;
        double root = sqrt(i);

        fprintf(f, "%d, %d, %.2lf\n", nombre, square, root);
    }
}

void read_data(FILE* f) {
    char ligne[100];
    while (fgets(ligne, 100, f) != NULL) {  // Vérifier si fgets ne retourne pas NULL
        printf("%s", ligne);
    }
}

int main() {
    FILE* f = fopen("Ex5.txt", "w");

    if(f==NULL)
        return -1;

    const int nombre = 10;
    process_data(f, nombre);
    fclose(f);
    f = fopen("Ex5.txt", "r");

    if(f==NULL)
        return -1;
    read_data(f);
    return 0;
}