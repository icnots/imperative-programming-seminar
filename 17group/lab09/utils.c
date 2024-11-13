#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 50


void fel1(void){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    
    int wordcount = 0;
    int charcount = 0;
    int length = strlen(buffer);
    
    //for (int i = 0; buffer[i] != '\0'; i++)
    for (int i = 0; i < length; i++){
        if (!isspace(buffer[i])){
            charcount++;
            if (0 == i){
                wordcount++;
            }else if (isspace(buffer[i-1])){
                wordcount++;
            }
        }
    }
    printf("Number of words: %d\n", wordcount);
    printf("Number of chars: %d\n", charcount);
}



void fel2(void){
    char buffer1[BUFFERSIZE];
    char buffer2[BUFFERSIZE];
    fgets(buffer1, BUFFERSIZE, stdin);
    fgets(buffer2, BUFFERSIZE, stdin);
    
    int result = strcmp(buffer1, buffer2);
    if (result < 0){
        printf("buffer1 appears before buffer2 in lexicographical order\n");
    }else if (result > 0){
        printf("buffer1 appears after buffer2 in lexicographical order\n");
    }else{
        printf("the buffers are identical\n");
    }
}

void fel3(void){
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    
    char copy[BUFFERSIZE];
    
    strcpy(copy, buffer);
    
    printf("%s", copy);
}

void fel4(void){
    char buffer1[BUFFERSIZE] = "almafa";
    // char buffer1[BUFFERSIZE] = {'a', 'l', 'm', 'a', 'f', 'a', '\0'};
    
    const char *buffer2 = "almafa";
    char *buffer3 = buffer1;
    
    buffer1[0] = 'A';
    // buffer2[0] = 'A';
    buffer3[0] = 'A';
    
    printf("%s\n", buffer1);
    printf("%s\n", buffer2);
}

void fel5(void){
    const char *filename = "valami.txt";
    FILE *fp = fopen(filename, "r");
    
    if (fp){
        char buffer[BUFFERSIZE];
        while (NULL != fgets(buffer, BUFFERSIZE, fp)){
            for (char *cp = buffer; *cp != '\0'; cp++){
                fprintf(stdout, "%c", toupper(*cp));
            }
        }
        
        fclose(fp);
    }
}


void fel6(void){
    const char *filename = "valami.txt";
    FILE *fp = fopen(filename, "r");
    
    if (fp){
        FILE *fpOut = fopen("output.txt", "w");
        if (fpOut){
    
            char buffer[BUFFERSIZE];
            while (NULL != fgets(buffer, BUFFERSIZE, fp)){
                for (char *cp = buffer; *cp != '\0'; cp++){
                    fprintf(fpOut, "%c", toupper(*cp));
                }
            }
            
            fclose(fpOut);
        }
        
        fclose(fp);
    }
}

