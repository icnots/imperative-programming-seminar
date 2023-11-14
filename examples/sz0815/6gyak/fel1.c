#include <stdio.h>

int main(){
    int i = 2, j = 7;
    
    printf("i: %d\n", i);
    
    int *pi = &i, *pj = &j;
    
    *pi = 19;

    printf("i: %d, j = %d\n", i, j);
    
    
    printf("pi: %p\n", (void*)pi);
    printf("&pi: %p\n", (void*)(&pi));
    
    int **ppi = &pi;
    
    **ppi = 12;
    
    printf("i: %d, j = %d\n", i, j);
    
    *ppi = pj;
    **ppi = 17;
    
    printf("i: %d, j = %d\n", i, j);
    
    pj = &i;
    **ppi = 15;
    
    printf("i: %d, j = %d\n", i, j);
    
    return 0;
}
