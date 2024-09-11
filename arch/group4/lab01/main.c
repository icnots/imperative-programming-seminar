#include "stdio.h"

int main(){

    int i = 13;
    char ch = 'a';
    float f = 0.122;
    double d = 13.15;
    char name[25] = "Agoston";
    printf("Hello World!\n");
    printf("i : %d\n", i);
    printf("karakter : %c\n", ch);
    printf("f : %f\n", f);
    printf("d : %f\n", d);

    printf("name : %s\n", name);

    fflush(stdout);
    scanf("%d %lf %s", &i, &d, name);

    printf("i : %d\n", i);
    printf("karakter : %c\n", ch);
    printf("f : %f\n", f);
    printf("d : %f\n", d);

    printf("name : %s\n", name);
    
    
    return 0;
}
