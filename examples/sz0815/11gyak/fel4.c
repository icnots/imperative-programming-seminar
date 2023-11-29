#include "fel4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 40


void fel4(void){
    char buffer[BUFFERSIZE];
    char **t = (char **)malloc(5*sizeof(char*));
    if (!t){
        fprintf(stderr, "No mem\n");
        exit(-1);
    }
    
    for (int i = 0; i < 5; i++){
        fgets(buffer, BUFFERSIZE, stdin);
        removeNewline(buffer);
        t[i] = copyString(buffer);
    }
    for (int i = 5-1; i >= 0; i--){
        fprintf(stdout, "%s\n", t[i]);
    }
    
    
    for (int i = 0; i < 5; i++){
        free(t[i]);
    }
    free(t);
}


char *copyString(char *str){
    int length = strlen(str);
    char *copy = (char *)malloc((length+1) * sizeof(char));

    if (!copy){
        fprintf(stderr, "No mem\n");
        exit(-1);
    }
    for (int i = 0; i <= length; i++){
        copy[i] = str[i];
    }
    return copy;
}



void removeNewline(char *s){
    while (*s != '\0'){
        if (*s == '\n'){
            *s = '\0';
            return;
        }
        s++;
    }
}



void fel5(int argc, char *argv[]){
    int n;
    if (argc == 2){
        n = atoi(argv[1]);    
    }else{
        fprintf(stderr, "Please provide a valid integer\n");
        exit(-2);
    }
    
    char buffer[BUFFERSIZE];
    char **t = (char **)malloc(n*sizeof(char*));
    if (!t){
        fprintf(stderr, "No mem\n");
        exit(-1);
    }
    
    for (int i = 0; i < n; i++){
        fgets(buffer, BUFFERSIZE, stdin);
        removeNewline(buffer);
        t[i] = copyString(buffer);
    }
    for (int i = n-1; i >= 0; i--){
        fprintf(stdout, "%s\n", t[i]);
    }
    
    
    for (int i = 0; i < n; i++){
        free(t[i]);
    }
    free(t);

}


void fel6(){
    int n = 6;
    
    char buffer[BUFFERSIZE];
    char **t = (char **)malloc(n*sizeof(char*));
    if (!t){
        fprintf(stderr, "No mem\n");
        exit(-1);
    }
    
    int counter = 0;
    while(1){
        fgets(buffer, BUFFERSIZE, stdin);
        removeNewline(buffer);
        
        if (0 == strcmp(buffer, "end")){
            break;
        }
        
        if (counter == n){
            increase(&t, &n);
        }
        
        t[counter] = copyString(buffer);
        counter++;
    }
    
    
    for (int i = counter-1; i >= 0; i--){
        fprintf(stdout, "%s\n", t[i]);
    }
    
    
    for (int i = 0; i < counter; i++){
        free(t[i]);
    }
    free(t);

}

void fel7(){
    int n = 6;
    
    char buffer[BUFFERSIZE];
    char **t = (char **)malloc(n*sizeof(char*));
    if (!t){
        fprintf(stderr, "No mem\n");
        exit(-1);
    }
    
    int counter = 0;
    while(fgets(buffer, BUFFERSIZE, stdin)){
        removeNewline(buffer);
                
        if (counter == n){
            increase(&t, &n);
        }
        
        t[counter] = copyString(buffer);
        counter++;
    }
    
    
    for (int i = counter-1; i >= 0; i--){
        fprintf(stdout, "%s\n", t[i]);
    }
    
    
    for (int i = 0; i < counter; i++){
        free(t[i]);
    }
    free(t);

}


void increase(char ***pt, int *pn){
    *pn *= 2;
    *pt = (char **)realloc(*pt, (*pn)*sizeof(char*));
    if (!*pt){
        fprintf(stderr, "No mem\n");
        exit(-1);
    }
}
