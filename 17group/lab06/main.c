#include <stdio.h>


void fel1();
void fel2();
void fel3();
void fel4();
void fel5();
void fel6();
void fel7();
void fel8();
void fel9();
void fel10();
void swap(int *a, int *b);
int sum1(int *t, int l);
int sum1(int t[], int l);
int sum2(int *f, int *l);
double average(int *f, int *l);


int main(){
    //fel1();
    //fel2();
    //fel3();
    //fel4();
    //fel5();
    //fel6();
    //fel7();
    //fel8();
    //fel9();
    fel10();
    return 0;
}


void fel1(){
    int i = 1;
    int *p;
    p = &i;
    
    printf("i: %d\n", i);
    *p = 2;
    printf("i: %d\n", i);
}


void fel2(){
    int i = 1, j = 2;
    int *p1 = &i, *p2 = &j;
    int **pp = &p1;
    
    printf("p1: %p\n", (void *)p1);
    *pp = p2;
    printf("p1: %p\n", (void *)p1);
    printf("pp: %p\n", (void *)pp);
    pp = &p2;
    printf("pp: %p\n", (void *)pp);
}

void fel3(){
    void *p;
    p = &p;
    
    printf("p: %p\n", (void *)p);
    printf("&p: %p\n", (void *)&p);
    /* *********p == p */
    
    printf("sizeof(int *): %ld\n", sizeof(int *));
    printf("sizeof(void *): %ld\n", sizeof(void *));
    printf("sizeof(double *): %ld\n", sizeof(double *));
    printf("sizeof(int **): %ld\n", sizeof(int **));
}

void fel4(){
    int t[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("sum: %d\n", sum1(t, length));
}


int sum1(int *t, int l){
    int sum_ = 0;
    for (int i = 0; i < l; i++){
        sum_ += t[i];
        // sum_ += *(t+i)
    }
    
    return sum_;
}

void fel5(){
    int t[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("sum: %d\n", sum2(t, t+length));
}

int sum2(int *f, int *l){
    int sum_ = 0;
    // int length = l - f;
    while (f != l){
        sum_ += *f;
        f++;
    }
    
    /*
    for (;f < l; f++){
        sum_ += *f;
    }
    */
    
    return sum_;
}


void fel6(){
    int t[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("average: %lf\n", average(t, t+length));
}


double average(int *f, int *l){
    int sum_ = 0;
    int length = l - f;

    for (;f < l; f++){
        sum_ += *f;
    }
    
    return sum_ * 1.0 / length;
}


int *func(){
    int p = 12;
    int *q = &p;
    return q;
}

void fel7(){
    int *p = func();
    /* undefined behavior */
    printf("%d\n", *p);
}

void fel8(){
    int *p = NULL;
    /* undefined behavior */
    printf("%d\n", *p);
}

void fel9(){
    int i = 1, j = 2;
    printf("i: %d, j:%d\n", i, j);
    swap(&i, &j);
    printf("i: %d, j:%d\n", i, j);
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int smaller(int *f, int *s){
    return f < s;
}

void fel10(){
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int *p1, *p2;
    p1 = t + 3;
    p2 = &(t[6]);
    
    printf("%s\n", smaller(p1, p2) ? "smaller" : "greater");
    
}


