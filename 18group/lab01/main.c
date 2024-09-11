#include <stdio.h>

int main();


int main(){
    char name[30];
    int a, b;

    printf("Please, give me your name!\n");
    fflush(stdout);

    scanf("%s", name);
    printf("Hello %s!\n", name);

    printf("Please, give me two numbers!\n");
    fflush(stdout);

    scanf("%d", &a);
    scanf("%d", &b);

    printf("Sum: %d\n", a+b);


    return 0;
}
