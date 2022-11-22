#include <stdio.h>
#include <stdlib.h>
#include "fel7.h"


int *feldolgoz(const char* filename, int *p, int *size, int *counter){
    FILE *fp = fopen(filename, "r");
    if (p == NULL){
        *size = 5;
        p = (int *)malloc(*size * sizeof(int));
        if (!p){
            printf("No memory\n");
            exit(7);
        }
        
        int temp, localCounter = 0;
        
        if (fp){
            while ((fscanf(fp, "%d", &temp) != -1)){
        printf("Hello %d\n", temp);
                if (*size == localCounter){
                    *size *= 2;
                    p = (int *)realloc(p, *size * sizeof(int));
                    if (!p){
                        printf("No memory\n");
                        exit(7);
                    }
                }
                
                p[localCounter] = temp;
                localCounter += 1;
            }
        
            fclose(fp);
            *counter = localCounter;
        }
    }else{
        int temp, localCounter = 0;
        
        if (fp){
            while ((fscanf(fp, "%d", &temp) != -1) && (localCounter < *counter)){
                p[localCounter] *= temp;
                localCounter += 1;
            }
        
            if (localCounter < *counter){
                *counter = localCounter;
            }
            fclose(fp);
        }
    }
    return p;
}

void fileWrite(int *p, const char *filename, int counter){
    FILE *fp = fopen(filename, "w");
    
    if (fp){
        for (int i = 0; i < counter; i++){
            fprintf(fp, "%d\n", p[i]);
        }
        
        fclose(fp);
    }
    
    
}
