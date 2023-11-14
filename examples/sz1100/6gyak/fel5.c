#include <stdio.h>

int sum(int *first, int *last);
int sum2(int *first, int *last);

int main(){
    int t[] = {3, 4, 5, 1, 2};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("sum: %d\n", sum(t, t+length));
    printf("sum2: %d\n", sum2(t, t+length));
    
    

    return 0;
}


int sum(int *first, int *last){
    int s = 0;
    int length = last - first;
    for (int i = 0; i < length; i++){
        s += *(first + i);
    }
    return s;
}

int sum2(int *first, int *last){
    int s = 0;
    while (first != last){
        s += *first;
        first++;
    }
    return s;
}



