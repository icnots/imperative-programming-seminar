#include <stdio.h>


void getValue(int *k, int *l);

int main(){
    int j = 19;
    int *p;    
    printf("j: %d\n", j);
    p = &j;
    int *p2 = &j;

    getValue(p, p2);
    
    printf("j: %d\n", j);



    return 0;
}



void getValue(int *k, int *l){

    printf("*k: %d\n", *k);
    scanf("%d", k);
    printf("*k: %d\n", *k);
    scanf("%d", l);
}
