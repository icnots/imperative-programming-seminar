#include "tasks.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /*for (int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }*/
    
    if (argc != 2){
        fprintf(stderr, "Not valid argument number\n");
        return 1;
    }
    int feladat = atoi(argv[1]);
    
    printf("feladat: %d\n", feladat);

    switch (feladat){
        case 1: feladat1(); break;
        case 2: feladat2(); break;
        case 3: feladat3(); break;
        case 4: feladat4(); break;
        case 5: feladat5(); break;
        case 6: feladat6(); break;
    
    }

    return 0;
}
