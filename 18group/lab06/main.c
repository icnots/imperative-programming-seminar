#include <stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int i = 1, j = 2;
    
    printf("i:%d j:%d\n", i, j);
    swap(&i, &j);
    printf("i:%d j:%d\n", i, j);
    
    
    int n;
    n = i;

    int *pi = &i;
    
    int t[10] = {0};
    
    int *p = &(t[1]);
    p = t+1;

    *p = 1;
    t[1] = 1;
    *(t+1) = 1;

    p[0] = 1;
    *(p+0) = 1;
    *(0+p) = 1;
    0[p] = 1;
    
    
    int **pp;
    pp = &p;
    (*pp) += 1;
    
    return 0;
}
