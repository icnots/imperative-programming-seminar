#include <stdio.h>

int isArmstrong(int n);
int power(int a, int b);

int main(){
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i <= n; i++){
        if (isArmstrong(i))
            printf("%d\n", i);
    
    }

    return 0;
}



int isArmstrong(int n){
    int l = 0, s = 0, o = n;

    while(n > 0){
        l++;
        n /= 10;
    }
    
    n = o;
    while(n > 0){
        int szamjegy = n % 10;
        n /= 10;
        
        s += power(szamjegy, l);
    }
   
    return s == o;
}


int power(int a, int b){
    int res = 1;
    for (int i = 0; i < b; i++){
        res *= a;
    }
    
    return res;
}

