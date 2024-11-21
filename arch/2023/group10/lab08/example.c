#include <stdio.h>


int i = 1;
int j = 3;


int main(){
    int *p = &j;
    int i = 2, j = 4;
    printf("j: %d\n", j);

    {
        int i = 3;
        j = 6;
        {
            extern int j;
            j = 15;
            i = 5;
            
            for (int i = 0; i < 12; i++){
            }
        }
        j = 7;
        printf("i: %d\n", i);
    }
    printf("j: %d\n", j);
    printf("*p: %d\n", *p);
}
