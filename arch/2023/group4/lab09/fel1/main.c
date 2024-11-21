#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 20


char *copy(char *p);

int main(){
    char buffer[BUFFERSIZE];
    
    fgets(buffer, BUFFERSIZE, stdin);
    
    char *newString;
    char *newString2;
    
    newString = copy(buffer);
    newString2 = copy(newString);
    
    fprintf(stdout, "%s%s", buffer, newString);
    
    free(newString);
    free(newString2);

    return 0;
}

char *copy(char *p){
    int length = strlen(p);

    char *newP = (char *)malloc((length+1) * sizeof(char));

    if (newP == NULL){
        fprintf(stderr, "No memory\n");
        exit(1);
    }
    
    for (int i = 0; i < length +1; i++){
        newP[i] = p[i];
    }
    
    return newP;
}
