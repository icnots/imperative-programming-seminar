#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 20

#define SNAKE_LENGTH 9


void init_field(char field[HEIGHT][WIDTH], int numberOfApples);
void init_snake(int snake[SNAKE_LENGTH][2]);
void print_game(char field[HEIGHT][WIDTH], int snake[SNAKE_LENGTH][2]);
int update_snake(char field[HEIGHT][WIDTH], int snake[SNAKE_LENGTH][2], char dir);
int checkNewHead(int row, int col, int snake[SNAKE_LENGTH][2]);

int main(){
    srand(time(NULL));
    const int initialApples = 10;
    char field[HEIGHT][WIDTH];
    int snake[SNAKE_LENGTH][2];
    int appleNumber = initialApples;
    
    init_field(field, appleNumber);
    init_snake(snake);
    print_game(field, snake);
    char ch;
    
    while (-1 != (ch = getchar())){
        if (
            'a' == ch ||
            's' == ch ||
            'w' == ch ||
            'd' == ch
        ){
            int step = update_snake(field, snake, ch);
            if (step < 0){
                printf("You lost\n");
                printf("You collected %d apples.\n", initialApples-appleNumber);
                return 0;
            }else if (0 == step){
                print_game(field, snake);
            }else if (1 == step){
                appleNumber--;
                print_game(field, snake);
                if (0 == appleNumber){
                    printf("You won!\n");
                    return 0;               
                }
            }
        }
    }
    
    return 0;
}

void init_field(char field[HEIGHT][WIDTH], int numberOfApples){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            field[i][j] = ' ';
        }
    }
    
    int counter = 0;
    while (counter < numberOfApples){
        int row, col;
        row = rand() % HEIGHT;
        col = rand() % WIDTH;
        if (field[row][col] == ' '){
            field[row][col] = 'a';
            counter++;
        }
    }
}


void init_snake(int snake[SNAKE_LENGTH][2]){
    for (int i = 0; i < SNAKE_LENGTH; i++){
        snake[i][0] = 3;
        snake[i][1] = i+3;
    }
}

void print_game(char field[HEIGHT][WIDTH], int snake[SNAKE_LENGTH][2]){
    char workingField[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            workingField[i][j] = field[i][j];
        }
    }
    int row, col;
    row = snake[0][0];
    col = snake[0][1];
    workingField[row][col] = '8';
    for (int i = 1; i < SNAKE_LENGTH; i++){
        row = snake[i][0];
        col = snake[i][1];
        workingField[row][col] = '0';
    }
    
    for (int i = 0; i < WIDTH+1; i++){ 
        printf("#");
    }
    printf("#\n#");
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            printf("%c", workingField[i][j]);
        }
        printf("#\n#");
    }
    for (int i = 0; i < WIDTH+1; i++){ 
        printf("#");
    }
    printf("\n");
    
    fflush(stdout);
}

/* return value 3 in case of invalid dir */
int update_snake(char field[HEIGHT][WIDTH], int snake[SNAKE_LENGTH][2], char dir){
    int row, col;
    row = snake[0][0];
    col = snake[0][1];
    
    switch (dir){
        case 'a' :  col -= 1;
                    break;
        case 'd' :  col += 1;
                    break;
        case 'w' :  row -= 1;
                    break;
        case 's' :  row += 1;
                    break;
        default: return -3;
    }
    
    int val = checkNewHead(row, col, snake);
    if (0 > val){
        return val;
    }
    
    for (int i = SNAKE_LENGTH-1; i > 0; i--){
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
    }
    snake[0][0] = row;
    snake[0][1] = col;
    
    if ('a' == field[row][col]){
        field[row][col] = ' ';
        return 1;
    }
    return 0;
}

/* return value based on new head position:
     0 - valid new head
    -1 - out of border
    -2 - on snake
*/
int checkNewHead(int row, int col, int snake[SNAKE_LENGTH][2]){
    if (
        row < 0 || row >= HEIGHT ||
        col < 0 || col >= WIDTH
    ){
        return -1;
    }
    for (int i = 0; i < SNAKE_LENGTH; i++){
        if (row == snake[i][0] && col == snake[i][1]){
            return -2;
        }
    }
    return 0;
}
