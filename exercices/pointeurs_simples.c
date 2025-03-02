#include <stdio.h>
int main(){
    printf("Ex1--------------------------------------\n");
    int val_i = 12;
    double val_d = 2.34;
    char val_c = 'a';

    int* pi = NULL;
    int* pi1 = NULL;
    double* pd = NULL;
    char* pc = NULL;
    printf("1)--------------------------------------\n");
    val_i = 10;
    pi = &val_i;

    printf("&val_i = %p\n",&val_i);
    printf("pi = %p\n",pi); // = &val_i

    printf("2)--------------------------------------\n");
    val_i = 10;
    val_d = 0.123;
    pi = &val_i;
    pd = &val_d;
    val_i = 5;

    printf("&val_i = %p\n",&val_i);
    printf("pi = %p\n",pi); // = &val_i

    printf("&val_d = %p\n",&val_d);
    printf("pd = %p\n",pd); // = &val_d

    printf("3)--------------------------------------\n");
    val_c = 'a';
    val_i = 2;
    pc = &val_c;
    *pc += val_i;

    printf("&val_c = %p\n",&val_c);
    printf("pc = %p\n",pc); // = &val_c

    printf("val_i = %d\n",val_i);
    printf("val_c = %c\n",val_c);
    printf("*pc = %c\n",*pc);

    printf("4)--------------------------------------\n");
    val_c = 4;
    pc = &val_c;
    pi = &val_c;
    *pi = 6;

    printf("&val_c = %p\n",&val_c);
    printf("pc = %p\n",pc); // = &val_c
    printf("pi = %p\n",pi); // = &val_c
    printf("*pi = %d\n",*pi);
    printf("val_c = %d\n",val_c);
    printf("*pc = %d\n",*pc);
    return 0;
}