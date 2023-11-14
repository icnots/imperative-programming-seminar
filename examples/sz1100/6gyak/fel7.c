#include <stdio.h>

int *f(){
    int a = 12;
    return &a;
}

int main(){
    int *p = f();
    printf("%p\n", (void*)p);
    //p = NULL;
    
    if (p){
        printf("*p: %d", *p);
    }
    return 0;
}
