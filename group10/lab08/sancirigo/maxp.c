#include <stdio.h>

int *maxp(int *x, int *y){
    if (*x > *y){
        return x;
    }
    return y;
}

int main(){
    int a = 18;
    int b = 9;
    int *bigp;
    bigp = maxp(&a, &b);
    printf("%d\n", *bigp);
    return 0;
}