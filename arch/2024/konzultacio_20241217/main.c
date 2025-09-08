#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "snake.h"

#define BUFFERSIZE 40

int main(int argc, char **argv){
    srand(time(NULL));
    Field field;
    int length = 1;
    Coordinate *snake = (Coordinate *)malloc(sizeof(Coordinate) * length);
    pointerCheck(snake);
    
    if (3 != argc){
        fprintf(stderr, "Please, provide 2 arguments\n");
        return 1;
    }
    
    field.height = atoi(argv[1]);
    sscanf(argv[2], "%d", &(field.width));

    // printf("h: %d, w: %d\n", field.height, field.width); // for debugging
    field.fields = (char *)malloc(sizeof(char) * field.height * field.width);
    pointerCheck(field.fields);
    int numberOfApples = field.height * field.width * 5 / 100 + 1;
    init_field(field, numberOfApples);
    init_snake(&snake, &length);

    //print_game(field, snake, length); // for debugging
    //print_field(field); // for debugging

    printf("Hello, this is a snake game.\n");
    printf("The rules are as usual.\n");
    
    char buffer[BUFFERSIZE];
    int appleCounter = 0;
    print_game(field, snake, length);
    while (NULL != fgets(buffer, BUFFERSIZE, stdin)){
        for (char *ch = buffer; *ch != '\0'; ch++){
            if (NULL != strchr("asdw", *ch)){
                int res = update_snake(field, &snake, &length, *ch);
                
                if (1 == res){
                    appleCounter += 1;
                }
                if (res == -1 || res == -2){
                    printf("You lost\n");
                    printf("You collected %d apples\n", appleCounter);
                    
                    free(field.fields);
                    free(snake);
                    return 0;
                }
                print_game(field, snake, length);
                
                if (appleCounter == numberOfApples){
                    printf("Congratulation! You won\n");
                    printf("You collected all the apples\n");
                    
                    free(field.fields);
                    free(snake);
                    return 0;
                }
            }
        }
    }
    printf("You collected all the apples\n");
    
    

    free(field.fields);
    free(snake);
    return 0;
}
