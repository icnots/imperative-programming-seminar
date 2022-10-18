#include <stdio.h>

#define BUFFERSIZE 100

char convertToLowerCase(char c);
void correction(char s[]);
int isSpecial(char c);

int main(){
    char a[BUFFERSIZE], b[BUFFERSIZE];
    int i;
    
    /*
    scanf("%s", &(a[0]));
    scanf("%s", a);
    */
    
    fgets(a, BUFFERSIZE, stdin);
    fgets(b, BUFFERSIZE, stdin);
    
    correction(a);
    correction(b);
    
    i = 0;
    while (convertToLowerCase(a[i]) == convertToLowerCase(b[i])){
        i++;
    }
    printf("I%d\n", i);
    
    if (convertToLowerCase(a[i]) - convertToLowerCase(b[i]) > 0){
        printf("%s %s\n", b, a);
    }else{
        printf("%s %s\n", a, b);
    }

    return 0;
}

char convertToLowerCase(char c){
    if ('A' <= c && c <= 'Z'){
        c += 'a'-'A';
    }
    return c;
}

void correction(char s[]){
    while (!isSpecial(*s)){
        s++;
    }
    *s = '\0';
}

int isSpecial(char c){
    return c == '\r' || c == '\n' || c == '\0';
}
