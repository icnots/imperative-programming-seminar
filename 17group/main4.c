#include <stdio.h>
#include <math.h>

void strcpynm(char a[], char b[], int n, int m);
int f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();
void f8();
int isUpperCharacter(char ch);
int toUpperCharacter(char ch);
int isLowerCharacter(char ch);
int toLowerCharacter(char ch);
void printInTwoDigits(int n);

int main(){
    //f1();
    //f2();
    //f8();
    char szo1[100] = "Dokumentumok";
    char szo2[100];

    strcpynm(szo1, szo2, 2, 5);

    printf("%s\n", szo2);


    return 0;
}


int f1(){
    int i;

    i = 0;
    printf("i++ : %d\n", i++);
    i = 0;
    printf("++i : %d\n", ++i);

    /*
    i = 0;
    printf("%d, %d, %d\n", i = i+1, i++, i++);
    undefined order
    */

    return 0;
}

int isUpperCharacter(char ch){
    return 'A' <= ch && ch <= 'Z';
}

int toUpperCharacter(char ch){
    return ch - 'A' + 'a';
}

int isLowerCharacter(char ch){
    return 'a' <= ch && ch <= 'z';
}

int toLowerCharacter(char ch){
    return ch - 'a' + 'A';
}

void f2(){
    char ch;

    while (EOF != (ch = getchar())){
        if (isUpperCharacter(ch)){
            printf("%c", toUpperCharacter(ch));
        }else if (isLowerCharacter(ch)){
            printf("%c", toLowerCharacter(ch));
        }
    }
}

void f3(){
    double a, b;

    scanf("%lf", &a);
    scanf("%lf", &b);

    printf("%lf + %lf = %lf\n", a, b, a + b);
    printf("%lf - %lf = %lf\n", a, b, a - b);
    printf("%lf * %lf = %lf\n", a, b, a * b);
    if (b*b > 0.000000001){
        printf("%lf / %lf = %lf\n", a, b, a / b);
    }
}

void f4(){
    double r;
    scanf("%lf", &r);

    printf("Diameter: %lf\n", 2*r);
    printf("Area: %lf\n", r*r*M_PI);
    printf("Perimeter: %lf\n", 2*r*3.14159);


}

void printInTwoDigits(int n){
    if (n < 10){
        printf("0");
    }
    printf("%d", n);
}

void f5(){
    /*YYYYMMDD*/
    int date, day, month, year;
    scanf("%d", &date);

    day = date % 100;
    month = (date / 100) % 100;
    year = date / 10000;

    /*DD-MM-YYYY*/
    printInTwoDigits(day);
    printf("-");
    printInTwoDigits(month);
    printf("-");
    printf("%d\n", year);
}

void f6(){
    double a0, a1, b0, b1, c0, c1, d0, d1;
    scanf("%lf", &a0);
    scanf("%lf", &a1);
    scanf("%lf", &b0);
    scanf("%lf", &b1);
    scanf("%lf", &c0);
    scanf("%lf", &c1);
    scanf("%lf", &d0);
    scanf("%lf", &d1);

    if (pow((a0-b0)*(c0-d0)+(a1-b1)*(c1-d1), 2)  < 0.00000001){
        printf("Merolegesek\n");
    }else{
        printf("Nem merolegesek\n");
    }

}

void f7(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("a: %d, b: %d\n", a, b);

    /* a: a , b: b */
    a = a + b;
    /* a: a+b , b: b */
    b = a - b;
    /* a: a+b , b: a */
    a = a - b;
    /* a: b , b: a */

    printf("a: %d, b: %d\n", a, b);

    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("a: %d, b: %d\n", a, b);
}

void f8(){
    int n, m = 0;
    scanf("%d", &n);

    /* 0000001 -> 1111110 */
    /* 0101001 -> 1010110 */
    //0 && 1 = 0
    //0 & 1 = 0
    n = n ^ -1;

    printf("%d\n", n);

    n = 123;
    while (n > 0){
        printf("%d, %d\n", n, m);
        m = m * 2 + n % 2;
        n /= 2; /* n = n / 2; */
    }

    printf("%d\n", m);
    /* 0101001, 0 -> 010100,1
       010100,1   -> 01010,10
       1001010
    */
}

void strcpynm(char a[], char b[], int n, int m){
    for (int i = 0; i < m-n; i++){
        b[i] = a[n+i];
    }
    b[m-n] = '\0';
}
