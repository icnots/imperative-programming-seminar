#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, *t, i, n;
    n = 5;
    
    t = (int *)malloc(n * sizeof(int));
    
    if (!t){
        fprintf(stderr, "No memory\n");
        return 1;
    }
    
    p = t + 2;

    for (i = 0; i < n; i++){
        t[i] = i;
    }
    
    fprintf(stdout, "%d\n", *p); 
    
    /* itt! */

    free(t);

    return 0;
}



/*
Stack:
p    :    #118
t    :    #110
i    :     5
n    :     5


Heap:
#110 :     0
#114 :     1
#118 :     2
#122 :     3
#126 :     4


*/
