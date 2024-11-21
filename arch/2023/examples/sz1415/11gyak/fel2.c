#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 20

int main(){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    endStringAtNewline(buffer);
    
    reverse(buffer);
    
    printf("reversed: %s\n", buffer);
    
    return 0;
}
