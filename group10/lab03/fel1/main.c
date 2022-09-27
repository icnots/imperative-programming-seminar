#include <stdio.h>

int main(){
    int a[1000];
    a[12] = 13;
    
    for (int i = 0; i < 100; i++){
        printf("%d ", a[i]);
    }


    return 0;
}
