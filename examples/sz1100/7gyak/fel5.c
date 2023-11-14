#include <stdio.h>

#define INPUT_LENGTH 100
void swap(char *a, char *b);
int main(){
    char input[INPUT_LENGTH];
    char ch;
    int counter = 0;


    while (0 <= (ch = getchar()) && counter < INPUT_LENGTH-1 ){
        if ('0' <= ch && ch <= '9'){
            input[counter++] = ch;
        }else{
            fprintf(stderr, "Not a valid dec digit\n");
        }
    }
    input[counter] = '\0';
    
    swap(&input[0], &input[counter-1]);
    
    /*swap(input, input+counter-1);*/
    
    printf("%s\n", input);

    return 0;
}

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

