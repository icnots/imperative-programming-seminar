#include "fel4.h"
#include <stdio.h>	

#define BUFFERSIZE 50

void fel4(){
    printf("fel4\n");
    
    char buffer1[BUFFERSIZE] = "Almafa";
    const char *buffer2 = "Almafa";
    
    // buffer2 == buffer1 ==> strcmp(buffer2, buffe1) == 0
    
    buffer1[0] = 'a';
    //buffer2[0] = 'a';
    
    printf("buffer1: %s\n", buffer1);
    printf("buffer2: %s\n", buffer2);
}
