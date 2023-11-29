#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 100

int main(int argc, char **argv){
    char buffer[BUFFERSIZE];
    int n;
    if (argc > 1){
        n = atoi(argv[1]);
        if (n < 1){
            fprintf(stderr, "please give a positive number\n");
            return 3;
        }    
    }else{
        fprintf(stderr, "please give a number as parameter\n");
        return 2;
    }
    
    char **t = (char**)malloc(n*sizeof(char*));
    
    for (int i = 0; i < n; i++){
        fgets(buffer, BUFFERSIZE, stdin);
        endStringAtNewline(buffer);
        
        int length = strlen(buffer);
        t[i] = (char *)malloc((length+1)*sizeof(char));
        if (!t[i]){
            fprintf(stderr, "not enough memory\n");
            return 1;
        }
        strcpy(t[i], buffer);
    }
      
    for (int i = n-1; i >= 0; i--){
        printf("%s\n", t[i]);
        free(t[i]);
    }
    free(t);
    
    return 0;
}
