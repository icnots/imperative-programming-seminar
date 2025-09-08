#ifndef THIRD_H_INCLUDED
#define THIRD_H_INCLUDED

#include "second.h"

enum Type{
    BSC,
    MSC,
    PHD
};

union Data{
    int numberOfCourses;
    double creditIndex;
    struct PhdData{
        double ifactor;
        int en;
    } phddata;
};

struct AdvStudent{
    double avg;
    int id;
    short age;
    enum Type type;
    union Data data;
};

typedef struct AdvStudent AdvStudent;

void fel3(void);

AdvStudent *advstudent_init(void);
void advstudent_print(AdvStudent st);
#endif
