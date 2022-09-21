#include <stdio.h>

int main(){
    int i, n = 1;
    
    printf("size of int: %ld\n", sizeof(int));
    printf("size of long double: %ld\n", sizeof(long double));
    printf("size of variable i: %ld\n", sizeof(i));

    for (i = 0; i < 31; i++){
        n *= 2; /* n = n * 2; */
    }   
    n -= 1;
    
    printf("n : %d\n", n);
    
    n++;
    printf("n : %d\n", n);
    
    n = 0;
    
    /* kevésbé jó
    while (n+1 > n){
        n++;
    }
    printf("n : %d\n", n);
    */
    
    return 0;
}
