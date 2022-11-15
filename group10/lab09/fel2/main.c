#include <stdio.h>

#define BUFFERSIZE 1024

void correctString(char *p);

void reverse(char *p);

int main(){
    char buffer[BUFFERSIZE];

    fgets(buffer, BUFFERSIZE, stdin);
    correctString(buffer);
    
    reverse(buffer);
    
    printf("%s\n", buffer);
    
    return 0;
}


void reverse(char *first){
    char *last = first;
    while (*last != '\0')
        last++;
    last--;
    while (first < last){
        char temp = *first;
        *first = *last;
        *last = temp;
        
        first++;
        last--;
    }    
}

void correctString(char *p){
    while ( (*p != '\r') && (*p != '\n') && (*p != '\0') ){
        p++;
    }
    *p = '\0';
}
