#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void endStringAtNewline(char *s){
    while (*s != '\0'){
        if (*s == '\n'){
            *s = '\0';
            return;
        }
        s++;
    }
}

void reverse(char *s){
    int length = strlen(s);
    for (int i = 0; i < length/2; i++){
        char temp = s[i];
        s[i] = s[length-i-1];
        s[length-i-1] = temp;
    }
}

char *reversed(const char *s){
    int length = strlen(s);
    char *mem = (char*)malloc((length+1)*sizeof(char));
    if (!mem){
        fprintf(stderr, "Not enough memory\n");
        exit(1);
    }
    
    strcpy(mem, s);
    reverse(mem);

    return mem;
}



void increase(int *pn, char ***pt){
    *pn *= 2;
    *pt = (char**)realloc(*pt, (*pn)*sizeof(char*));
    if (!*pt){
        fprintf(stderr, "not enough memory\n");
        exit(1);
    }


}
