#include <stdio.h>
#include <math.h>

void fel1();
int fel2();
int fel3();
int fel4();
int fel5();
int fel6();
int fel7();
int fel8();

int is_lower_character(char ch);
char from_lower_to_upper(char ch);


int main(){
    //fel1();
    fel8();

    return 0;
}


void fel1(){
    int i;
    
    i = 0;
    printf("i=0 and i++: %d ", i++);
    printf("i: %d\n", i);
    i = 0;
    printf("i=0 and ++i: %d ", ++i);
    printf("i: %d\n", i);
}

int is_lower_character(char ch){
    return 'a' <= ch && ch <= 'z';
}
char from_lower_to_upper(char ch){
    return ch - 'a' + 'A';
}


int fel2(){
    char ch = 'a';
    while (EOF != (ch = getchar())){
        if (is_lower_character(ch)){
            ch = from_lower_to_upper(ch);
            printf("%c", ch);
        }else if ('A' <= ch && ch <= 'Z'){
            ch = ch - 'A' + 'a';
            printf("%c", ch);
        }else{
            /* do nothing */
        }
    }
    

    return 0;
}

int fel3(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("a + b: %d\n", a+b);
    printf("a - b: %d\n", a-b);
    printf("a * b: %d\n", a*b);
    if (b != 0){
        printf("a / b: %d\n", a/b);
        printf("a %% b: %d\n", a%b);
        printf("a / b: %f\n", a * 1.0 /b);
    }

    return 0;
}


int fel4(){
    double r;
    scanf("%lf", &r);
    
    printf("d: %f\n", 2*r);
    printf("t: %f\n", r * r * 3.1415926535);
    printf("k: %f\n", 2*r * M_PI);
    
    
    return 0;
}
void print_in_2_chars(int n){
    if (n < 10){
        printf("0%d", n);
    }else{
        printf("%d", n);
    }
}

int fel5(){
    /*YYYYMMDD*/
    int date;
    int month, year, day;
    
    scanf("%d", &date);
    month = (date / 100) % 100;
    day = date % 100;
    year = (date / 10000) % 10000;
    
    /* DD-MM-YYYY */
    print_in_2_chars(day);
    printf("-");
    print_in_2_chars(month);
    printf("-");
    printf("%dn", year);

    return 0;
}

int fel6(){
    double a0,a1,b0,b1,c0,c1,d0,d1;
    scanf("%lf", &a0);
    scanf("%lf", &a1);
    scanf("%lf", &b0);
    scanf("%lf", &b1);
    scanf("%lf", &c0);
    scanf("%lf", &c1);
    scanf("%lf", &d0);
    scanf("%lf", &d1);

    if (pow((a0-b0)*(c0-d0) + (a1-b1)*(c1-d1), 2) < 0.00000000001 ){
        printf("Merolegesek\n");
    }else{
        printf("Nem merolegesek\n");
    }

    return 0;
}

int fel7(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("a: %d, b: %d\n", a, b);
    /* a: a, b: b */
    a = a + b;
    /* a: a+b, b: b */
    b = a-b;
    /* a: a+b, b: a */
    a = a-b;
    /* a: b, b: a */
    
    printf("a: %d, b: %d\n", a, b);
    return 0;
}

int fel8(){
    int n;
    scanf("%d", &n);
    n = n ^ -1;
    printf("n: %d\n", n);
    

    return 0;
}

