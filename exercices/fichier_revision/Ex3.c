#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void generate_csv(char* file, double times, double pas, double freq){
    FILE* f = fopen(file, "w");
    if(f==NULL)
        return;
    fprintf(f, "temps,sinus,cosinus\n");
    for(double i=0;i<=times; i+=pas){
        double sinus = sin(2 * M_PI * freq * i);
        double cosinus = cos(2 * M_PI * freq * i);
        fprintf(f, "%.2f,%f,%f\n", i, sinus, cosinus);
    }
}

int main() {
    generate_csv("sinus.csv", 10, 0.1, 1);

    return 0;
}