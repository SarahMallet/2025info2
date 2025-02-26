#include <stdio.h>

#include <stdio.h>

int main() {
    int a = 10;
    int tab[2] = {1,2};
    int *p = &a;
    int *p1tab = tab;  // Correct
    int *p1tab1 = &tab[1]; // Correct

    printf("a = %d\n", a);
    printf("p = %p\n", (void *)p);
    printf("*p = %d\n", *p);

    printf("p1tab = %p\n", (void *)p1tab);
    printf("p1tab1 = %p\n", (void *)p1tab1);
    
    return 0;
}