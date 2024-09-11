#include <stdio.h>

int *min(int *first, int *last);
int sum(int *first, int *last);

int main(){
    int t[] = {-10, 2, 3, 4, 0, -2, 3, -1};
    int l = sizeof(t) / sizeof(*t);
    
    int s = sum(t, t+l);
    int *m = min(t, t+l);
    printf("min: %d, index: %ld\n", *m, m-t);
    

    printf("sum: %d\n", s);
    return 0;
}

/*
int sum(int *first, int *last){
    int result = 0;
    int l = last - first;
    for (int i = 0; i < l; i++){
        result += first[i];
    }
    
    return result;
}
*/


int sum(int *first, int *last){
    int result = 0;
    while (first != last){
        result += *(first++);
    }
    return result;

}


int *min(int *first, int *last){
    int *minelem = first++;
    while (first != last){
        if (*first < *minelem){
            minelem = first;
        }
        first++;
    }
    
    return minelem;
}





















