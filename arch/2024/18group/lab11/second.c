#include <stdlib.h>
#include <stdio.h>
#include "first.h"
#include "second.h"



void fel2(void){
    Student *students[STUD_CNT];
    
    for (int i = 0; i < STUD_CNT; i++){
        students[i] = student_init();
    }
    
    for (int i = 0; i < STUD_CNT; i++){
        student_print(*(students[i]));
    }
    
    
    Student *highest_average = student_search(students, STUD_CNT);
    printf("Highest average student id: %d\n", highest_average->id);
    
    for (int i = 0; i < STUD_CNT; i++){
        free(students[i]);
    }
    
    printf("size of Student: %ld\n", sizeof(Student));
}


Student *student_init(void){
    Student *p = (Student *)malloc(1*sizeof(Student));
    static int counter = 0;

    my_mem_check(p);
    (*p).id = counter++;
    p->avg = get_random(10, 50) / 10.0;
    p->age = get_random(18, 24);
    
    return p;
}

void my_mem_check(void *p){
    if (!p){
        fprintf(stderr, "No mem\n");
        exit(1);
    }
}


void student_print(Student st){
    printf("id: %d, avg: %lf, age: %d\n", st.id, st.avg, st.age);
}

Student *student_search(Student **students, int length){
    Student *chosen = students[0];
    for (int i = 1; i < length; i++){
        if (chosen->avg < students[i]->avg){
            chosen = students[i];
        }
    }
    return chosen;
}
