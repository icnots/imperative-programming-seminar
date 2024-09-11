#include <stdio.h>

int sum(int *first, int length);

int main(){
    int t[] = {1,2,3,4,5};
    int l = sizeof(t)/sizeof(t[0]);
    int s = sum(t, l);

    printf("sum: %d\n", s);
    return 0;
}


int sum(int *first, int length){
    int s = 0;
    for (int i = 0; i < length; i++){
        s += *(first + i);
    }
    
    return s;
}
