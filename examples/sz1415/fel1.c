#include <stdio.h>

void print(int p);

int main(){
    print(sizeof(int));
    print(sizeof(long int));
    print(sizeof(unsigned int));
    print(sizeof(unsigned long long));

    return 0;
}

void print(int p){
    printf("%d\n", p);
}

