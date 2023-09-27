#include <stdio.h>
#include <stdbool.h>

void print(int p);

int main(){
    print(sizeof(int));
    
    
    printf("int: %ld\n", sizeof(int));
    printf("uint: %ld\n", sizeof(unsigned int));
    printf("long int: %ld\n", sizeof(long int));
    printf("_Bool: %ld\n", sizeof(_Bool));
    printf("bool: %ld\n", sizeof(bool));
    
    
    return 0;
}



void print(int p){
    printf("%d\n", p);
}


