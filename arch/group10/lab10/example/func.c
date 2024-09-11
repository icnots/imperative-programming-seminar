#include <stdio.h>
#include <stdlib.h>

#include "func.h"


int *func1(int a, int b){
    static int result;
    
    result = a + b;
    
    return &result;
}


int *func2(int a, int b){
    int *p = (int *)malloc(sizeof(int));
    
    if (p != NULL){
        *p = a + b;
    }else{
        printf("No memory\n");
        exit(1);
    }
    
    return p;
}
