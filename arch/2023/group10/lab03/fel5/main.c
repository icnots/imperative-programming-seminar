#include <stdio.h>

long int fakt(int k){
    long int value = 1;
    for (int i = 1; i <= k; i++){
        value *= i;
    }
    return value;
}

long int binom(long int n, long int k){
    return fakt(n) / fakt(k) / fakt(n-k);
}

int main(){
    printf("%ld\n", sizeof(long int));

    printf("binom(10, 7) : %d\n", binom(10,7));
    printf("binom(14, 4) : %d\n", binom(14,4));
    printf("binom(12, 5) : %d\n", binom(12,5));
    return 0;
}
