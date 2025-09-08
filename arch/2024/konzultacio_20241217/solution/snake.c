#include <stdio.h>
#include <stdlib.h>

#include "snake.h"



void pointerCheck(void * p){
    if (!p){
        fprintf(stderr, "Null pointer error\n");
        exit(2);
    }
}



void init_field(char *field, int height, int width, int numberOfApples){
    int fieldSize = height * width;
    
    // initialization of filed
    for (int i = 0; i < fieldSize; i++){
        field[i] = ' ';
    }
    
    // apple distribution
    while (numberOfApples > 0){
        int i = rand() % fieldSize;
        if (field[i] == ' '){
            field[i] = 'a';
            numberOfApples -= 1;
        }
    }
}


void init_snake(Coordinate **snake, int *length){
    *length = 5;
    *snake = (Coordinate *)realloc(*snake, sizeof(Coordinate) * (*length));
    pointerCheck(*snake);
    
    for (int i = 0; i < *length; i++){
        (*snake)[i].h = 0;
        (*snake)[i].w = *length - i - 1;
    }
}

void print_field(char *field, int height, int width){
    for (int i = 0; i < width + 2; i++){
        printf("#");
    }
    printf("\n");
    for (int i = 0; i < height; i++){
        printf("#");
        for (int j = 0; j < width; j++){
            printf("%c", field[i * width + j]);
        }        
        printf("#\n");
    }
    for (int i = 0; i < width + 2; i++){
        printf("#");
    }
    printf("\n");
}


void print_game(char *field, int height, int width, Coordinate *snake, int length){
    int fieldSize = height * width;
    char *workingMatrix = (char *)malloc(sizeof(char) * fieldSize);
    pointerCheck(workingMatrix);
    for (int i = 0; i < fieldSize; i++){
        workingMatrix[i] = field[i];
    }
    for (int i = 0; i < length; i++){
        int h, w;
        h = snake[i].h;
        w = snake[i].w;
        if (0 == i){
            workingMatrix[h * width + w] = '8';
        }else{
            workingMatrix[h * width + w] = '0';
        }
    }
    
    print_field(workingMatrix, height, width);

    free(workingMatrix);
}


int update_snake(
    char *field,
    int height,
    int width,
    Coordinate **snake,
    int *length,
    char direction
){
    int h = (*snake)[0].h;
    int w = (*snake)->w;
    switch (direction){
        case 'a':
            w -= 1;
            break;
        case 'd':
            w += 1;
            break;
        case 'w':
            h -= 1;
            break;
        case 's':
            h += 1;
            break;
        default:
            return -3;
    }
    
    if (0 <= h && h < height && 0 <= w && w < width){
        // onmagaval valo utkozes
        for (int i = 0; i < (*length) - 1; i++){
            if (h == (*snake)[i].h && w == (*snake)[i].w){
                return -2;
            }
        }
        
        int res = 0;
        // alma elkapas
        if (field[h * width + w] == 'a'){
            res = 1;
            *length += 1;
            *snake = (Coordinate *)realloc(*snake, sizeof(Coordinate) * (*length));
            pointerCheck(*snake);
            field[h * width + w] = ' ';
        }
        
        // kigyo update
        for (int i = (*length)-1; i > 0; i--){
            (*snake)[i] = (*snake)[i-1];
        }
        (*snake)[0].h = h;
        (*snake)[0].w = w;
        
        return res;
    }else{
        // palya szelevel valo utkezes
        return -1;
    }
    
}

