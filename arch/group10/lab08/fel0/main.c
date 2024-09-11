#include <stdio.h>

#define BUFFERSIZE 1024

void countering(char ch);

int main(){
    char buffer[BUFFERSIZE];
    char *chp;
    
    fgets(buffer, BUFFERSIZE, stdin);
    chp = buffer;
    
    while (*chp != '\0'){
        countering(*chp);
        chp++;
    }
    
    countering('\0');
    
    return 0;
}


void countering(char ch){
    static int counter = 0;
    if (ch == '\0'){
        printf("Number of characters: %d\n", counter);
    }else if (ch >= 'a' && ch <= 'z'){
        counter++;
    }
}

