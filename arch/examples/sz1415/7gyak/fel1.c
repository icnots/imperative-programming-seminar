#include <stdio.h>

#define INPUT_LENGTH 30

long int hex_to_dec(char *p);
char value(char ch);

int main(){
    char ch;
    char input[INPUT_LENGTH];
    int counter = 0;
    
    while ( 0 <= (ch = getchar()) && counter < INPUT_LENGTH-1 ){
        if (
            ('a' <= ch && ch <= 'f') ||
            ('A' <= ch && ch <= 'F') ||
            ('0' <= ch && ch <= '9')
        ){
            input[counter++] = ch;
        }else{
            fprintf(stderr, "Not a valid hexa digit\n");
        }
    }
    input[counter] = '\0';


    printf("%s -> %ld\n", input, hex_to_dec(input));
    
    return 0;
}



long int hex_to_dec(char *p){
    long int n = 0;
    
    while (*p != '\0'){
        n = (n*16) + value(*p);
        p++;
    }
    
    return n;
}

char value(char ch){
    if ('a' <= ch && ch <= 'f'){
        return ch - 'a' + 10;
    }else if ('A' <= ch && ch <= 'F'){
        return ch - 'A' + 10;
    }else if ('0' <= ch && ch <= '9'){
        return ch - '0';
    }else{
        return -1;
    }
}
