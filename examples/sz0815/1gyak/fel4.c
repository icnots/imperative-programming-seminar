#include <stdio.h>

int main(){
    int year;
       
    printf("Give me a year\n");
    fflush(stdout);
    scanf("%d", &year);
    
    printf("%s\n", 
        (0 == year % 4) ?
            ((0 == year % 400) ? 
                "True" :
                (0 == year % 100) ? 
                    "False" :
                    "True") :
            "False");

    return 0;
}
