#include <stdio.h>

void increase(int *p);
void fel1();
void fel2();
void fel3();
void fel4();
void fel5();
void fel6();
void fel7();
void fel8();
void fel10();
int sum1(int t[], int l);
int sum1(int *t, int l);
int sum2(int *first, int *last);
double average(int *first, int *last);

int main(){
    /* fel1(); */
    //fel2();
    //fel3();
    //fel4();
    //fel5();
    //fel6();
    //fel7();
    //fel8();
    fel10();

    return 0;
}

int decide(int *a, int *b){
    return a < b;
}

void fel10(){
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *p1, *p2;
    
    p1 = t + 3;
    p2 = t + 1;
    
    if (decide(p1, p2)){
        printf("p1 < p2\n");
    }else{
        printf("p1 !< p2\n");
    }
}


void fel8(){
    int *p = NULL;
    printf("*p: %d\n", *p); /*undefined behavior*/
}

int *func(){
    int i = 12;
    /* return &i; */
    int *p = &i;
    
    return p;
}

void fel7(){
    int *p = func(); /*undefined behavior*/
    printf("*p: %d\n", *p); /*undefined behavior*/
}


void fel6(){
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("average: %lf\n", average(t, t+length));
}

double average(int *first, int *last){
    int sum_ = 0;
    int length = last - first;
    
    for (; first != last; first += 1){
        sum_ += *first;
    }
    
    return sum_ * 1.0 / length;
}


int sum2(int *first, int *last){
    int sum_ = 0;
    /*int length = last - first;*/
    
    for (; first != last; first += 1){
        sum_ += *first;
    }
    
    return sum_;
}


void fel5(){
    int t[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("sum: %d\n", sum2(t, t+length));
}


int sum1(int *t, int l){
    int i, sum_ = 0;
    for (i = 0; i < l; increase(&i)){
        sum_ += *(t+i);
    }
    return sum_;
}

void fel4(){
    int t[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("sum: %d\n", sum1(t, length));
}

void fel3(){
    void *p;
    
    p = (void *)&p;
    
    /* *******p == p */
    printf("sizeof(int *): %ld\n", sizeof(int*));
    printf("sizeof(void *): %ld\n", sizeof(void *));
    printf("sizeof(int **): %ld\n", sizeof(int**));
}

void fel2(){
    int i, j;
    int *p1, *p2;
    int **pp;
    
    p1 = &i;
    pp = &p1;
    
    
    printf("p1: %p\n", (void *)p1);
    *pp = &j;
    printf("p1: %p\n", (void *)p1);
    printf("pp: %p\n", (void *)pp);
    pp = &p2;
    printf("pp: %p\n", (void *)pp);
}

void fel1(){
    int i;
    i = 1;
    printf("i: %d\n", i);
    increase(&i);
    printf("i: %d\n", i);
}

void increase(int *p){
    *p += 1;
}
