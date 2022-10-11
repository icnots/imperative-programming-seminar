#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
#define TARGET 15
*/

int main(){
    /* Folytatandó feladat */
    srand(time(NULL));
    int target = rand() % 100;
    int guess;
    
    scanf("%d", &guess);
    while (guess != target){
        printf("Target is %s\n",
            (target < guess) 
                ? "smaller"
                : "greater"
        );

        scanf("%d", &guess);
    }
    printf("You found the target!\n");

    return 0;
}
