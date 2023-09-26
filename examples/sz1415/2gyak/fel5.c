#include <stdio.h>


int main(){
    int i; /* char, short, long int, long long int */
    double d; /* float, long double */
    char c;
    
    d = 13.5;
    i = d;
    
    printf("i: %d, d: %f\n", i, d);
    
    d = i;
    printf("i: %d, d: %f\n", i, d);
    
    i = 200;
    c = i;
    printf("c: %c\n", c);

    return 0;
}
