#include <stdio.h>

int binom(int n, int k){
    int value = 1;
    int i;
    
    for (i = 1; i <= n; i++){
        value *= i;
    }
    
    for (i = 1; i <= k; i++){
        value /= i;
    }
    
    for (i = 1; i <= n-k; i++){
        value /= i;
    }
    
    return value;
}

int main(){
    printf("5 alatt 2: %d\n", binom(5, 2));


    return 0;
}
