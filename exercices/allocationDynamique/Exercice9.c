#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void insert_element(int* tableau, int* count, int element){
    if(!tableau || !count)
        return;
    for(int i=*count;i>0;i--){
        tableau[i]=tableau[i-1];
    }
    tableau[0]=element;
    (*count) ++;
}

int main(void){
    int* tab = (int*)malloc(10*sizeof(int));
    int nbElem = 5;
    tab[0] = 10;
    tab[1] = 20;
    tab[2] = 30;
    tab[3] = 40;
    tab[4] = 50;
    insert_element(tab, &nbElem, 90);
    for(int i=0;i<nbElem;i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}