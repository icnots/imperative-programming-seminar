#include <stdio.h>

int main(){
    char name[20] = "Petike\0";
    
    printf("%c\n", name[4]);

    int valtozok[100];
    
    printf("86. elem: %d\n", valtozok[85]);
    
    return 0;
}
