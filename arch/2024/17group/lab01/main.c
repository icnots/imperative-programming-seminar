#include <stdio.h>

int main();


int main(){
    char name[30];
    int a;
    int b; /* int a, b; */

    printf("Hello World!\n");
    
    printf("Please, give me your name!\n");
    /* fflush(stdout); */
    scanf("%s", name);
    
    printf("Hello, %s\n", name);
    
    printf("Give me two numbers!\n");
    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("Sum: %d\n", a+b);
    printf("%d + %d = %d\n", a, b, a+b);
    
    return 0;
}
