#include <stdio.h>

#include "my_utils.h"

int f2();
int f4();
void f5();
void f6(int);

void f7(int, int);

int global_variable = 4;

int main(){
    //f2();
    //f4();
    //f5();
    //f6(12);
    //f7(12, 13);
    /*
    testStatic();
    testStatic();
    testStatic();
    */
    
    int a = 11, b = 8;
    //int *p = &a, *q = &b;
    
    f7(a, b);
    
    
    void swap2(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    swap2(&a, &b);
    f7(a, b);
    
    /*
    //swap(&a, &b);
    *greater(&a, &b) -= 2;
    f7(a, b);
    *greater(&a, &b) -= 2;
    f7(a, b);
    *greater(&a, &b) -= 2;
    f7(a, b);
    *greater(&a, &b) -= 2;
    f7(a, b);
    *greater(&a, &b) -= 2;
    f7(a, b);
    */

    /*
    printf("global_variable: %d\n", global_variable);
    global_variable = 5;
    printf("global_variable: %d\n", global_variable);
    */

    return 0;
}

int f2(){
    int i = 3;
    
    if (i > 2){
        i += 1;
    }else{
        i += 2;
    }
    
    return i;
}

int f4(){
    int i = 20;
    if (1 == 1){
        i = 23;
    }
    
    i += 2;
    
    return i;
}

void f5(){
    int i = 0;
    {
        int j = 1;
        {
            int k = 2;
            {
                printf("i: %d, j: %d, k: %d\n", i, j, k);
            }
            printf("i: %d, j: %d, k: %d\n", i, j, k);
        }
        printf("i: %d, j: %d\n", i, j);
    }
    printf("i: %d\n", i);
    
    
    int p = 3;
    {
        printf("1: p: %d\n", p);
        int p = 4;
        printf("2: p: %d\n", p);
        {
            printf("3: p: %d\n", p);
            int p = 5;
            printf("4: p: %d\n", p);
        }
        printf("5: p: %d\n", p);
    }
    printf("6: p: %d\n", p);
}

void f6(int n){
    printf("n: %d\n", n);
}

void f7(int a, int b){
    printf("%d %d\n", a, b);
}


