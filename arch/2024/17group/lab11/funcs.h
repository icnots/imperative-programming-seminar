#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

struct Student_t;
typedef struct Student_t Student;
struct AdvStudent;
typedef struct AdvStudent AdvStudent;

void fel2(void);
void fel1(void);

void fel3(void);

Student *student_init(void);
AdvStudent *advstudent_init(void);
void init(int *ids, double *avgs, short *ages);
void memCheck(void *p);

void student_print(Student s);
void advstudent_print(AdvStudent s);
int getRandom(int from, int to);
Student *student_search(Student **ss);


#endif
