#include <stdio.h>
#include <stdlib.h>

#include "func.h"

FILE *fileOpening(const char *filename){
    FILE *fp = fopen(filename, "r");
    
    if (fp){
        return fp;
    }else{
        fprintf(stderr, "File not exist: %s\n", filename);
        exit(-1);
    }
}

FILE *fileWrite(const char *filename){
    FILE *fp = fopen(filename, "w");
    
    if (fp){
        return fp;
    }else{
        fprintf(stderr, "File not exist: %s\n", filename);
        exit(-1);
    }
}

