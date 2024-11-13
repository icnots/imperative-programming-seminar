#include "my_utils.h"
#include <stdio.h>

void testStatic(){
    static int v = 0;
    
    v++;
    printf("v: %d\n", v);
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int *greater(int *a, int *b){
    if (*a > *b){
        return a;
    }else{
        return b;
    }
}

