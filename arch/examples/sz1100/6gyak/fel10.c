#include <stdio.h>

int *minp(int *f, int *s);

int main(){
    int t[] = {2,3,4,5,6,7,4,2,1,0,0,1,3,45,6,7,4};
    printf("minimal index of 5 7 value: %d\n", *minp(t+7, t+5));
    printf("minimal index of 5 7: %ld\n", minp(t+7, t+5) - t);


    return 0;
}


int *minp(int *f, int *s){
    if (f < s){
        return f;
    }else{
        return s;
    }
}
