#include <stdio.h>

#define N 8

void fill(int matrix[][N]);
void fill(int matrix[N][N]);
void fill(int (*matrix)[N]);
void print(int (*matrix)[N]);

int main(){
    int matrix[N][N];
    /*matrix[i][j] == *(matrix[i] + j) == *(*(matrix+i) + j)*/
    fill(matrix);
    
    print(matrix);

    return 0;
}



void print(int (*matrix)[N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}


void fill(int matrix[][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            matrix[i][j] = (i+1) * (j+1);
        }
    }
}

