#include <stdio.h>

#include "my_utils.h"

int f();
int f2();
int f3();
int f6(int);
int f7(int, int);

int p = 3;

int main(){
    /*testStatic();
    testStatic();
    testStatic();
    testStatic();
    testStatic();
    testStatic();*/
    
    int a = 4, b = 4;
    /*
    printf("a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    */
    
    /*
    printf("a: %d, b: %d\n", a, b);
    *greater(&a, &b) -= 1;
    printf("a: %d, b: %d\n", a, b);
    *greater(&a, &b) -= 1;
    printf("a: %d, b: %d\n", a, b);
    *greater(&a, &b) -= 1;
    printf("a: %d, b: %d\n", a, b);
    */

    void swap2(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }



    printf("a: %d, b: %d\n", a, b);
    swap2(&a, &b);
    printf("a: %d, b: %d\n", a, b);


    //printf("result of f2: %d\n", f2())	;
    //a = 4;
    
    //f3();
    
    //f6(12);
    //f7(1, 2);
    
    /*
    printf("p: %d\n", p);
    p = 5;
    printf("p: %d\n", p);
    f();
    printf("p: %d\n", p);
    int p = 4;
    printf("p: %d\n", p);
    */

    return 0;
}

int f(){
    p = 6;
    return 0;
}

int f2(){
    int a = 3;
    
    if (a > 0){
        a = 4;
        int b = 7;
        b ++;
    }else{
        a = 5;
    }
    // b = 8;
    
    return a;
}


int f3(){
    int i = 0;
    {
        int j = 1;
        {
            int k = 2;
            printf("i: %d, j: %d, k: %d\n", i, j, k);
        }
        printf("i: %d, j: %d\n", i, j);
    }

    printf("i: %d\n", i);


    int a = 0;
    {
        printf("1. a: %d\n", a);
        int a = 1;
        printf("2. a: %d\n", a);
        {
            printf("3. a: %d\n", a);
            int a = 2;
            printf("4. a: %d\n", a);
        }
        printf("5. a: %d\n", a);
    }
    printf("6. a: %d\n", a);


    return 0;
}

int f6(int a){
    printf("a: %d\n", a);
    
    return 0;
}


int f7(int a, int b){
    a = b;
    b = a;
    return 0;
}

