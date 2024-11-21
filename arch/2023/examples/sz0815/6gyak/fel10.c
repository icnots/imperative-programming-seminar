#include <stdio.h>

int *minp(int *f, int *s);

int main(){
    int t[] = {6, 5, 4, 3, 3, 2, 1};

    printf("min index elem: %d\n", *minp(t+2, &t[6]));
    
    printf("min index: %ld\n", minp(t+2, t+6)-t);

    return 0;
}


int *minp(int *f, int *s){
    if (f < s){ /* f-s < 0   ==== 0 < s-f */
        return f;
    }else{
        return s;
    }
}
