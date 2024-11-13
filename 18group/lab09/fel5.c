#include "fel5.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 50

void fel5(){
    printf("fel5\n");
    
    const char *filename = "valami.txt";
    FILE *fp;
    FILE *outsource = stdout;
    
    fp = fopen(filename, "r");
    if (fp){
        char buffer[BUFFERSIZE];
        while (NULL != fgets(buffer, BUFFERSIZE, fp)){
            int length = strlen(buffer);
            for (int i = 0; i < length; i++){
                fprintf(outsource, "%c", toupper(buffer[i]));
            }
        }
        
    
        fclose(fp);
    }else{
        fprintf(stdout, "Could not open %s\n", filename);
    }
    
}
