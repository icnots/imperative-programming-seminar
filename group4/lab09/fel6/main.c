#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 20
#define FIRSTSIZE 5

void correctString(char *p);
void memcheck(void *p);
char *copy(char *p);



int main(){
    int size = FIRSTSIZE;
    int counter = 0;
    
    char buffer[BUFFERSIZE];
    char **tomb;
    tomb = (char **)malloc(size * sizeof(char *));
    
    memcheck(tomb);
    
    fgets(buffer, BUFFERSIZE, stdin);
    correctString(buffer);
    while (strcmp(buffer, "END") != 0){
      
        tomb[counter] = copy(buffer);
        counter++;
        
        if (counter == size){
            size *= 2;
            tomb = (char **)realloc(tomb, size * sizeof(char *));
            
            memcheck(tomb);
                    
        }
        fgets(buffer, BUFFERSIZE, stdin);
        correctString(buffer);
        
    }
    
    fprintf(stdout, "%d %d\n", counter, size);
    
    for (int i = counter-1; i >=0; i--){
        fprintf(stdout, "%s\n", tomb[i]);
    }
    
    
    for (int i = 0; i < counter; i++){
        free(tomb[i]);
    }
    free(tomb);
    
    
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
