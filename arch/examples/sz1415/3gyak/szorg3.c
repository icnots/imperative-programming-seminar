#include <stdio.h>

int reverse(int p);

int main(){
    int a, b;
    scanf("%d", &a);
    
    b = reverse(a);
    printf("%d -> %d\n", a, b);
    
    
    int i = 0;
    printf("%d, %d, %d\n", ++i, i++, i-1);
    
    i = 0;
    a = ++i;
    b = i++;
    int c = i-1;
    printf("%d, %d, %d\n", a, b, c);
    
    

    return 0;
}


/* p             n
12345  -->       0
 1234  -->       5
  123  -->      54
   12  -->     543
    1  -->    5432
    0  -->   54321
*/
int reverse(int p){
    int n = 0;
    while (p > 0){
        n *= 10;
        n += p % 10;
        p /= 10;
    }    

    return n;
}

