#include <stdio.h>

#include "my_utils.h"

void f(int m, int n){
    printf("n: %d\n", n);
    printf("m: %d\n", m);
}

int g(int m, char ch){
    printf("char: %d\n", ch);
    printf("m: %d\n", m);
    return 0;
}



void func(void){
    static int s = 1;

    s += 2;

    printf("s: %d\n", s);
}


void swap(int *pa, int *pb){
    int atm = *pa;
    *pa = *pb;
    *pb = atm;
}


int *max(int *pa, int *pb){
    if (*pa > *pb){
        return pa;
    }else{
        return pb;
    }
}
int *min(int *pa, int *pb){
        if (*pa < *pb){
            return pa;
        }else{
            return pb;
        }
    }
