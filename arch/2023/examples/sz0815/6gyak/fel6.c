#include <stdio.h>

int sum(int *first, int *last);
double average(int *first, int *last);

int main(){
    int t[] = {1,2,3,4,6};
    int l = sizeof(t)/sizeof(t[0]);
    int *f = t;
    int *last = t + l;
    int s = sum(f, last);

    printf("sum: %d\n", s);
    printf("average: %f\n", average(f, last));
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

/*
double avg(int *first, int *last){
    double s = 0;
    int *ff = first;
    int l = last - first;
    while (first != last){
        s += *first;
        first++;
    }
    
    return s / (last - ff);
}*/


double average(int *first, int *last){
    return ((double)sum(first, last)) / (last - first);
}
