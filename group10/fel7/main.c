#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 1024

void correct(char s[]);
int isSpecialChar(char c);
char toLower(char c);

int main(){
    char a[BUFFERSIZE], b[BUFFERSIZE];
    char ca[BUFFERSIZE], cb[BUFFERSIZE];

    /*scanf("%s", &a[0]);
    scanf("%s", b);*/
    
    fgets(a, BUFFERSIZE, stdin);
    fgets(b, BUFFERSIZE, stdin);
    
    strcpy(ca, a);
    strcpy(cb, b);

    correct(a);
    correct(b);
    
    int i = 0;
    
    while (toLower(a[i]) == toLower(b[i])){
        i++;
    }
    if (toLower(a[i]) < toLower(b[i])){
        printf("First: %s\nSecond: %s\n", a, b);
    }else{
        printf("First: %s\nSecond: %s\n", b, a);
    }

    return 0;
}


void correct(char s[]){
    while (!isSpecialChar(*s)){
        /*if ('A' <= *s && *s <= 'Z'){
            *s -= 'A' - 'a';
        }*/
        s++;
    }
    
    *s = '\0';
}

int isSpecialChar(char c){
    return c == '\r' || c == '\n' || c == '\0';
}

char toLower(char c){
    if ('A' <= c && c <= 'Z'){
        c -= 'A' - 'a';
    }
    return c;
}

















