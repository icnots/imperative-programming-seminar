#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


enum Type{
    BSC,
    MSC,
    PHD
};


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


typedef enum Type Type;
typedef struct Student Student;

Student *student_init(Type t);
Student *maxAverage(Student *s[], int length);
void printStudent(Student *s);





#endif
