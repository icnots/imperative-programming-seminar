#include <stdio.h>

int main(){
    int a, b;
    
    /*scanf("%d %d", &a, &b);*/
    scanf("%d", &a);
    
    b = 0;
    while (a != 0){
        b = b * 10 + a % 10;
        a /= 10;
    }
    printf("%d\n", b);
    
    
    /*printf("Average: %1.1f\n", (a+b)/2.0);*/
    
    /*
      0     12345
        5        1234
       54       4     123
           543         3     12
              5432          2  1
                54321         1 0
    */
    
    
    return 0;
}
