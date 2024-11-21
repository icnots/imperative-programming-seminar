#include <stdio.h>

typedef int * int_p;

void setZero(int_p);

int main(){
    int i;
    
    int_p p;
    
    
    p = &i;
    
    setZero(p);
    
    int_p *pp = &p;
    
}



void setZero(int_p a){
    *a = 0;
}
