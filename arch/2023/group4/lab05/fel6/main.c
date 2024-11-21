#include <stdio.h>


int isArmstrong(int k);
int power(int a, int b);

int main(){
    int n;
    scanf("%d", &n);
    
    n++;
    for (int i = 0; i < n; i++){
        if (isArmstrong(i)){
            printf("%d\n", i);
        }
    }

    return 0;
}



int isArmstrong(int k){
    int len = 1, original = k, sum = 0;
    while(0 < (k /= 10)){
        len++;
    }
    k = original;
    while(0 < k){
        sum += power(k % 10, len);
        k /= 10;
    } 
    return sum == original;
}


int power(int a, int b){
    int res = 1;
    for (int i = 0; i < b; i++){
        res *= a;
    }
    
    return res;
}
