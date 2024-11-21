#include <stdio.h>

int sum(int n);

int main(){
    int n;
    scanf("%d", &n);
    
    printf("%d", sum(n));
    
    return 0;
}


int sum(int n){
    /*return n * (n+1) / 2;*/
    int s = 0;
    for (int i = 1; i <= n; i++){
        s += i;
    }
    return s;
}
