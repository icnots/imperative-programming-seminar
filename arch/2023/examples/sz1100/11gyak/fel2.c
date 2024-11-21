#include <stdlib.h>
#include <stdio.h>

#include "header.h"

#define BUFFERSIZE 20

int main(){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    endStringAtNewline(buffer);
    
    reverse(buffer);
    
    fprintf(stdout, "%s\n", buffer);

    return 0;
}
