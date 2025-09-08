#include "fel2.h"
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 50

void fel2(){
    printf("fel2\n");
    
    
    char buffer1[BUFFERSIZE];
    char buffer2[BUFFERSIZE];
    fgets(buffer1, BUFFERSIZE, stdin);
    fgets(buffer2, BUFFERSIZE, stdin);
    
    int result = strcmp(buffer1, buffer2);
    
    if (result < 0){
        printf("first appears before second in lexicographical order\n");
    }else if (result > 0){
        printf("first appears after second in lexicographical order\n");
    }else{
        printf("chararrays are equal\n");
    }
}
