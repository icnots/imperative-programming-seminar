#include <stdlib.h>
#include <stdio.h>

#include "header.h"

#define n 5
#define BUFFERSIZE 20

int main(){
    /*int n = 5;*/
    //char *t[n];
    char **t = (char **)malloc(n * sizeof(char *));
    if (!t){
        fprintf(stderr, "No memory\n");
        exit(-1);
    }

    char buffer[BUFFERSIZE];

    for (int i = 0; i < n; i++){
        fgets(buffer, BUFFERSIZE, stdin);
        endStringAtNewline(buffer);
        
        t[i] = copyString(buffer); // malloc
    }
    
    for (int i = n - 1; i >= 0; i--){
        printf("%s\n", t[i]);
    }
    
    for (int i = 0; i < n; i++){
        free(t[i]);
    }
    free(t);
    return 0;
}
