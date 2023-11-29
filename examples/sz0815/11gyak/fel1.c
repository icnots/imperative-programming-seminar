#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 20

void memcheck(void *p);
void removeWhitespaces(char *s);

int main(){
    char buffer[BUFFERSIZE];
    char *copy;
    int length;
    
    fgets(buffer, BUFFERSIZE, stdin);
    removeWhitespaces(buffer);
    length = strlen(buffer);
    
    copy = (char *)malloc((length+1) * sizeof(char));
    memcheck(copy);
    for (int i = 0; i <= length; i++){
        copy[i] = buffer[i];
    }
    
    fprintf(stdout, "%s\n", copy);


    free(copy);
    return 0;
}



void removeWhitespaces(char *s){
    while(*s != '\0'){
        if (isspace(*s)){
            *s = '\0';
            return;
        }
        s++;
    }
}





void memcheck(void *p){
    if (!p){
        fprintf(stderr, "Not enough memory\n");
        exit(-1);
    }
}
