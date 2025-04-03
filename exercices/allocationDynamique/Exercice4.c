#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    double value;
} Measure;

typedef struct {
    Measure* datas;
    int capacity;
    char* name;
} Container;

Container* create(int capacity, char* name){
    Container* ar = malloc(sizeof(Container));
    ar->datas = malloc(capacity * sizeof(Measure));
    ar->name = name;
    return ar;
}

int main(void){
    Container* tab = create(10, "Meas1");
    printf("Mesure 3: %d\n", tab->datas[2].value);
}