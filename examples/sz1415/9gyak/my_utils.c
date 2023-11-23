#include "my_utils.h"

#include <stdio.h>

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int *func(void){
    static int n = 0;
    n++;
    return &n;
}

int sum(int n1, int n2){
    return n1 + n2;
}


void staticFunction(void){
    static int variable = 10;
    
    variable += 2;
    printf("variable: %d\n", variable);
}


void swap(int *p1, int *p2){
    int atm = *p1;
    *p1 = *p2;
    *p2 = atm;
}


int *max(int *p1, int *p2){
    if (*p1 > *p2){
        return p1;
    }else{
        return p2;
    }

}

int *min(int *p1, int *p2){
    if (*p1 < *p2){
        return p1;
    }else{
        return p2;
    }

}


