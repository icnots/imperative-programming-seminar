#include <stdio.h>

typedef int * intp;

int main(){
    int i = 12;
    int *pi;
    int **ppi;

    ppi = &pi;

    *ppi = &i;


    intp p;
    intp *pp;
    
    pp = &p;
    *pp = &i;

    *p = 23;
    
    printf("%d\n", i);
    

    return 0;
}
