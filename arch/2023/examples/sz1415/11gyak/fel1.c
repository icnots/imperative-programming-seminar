#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 20

int main(){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    endStringAtNewline(buffer);
    
    int length = strlen(buffer);
    char *copy = (char*)malloc((length+1)*sizeof(char));
    if (copy == NULL){ /* (!copy) */
        fprintf(stderr, "Not enough memory\n");
        exit(1);
    }
    strcpy(copy, buffer);
    
    fprintf(stdout, "buffer: %s\n", buffer);
    fprintf(stdout, "copy  : %s\n", copy);
    
    free(copy);
    return 0;
}
