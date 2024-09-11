#include <stdio.h>
#include <math.h>

int main(){
    /* Folytatandó feladat */
    int n, l = 1, o;
    scanf("%d", &n);
    o = n;
    
    while ((n /= 10) > 0){
        l++;
    }
    
    printf("length: %d\n", l);
    printf("%f\n", pow(10, l));
    
    
    return 0;
}
