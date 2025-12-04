#include <stdio.h>
#include <stdlib.h>

#include "helper.h"


void memCheck(void *p, const char *str){
    if (NULL == p){
        fprintf(stderr, "%s\n", str);
        exit(-1);
    }
}


void strip(char *p){
    while ('\r' != *p && '\n' != *p && '\0' != *p){
        p++;
    }
    *p = '\0';
}


int signum(int n){
    if (n > 0){
        return 1;
    }else if (n < 0){
        return -1;
    }else{
        return 0;
    }
}