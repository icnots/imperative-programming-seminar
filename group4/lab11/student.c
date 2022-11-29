#include "student.h"
#include <stdlib.h>
#include <stdio.h>


struct Student{
    int id;
    int age;
    double average;
    Type t;
    Data data;
};



Student *maxAverage(Student *students[], int length){
    Student *max = students[0];
    
    for (int i = 1; i < length; i++){
        if (max->average < students[i]->average){
            max = students[i];
        }
    }
    
    return max;

}

Student *student_init(Type t){
    static int currentId = 100;
    Student *p = (Student *)malloc(sizeof(Student));
    if (!p){
        fprintf(stderr, "No memory\n");
        exit(7);
    }
    
    p->id = currentId++;
    p->age = 18 + rand() % 10;
    p->average = 1.9 + (rand() % 32) / 10.0;
    p->t = t;
    switch (t){
        case BSc : p->data.n = rand() % 8;
              break;
        case MSc : p->data.ci = 1.9 + (rand() % 32) / 10.0;
              break;
        case PhD : p->data.phdData.en = rand() % 20 + 1;
              p->data.phdData.impf = (rand() % 100) / 10.0;
              break;
    }
    
    return p;
}

void printStudent(Student *p){
    printf("%d (%d): average: %f, ", p->id, p->age, p->average);
    switch (p->t){
        case BSc : printf("BSc, number of subjects: %d\n", p->data.n);
              break;
        case MSc : printf("MSc, corrigated credit index: %f\n", p->data.ci);
              break;
        case PhD : printf("PhD, erdos number: %d impf: %f\n", p->data.phdData.en, p->data.phdData.impf);
              break;
    }
}
