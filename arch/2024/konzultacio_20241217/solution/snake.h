#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

struct Coordinate{
    int h, w;
};
typedef struct Coordinate Coordinate;

void pointerCheck(void * p);

void init_field(char *field, int height, int width, int numberOfApples);
void init_snake(Coordinate **snake, int *length);
void print_field(char *field, int height, int width);
void print_game(char *field, int height, int width, Coordinate *snake, int length);
int update_snake(char *field, int height, int width, Coordinate **snake, int *length, char direction);


#endif
