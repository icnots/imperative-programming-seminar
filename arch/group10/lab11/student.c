#include <stdio.h>
#include <stdlib.h>

#include "student.h"



struct Student{
    int id, age;
    double av;
    enum Type t;
    union Data{
        int cn;
        double ci;
        struct PHdData{
            double impf;
            int en;
        }phd;
    }data;
};

Student *student_init(Type t){
    static int counter = 1000;
    Student *s =(Student *)malloc(sizeof(Student));
    if (!s){
        fprintf(stderr, "no memory\n");
        exit(7);
    }
    
    s->id = counter++;
    s->age = 18 + rand() % 20;
    s->av = 1.9 + (rand() % 32) / 10.0;
    s->t = t;
    switch(t){
        case BSC:
            s->data.cn = rand() % 15;
            break;
        case MSC:
            s->data.ci = 1.9 + (rand() % 32) / 10.0;
            break;
        case PHD:
            s->data.phd.impf = (rand() % 100) / 10.0;
            s->data.phd.en = 1 + rand() % 10;
            break;
    }
    
    return s;    
}

Student *maxAverage(Student *s[], int length){
    Student *max = s[0];
    for (int i = 1; i < length; i++){
        if (max->av < s[i]->av){
            max = s[i];
        }
    }
    
    return max;
}

void printStudent(Student *s){
    printf("%d : age: %d, av: %lf, ", s->id, s->age, s->av);
    switch(s->t){
        case BSC:
            printf("BSC, cn: %d\n", s->data.cn);
            break;
        case MSC:
            printf("MSC, ci: %lf\n", s->data.ci);
            break;
        case PHD:
            printf("PHD, impf: %lf, en: %d\n", s->data.phd.impf, s->data.phd.en);
            break;
    }
}
