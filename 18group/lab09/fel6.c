#include "fel6.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 50

void fel6(){
    printf("fel6\n");
    
    const char *filename = "valami.txt";
    FILE *fp, *fpout;
    
    fp = fopen(filename, "r");
    fpout = fopen("masik.txt", "w");
    if (NULL == fpout){
        fpout = stdout;
    }
    if (fp && fpout){
        char buffer[BUFFERSIZE];
        while (NULL != fgets(buffer, BUFFERSIZE, fp)){
            int length = strlen(buffer);
            for (int i = 0; i < length; i++){
                fprintf(fpout, "%c", toupper(buffer[i]));
            }
        }
        
    
    }else{
        fprintf(stdout, "Could not open %s\n", filename);
    }
    
    fclose(fp);
    fclose(fpout);
}
