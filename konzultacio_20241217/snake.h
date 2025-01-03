#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

struct Coordinate{
    int h, w;
};
typedef struct Coordinate Coordinate;

struct Field{
    int height, width;
    char *fields;
};
typedef struct Field Field;

void pointerCheck(void * p);

void init_field(Field field, int numberOfApples);
void init_snake(Coordinate **snake, int *length);
void print_field(Field field);
void print_game(Field field, Coordinate *snake, int length);
int update_snake(Field field, Coordinate **snake, int *length, char direction);


#endif
