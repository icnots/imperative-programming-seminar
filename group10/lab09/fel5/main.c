#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 1024

void correctString(char *p);
char *copy(char *p);
void memcheck(void *p);

int main(int argc, char **argv){
    if (argc != 2){
        printf("please give me a number\n");
        return 2;
    }
    char buffer[BUFFERSIZE];
    int n = atoi(argv[1]);
    char **tomb;
    tomb = (char **)malloc(n * sizeof(char *));
    
    memcheck(tomb);
    
    for (int i = 0; i < n; i++){
        fgets(buffer, BUFFERSIZE, stdin);
         
        correctString(buffer);
        
        tomb[i] = copy(buffer);
    }
    
    for (int i = n-1; i >= 0; i--){
        printf("%d: %s\n", i, tomb[i]);
    }
    
    for (int i = 0; i < n; i++){
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
