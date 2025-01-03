#include <stdio.h>
#include <stdlib.h>

#include "snake.h"



void pointerCheck(void * p){
    if (!p){
        fprintf(stderr, "Null pointer error\n");
        exit(2);
    }
}



void init_field(Field field, int numberOfApples){
    int fieldSize = field.height * field.width;
    
    // initialization of filed
    for (int i = 0; i < fieldSize; i++){
        field.fields[i] = ' ';
    }
    
    // apple distribution
    while (numberOfApples > 0){
        int i = rand() % fieldSize;
        if (field.fields[i] == ' '){
            field.fields[i] = 'a';
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

void print_field(Field field){
    for (int i = 0; i < field.width + 2; i++){
        printf("#");
    }
    printf("\n");
    for (int i = 0; i < field.height; i++){
        printf("#");
        for (int j = 0; j < field.width; j++){
            printf("%c", field.fields[i * field.width + j]);
        }        
        printf("#\n");
    }
    for (int i = 0; i < field.width + 2; i++){
        printf("#");
    }
    printf("\n");
}


void print_game(Field field, Coordinate *snake, int length){
    int fieldSize = field.height * field.width;
    Field workingMatrix;
    workingMatrix.height = field.height;
    workingMatrix.width = field.width;
    workingMatrix.fields = (char *)malloc(sizeof(char) * fieldSize);
    pointerCheck(workingMatrix.fields);
    for (int i = 0; i < fieldSize; i++){
        workingMatrix.fields[i] = field.fields[i];
    }
    for (int i = 0; i < length; i++){
        int h, w;
        h = snake[i].h;
        w = snake[i].w;
        if (0 == i){
            workingMatrix.fields[h * workingMatrix.width + w] = '8';
        }else{
            workingMatrix.fields[h * workingMatrix.width + w] = '0';
        }
    }
    
    print_field(workingMatrix);

    free(workingMatrix.fields);
}


int update_snake(
    Field field,
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
    
    if (0 <= h && h < field.height && 0 <= w && w < field.width){
        // onmagaval valo utkozes
        for (int i = 0; i < (*length) - 1; i++){
            if (h == (*snake)[i].h && w == (*snake)[i].w){
                return -2;
            }
        }
        
        int res = 0;
        // alma elkapas
        if (field.fields[h * field.width + w] == 'a'){
            res = 1;
            *length += 1;
            *snake = (Coordinate *)realloc(*snake, sizeof(Coordinate) * (*length));
            pointerCheck(*snake);
            field.fields[h * field.width + w] = ' ';
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

