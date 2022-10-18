#include <stdio.h>


int sum(int a[], int l);

int main(){
    int t[] = {1, 2, 3, 4, 5, 6, 7};
    int l, result;
    
    l = sizeof(t) / sizeof(t[0]);
    /*printf("Length: %d\n", l);
    printf("sizeof(t): %ld\n", sizeof(t));*/
    
    result = sum(t, l);
    
    printf("Sum: %d\n", result);

    return 0;
}

int sum(int a[], int l){
    int s = 0;
    for (int i = 0; i < l; i++){
        s += a[i];
        
        /*s += *(a + i);
        s += *(i + a);
        s += i[a];*/
    }
    
    /*printf("sizeof(a): %ld\n", sizeof(a));*/

    return s;
}
