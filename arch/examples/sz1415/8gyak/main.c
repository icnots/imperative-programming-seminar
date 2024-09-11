#include <stdio.h>

#define HEIGHT 10
#define WIDTH 10

void init(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4]
);
void printTable(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4]
);
int submit(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4],
    char columnChar,
    int rowNumber,
    int length,
    char direction
);
int isValid(int table[HEIGHT][WIDTH], int rowI, int colI);
int validate(int numberOfShips[4]);


int main(){
    int table[HEIGHT][WIDTH];
    int numberOfShips[4];
    
    printTable(table, numberOfShips);
    init(table, numberOfShips);
    submit(table, numberOfShips, 'A', 1, 3, '_');
    submit(table, numberOfShips, 'A', 1, 6, '_');
    submit(table, numberOfShips, 'J', 1, 2, '_');
    submit(table, numberOfShips, 'A', 10, 2, '|');
    submit(table, numberOfShips, 'A', 1, 3, '_');
    submit(table, numberOfShips, 'J', 9, 2, '\\');
    submit(table, numberOfShips, 'E', 5, 2, '_');
    submit(table, numberOfShips, 'G', 3, 4, '_');
    submit(table, numberOfShips, 'H', 5, 3, '|');
    submit(table, numberOfShips, 'B', 9, 5, '_');
    printTable(table, numberOfShips);
    printf("valid table?: %d\n", validate(numberOfShips));

    init(table, numberOfShips);
    
    submit(table, numberOfShips, 'A', 1, 3, '_');
    submit(table, numberOfShips, 'E', 5, 2, '_');
    submit(table, numberOfShips, 'G', 3, 4, '_');
    submit(table, numberOfShips, 'H', 5, 4, '|');
    submit(table, numberOfShips, 'B', 9, 5, '_');
    
    printTable(table, numberOfShips);
    printf("valid table?: %d\n", validate(numberOfShips));
    
    return 0;
}


void init(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4]
){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            table[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++){
        numberOfShips[i] = 0;
    }
}

void printTable(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4]
){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            printf("%c ", table[i][j]?'X':'.');
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++){
        printf("%d ", numberOfShips[i]);
    }
    printf("\n");
}

/* Return values:
    0 - succesful placement
    1 - Not proper length
    2 - Out of bounds horizontal
    3 - Out of bounds vertical
    4 - Neighbouring ship
    5 - not valid direction
*/
int submit(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4],
    char columnChar,
    int rowNumber,
    int length,
    char direction
){
    if (length < 2 || length > 5){
        fprintf(stderr, "Not proper length\n");
        return 1;
    }
    int rowI = rowNumber - 1;
    int colI = columnChar - 'A';
    if ('_' == direction && colI + length > WIDTH){
        fprintf(stderr, "Out of bounds horizontal\n");
        return 2;
    }
    if ('|' == direction && rowI + length > HEIGHT){
        fprintf(stderr, "Out of bounds vertical\n");
        return 3;
    }
    if ('_' == direction){
        for (int i = 0; i < length; i++){
            if (!isValid(table, rowI, colI+i)){
                fprintf(stderr, "Neighbouring ship!\n");
                return 4;
            }
        }
        for (int i = 0; i < length; i++){
            table[rowI][colI+i] = 7;
        }
        numberOfShips[length-2] += 1;
        return 0;
    }
    if ('|' == direction){
        for (int i = 0; i < length; i++){
            if (!isValid(table, rowI+i, colI)){
                fprintf(stderr, "Neighbouring ship!\n");
                return 4;
            }
        }
        for (int i = 0; i < length; i++){
            table[rowI+i][colI] = 7;
        }
        numberOfShips[length-2] += 1;
        return 0;
    }
    fprintf(stderr, "not valid direction\n");
    return 5;
}

/* return value:
    0 - false => ship not placeable
    1 - true  => ship is placeable
*/
int isValid(int table[HEIGHT][WIDTH], int rowI, int colI){
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (
                0 <= rowI + i && rowI + i < HEIGHT &&
                0 <= colI + j && colI + j < WIDTH
            ){
                if (7 == table[rowI+i][colI+j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* return value:
    0 - invalid
    1 - valid
*/
int validate(int numberOfShips[4]){
    int validNumberOfShips[4] = {1, 2, 1, 1};
    for (int i = 0; i < 4; i++){
        if (validNumberOfShips[i] != numberOfShips[i]){
            return 0;
        }
    }
    return 1;
}



