#include <stdio.h>

int main(){
    unsigned int max;
    
    /*
    abcdefghijk
    *2
    bcdefghijk0
    +1
    bcdefghijk1
    *2
    cdefghijk10
    +1
    cdefghijk11    
    */
    for (unsigned int i = 0; i < 8*sizeof(max); i++){
        max *= 2;
        max += 1;
    }
    
    /* max = -1; */
    printf("Max: %u\n", max);
    max++;
    printf("Min: %u\n", max);


    return 0;
}
