#include <stdio.h>

void swap(int *a, int *b);

int main(){
    int i = 1, j = 2;
    
    printf("i: %d, j: %d\n", i, j);
    swap(&i, &j);
    
    printf("i: %d, j: %d\n", i, j);

    return 0;
}
