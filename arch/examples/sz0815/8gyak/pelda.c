#include <stdio.h>
#include <ctype.h>

int main(){
    char ch;
    ch = getchar();
    
    if (isxdigit(ch)){
        printf("Hexadecimal digit\n");
    }else{
        printf("Not hexadecimal digit\n");
    }
    
    return 0;
}
