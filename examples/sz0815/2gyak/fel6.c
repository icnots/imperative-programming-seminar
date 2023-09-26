#include <stdio.h>

int main(){
    int max = 0;
    unsigned int i;
    
    printf("%ld == ", sizeof(max));
    printf("%ld\n", sizeof(int));
    
    for (i = 1; i < 8*sizeof(int); ++i){
        max = 2*max; /* max *= 2;*/
        max = max + 1; /* max++; ++max; max += 1;*/ 
    }
    
    printf("max: %d\n", max);
    max++;
    printf("max: %d\n", max);
    
    return 0;
}
