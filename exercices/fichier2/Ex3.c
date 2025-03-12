#include <stdio.h>

int main() {
    FILE* f = fopen("Ex3.txt", "w");
    if (f == NULL)
        return -1;
    for(int i=1; i<=100;i++){
        int multiple7 = i*7;
        if(multiple7>100)
            break;
        fprintf(f,"%d\n",multiple7);
    }
    fclose(f);
    
}