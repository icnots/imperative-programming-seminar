#include "first.h"
#include <stdlib.h>
#include <stdio.h>

void fel1(void){
    int ids[STUD_CNT];
    double avgs[STUD_CNT];
    short ages[STUD_CNT];
    
    init(ids, avgs, ages);
    
    for (int i = 0; i < STUD_CNT; i++){
        printf("id: %d, avg: %lf, age: %d\n", ids[i], avgs[i], ages[i]);
    }
}

void init(int *ids, double *avgs, short *ages){
    for (int i = 0; i < STUD_CNT; i++){
        ids[i] = i;
        avgs[i] = get_random(10, 50) / 10.0;
        ages[i] = get_random(18, 24);
    }
}


int get_random(int from, int to){
    return rand() % (to - from + 1) + from;
}
