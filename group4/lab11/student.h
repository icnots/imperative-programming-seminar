#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


typedef enum Type{
    BSc,
    MSc,
    PhD
}Type;

typedef union Data{
    int n;
    double ci;
    struct PhDData{
        double impf;
        int en;
    }phdData;
}Data;

struct Student{
    int id;
    int age;
    double average;
    Type t;
    Data data;
};

typedef struct Student Student;

Student *maxAverage(Student *students[], int length);
Student *student_init(Type t);
void printStudent(Student *p);


#endif
