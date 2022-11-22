#include <stdio.h>
#include <stdlib.h>

#include "func.h"

int main(){
    int *p1, *p2;
    
    p1 = func2(2, 3);
    p2 = func2(4, 5);
    
    printf("*p1: %d\n", *p1);
    printf("*p2: %d\n", *p2);
    
    free(p1);
    free(p2);
    
    return 0;
}

