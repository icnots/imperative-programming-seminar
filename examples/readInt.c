#include <stdio.h>


int isDigit(char ch){
    return '0' <= ch && ch <= '9';
}

int readInt(){
    char ch;
    ch = getchar();
    while (!isDigit(ch) && ch != '-'){
        ch = getchar();
    }

    int sign = 1;
    if (ch == '-'){
        sign = -1;
        ch = getchar();
        /*Ha most nem számjegy következik, akkor rossz számformátumot írtak be.*/
        if (!isDigit(ch)){
            printf("Invalid number");
            return 0;
        }
    }

    int value = ch - '0'; /*Mivel sorrendben vannak a számjegyek, a '0' értékét kivonva magát az értéket kapjuk.*/
    ch = getchar();
    while (isDigit(ch)){
        value *= 10;
        value += ch - '0';
        ch = getchar();
    }
    return sign * value;
}


int main(){
    int a = readInt();
    int b = readInt();

    printf("Your number is: %d %d\n", a, b);
    return 0;
}