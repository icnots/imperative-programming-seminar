#include <stdio.h>
#include <stdlib.h>

int *func1(int a, int b);
int *func2(int a, int b);

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
