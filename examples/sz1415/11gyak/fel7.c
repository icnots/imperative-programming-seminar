#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 100

int main(){
    char buffer[BUFFERSIZE];
    int n = 1;
    
    int counter = 0;
    char **t = (char**)malloc(n*sizeof(char*));
    
    while (fgets(buffer, BUFFERSIZE, stdin)){
        endStringAtNewline(buffer);
        
        if (counter == n){
            increase(&n, &t);
            
            /*n *= 2;
            t = (char**)realloc(t, n*sizeof(char*));
            if (!t){
                fprintf(stderr, "not enough memory\n");
                return 1;
            }*/
        }
        
        int length = strlen(buffer);
        t[counter] = (char *)malloc((length+1)*sizeof(char));
        if (!t[counter]){
            fprintf(stderr, "not enough memory\n");
            return 1;
        }
        strcpy(t[counter], buffer);
        counter++;
    }
      
    for (int i = counter-1; i >= 0; i--){
        printf("%s\n", t[i]);
        free(t[i]);
    }
    free(t);
    
    return 0;
}
