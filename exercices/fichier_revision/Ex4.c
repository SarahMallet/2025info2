#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int z;
} Point;

void save_points(char* file, Point* p, int nb_elem){
    FILE* f = fopen(file, "wb");
    if(f==NULL)
        return;
    fwrite(p,sizeof(Point),nb_elem, f);
    fclose(f);
}

void add_point(char* file, Point* p){
    FILE* f = fopen(file, "a");
    if(f==NULL)
        return;
    fwrite(p, sizeof(Point), 1, f);
    fclose(f);
}

void read_point(char* file){
    FILE* f = fopen(file, "r");
    if(f==NULL)
        return;
    Point p[1024];
    size_t count = fread(p, sizeof(Point), 1024, f);
    if(count==0)
        return;
    for(size_t i=1;i<=count;i++){
        printf("point %ld : x=%d, y=%d, z=%d\n", i, p[i].x, p[i].y, p[i].z); 
    }
    fclose(f);
}

int main() {

    Point points[] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Point pointAdd[]={10,11,12};
    
    save_points("points.bin", points, 3);
    add_point("points.bin", pointAdd);
    read_point("points.bin");

    return 0;
}