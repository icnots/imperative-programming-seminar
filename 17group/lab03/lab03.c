#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int exercise1();
int exercise2();
int exercise3();
int exercise4();
int printRandomNumbers(int n);

int main(){
    // exercise1();
    // exercise2();
    // exercise3();
    // exercise4();

    srand(time(NULL));
    printRandomNumbers(10);

    return 0;
}



int exercise1(){
    printf("sizeof(int): %d\n", (int)sizeof(int));
    printf("sizeof(unsigned long int): %d\n", (int)sizeof(unsigned long int));
    
    return 0;
}


int exercise2(){
    int a = 7 , b = 8, c = 9;
    
    if ((a < b) && (b < c)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    
    a =-9, b = -8, c = -7;
    
    if ((a < b) && (b < c)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    
    
    
    return 0;
}

int exercise3(){
    /*
    i--; --i; i -= 1; i += -1; i = i-1;
    */
    for (int i = 10; i >= 0; i--){
        printf("%d ", i);
    }
    printf("\n");
    
    for (unsigned int i = 10; i < 11; i--){
        printf("%u ", i);
    }
    printf("\n");
    
    return 0;
}

int exercise4(){
    int year, condition;
    scanf("%d", &year);
    condition = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    
    printf(
        "This year (%d) is a %sleap year\n",
        year,
        condition ? "" : "not "
    );
    
    return 0;
}


int printRandomNumbers(int n){
    int randomNumber;
    for (int i = 0; i < n; i++){
        randomNumber = rand() % 101 + 100;
        printf("%d ", randomNumber);
    }
    printf("\n");
    
    return 0;
}

