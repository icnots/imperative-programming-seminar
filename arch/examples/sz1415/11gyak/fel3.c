#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 20

int main(){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    endStringAtNewline(buffer);
    
    char *reversedBuffer = reversed(buffer);
    
    printf("%s => %s\n", buffer, reversedBuffer);
    
    free(reversedBuffer);
    return 0;
}
