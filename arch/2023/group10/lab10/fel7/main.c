#include <stdio.h>
#include <stdlib.h>

#include "fel7.h"

int main(int argc, char **argv){
    int size, counter = 0;
    int *p = NULL;
    
    for (int i = 1; i < argc; i++){
        printf("Feldogozas: %s\n", argv[i]);
        p = feldolgoz(argv[i], p, &size, &counter);
    }
    
    fileWrite(p, "output.txt", counter);
    
    if (!p){
        free(p);
    }


    return 0;
}
