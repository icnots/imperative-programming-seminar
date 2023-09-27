#include <stdio.h>

int main(){
    unsigned int max;
    /* 2-es számrendszer:
    
    abcdefg
    *2
    bcdefg0
    +1
    bcdefg1
    
    10-es számrendszer:
    
    1.   -->  00      (0)
    2.   -->  01      (1)
    3.   -->  10      (2)
    2^k. -->  1111111 (2^k-1)
    
    1111 -> 2^32 - 1
    
    
    2^t - 1
    *2
    2^(t+1) - 2
    + 1
    2^(t+1) - 1
              */

    for (long unsigned int i = 0; i < 8*sizeof(max); i++){
        max *= 2;
        max += 1;
    }

    /* max = -1;*/
    printf("max: %u\n", max);
    
    max += 1;
    
    printf("min: %u\n", max);

    return 0;
}
