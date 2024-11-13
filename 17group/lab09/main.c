#include <stdio.h>

#include "utils.h"

//  int main(int argc, char *argv[]){
int main(int argc, char **argv){
    /*for (int i = 0; i < argc; i++){
        fprintf(stdout, "%d: %s\n", i, argv[i]);
    }*/
    
    if (argc == 2){
        int fel_szam = argv[1][0] - '0';
        printf("fel: %d\n", fel_szam);
        if (fel_szam == 1){
            fel1();
        }
        switch (fel_szam){
            case 1: break;
            case 2: fel2(); break;
            case 3: fel3(); break;
            case 4: fel4(); break;
            case 5: fel5(); break;
            case 6: fel6(); break;
        
            default: printf("not implemented yet\n");
        }
        
        
    }else{
        printf("Please provide exactly 1 parameter!\n");
    }
    return 0;
}
