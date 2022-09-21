#include <stdio.h>


int g(){
    int k = 79;
}
int f(){
    int j;
    printf("%d\n", j);
}

int main(){
    g();
    f();
    
    
    int i;
    scanf("%d", &i);
    
    if (i % 2 == 0){
        printf("even\n");
    }
    else{
        printf("odd\n");
    }
    
    i = -7;
    printf("%d\n", i % 2);
    printf("%d\n", i / 2);
    /*szam = (szam / masik) * masik + (szam % masik)*/
    return 0;
}
