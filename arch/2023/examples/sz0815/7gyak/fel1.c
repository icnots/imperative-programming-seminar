#include <stdio.h>

#define INPUT_LENGTH 100

int value(char ch);

int main(){
    char ch;
    char input[INPUT_LENGTH];
    int counter = 0;
    
    while (0 < (ch = getchar()) && (counter < INPUT_LENGTH-1)){
        if ( ('a' <= ch && ch <= 'f')
            || ('0' <= ch && ch <= '9') ){
            input[counter++] = ch;
        }else{
            fprintf(stderr, "Not a valid hexadecimal digit: %c\n", ch);
        }
        /*if ( value(ch) != -1 ){
            input[counter++] = ch;
        }*/
    }
    input[counter] = '\0';
    
    
    long int n = 0;
    for (int i = 0; i < counter; i++){
        n = n * 16 + value(input[i]);
    }
    
    printf("%s -> %ld\n", input, n);

    return 0;
}

int value(char ch){
    if ('a' <= ch && ch <= 'f'){
        return ch - 'a' + 10;
    }else if ('0' <= ch && ch <= '9'){
        return ch -'0';
    }
    return -1;
}

/*
Parancssor
cd .. + cd directoryname

*/
