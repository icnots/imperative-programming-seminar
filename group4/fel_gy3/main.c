#include <stdio.h>
#include <stdlib.h>

int *func1 (int a, int b);
int *func2 (int a, int b);

int main(){
    int *p;
    int *p2;
    
    p = func2(2, 3);
    p2 = func2(4, 5);

    printf("%d\n", *p);
    printf("%d\n", *p2);

    free(p);
    free(p2);

    return 0;
}



int *func1 (int a, int b){
    static int result;
    result = a + b;
    
    return &result;
}

int *func2 (int a, int b){
    static int statResult;
    int *result = (int *)malloc(sizeof(int));

    if (result != NULL){
        *result = a + b;
        return result;
    }else{
        statResult = a + b;
        return &statResult;
    }
}

