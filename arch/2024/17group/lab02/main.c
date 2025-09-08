#include <stdio.h>
#include <limits.h>

int main(){
    /* 1. feladat */
    /*
    int n = 7;
    printf("%d\n", n);
    */
    
    /* 2. feladat */
    /*
    n = -11;    
    printf("%d\n", n);
    */
    
    
    /* 3. feladat */
    /*
    int n;
    scanf("%d", &n);
    while (n % 2 == 0){
        printf("Give me an odd number!\n");
        scanf("%d", &n);
    }
    int n, m;
    */
    
    /* 4. feladat */
    /*
    int i;
    i = 3.9;
    printf("3.9: %d\n", i);
    i = 'a';
    printf("'a': %d\n", i);
    i = 0<1;
    printf("0<1: %d\n", i);
    i = "ferike";
    printf("\"ferike\": %d\n", i);
    */
    
    /* 5. feladat */
    /*
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("average: %lf\n", (a+b)/2.);
    */
    
    /* 6. feladat */
    /*
    double d;
    for (d = 0.; d <= 1.001; d += 0.1){
        printf("%lf\n", d);
    }
    */
    /*
    int i;
    for (i = 0; i <= 10; i++){
        printf("%.2lf\n", i * 0.1);
    }
    */
    
    /* 7. feladat */
    int max, min;
    int length = sizeof(int) * 8 - 1;
    max = 0;
    for (int i = 0; i < length; i++){
        max = 2 * max + 1;
    }
    printf("max: %d\n", max);
    printf("MAX: %d\n", INT_MAX);
    min = max + 1;
    printf("min: %d\n", min);
    printf("MIN: %d\n", INT_MIN);
    

    return 0;
}
