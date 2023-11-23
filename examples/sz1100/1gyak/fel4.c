#include <stdio.h>


int main(){
    int year;
    scanf("%d", &year);
    
    printf("%s\n",
        (0 == year % 4)
        ? (0 == year % 100)
            ? (0 == year % 400)
                ? "True"
                : "False"
            : "True"
        : "False"
    );
    
    return 0;
}


