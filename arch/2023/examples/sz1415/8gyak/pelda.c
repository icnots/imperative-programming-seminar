#include <stdio.h>
#include <ctype.h>

int main(){
    char ch;
    ch = getchar();
    
    switch(ch){
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case '0':
        case '1': printf("Hexadecimal\n");
                  break;
        default:  printf("Not hexadecimal\n");
    }
    
    if (isxdigit(ch)){
        printf("Hexadecimal\n");
    }else{
        printf("Not hexadecimal\n");
    }
    return 0;
}
