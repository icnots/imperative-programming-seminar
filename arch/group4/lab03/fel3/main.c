#include <stdio.h>

int main(){
    char szam;
    
    szam = 42;
    printf("%d\n", szam);
    szam = '*';
    printf("%d\n", szam);
    szam = 052;
    printf("%d\n", szam);
    szam = 0x2A;
    printf("%d\n", szam);
    szam = 42.29;
    printf("%d\n", szam);
    szam = 298;
    printf("%d\n", szam);
    
    szam = -214;
    printf("%d\n", szam);
    return 0;
    
    
    /*  0  --->    00000000000000
        1  --->    00000000000001
        
        max --->   01111111111111
        max+1-->   10000000000000
        
        -1 -->     11111111111111
        19 ---->   00000010011
        -19---->   11111101101
        
        
    
    */
    
}
