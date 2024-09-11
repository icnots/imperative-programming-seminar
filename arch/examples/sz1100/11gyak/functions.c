
#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void endStringAtNewline(char *s){
    while (*s != '\0'){
        if (*s == '\n'){
            *s = '\0';
            return;
        }
        s++;
    }

}

char *copyString(const char *s){
    int length = strlen(s);
    char *copy = (char *)malloc((length+1)*sizeof(char));
    if (copy == NULL){ /* (!copy) */
        fprintf(stderr, "Not enough memory\n");
        exit(-1);
    }
    
    for (int i = 0; i <= length; i++){
        copy[i] = s[i];
    }
    /* strcpy(copy, s);*/
    
    return copy;
}



void reverse(char *s){
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++){
        char temp;
        temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}


char *reversed(const char *s){
    char *copy = copyString(s);
    reverse(copy);
    return copy;
}

void increase(char ***pt, int *pn){
    *pn *= 2;
    *pt = (char **)realloc(*pt, *pn * sizeof(char *));
    if (!*pt){
        fprintf(stderr, "No memory\n");
        exit(1);
    }
}


