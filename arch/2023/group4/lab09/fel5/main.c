#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 20


void correctString(char *p);
void memcheck(void *p);
char *copy(char *p);


int main(int argc, char **argv){
    if (argc > 1){
        int n = atoi(argv[1]);
        
        char buffer[BUFFERSIZE];
        char **tomb;
        tomb = (char **)malloc(n * sizeof(char *));
        
        memcheck(tomb);
        
        for (int i = 0; i < n; i++){
            fgets(buffer, BUFFERSIZE, stdin);
            
            correctString(buffer);
            
            tomb[i] = copy(buffer);
        }
        
        for (int i = n-1; i >=0; i--){
            fprintf(stdout, "%s\n", tomb[i]);
        }
        
        
        for (int i = 0; i < n; i++){
            free(tomb[i]);
        }
        free(tomb);
    }
    
    
    return 0;
}


void correctString(char *p){
    while ( (*p != '\r') && (*p != '\n') && (*p != '\0') ){
        p++;
    }
    *p = '\0';
}

void memcheck(void *p){
    if (p == NULL){
        fprintf(stderr, "Error\n");
        exit(1);
    }
}


char *copy(char *p){
    int length = strlen(p);

    char *newP = (char *)malloc((length+1) * sizeof(char));

    memcheck(newP);
    
    for (int i = 0; i < length +1; i++){
        newP[i] = p[i];
    }
    
    return newP;
}
