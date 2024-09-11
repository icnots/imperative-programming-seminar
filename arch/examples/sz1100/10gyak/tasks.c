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
void wc(const char *s){
    int chars = 0;
    int words = 0;
    
    while(*s != '\0'){
        if (isalpha(*s)){
            chars++;
            /*
            if (!isalpha(*(s+1))){
                words++;
            }
            */
        }
        if (isalpha(*s) && !isalpha(*(s+1))){
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
    
    printf("compare: %d\n", compare(buffer1, buffer2));
    printf("strcmp : %d\n", strcmp(buffer1, buffer2));
}

int compare(const char *s1, const char *s2){
    while ((*s1 == *s2) && ('\0' != *s1) && ('\0' != *s2)){
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void feladat3(void){
    char buffer1[BUFFERSIZE];
    char buffer2[BUFFERSIZE];
    char buffer3[BUFFERSIZE];
    fgets(buffer1, BUFFERSIZE, stdin);
    copy(buffer1, buffer2);
    strcpy(buffer3, buffer1);
    
    printf("buffer2: %s\n", buffer2);
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
   
    t1[0] = 'b';
    
    printf("t1: %s\n", t1);
    printf("t2: %s\n", t2);
    printf("t2 ?= t3: %d\n", t2 == t3);
}

void feladat5(void){
    const char *input_filename = "szoveg.txt"; 
    FILE *input = fopen(input_filename, "r");
    char buffer[BUFFERSIZE];
    if (input){
        while (fgets(buffer, BUFFERSIZE, input)){
            my_to_upper(buffer);
            printf("%s", buffer);
        }
        fclose(input);
    }else{
        fprintf(stderr, "Unable to open file\n");
    }

}

void my_to_upper(char *buffer){
    while (*buffer != '\0'){
        if ('a' <= *buffer && *buffer <= 'z'){
            *buffer += 'A' - 'a';
        }
        buffer++;
    }
}


void feladat6(void){
    const char *input_filename = "szoveg.txt";
    const char *output_filename = "upper.txt";
    FILE *input = fopen(input_filename, "r");
    FILE *output = fopen(output_filename, "w");
    char buffer[BUFFERSIZE];
    if (input && output){
        while (fgets(buffer, BUFFERSIZE, input)){
            my_to_upper(buffer);
            fprintf(output, "%s", buffer);
        }
        fclose(input);
        fclose(output);
    }else{
        fprintf(stderr, "Unable to open file\n");
    }

}
















