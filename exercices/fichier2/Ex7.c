#include <stdio.h>
#include <stdlib.h>

int main(){
    int year, month, day;
    int hour, min;
    int id;
    double value;

    int line = 3;
    int current_line = 1;

    FILE* f = fopen("Ex7.txt","r");
    if(f==NULL)
        return -1;
    
        while (fscanf(f, "%d-%d-%d %d:%d\t%d\t%lf", 
            &year, &month, &day, &hour, &min, &id, &value) == 7) {
                if (current_line == line) {
                    printf("\nExercice 7 : lecture\n");
                    printf("Dat : %d/%d/%d\n", day, month, year);
                    printf("Time : %dh%d\n", hour, min);
                    printf("Value : %.2lf\n", value);
                    break;
                }
                current_line++;
            
        }

fclose(f);
return 0;
}