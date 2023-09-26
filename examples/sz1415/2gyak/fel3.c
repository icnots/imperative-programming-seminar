#include <stdio.h>


int main(){
    int var;
    
    scanf("%d", &var);
    
    if (0 < var){
        printf("Positive\n");
    }else if (0 > var){
        printf("Negative\n");
    }else{
        printf("Zero\n");        
    }
        
    
    

    return 0;
}
