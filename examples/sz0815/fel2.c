#include <stdio.h>

int main(){
    int a, b, c;
    a = -1;
    b = 0;
    c = 2;
    
    if ( a < b && b < c ){
        printf("True\n");
    }else{
        printf("False\n");
    }

    return 0;
}
