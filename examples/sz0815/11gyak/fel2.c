#include "fel2.h"

#include <string.h>
#include <stdlib.h>


void reverse(char *s){
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++){
        int other_i = length - i - 1;
        
        char temp = s[i];
        s[i] = s[other_i];
        s[other_i] = temp;
    }
}


char *reversed(char *s){
    int len = strlen(s);
    char *other =(char *)malloc((len+1) * sizeof(char));
    
    char *fromEnd = other + len - 1;
    char *fromStart = s;
    
    while (*fromStart != '\0'){
        *fromEnd = *fromStart;
        fromEnd--;
        fromStart++;
    }
    other[len] = '\0';
    
    return other;
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
