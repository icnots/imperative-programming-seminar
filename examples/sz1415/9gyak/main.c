#include <stdio.h>

#include "my_utils.h"

int main(){



    printf("func: %d\n", *func());
    printf("func: %d\n", *func());
    printf("func: %d\n", *func());
    
    int *p = func();
    *p = 16;
    
    printf("func: %d\n", *func());
    printf("func: %d\n", *func());
    
    staticFunction();
    staticFunction();
    staticFunction();
    
    int *(*function)(int*,int*) = min;
    
    int a = 3, b = 10;
    printf("a: %d, b: %d\n", a, b);
    ++(*max(&a, &b));
    printf("a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    p = max(&a, &b);
    ++(*p);
    printf("a: %d, b: %d\n", a, b);
    
    void swap2(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    swap2(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    
    ++*function(&a, &b);
    
    
    return 0;
}



