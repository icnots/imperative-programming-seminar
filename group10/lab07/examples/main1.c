#include <stdio.h>

int main(){
    int i = 1, j = 2;
    
    /* int *p = &i; */
    int *p;
    p = &i;
    
    int **pp = &p;
    /*int **pp;
    pp = &p;*/
    
    *p = 3;
    *pp = &j;
    **pp = 4;
    *p = 5;
    
    /* What are in variables i and j here? */

    return 0;
}

