#include "tasks.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /*for (int i = 0; i < argc; i++){
        printf("%d: %s\n", i, argv[i]);
    }*/
    
    if (argc != 2){
        fprintf(stderr, "Not valid argument!\n");
        return 1;
    }
    
    int task_number = atoi(argv[1]);
    
    switch(task_number){
        case 1: feladat1(); break;
        case 2: feladat2(); break;
        case 3: feladat3(); break;
        case 4: feladat4(); break;
        case 5: feladat5(); break;
        case 6: feladat6(); break;
        default: fprintf(stderr, "This is not implemented yet.\n");
    }
    
    
    return 0;
}
