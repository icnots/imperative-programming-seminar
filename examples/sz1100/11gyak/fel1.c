#include <stdlib.h>
#include <stdio.h>

#include "header.h"

#define BUFFERSIZE 20

int main(){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    endStringAtNewline(buffer);
    
    char *copyBuffer = copyString(buffer);
    printf("copy: %s\n", copyBuffer);
    
    free(copyBuffer);
    return 0;
}
