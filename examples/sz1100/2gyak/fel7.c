#include <stdio.h>

int main(){
    int a, b;
    double avg;
    
    scanf("%d", &a);
    scanf("%d", &b);

    avg = (a+b) / 2.;
    
    
    avg = a + b;
    avg = avg / 2; /* avg /= 2; */
    
    printf("Average: %f\n", avg);
    

    return 0;
}
