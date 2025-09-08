#include "fel1.h"
#include <stdio.h>
#include <ctype.h>

#define BUFFERSIZE 50

void fel1(){
    printf("fel1\n");
    
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE, stdin);
    
    int wordcounter = 0;
    int charcounter = 0;
    // for (int i = 0; buffer[i] != '\0', i++)
    for (char *pc = buffer; *pc != '\0'; pc++){
        if (isspace(*pc)){
            
        }else{
            charcounter++;
            if (pc != buffer){
                if (isspace(*(pc-1))){
                    wordcounter++;
                }
            }else{
                wordcounter++;
            }
        }
    }
    printf("Number of characters: %d\n", charcounter);
    printf("Number of words: %d\n", wordcounter);
    
}
