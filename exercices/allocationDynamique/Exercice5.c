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

double* creer_tableau(int taille){
    Container* arr = (Container*)malloc(sizeof(Container));
    if(!arr)
        return NULL;
    arr->datas = (Measure*)malloc(taille * sizeof(Measure));
    arr->capacity = taille;
    for(int i=0;i<arr->capacity;i++){
        arr->datas[i].value = 0;
    }
    return &(arr->datas[0].value); // Retourne l'adresse du premier `value`
}

int main(void){
    double* tab = creer_tableau(10);
    for (int i = 0; i < 10; i++) {
        printf("%lf\n", tab[i]);
    }
    return 0;
}