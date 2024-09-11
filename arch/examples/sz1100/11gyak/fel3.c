#include <stdlib.h>
#include <stdio.h>

#include "header.h"

#define BUFFERSIZE 20

int main(){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    endStringAtNewline(buffer);
    
    char *rev = reversed(buffer);
    
    fprintf(stdout, "%s - %s\n", buffer, rev);

    free(rev);
    return 0;
}
