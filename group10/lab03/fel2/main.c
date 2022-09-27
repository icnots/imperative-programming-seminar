#include <stdio.h>

int main(){
    int a = 5, b = 4, c = 3;
    
    if (a < b && b < c){
        printf("True\n");
    }else{
        printf("False\n");
    }

    char n;
    n = 42;
    printf("%d\n", n);
    n = '*';
    printf("%d\n", n);
    n = 0x2A;
    printf("%d\n", n);
    n = 052;
    printf("%d\n", n);
    n = 42.9765423;
    printf("%d\n", n);
    n = 298;
    printf("%d\n", n);
    n = -214;
    printf("%d\n", n);
    
    char name[30];
    scanf("%s", name);
    
    
    


    return 0;
}
