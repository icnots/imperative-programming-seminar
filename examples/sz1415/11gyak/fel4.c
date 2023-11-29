#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 100
#define n 5

int main(){
    char buffer[BUFFERSIZE];
    char *t[n];
    
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
    
    return 0;
}
