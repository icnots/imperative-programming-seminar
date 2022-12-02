#include <stdio.h>
#include <stdlib.h>

int anyad = 15;

int *szam(){
    int i = 3;
    int *ip = &i;
    return ip;
}

int *statszam(int a, int b){
    int *ptr = (int*) malloc(sizeof(int));
    *ptr = a + b;
    return ptr;
}

int main(){
    int *num = szam();
    int res = *statszam(5, 15);
    printf("%d\n", *num);
    printf("%d\n", res);
    return 0;
}

