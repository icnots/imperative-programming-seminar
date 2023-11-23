#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"

int main(int argc, char *argv[]){
    /*for (int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }*/
    if (2 != argc){
        fprintf(stderr, "Not valid number of arguments\n");
        return 1;
    }
    
    int feladat_number = atoi(argv[1]);
    
    printf("feladat: %d\n", feladat_number);
    switch(feladat_number){
        case 1: feladat1(); break;
        case 2: feladat2(); break;
        case 3: feladat3(); break;
        case 4: feladat4(); break;
        case 5: feladat5(); break;
        case 6: feladat6(); break;
        default:
            fprintf(stderr, "feladat_number is invalid\n");
    }
    
    return 0;
}
