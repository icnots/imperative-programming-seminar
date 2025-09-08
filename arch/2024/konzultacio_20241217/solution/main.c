#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "snake.h"

#define BUFFERSIZE 40

int main(int argc, char **argv){
    srand(time(NULL));
    int height, width;
    int length = 1;
    Coordinate *snake = (Coordinate *)malloc(sizeof(Coordinate) * length);
    pointerCheck(snake);
    
    if (3 != argc){
        fprintf(stderr, "Please, provide 2 arguments\n");
        return 1;
    }
    
    height = atoi(argv[1]);
    sscanf(argv[2], "%d", &width);

    // printf("h: %d, w: %d\n", height, width); // for debugging
    char *field = (char *)malloc(sizeof(char) * height * width);
    pointerCheck(field);
    int numberOfApples = height * width * 5 / 100 + 1;
    init_field(field, height, width, numberOfApples);
    init_snake(&snake, &length);

    //print_game(field, height, width, snake, length); // for debugging
    //print_field(field, height, width); // for debugging

    printf("Hello, this is a snake game.\n");
    printf("The rules are as usual.\n");
    
    char buffer[BUFFERSIZE];
    int appleCounter = 0;
    print_game(field, height, width, snake, length);
    while (NULL != fgets(buffer, BUFFERSIZE, stdin)){
        for (char *ch = buffer; *ch != '\0'; ch++){
            if (NULL != strchr("asdw", *ch)){
                int res = update_snake(field, height, width, &snake, &length, *ch);
                
                if (1 == res){
                    appleCounter += 1;
                }
                if (res == -1 || res == -2){
                    printf("You lost\n");
                    printf("You collected %d apples\n", appleCounter);
                    
                    free(field);
                    free(snake);
                    return 0;
                }
                print_game(field, height, width, snake, length);
                
                if (appleCounter == numberOfApples){
                    printf("Congratulation! You won\n");
                    printf("You collected all the apples\n");
                    
                    free(field);
                    free(snake);
                    return 0;
                }
            }
        }
    }
    printf("You collected %d apples\n", appleCounter);
    
    

    free(field);
    free(snake);
    return 0;
}
