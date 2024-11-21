#include <stdio.h>

int main(){
    int i; /* long int, short, char */
    double d; /* float, long double */
    
    i = 3.14;
    printf("3.14 : %d\n", i);
    
    i = 'A';
    printf("'A' : %d\n", i);
    
    i = 0 < 1;
    printf("0 < 1 : %d\n", i);
    
    i = "szia";
    printf("\"szia\" : %d\n", i);
    
    return 0;
}
