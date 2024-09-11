#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "header.h"

#define BUFFERSIZE 20

int main(int argc, char **argv){
    int n;
    if (argc > 1){
        n = atoi(argv[1]);
    }else{
        fprintf(stderr, "Please provide a number as argument\n");
        return 2;
    }
    
    char **t = (char **)malloc(n * sizeof(char *));
    if (!t){
        fprintf(stderr, "No memory\n");
        exit(-1);
    }

    char buffer[BUFFERSIZE];

    for (int i = 0; i < n; i++){
        fgets(buffer, BUFFERSIZE, stdin);
        endStringAtNewline(buffer);
        
        /* //Jó megoldás:
        int length = strlen(buffer);
        t[i] = (char *)malloc((length+1)*sizeof(char));
        if (!t[i]){
            fprintf(stderr, "No memory\n");
            exit(-1);
        }
        strcpy(t[i], buffer);
        */
        
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
