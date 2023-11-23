#include "tasks.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFERSIZE 100


void feladat1(void){
    char buffer[BUFFERSIZE];
    
    fgets(buffer, BUFFERSIZE, stdin);
    
    wc(buffer);
}

void wc(char *s){
    int words = 0;
    int chars = 0;
    
    while (*s != '\0'){
        if (isalpha( *s )){
            chars++;
        }
        if (isalpha( *s ) && !isalpha( *(s+1) )){
            words++;
        }
        
        s++;
    }
    
    printf("chars: %d\nwords: %d\n", chars, words);
}



void feladat2(void){
    char buffer1[BUFFERSIZE];
    char buffer2[BUFFERSIZE];
    
    fgets(buffer1, BUFFERSIZE, stdin);
    fgets(buffer2, BUFFERSIZE, stdin);
    
    printf("comparison: %d\n", comparison(buffer1, buffer2));
    printf("strcmp: %d\n", strcmp(buffer1, buffer2));
}


int comparison(char *buffer1, char *buffer2){
    while ((*buffer1 == *buffer2) && *buffer1 != '\0' && *buffer2 != '\0'){
        buffer1++;
        buffer2++;
    }
    return *buffer1 - *buffer2;
}

void feladat3(void){
    char buffer1[BUFFERSIZE];
    char buffer2[BUFFERSIZE];
    char buffer3[BUFFERSIZE];
    
    fgets(buffer1, BUFFERSIZE, stdin);
    copy(buffer1, buffer2);
    printf("buffer2: %s\n", buffer2);
    strcpy(buffer1, buffer3);
    printf("buffer3: %s\n", buffer3);
}

void copy(const char *from, char *to){
    while (*from != '\0'){
        *(to++) = *(from++);
    }
    *to = '\0';
}



void feladat4(void){
    char t1[] = "alma";
    const char *t2 = "alma";
    const char *t3 = "alma";
    *t1 = 'b';
    
    printf("t1: %s\n", t1);
    printf("t2: %s\n", t2);
    printf("t2 ?= t3: %d\n", t2 == t3);
}


void feladat5(void){
    const char *filename = "szoveg.txt";
    char buffer[BUFFERSIZE];
    FILE *f = fopen(filename, "r");
    if (f){
        while (fgets(buffer, BUFFERSIZE, f)){
            char *s = buffer;
            while (*s != '\0'){
                if ('a' <= *s && *s <= 'z'){
                    *s += 'A'-'a';
                }
                s++;
            }
            printf("%s", buffer);
        }
        fclose(f);
    }else{
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }
}

void feladat6(void){
    const char *filename = "szoveg.txt";
    const char *tofilename = "upper.txt";
    char buffer[BUFFERSIZE];
    FILE *input = fopen(filename, "r");
    FILE *output = fopen(tofilename, "w");
    if (input && output){
        while (fgets(buffer, BUFFERSIZE, input)){
            char *s = buffer;
            while (*s != '\0'){
                if ('a' <= *s && *s <= 'z'){
                    *s += 'A'-'a';
                }
                s++;
            }
            fprintf(output, "%s", buffer);
        }
        fclose(input);
        fclose(output);
    }else{
        fprintf(stderr, "Unable to open file\n");
        return;
    }
}
















