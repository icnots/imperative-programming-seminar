#include <stdio.h>

void test(){
    static int a = 0;
    a++;
    printf("%d\n", a);

    return;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int fact(int x){
    static int smol;
    int i;
    int num = 1;
    if (x < 1){
        smol++;
        printf("Eddigi 1-nel kisebb hivasok: %d\n", smol);
        return x;
    } else {
        for ( i = 2; i <= x; i++){
            num *= i;
        }
        return num;
    }
}

int main(){
    int a,b;
    a = 15;
    b = 18;
    swap(&a, &b);
    printf("%d\t%d\n", a, b);
    printf("%d\n",fact(0));
    printf("%d\n",fact(1));
    printf("%d\n",fact(2));
    printf("%d\n",fact(3));
    printf("%d\n",fact(5));
    printf("%d\n",fact(4));
    return 0;
}