#include <stdlib.h>
#include <stdio.h>
#include "first.h"
#include "third.h"



void fel3(void){
    AdvStudent *students[STUD_CNT];
    
    for (int i = 0; i < STUD_CNT; i++){
        students[i] = advstudent_init();
    }
    
    for (int i = 0; i < STUD_CNT; i++){
        advstudent_print(*(students[i]));
    }
    
    
    for (int i = 0; i < STUD_CNT; i++){
        free(students[i]);
    }
    
}


AdvStudent *advstudent_init(void){
    AdvStudent *p = (AdvStudent *)malloc(1*sizeof(AdvStudent));
    static int counter = 0;

    my_mem_check(p);
    (*p).id = counter++;
    p->avg = get_random(10, 50) / 10.0;
    p->age = get_random(18, 24);
    p->type = get_random(0, 2);
    switch(p->type){
        case BSC: p->data.numberOfCourses = get_random(2, 10);
            break;
        case MSC: p->data.creditIndex = get_random(10, 50) / 10.0;
            break;
        case PHD: p->data.phddata.ifactor = get_random(0, 100) / 10.0
                p->data.phddata.en = get_random(3, 8);
               break;
    }
    return p;
}


void advstudent_print(AdvStudent st){
    printf("id: %d, avg: %lf, age: %d", st.id, st.avg, st.age);
    switch(p->type){
        case BSC: printf("number of courses: %d\n", st.data.numberOfCourses);
                break;
        case MSC: printf("credit index: %lf\n", st.data.creditIndex);
                break;
            
        case PHD: printf("impact factor: %lf", st.data.phddata.ifactor);
                printf("Erdos number: %d\n", st.data.phddata.en);
                break;
    }
}

