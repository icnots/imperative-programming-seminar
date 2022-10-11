#include <stdio.h>

int main(){
    int i, j;
    i = 12;
    
    printf("%d\n", i);
    
    int *p;
    p = &i;

    p = &j;
    int **pp;
    
    pp = &p;
    
    printf("%d\n", *p);

    return 0;
}
