#include <stdio.h>

int main(){
    int i; /* long int, short, char */
    double d; /* float, long double */
    
    i = 12;
    d = 13.6;
    
    i = d; /*kerekites?*/
    printf("i: %d, d: %f\n", i, d);
    
    d = i;
    printf("i: %d, d: %f\n", i, d);
    
    return 0;
}
