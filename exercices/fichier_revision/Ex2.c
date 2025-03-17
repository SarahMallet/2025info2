#include <stdio.h>

int main() {
    size_t count = 0;
    char buffer[1024];
    FILE* f = fopen("Ex1.txt", "r");
    if(f==NULL)
        return -1;
    while (fgets(buffer, 1024, f)!=NULL){
        count++;
    }
    
    fclose(f);
    printf("%ld\n", count);
    return 0;
}