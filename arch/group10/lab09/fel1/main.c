#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 1024

void correctString(char *p);
char *copy(char *p);
void memcheck(void *p);

int main(){
    char buffer[BUFFERSIZE];
    
    fgets(buffer, BUFFERSIZE, stdin);
    
    correctString(buffer);

    char *newString = copy(buffer);

    printf("1.: %s\n2.: %s\n", buffer, newString);

    free(newString);

    return 0;
}

void memcheck(void *p){
    if (NULL == p){
        fprintf(stderr, "Error in memcheck\n");
        exit(1);
    }
}

char *copy(char *p){
    int length = strlen(p)+1;
    char *new = (char *)malloc(length * sizeof(char));
    
    memcheck(new);
    
    strcpy(new, p);
    return new;
}

void correctString(char *p){
    while ( (*p != '\r') && (*p != '\n') && (*p != '\0') ){
        p++;
    }
    *p = '\0';
}
