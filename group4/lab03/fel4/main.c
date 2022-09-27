#include <stdio.h>
#include <string.h>

int main(){
    char buffer[50];
    int values[49];
    
    scanf("%s", buffer);

    int hossz = strlen(buffer);

    for (int i = 0; i < hossz; i++){
        if ('0' <= buffer[i] && buffer[i] <= '9'){
            values[i] = buffer[i]-'0';
        }
        else if ('a' <= buffer[i] && buffer[i] <= 'f'){
            values[i] = buffer[i]-'a'+10;
        }
        else{
            printf("Please give me 0,..,9,a..f\n");
            return 1;
        }
        //printf("%d ", values[i]);
    }
    
    int value = 0;
    for (int i = 0; i < hossz; i++){
        value *= 16;
        value += values[i];
    }
    
    printf("decimal: %d\n", value);
    return 0;
}
