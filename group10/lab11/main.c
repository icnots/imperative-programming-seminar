

#include <stdlib.h>
#include <stdio.h>

#include "student.h"

#define STUDENTSSIZE 200

int main(){
/*
    Student students[] = {
        {1, 18, 4.5, BSC, {.cn = 3}},
        {2, 22, 4.6, MSC, {.ci = 3.9}},
        {3, 22, 4.0, PHD, {.phd = {7.6, 4}}}    
    };
*/

    Student *t[STUDENTSSIZE];
    for (int i = 0; i < STUDENTSSIZE; i++){
        t[i] = student_init(rand() % 3);
    }
    
    
    int length = sizeof(t) / sizeof(t[0]);
    Student *max = maxAverage(t, length);
    
    printf("Data of max:\n");
    printStudent(max);
    
    /*
    for (int i = 0; i < length; i++){
        printStudent(t[i]);
    }
    */
}
