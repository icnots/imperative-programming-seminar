#include <stdio.h>

int *min(int *first, int *last);
int *f();

int main(){
    int t[] = {2,4,5,6,3,2,1,3,4,5,6};

    printf("min: %d\n", *min(t, (t+sizeof(t)/sizeof(t[0]))));
    
    int *p = f();
    p = NULL;
    printf("NULL: %d\n", *p);
    
    return 0;
}


int *min(int *first, int *last){
    int *mp = first;
    while (first != last){
        if (*first < *mp){
            mp = first;
        }
        first++;
    }
    return mp;
}

int *f(){
    int a = 12;
    return &a;
}
