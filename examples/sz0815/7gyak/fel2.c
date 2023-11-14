#include <stdio.h>

#define N 8

void fill(int matrix[][N]);
void fill(int (*matrix)[N]);
void print(int (*matrix)[N]);

int main(){
    int matrix[N][N];
    
    fill(matrix);
    print(matrix);

    return 0;
}

void fill(int matrix[][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            matrix[i][j] = (i+1)*(j+1);
        }
    }  
}

void print(int (*matrix)[N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
