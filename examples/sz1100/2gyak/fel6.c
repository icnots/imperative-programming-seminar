#include <stdio.h>

int main(){
    int max = 0;
    unsigned int i;
    
    for (i = 1; i < 8 * sizeof(int); ++i){
        /* max = 2 * max + 1; */
        max = 2 * max; /* max *= 2; */
        max = max + 1; /* max += 1; max++; ++max; */
        
        /*printf("%d\n", ++i);*/
    }
    
    printf("Max: %d\n", max);
    
    max++;
    
    printf("Max: %d\n", max);
    

    return 0;
}
