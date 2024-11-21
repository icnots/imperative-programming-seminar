#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "student.h"

#define STUDENTSIZE 20

int main(){
    Student *s[STUDENTSIZE];
    
    for (int i = 0; i < STUDENTSIZE; i++){
        s[i] = student_init(rand() % 3);
    }
    
    
    for (int i = 0; i < STUDENTSIZE; i++){
        printStudent(s[i]);
    }
    
    
    Student *max = maxAverage(s, STUDENTSIZE);
    printf("data of max average Student:\n");
    printStudent(max);

    for (int i = 0; i < STUDENTSIZE; i++){
        free(s[i]);
    }
    
}


