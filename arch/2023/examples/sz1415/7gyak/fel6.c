#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void fill(int *p);

int main(){
    srand(time(NULL));
    int arr[N];
    int counter = 0;
    
    fill(arr);
    
    for (int i = 0; i < N; i++){
        /*printf("%d, ", arr[i]);*/
        if (arr[i] > 50){
            counter++;
        }
    }
    printf("%d\n", counter);
    
    return 0;
}


void fill(int *p){
    for (int i = 0; i < N; i++){
        p[i] = rand() % 100;
    }
}

