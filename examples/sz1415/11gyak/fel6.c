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
    
    int counter = 0;
    char **t = (char**)malloc(n*sizeof(char*));
    
    while (counter < n){
        fgets(buffer, BUFFERSIZE, stdin);
        endStringAtNewline(buffer);
        
        if (0 == strcmp(buffer, "end")){
            n = counter;
        }else{
            int length = strlen(buffer);
            t[counter] = (char *)malloc((length+1)*sizeof(char));
            if (!t[counter]){
                fprintf(stderr, "not enough memory\n");
                return 1;
            }
            strcpy(t[counter], buffer);
            counter++;
        }
    }
      
    for (int i = counter-1; i >= 0; i--){
        printf("%s\n", t[i]);
        free(t[i]);
    }
    free(t);
    
    return 0;
}
