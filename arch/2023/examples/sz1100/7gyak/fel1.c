#include <stdio.h>

#define INPUT_LENGTH 100

long int to_decimal(char *str);
int value(char ch);

int main(){
    char input[INPUT_LENGTH];
    char ch;
    int counter = 0;


    while (0 <= (ch = getchar()) && counter < INPUT_LENGTH-1 ){
        if (
            ('0' <= ch && ch <= '9') ||
            ('a' <= ch && ch <= 'f')
        ){
            input[counter++] = ch;
        }else{
            fprintf(stderr, "Not a valid hexa digit\n");
        }
    }
    input[counter] = '\0';
    
    printf("%s -> %ld\n", input, to_decimal(input));

    return 0;
}

long int to_decimal(char *str){
    long int n = 0;
    for (;*str != '\0'; str++){
        n = n * 16 + value(*str);
    }
    return n;
}
int value(char ch){
    if ('0' <= ch && ch <= '9'){
        return ch - '0';
    }else if ('a' <= ch && ch <= 'f'){
        return ch - 'a' + 10;
    }else{
        return -1;
    }

}

