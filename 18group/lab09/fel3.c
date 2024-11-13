#include "fel3.h"
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 50

void fel3(){
    printf("fel3\n");
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    
    char copy[BUFFERSIZE];
    
    strcpy(copy, buffer);
    
    printf("buff: %s\n", buffer);
    printf("copy: %s\n", copy);
}
