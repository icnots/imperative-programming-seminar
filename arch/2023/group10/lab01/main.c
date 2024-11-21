#include "stdio.h"

int main(){
    int szam;
    szam = 7100;
    float f = 1.5;
    char ch = 'a';
    char name[25] = "Ferike";


    printf("Hello World!\n");
    printf("A szám : %d\n", szam);
    printf("f: %f\n", f);
    printf("Name: %s\n", name);
    printf("ch: %c\n", ch);
    
    fflush(stdout);
    
    scanf("%d", &szam);
    scanf("%f", &f);
    scanf("%c", &ch);
    scanf("%c", &ch);
    scanf("%s", name);
    
    
    
    printf("Hello World!\n");
    printf("A szám : %d\n", szam);
    printf("f: %f\n", f);
    printf("Name: %s\n", name);
    printf("ch: %c\n", ch);
    
    
    return 0;
}
