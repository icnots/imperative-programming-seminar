#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(){
    int tomb[N];
    int counter = 0;
    
    srand(time(NULL));

    for (int i = 0; i < N; i++){
        tomb[i] = rand() % 100;
        if (tomb[i] > 50){
            counter++;
        }
    }
    
    /*for (int i = 0; i < N; i++){
        printf("%d, ", tomb[i]);
    }
    printf("\n");*/
    printf("Greater than 50: %d\n", counter);

    return 0;
}
