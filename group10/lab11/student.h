#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct Student;

enum Type{
    BSC,
    MSC,
    PHD
};



typedef enum Type Type;
typedef struct Student Student;

Student *student_init(Type t);
Student *maxAverage(Student *s[], int length);
void printStudent(Student *s);





#endif
