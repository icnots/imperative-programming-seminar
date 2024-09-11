#include <stdio.h>

int main(){
    int var;
    
    scanf("%d", &var);
    
    /*szam = mas * (szam / mas) + (szam % mas)*/
    if (0 == (var % 2)){
        printf("Even.\n");
    }else{
        printf("Odd.\n");
    }
    
    if (0 == (var % 2))
        printf("Even.\n");
    else
        printf("Odd.\n");
    
    return 0;
}
