#include <stdio.h>

void print_powers(int, int);

int main(){
    int a, n;
    scanf("%d", &a);
    scanf("%d", &n);
    
    print_powers(a, n);

    return 0;
}

void print_powers(int a, int n){
    int q = 1;
    for (int i = 0; i <= n; i++){
        printf("%d^%d = %d\n", a, i, q);
        q *= a;
    }
}
