#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROWTH_FACTOR 2

typedef struct
{
    double *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createArray(int capacity){
    if(capacity<=0)
        return NULL;
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    if(!arr)
        return NULL;
    arr->data=(double*)malloc(capacity*sizeof(double));
    if(!arr->data){
        free(arr);
        return NULL;
    }
    arr->size=0;
    arr->capacity=capacity;
    return arr;
}

void destroyArray(DynamicArray* arr){
    if (arr) {
        free(arr->data);
        free(arr);
    }
}

int availableSpace(DynamicArray* arr){
    return arr ? (arr->capacity - arr->size) : -1;
}

void addElement(DynamicArray* arr, double value){
    if(!arr)
        return;
    if(arr->size >= arr->capacity){
        int newCapacity = arr->capacity*GROWTH_FACTOR;
        double* newData = (double*)realloc(arr->data, newCapacity*sizeof(double));
        if(!newData)
            return;
        arr->data=newData;
        arr->capacity=newCapacity;
        printf("Capacité augmentée à %d\n", arr->capacity);
    }
    arr->data[arr->size++]=value;
}

void displayArray(DynamicArray* arr){
    if(!arr || arr->size == 0){
        printf("Tableau vide\n");
        return;
    }
    for(int i = 0;i<arr->size;i++){
        printf("%.2lf ", arr->data[i]);
    }
    printf("\n");
}

bool popElement(DynamicArray* arr, double* val){
    if(!arr || arr->size == 0 || !val)
        return false;
    *val = arr->data[arr->size-1];
    arr->size--;
    return true;
}

bool isInitialized(DynamicArray* arr){
    return arr && arr->data;
}

bool getElement(DynamicArray* arr, int index, double* val){
    if(!arr || arr->size == 0 || index<0 || index>=arr->size || !val)
        return false;
    *val = arr->data[index];
    return true;
}


int main() {
    // Création du tableau dynamique avec une capacité initiale de 3
    DynamicArray* arr = createArray(3);
    
    if (!isInitialized(arr)) {
        printf("Échec de l'initialisation du tableau.\n");
        return 1;
    }

    // Affichage de l'espace disponible
    printf("Espace disponible 1 : %d\n", availableSpace(arr));

    // Ajout d'éléments
    addElement(arr, 10.5);
    addElement(arr, 20.3);
    addElement(arr, 30.8);
    addElement(arr, 40.2); // Devrait déclencher un agrandissement

    // Affichage du tableau
    printf("Contenu du tableau :\n");
    displayArray(arr);

    // Affichage de l'espace disponible
    printf("Espace disponible 2 : %d\n", availableSpace(arr));

    // Récupération d'un élément par index
    int index = 2;
    double val;
    if (!getElement(arr, index, &val)) {
        printf("Échec de la récupération de l'élément.\n");
    }
    else {
        printf("Élément à l'index %d : %.2f\n", index, val);
    }

    // Suppression du dernier élément
    double pop;
    if (!popElement(arr, &pop)) {
        printf("Échec de la suppression de l'élément.\n");
    }
    else {
        printf("Élément supprimé : %.2f\n", pop);
    }

    // Affichage après suppression
    printf("Tableau après suppression :\n");
    displayArray(arr);

    // Libération de la mémoire
    destroyArray(arr);

    // Récupération d'un élément par index qui devrait échouer
    index = 1;
    if (!getElement(arr, index, &val)) {
        printf("Échec de la récupération de l'élément.\n");
    }
    else {
        printf("Élément à l'index %d : %.2f\n", index, val);
    }

    return 0;
}