#include <stdio.h>
#include "fel1.h"
#include "fel2.h"
#include "fel3.h"
#include "fel4.h"
#include "fel5.h"
#include "fel6.h"


//int main(int argc, char **argv){

int main(int argc, char *argv[]){
    for (int i = 0; i < argc; i++){
        printf("%d: %s\n", i, argv[i]);
    }

    if (argc == 2){
        int fel_sorszam = argv[1][0] - '0';
        
        switch (fel_sorszam){
            case 1: fel1(); break;
            case 2: fel2(); break;
            case 3: fel3(); break;
            case 4: fel4(); break;
            case 5: fel5(); break;
            case 6: fel6(); break;
            default: fprintf(stdout, "This exercise is not implemented yet.\n");
        
        }
    }else{
        printf("Please, provide exactly 1 argument!\n");
    }

    return 0;
}
