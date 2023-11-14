#include <stdio.h>

int reverse(int p);

int main(){
    int a;
    scanf("%d", &a);
    
    /*  a       b
    12345       0
     1234       5
      123      54
       12     543
        1    5432
        0   54321
    */
    printf("%d -> %d\n", a, reverse(a));

    /*
    int i = 0;
    printf("%d,%d,%d\n", ++i, i++, i-1);
    */
    
    return 0;
}


int reverse(int p){
    int b = 0;
    while (p > 0){
        b = b * 10 + p % 10;
        p /= 10;
    }
    return b;
}
