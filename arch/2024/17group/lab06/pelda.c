#include <stdio.h>


void func(int t[], int l);
void func(int *t, int l);

int main(){
    int i, j;
    int *p;
    
    i = 1;
    j = 2;    
    p = &i;

    *p = 3;

    int **pp;
    
    pp = &p;
    **pp = 5;
    *pp = &j;
    *p = 7;

    int t[10] = {0};
    int length = sizeof(t) / sizeof(t[0]);
    
    /* int *p; */
    p = &(t[2]);
    p = t + 2;
    
    *p = 10;
    t[2] = 10;
    *(t+2) = 10;
    *(2+t) = 10;
    2[t] = 10;
    p[0] = 10;
    0[p] = 10;
    *(0 + p) = 10;
    
    return 0;
}
