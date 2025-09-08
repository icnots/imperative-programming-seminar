#include <stdio.h>

int fel1();
int demo();

int main(){
    fel1();
    return 0;
}


int fel1(){
    printf("sizeof(short): %d\n", (int)sizeof(short));

    return 0;
}

int demo(){
    int i = 97;
    unsigned int u;
    i = 'a';

    printf("%d\n", i);
    printf("%f\n", (float)i);
    printf("%c\n", i);

    u = -1;
    printf("%u\n", u);

    printf("sizeof(short): %d\n", (int)sizeof(short));

    return 0;
}
