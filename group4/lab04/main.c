#include <stdio.h>

int main(){
    int t[1000];
    int j = 0;
    
    for (int i = 0; i < 1000; i++){
        t[i] = ++j;
        
    }

    for (int i = 0; i < 20;i++){
        printf("t[%d] elem: %d\n",i, t[i]);
        
    }
    return 0;
}
