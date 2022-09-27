#include <stdio.h>

int main(){
    char num[30];
    int values[29];
    int len;
    int i = 0;
    int value = 0;
    
    scanf("%s", num);
    
    len = 0;
    while (num[i] != '\0'){
        i += 1;
        len += 1;
    }
    
    for (i = 0; i < len; i++){
        if ('0' <= num[i] && num[i] <= '9'){
            values[i] = num[i] - '0';
        }else if ('a' <= num[i] && num[i] <= 'f'){
            values[i] = num[i] - 'a' + 10;
        }else{
            printf("Please give me a valid hexadecimal number!\n");
            return 1;
        }
    }
    
    
    for (i = 0; i < len; i++){
        value = value * 16 + values[i];
    }
    printf("decimal form: %d\n", value);
    
    /*
    for (i = 0; i < len; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    for (i = 0; i < len; i++){
        printf("%d ", values[i]);
    }
    printf("\n");
    */

    return 0;
}
