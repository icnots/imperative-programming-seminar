#include <stdio.h>

double average(int *first, int *last);
int sum2(int *first, int *last);

int main(){
    int t[] = {3, 4, 6, 1, 2};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("average: %f\n", average(t, t+length));
    printf("sum2: %d\n", sum2(t, t+length));
    
    

    return 0;
}


double average(int *first, int *last){
    return sum2(first, last) / (double)(last-first);
}

int sum2(int *first, int *last){
    int s = 0;
    while (first != last){
        s += *first;
        first++;
    }
    return s;
}



