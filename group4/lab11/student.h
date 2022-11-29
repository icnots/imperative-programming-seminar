#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

typedef enum Type{
    BSc,
    MSc,
    PhD
}Type;

struct Student;

typedef struct Student Student;

Student *maxAverage(Student *students[], int length);
Student *student_init(Type t);
void printStudent(Student *p);


#endif
