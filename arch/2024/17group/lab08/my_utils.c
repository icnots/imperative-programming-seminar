#include <stdio.h>

#include "my_utils.h"

void testStatic(){
    static int s = 0;

    s++;
    
    printf("s: %d\n", s);
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int *greater(int *a, int *b){
    if (*a < *b){
        return b;
    }else{
        return a;
    }
}

