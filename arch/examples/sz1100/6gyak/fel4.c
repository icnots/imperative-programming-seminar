#include <stdio.h>

int sum(int *first, int length);

int main(){
    int t[] = {3, 4, 5, 1, 2};
    int length = sizeof(t) / sizeof(t[0]);
    
    printf("sum: %d\n", sum(t, length));
    
    

    return 0;
}


int sum(int *first, int length){
    int s = 0;
    for (int i = 0; i < length; i++){
        /* s += first[i]; */
        s += *(first + i);
        /* s += *(i + first); */
        /* s += i[first]; */
    }
    return s;
}
