#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

void fill(int *p);

int main(){
    srand(time(NULL));
    int arr[N];
    fill(arr);    
    int counter = 0;
    
    for (int i = 0; i < N; i++){
        if (arr[i] > 50)
            counter++;
    }
    
    /*for (int i = 0; i < N; i++){
        printf("%d, ", arr[i]); 
    }
    printf("\n");*/
    
    printf("%d\n", counter);
    return 0;
}


void fill(int *p){
    for (int i = 0; i < N; i++){
        p[i] = rand() % 100;
    }
}

