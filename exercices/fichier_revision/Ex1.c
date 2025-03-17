#include <stdio.h>

int main() {
    FILE* f = fopen("Ex1.txt", "r");
    if(f==NULL)
        return -1;
    fseek(f, 0, SEEK_END);
    long long_file = ftell(f);
    fclose(f);
    printf("%ld\n",long_file);
    return 0;
}