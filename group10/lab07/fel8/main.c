#include <stdio.h>

int *func1();
void func2(int *a);

int main(){
    int a = 3;
    int *p = func1();
    
    func2(&a);
    
    //printf("%d\n", *p);
    printf("%d\n", a);

    return 0;
}


int *func1(){
    int j = 22;
    return &j;
}


void func2(int *a){
    *a = 4;
}
