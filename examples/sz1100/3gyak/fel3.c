#include <stdio.h>


int main(){
    /* 2-es számrendszer:
    abcdefgh
    *2
    bcdefgh0
    +1
    bcdefgh1
    *2
    cdefgh10
    +1
    cdefgh11
    
    2 ^ k - 1
    *2
    2 ^ (k+1) - 2
    +1
    2 ^ (k+1) - 1
    */
    
    unsigned long int max = 0;
    
    for (unsigned long int i = 0; i < 8*sizeof(max); i++){
        max *= 2;
        max += 1;
    }

    /* max = -1; */
    printf("%lu\n", max);
    max++;
    printf("%lu\n", max);

    return 0;
}



