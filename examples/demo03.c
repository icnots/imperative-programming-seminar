#include <stdio.h>

int demo1(){
    int t[10];

    t[0] = 13;

    int i = 0;
    while (i < 10){
        t[i] = i;
        i += 1;
    }

    for (int i = 0; i < 10; i++){
        printf("%d. : %d\n", i, t[i]);
    }

    return 0;
}

float demo2(char ch){
    
    while ('0' != (ch = getchar())){
        printf("'%c' : ASCII: %d\n", ch, ch);
    }


    return 0.0;
}

int main(){
    demo1();
    demo2('Z');

    return 0;
}