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
    fprintf(f, "%d\n%.2lf\n%s\n", m1.id, m1.value, m1.txt);
    fclose(f);
    return 0;
}