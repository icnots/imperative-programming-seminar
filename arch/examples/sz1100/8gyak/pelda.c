#include <stdio.h>
#include <ctype.h>

int main(){
    char ch;
    ch = getchar();
    
    switch(ch){
        case '0':
        case '1':
        case '2':
        case '3':
        case 'A':
        case 'C':
        case 'E':
        case 'D':
        case 'F':
        case 'B': printf("Hexadecimal digit\n");
                  break;
        default : printf("Not hexadecimal digit\n");
    }
    
    if (isxdigit(ch)){
        printf("Hexadecimal digit\n");
    }else{
        printf("Not hexadecimal digit\n");
    }
    

    return 0;
}
