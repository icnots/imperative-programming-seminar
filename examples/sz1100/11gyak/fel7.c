#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "header.h"

#define BUFFERSIZE 20

int main(){
    int *p = (int*)malloc(100000000000000*sizeof(int));
    if (!p){
        fprintf(stderr, "No memory\n");
        exit(-1);
    }
    int counter = 0;
    int n = 1;
    
    char **t = (char **)malloc(n * sizeof(char *));
    if (!t){
        fprintf(stderr, "No memory\n");
        exit(-1);
    }

    char buffer[BUFFERSIZE];

    while (fgets(buffer, BUFFERSIZE, stdin)){
        endStringAtNewline(buffer);
        
        if (counter == n){
            increase(&t, &n);
        }
        
        int length = strlen(buffer);
        t[counter] = (char *)malloc((length+1)*sizeof(char));
        if (!t[counter]){
            fprintf(stderr, "No memory\n");
            exit(-1);
        }
        strcpy(t[counter], buffer);
        counter++;
        
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
