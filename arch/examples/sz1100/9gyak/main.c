#include "my_utils.h"

#include <stdio.h>
int main(){
    int a=3, b=1;
    func();
    func();
    int t[] = {1,2,3,4,5,66,7};
    
    print(a, b);
    swap(&a, &b);
    print(a, b);
    printTable(t, sizeof(t)/sizeof(t[0]));
    
    
    
    func();
    print(a, b);
    (*max(&a, &b))++;
    print(a, b);
    swap(&a, &b);
    print(a, b);
    (*max(&a, &b))++;
    print(a, b);

    void print(int n){
        printf("%d\n", n);
    }

    print(a);
    
    return 0;
}



