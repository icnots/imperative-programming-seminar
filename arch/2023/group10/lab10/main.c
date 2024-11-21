#include <stdio.h>

int main(){
    char b[] = "almafa";
    char *p = "almafa";
    //p = b;
    
    p[2] = 'x';
    
    printf("%s\n", p);
    
    return 0;
}
