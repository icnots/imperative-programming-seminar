#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "func.h"

#define BUFFERSIZE 51

void demo(void){
    char buffer[BUFFERSIZE];
    int n; // sorok száma
    char **t;
    
    fgets(buffer, BUFFERSIZE, stdin);
    sscanf(buffer, "%d", &n);
    
    t = (char **)malloc(n * sizeof(char *));
    if (NULL == t){
        fprintf(stderr, "No memory\n");
        exit(1);
    }
    
    for (int i = 0; i < n; i++){
        fgets(buffer, BUFFERSIZE, stdin);
        int len = strlen(buffer) + 1;
        t[i] = (char *)malloc(len * sizeof(char));
        if (NULL == t[i]){
            fprintf(stderr, "No memory\n");
            exit(1);
        }
        strcpy(t[i], buffer);
    }
    
    for (int i = n; i > 0; i--){
        printf("%d: %s", i, t[i-1]);
        free(t[i-1]);
    }
    
    free(t);
}


void memCheck(void *p){
    if (NULL == p){
        fprintf(stderr, "No memory\n");
        exit(1);
    }
}

void removeNewLine(char *p){
    while (*p != '\0'){
        if (*p == '\n'){
            *p = '\0';
        }
        p++;
    }
}

void fel1(void){
    char buffer[BUFFERSIZE];
    fgets(buffer, 21, stdin);
    removeNewLine(buffer);
    
    char *cpy;
    int len = strlen(buffer)+1;
    cpy = (char *)malloc(len * sizeof(char));
    memCheck(cpy);
    
    for (int i = 0; i < len; i++){
        cpy[i] = buffer[i];
    }
    
    printf("orig: %s\n", buffer);
    printf("copy: %s\n", cpy);
}

void fel2(void){
    char buffer[BUFFERSIZE];
    char *t[5];
        
    for (int i = 0; i < 5; i++){
        fgets(buffer, BUFFERSIZE, stdin);
        int len = strlen(buffer) + 1;
        t[i] = (char *)malloc(len * sizeof(char));
        memCheck(t[i]);
        strcpy(t[i], buffer);
    }
    
    for (int i = 5; i > 0; i--){
        printf("%d: %s", i, t[i-1]);
        free(t[i-1]);
    }
}

void fel3(void){
    int size = 1;
    int counter = 0;
    int *t;
    int n;
    char buffer[BUFFERSIZE];
   
    t = (int *)malloc(size * sizeof(int));
    memCheck(t);
    
    while (fgets(buffer, BUFFERSIZE, stdin)){
        sscanf(buffer, "%d", &n);
        
        if (counter >= size){
            size *= 2;
            t = (int *)realloc(t, size * sizeof(int));
            memCheck(t);
        }
        
        t[counter] = n;
        counter++;
    }
    
    for (int i = counter; i > 0; i--){
        printf("%d: %d\n", i, t[i-1]);
    }
    
    free(t);
}


void swap(char *fst, char *snd){
    char tmp = *fst;
    *fst = *snd;
    *snd = tmp;
}

void reverse(char *str){
    char *fst = str;
    char *lst = str + strlen(str) - 1;
    while (fst < lst){
        swap(fst++, lst--);
    }
}

void fel4(void){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    removeNewLine(buffer);
    reverse(buffer);
    printf("%s\n", buffer);
}

char *reverseNew(char *str){
    int len = strlen(str)+1;
    char *res = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len-1; i++){
        res[i] = str[len-i-2];
    }
    res[len-1] = '\0';
    
    return res;
}

void fel5(void){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    removeNewLine(buffer);
    char *newStr = reverseNew(buffer);
    printf("%s\n", newStr);
    
    free(newStr);
}

void increaseArray(int *size, char ***t){
    *size *= 2;
    *t = (char **)realloc(*t, *size * sizeof(char *));
    memCheck(*t);
}

void fel6(void){
    char buffer[BUFFERSIZE];
    int size = 1; // tömböm mérete
    char **t;
    int counter = 0;
    
    t = (char **)malloc(size * sizeof(char *));
    memCheck(t);
    
    while (fgets(buffer, BUFFERSIZE, stdin)){
        if (counter >= size){
            increaseArray(&size, &t);
        }
        
        int len = strlen(buffer) + 1;
        t[counter] = (char *)malloc(len * sizeof(char));
        memCheck(t[counter]);
        strcpy(t[counter], buffer);
        counter++;
    }
    
    for (int i = counter; i > 0; i--){
        printf("%d: %s", i, t[i-1]);
        free(t[i-1]);
    }
    
    free(t);
}
