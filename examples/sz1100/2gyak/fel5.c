#include <stdio.h>

int main(){
    int i; /* char, short, long int */
    char c;
    double d; /* float, long double */

    d = 3.74;
    i = d;
    
    printf("i: %d, d: %f\n", i, d);

    d = i;

    printf("i: %d, d: %f\n", i, d);
    
    i = 200;
    c = i;
    
    printf("c: %d\n", c);

    return 0;
}
