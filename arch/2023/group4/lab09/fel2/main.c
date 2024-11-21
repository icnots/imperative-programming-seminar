#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 20

void correctString(char *p);
void reverse(char *p);
void swapCharacters(char *a, char *b);

int main(){
    char buffer[BUFFERSIZE];
    
    fgets(buffer, BUFFERSIZE, stdin);
    
    correctString(buffer);
    
    reverse(buffer);
    
    printf("%s\n", buffer);
    
    return 0;
}

void reverse(char *first){
    int length = strlen(first);
    
    char *last = first + length - 1;
    
    while (first < last){
        swapCharacters(first, last);
        first++;
        last--;
    }
}

void swapCharacters(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void correctString(char *p){
    while ( (*p != '\r') && (*p != '\n') && (*p != '\0') ){
        p++;
    }
    *p = '\0';
}


