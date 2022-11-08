#include <stdio.h>

#define BUFFERSIZE 1024

void szamol(char ch);

int main(){
    char buffer[BUFFERSIZE];
    char *chp;
    
    fgets(buffer, BUFFERSIZE, stdin);
    
    chp = buffer;
    
    while (*chp != '\0'){
        szamol(*chp);
        chp++;
    }
    
    szamol('\0');


    return 0;
}

void szamol(char ch){
    static int counter = 0;
    
    if (ch == '\0'){
        printf("Number of characters: %d\n", counter);
    }else{
        if ((ch >= 'A' && ch <= 'Z')
            || (ch >= 'a' && ch <= 'z')
        ){
            counter++;
        }
    }

}
