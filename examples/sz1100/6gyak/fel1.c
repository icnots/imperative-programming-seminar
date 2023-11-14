#include <stdio.h>

int main(){
    int i = 2, j = 3;
    printf("i: %d, j: %d\n", i, j);
    
    int *pi = &i, *pj = &j;
    *pi = 4; /* i = 4 */
    
    printf("i: %d, j: %d\n", i, j);
    
    int **pp;
    pp = &pi;
    **pp = 5; /* *pi = 5; i = 5 */
    
    printf("i: %d, j: %d\n", i, j);
    
    *pp = pj; /* pi = pj; */
    **pp = 6;
    
    printf("i: %d, j: %d\n", i, j);
    
    *pi = 7;
    
    printf("i: %d, j: %d\n", i, j);

    printf("%p\n", (void*)pi);

    
    
    int a = pp;

    return 0;
}
