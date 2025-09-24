#include <stdio.h>
#include <math.h>

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

void fel2(){
    char ch;

    while ('0' != (ch = getchar())){
        if ('a' <= ch && ch <= 'z'){
            printf("%c", ch - 'a' + 'A');
        }else if ('A' <= ch && ch <= 'Z'){
            printf("%c", ch - 'A' + 'a');
        }
    }

}


void fel3(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    if (0 != b){
        printf("%d / %d = %d\n", a, b, a / b);
        printf("%d %% %d = %d\n", a, b, a % b);
        printf("%d.0 / %d.0 = %f\n", a, b, a * 1.0 / b);
    }

}

void fel5(){
    int n;
    int d, m, y;

    scanf("%d", &n);

    d = n % 100;
    y = n / 10000;
    m = (n / 100) % 100;

    printf("Date: %d-%d-%d", d, m, y);

}

void fel6(){
    double x1, x2, y1, y2;
    double a1, a2, b1, b2;

    scanf("%lf", &x1);
    scanf("%lf", &x2);
    scanf("%lf", &y1);
    scanf("%lf", &y2);
    scanf("%lf", &a1);
    scanf("%lf", &a2);
    scanf("%lf", &b1);
    scanf("%lf", &b2);
    
    double v1, v2;
    double n1, n2;
    v1 = x1 - y1;
    v2 = x2 - y2;
    n1 = a1 - b1;
    n2 = a2 - b2;

    double res = v1 * n1 + v2 * n2;

    if (res < 0.0){
        res *= -1;
    }

    if (res < 0.000000001){
        printf("Merolegesek\n");
    }else{
        printf("Nem merolegesek");
    }
}

void fel7(){
    int a, b;
    a = 10;
    b = -7;

    printf("a: %d, b: %d\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;



    printf("a: %d, b: %d\n", a, b);

}


void fel8(){
    int n = 0;

    printf("n: %d\n", n);

    //n *= -1;
    //n -= 1;
    
    n ^= -1;
    
    printf("n: %d\n", n);

}

int main(){
    /*demo1();*/
    /*demo2('Z');*/

    /* double d = M_PI; */

    /*fel2();*/
    fel8();

    return 0;
}