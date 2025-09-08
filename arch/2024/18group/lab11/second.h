#ifndef SECOND_H_INCLUDED
#define SECOND_H_INCLUDED

/*
struct Student{
    double avg;
    int id;
    short age;
};

typedef struct Student Student;
*/

typedef struct Student{
    double avg;
    int id;
    short age;
} Student;



void fel2(void);
Student *student_init(void);
void student_print(Student st);

void my_mem_check(void *p);
Student *student_search(Student **students, int length);

#endif
