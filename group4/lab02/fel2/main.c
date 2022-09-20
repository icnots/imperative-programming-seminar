#include <stdio.h>

int main(){
    int i;
    
    i = 120;
    
    printf("%d\n", i);
    
/*    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("average: %f\n", (a + b) / 2.0);
*/

    int u;
    int t[100];
    
    printf("sizeof(int): %ld\n", sizeof(int));
    printf("sizeof(u): %ld\n", sizeof(u));
    printf("sizeof(long double): %ld\n", sizeof(long double));
    printf("sizeof(float): %ld\n", sizeof(float));
    printf("sizeof(double): %ld\n", sizeof(double));
    printf("sizeof(t): %ld\n", sizeof(t));
    printf("length of t: %ld\n", sizeof(t) / sizeof(t[0]));
    
    
    /*   12345    
      5         1234
    54       4      123
        543     3     12
    ...
    ...
    
        54321
    */
    
    
    
    int n;
    int newN = 0;
    scanf("%d", &n);
    while(n != 0){
        newN *= 10;
        newN += n % 10;
        n /= 10;
    }
    printf("%d\n", newN);
    
    
    
    
    return 0;
}
