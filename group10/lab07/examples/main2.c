#include <stdio.h>

int sumValue(int *p, int l);
int sumPointer(int *first, int *last);
int *min(int *first, int *last);

int main(){
    int t[] = {1, 2, 3, 4, 0, 5, 6, 7, -6};
    int l = sizeof(t) / sizeof(*t);
    
    int s1 = sumValue(t, l);
    int s2 = sumPointer(t, t+l);
    
    printf("%d\n", s1);
    printf("%d\n", s2);
    
    int *minimal = min(t, t+l);
    printf("min: %d, index: %ld\n", *minimal, minimal-t);

    return 0;
}


int sumValue(int *p, int l){
    int result = 0;
    for (int i = 0; i < l; i++){
        result += p[i];
    }
    return result;
}


int sumPointer(int *first, int *last){
    int result = 0;
    /* int l = last - first;*/
    while (first != last){
        result += *(first++);
    }
    return result;
}

int *min(int *first, int *last){
    int *minPointer = first;
    while (++first != last){
        if (*minPointer > *first){
            minPointer = first;
        }
    }
    return minPointer;
}












