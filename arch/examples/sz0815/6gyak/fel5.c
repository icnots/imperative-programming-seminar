#include <stdio.h>

int sum(int *first, int *last);

int main(){
    int t[] = {1,2,3,4,5};
    int l = sizeof(t)/sizeof(t[0]);
    int *f = t;
    int *last = t + l;
    int s = sum(f, last);

    printf("sum: %d\n", s);
    return 0;
}


int sum(int *first, int *last){
    int s = 0;
    while (first != last){
        s += *first;
        first++;
    }
    
    return s;
}
