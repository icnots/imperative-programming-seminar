#include <stdio.h>

int sum(int a, int b, int c){
    printf("%d %d %d\n", a, b, c);
}

int main(){
    
    for (int i = 0; i < 10;){
        
        
        sum(i, 2*i++ , 3* i);
    }
    
    
    
    return 0;
}
