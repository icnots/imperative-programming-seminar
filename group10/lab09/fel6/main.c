#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 1024
#define FIRSTN 5

void correctString(char *p);
char *copy(char *p);
void memcheck(void *p);

int main(){

    char buffer[BUFFERSIZE];
    int n = FIRSTN;
    int counter = 0;
    char **tomb;
    tomb = (char **)malloc(n * sizeof(char *));
    
    memcheck(tomb);
    
    fgets(buffer, BUFFERSIZE, stdin);
    correctString(buffer);
    
    while ( 0 != strcmp(buffer, "END") ){
        tomb[counter] = copy(buffer);
        counter++;
    
        if (counter == n){
            n *= 2;
            
            tomb = (char **)realloc(tomb, n * sizeof(char *));
            memcheck(tomb);
        }
    
        fgets(buffer, BUFFERSIZE, stdin);
        correctString(buffer);
    }

    
    for (int i = counter-1; i >= 0; i--){
        printf("%d: %s\n", i, tomb[i]);
    }
    
    for (int i = 0; i < counter; i++){
        free(tomb[i]);
    }
    
    free(tomb);

    
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
