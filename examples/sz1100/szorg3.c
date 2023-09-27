#include <stdio.h>

int reverse(int p);

int main(){
    int a;
    printf("Give me a number\n");
    fflush(stdout);
    
    scanf("%d", &a);
    
    printf("%d -> %d\n", a, reverse(a));
    
    /*
    int i = 0;
    printf("%d,%d,%d", ++i, i++, i-1);

    int tomb[100];
    i = 0;
    for (; i < 100;){
        tomb[i++] = i;
    }
    */

    return 0;
}


int reverse(int p){
    int n = 0;    
    /*  p               n 
    12345     --->      0
     1234     --->      5
      123     --->     54
       12     --->    543
        1     --->   5432
        0     --->  54321
    */
    
    while (p > 0){
        n *= 10;
        n += p % 10;
        p /= 10;
    }
    
    return n;
}

















