#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"


#define BUFFERSIZE 51

int demo(void){
    int n;
    char **t;
    char buffer[BUFFERSIZE];
    
    fgets(buffer, BUFFERSIZE, stdin);
    sscanf(buffer, "%d", &n);
    
    t = (char **)malloc(n * sizeof(char *));
    if (!t){ // (NULL == t)
        fprintf(stderr, "No memory\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++){
        printf("%d: ", i+1);
        fgets(buffer, BUFFERSIZE, stdin);
        int len = strlen(buffer) + 1; // '\0' miatt a +1
        t[i] = (char *)malloc(len * sizeof(char));
        if (!(t[i])){ // (NULL == t[i])
            fprintf(stderr, "No memory\n");
            return 1;
        }
        
        strcpy(t[i], buffer);
    }
    
    for (int i = n-1; i >= 0; i--){
        printf("%d: %s", i+1, t[i]);
    }
    
    for (int i = 0; i < n; i++){
        free(t[i]);
    }
    free(t);
    
    return 0;
}


void fel1(void){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    removeWhiteSpace(buffer);
    
    char *copy;
    int len = strlen(buffer)+1;
    copy = (char *)malloc(len * sizeof(char));
    if (!copy){
        fprintf(stderr, "no memory\n");
        exit(1);
    }
    
    copyString(copy, buffer);
    
    printf("orig: %s\n", buffer);
    printf("copy: %s\n", copy);
    
    free(copy);
}

char *copyString(char *target, const char *str){
    int len = strlen(str)+1;

    
    for (int i = 0; i < len; i++){
        target[i] = str[i];
    }
    return target;
}

void removeWhiteSpace(char *str){
    while (*str != '\0'){
        if (*str == '\n'){
            *str = '\0';
        }
        str++;
    }
}

void fel2(void){
    char *t[5];
    char buffer[BUFFERSIZE];
    for (int i = 0; i < 5; i++){
        printf("%d: ", i+1);
        fgets(buffer, BUFFERSIZE, stdin);
        int len = strlen(buffer) + 1; // '\0' miatt a +1
        t[i] = (char *)malloc(len * sizeof(char));
        if (!(t[i])){ // (NULL == t[i])
            fprintf(stderr, "No memory\n");
            exit(1);
        }
        
        copyString(t[i], buffer);
    }
    for (int i = 4; i >= 0; i--){
        printf("%d: %s", i+1, t[i]);
    }
    for (int i = 0; i < 5; i++){
        free(t[i]);
    }
}


void fel3(void){
    int *t;
    int size = 1;
    int counter = 0;
    char buffer[BUFFERSIZE];
    
    t = (int *)malloc(size * sizeof(int));
    if (!t){
        fprintf(stderr, "No memory\n");
        exit(1);
    }
    
    while (NULL != fgets(buffer, BUFFERSIZE, stdin)){
        int n;
        sscanf(buffer, "%d", &n);
        
        if (counter >= size){
            size *= 2;
            t = (int *)realloc(t, size * sizeof(int));
            if (!t){
                fprintf(stderr, "No memory\n");
                exit(1);
            }
        }
        t[counter] = n;
        counter++;
    }
    
    while (counter > 0){
        printf("%d: %d\n", counter, t[counter-1]);
        counter--;
    }
    
    free(t);
}

void swap(char *fst, char *snd){
    char temp;
    temp = *fst;
    *fst = *snd;
    *snd = temp;
}

void reverse(char *str){
    char *first = str;
    char *last = str + strlen(str) - 1;
    while (first < last){
        swap(first++, last--);
    }
}

void fel4(void){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    removeWhiteSpace(buffer);
    
    reverse(buffer);
    
    printf("%s\n", buffer);
}

char *reverseNew(char *str){
    char *other;
    int len = strlen(str);
    other = (char *)malloc((len+1) * sizeof(char));
    
    if (!other){
        fprintf(stderr, "No mem\n");
        exit(1);
    }
    
    for (int i = 0; i < len; i++){
        other[i] = str[len-i-1];
    }
    other[len] = '\0';
    
    return other;
}

void fel5(void){
    char buffer[BUFFERSIZE];
    char *other;
    fgets(buffer, BUFFERSIZE, stdin);
    removeWhiteSpace(buffer);
    
    other = reverseNew(buffer);
    
    printf("%s\n", other);
    free(other);
}



void fel6(void){
    char **t;
    char buffer[BUFFERSIZE];
    int counter = 0;
    int size = 1;
    

    
    t = (char **)malloc(size * sizeof(char *));
    if (!t){ // (NULL == t)
        fprintf(stderr, "No memory\n");
        exit(1);
    }
    
    while (NULL != fgets(buffer, BUFFERSIZE, stdin)){
        if (counter >= size){
            size *= 2;
            t = (char **)realloc(t, size * sizeof(char *));
            if (!t){ // (NULL == t)
                fprintf(stderr, "No memory\n");
                exit(1);
            }
        }
        int len = strlen(buffer) + 1; // '\0' miatt a +1
        t[counter] = (char *)malloc(len * sizeof(char));
        if (!(t[counter])){ // (NULL == t[i])
            fprintf(stderr, "No memory\n");
            exit(1);
        }
        
        strcpy(t[counter], buffer);
        counter++;
    }
    
    for (int i = counter-1; i >= 0; i--){
        printf("%d: %s", i+1, t[i]);
    }
    
    for (int i = 0; i < counter; i++){
        free(t[i]);
    }
    free(t);
}














