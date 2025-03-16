#include <stdio.h>

typedef struct{
    int id;
    double value;
    char txt[10];
} Meas;

int main(){
    Meas m1 = {.id=1, .value=2.34, .txt="Bonjour"};
    FILE* f = fopen("Ex6.txt", "w");
    if (f == NULL)
        return -1;
    //fprintf(f, "%d\n%.2lf\n%s\n", m1.id, m1.value, m1.txt); 
    fwrite(&m1, sizeof(Meas), 1, f);
    fclose(f);
    f = fopen("Ex6.txt", "r");
    Meas m2;
    fread(&m2, sizeof(Meas), 1, f);

    printf("\nExercice 6 : structure\n");
    printf("Meas id : %d\n", m2.id);
    printf("Meas value : %.2lf\n", m2.value);
    printf("Meas txt : %s\n", m2.txt);
    fclose(f);
    return 0;
}