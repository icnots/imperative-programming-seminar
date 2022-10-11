#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int target = rand() % 100, guess = -1;
    
    while (target != guess){
        scanf("%d", &guess);
        
        if (target < guess){
        
        }else if (target > guess){
            printf("target is greater\n");
        }
    }
    printf("You found it!\n");
    
    return 0;

}
