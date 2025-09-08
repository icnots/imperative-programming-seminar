#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

#define STUD_CNT 20


struct Student_t{
    double avg;
    int id;
    short age;
};
/*
typedef struct Student_t{
    int id;
    double avg;
    short age;
} Student;
*/
typedef enum Type{
    BSC,
    MSC,
    PHD
} Type;

union Data{
    int cn;
    double cci;
    struct PhdData{
        double ifactor;
        int en;
    } phddata;
};
typedef union Data Data;

struct AdvStudent{
    Data data;
    double avg;
    int id;
    Type t;
    short age;
};

void fel2(void){
    // printf("size of student: %ld\n", sizeof(Student));
    
    Student *ss[STUD_CNT];
    for (int i = 0; i < STUD_CNT; i++){
        ss[i] = student_init();
    }
    
    for (int i = 0; i < STUD_CNT; i++){
        student_print(*ss[i]);
    }

    printf("Highest average student id: %d\n", student_search(ss)->id);
    
    for (int i = 0; i < STUD_CNT; i++){
        free(ss[i]);
    }
    

}

void fel3(void){
    // printf("size of advstudent: %ld\n", sizeof(AdvStudent));
    
    AdvStudent *ss[STUD_CNT];
    for (int i = 0; i < STUD_CNT; i++){
        ss[i] = advstudent_init();
    }
    
    for (int i = 0; i < STUD_CNT; i++){
        advstudent_print(*ss[i]);
    }
    
    for (int i = 0; i < STUD_CNT; i++){
        free(ss[i]);
    }
}

void advstudent_print(AdvStudent s){
    printf("id: %d, avg: %lf, age: %d", s.id, s.avg, s.age);
    switch(s.t){
        case BSC: 
            printf(" cn: %d\n", s.data.cn);
            break;
        case MSC:
            printf(" cci: %lf\n", s.data.cci);
            break;
        case PHD:
            printf(" if.: %lf", s.data.phddata.ifactor);
            printf(" en %d\n", s.data.phddata.en);
            break;
    }
}
void student_print(Student s){
    printf("id: %d, avg: %lf, age: %d\n", s.id, s.avg, s.age);
}


Student *student_init(void){
    Student *p;
    p = (Student *)malloc(1*sizeof(Student));
    memCheck(p);
    static int counter = 0;
    
    (*p).id = counter++;
    p->avg = getRandom(10, 50) / 10.0;
    p->age = getRandom(18, 30);
    
    return p;
}

AdvStudent *advstudent_init(void){
    AdvStudent *p;
    p = (AdvStudent *)malloc(1*sizeof(AdvStudent));
    memCheck(p);
    static int counter = 0;
    
    (*p).id = counter++;
    p->avg = getRandom(10, 50) / 10.0;
    p->age = getRandom(18, 30);
    
    int random = getRandom(0, 2);
    switch (random){
        case 0:
            p->t = BSC;
            p->data.cn = getRandom(1, 10);
            break;
        case 1:
            p->t = MSC;
            p->data.cci = getRandom(100, 500) / 100.0;
            break;
        case 2:
            p->t = PHD;
            p->data.phddata.ifactor = getRandom(100, 1000) / 100.0;
            p->data.phddata.en = getRandom(3, 8);
            break;
    }
    
    return p;
}

void memCheck(void *p){
    if (!p){
        fprintf(stderr, "no mem\n");
        exit(1);
    }
}

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
        avgs[i] = getRandom(10, 50) / 10.0;
        ages[i] = getRandom(18, 30);
    }
    
}

int getRandom(int from, int to){
    return rand() % (to - from + 1) + from;
}


Student *student_search(Student **ss){
    Student *highest = ss[0];
    for (int i = 1; i < STUD_CNT; i++){
        if (ss[i]->avg > highest->avg){
            highest = ss[i];
        }
    }
    
    return highest;
}
