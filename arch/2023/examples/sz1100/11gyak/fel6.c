#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "header.h"

#define BUFFERSIZE 20

int main(int argc, char **argv){
    int counter = 0;
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

    while (counter < n){
        fgets(buffer, BUFFERSIZE, stdin);
        endStringAtNewline(buffer);
        
        if (0 == strcmp(buffer, "end")){
            n = counter;
        }else{
        
            int length = strlen(buffer);
            t[counter] = (char *)malloc((length+1)*sizeof(char));
            if (!t[counter]){
                fprintf(stderr, "No memory\n");
                exit(-1);
            }
            strcpy(t[counter], buffer);
            counter++;
        }
    }
    
    for (int i = counter - 1; i >= 0; i--){
        printf("%s\n", t[i]);
    }
    
    for (int i = 0; i < counter; i++){
        free(t[i]);
    }
    free(t);
    return 0;
}
