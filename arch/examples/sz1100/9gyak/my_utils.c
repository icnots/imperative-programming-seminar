#include "my_utils.h"

#include <stdio.h>


int sum(int a, int b){
    return a+b;
}

void print(int a, int b){
    printf("a: %d, b: %d\n", a, b);
}

void printTable(int a[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


void func(void){
    static int counter = 0;
    counter++;
    
    printf("func() is called %d times\n", counter);
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int *max(int *a, int *b){
    if (*a < *b){
        return b;
    }else{
        return a;
    }
}

int *min(int *a, int *b){
    if (*a > *b){
        return b;
    }else{
        return a;
    }
}

