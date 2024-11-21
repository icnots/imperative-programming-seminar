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
    char c,
    int r,
    int length,
    char direction
);
int isValidField(int table[HEIGHT][WIDTH], int rowIndex, int columnIndex);
int validate(int table[HEIGHT][WIDTH], int numberOfShips[4]);

int main(){
    int table[HEIGHT][WIDTH];
    int numberOfShips[4];
    int r;

    init(table, numberOfShips);
    printTable(table, numberOfShips);
    r = submit(table, numberOfShips, 'A', 1, 5, '|');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'A', 1, 5, '|');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'C', 3,  5, '|');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'C', 3, -19, '_');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'F', 9, 3, '_');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'G', 2, 3, '|');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'A', 10, 2, '|');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'A', 10, 2, '_');
    printf("submit: %d\n", r);
    r = submit(table, numberOfShips, 'G', 6, 4, '_');
    printf("submit: %d\n", r);
    printTable(table, numberOfShips);
    printf("Valid table: %d\n", validate(table, numberOfShips));
    
    
    
    init(table, numberOfShips);
    printTable(table, numberOfShips);
    r = submit(table, numberOfShips, 'A', 1, 5, '|');
    r = submit(table, numberOfShips, 'F', 9, 3, '_');
    r = submit(table, numberOfShips, 'G', 2, 3, '|');
    r = submit(table, numberOfShips, 'A', 10, 2, '_');
    r = submit(table, numberOfShips, 'G', 6, 4, '_');
    printTable(table, numberOfShips);
    printf("Valid table: %d\n", validate(table, numberOfShips));
    
    return 0;
}

/* table field's meaning:
   10 - empty
   20 - ship
*/
void init(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4]
){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            table[i][j] = 10;
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
            printf("%c ",
                10 == table[i][j]?'.':'X'
            );
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++){
        printf("%d ", numberOfShips[i]);
    }
    printf("\n");
}

/* Return values:
    0 - succesful
    1 - invalid length
    2 - not placeable on the table
    3 - neighbouring ships
    4 - not valid direction
*/
int submit(
    int table[HEIGHT][WIDTH],
    int numberOfShips[4],
    char c,
    int r,
    int length,
    char direction
){
    if (length < 2 || length > 5){
        fprintf(stderr, "invalid length\n");
        return 1;
    }
    int columnIndex = c - 'A';
    int rowIndex = r - 1;
    if ('_' == direction && columnIndex + length > WIDTH){
        fprintf(stderr, "not placeable on the table\n");
        return 2;
    }
    if ('|' == direction && rowIndex + length > HEIGHT){
        fprintf(stderr, "not placeable on the table\n");
        return 2;
    }
    if ('_' == direction){
        for (int i = 0; i < length; i++){
            if (0 == isValidField(table, rowIndex, columnIndex+i)){
                fprintf(stderr, "neighbouring ships\n");
                return 3;
            }
        }
        for (int i = 0; i < length; i++){
            table[rowIndex][columnIndex+i] = 20;
        }
        numberOfShips[length-2]++;
        return 0;
    }
    if ('|' == direction){
        for (int i = 0; i < length; i++){
            if (0 == isValidField(table, rowIndex+i, columnIndex)){
                fprintf(stderr, "neighbouring ships\n");
                return 3;
            }
        }
        for (int i = 0; i < length; i++){
            table[rowIndex+i][columnIndex] = 20;
        }
        numberOfShips[length-2]++;
        return 0;
    }
    fprintf(stderr, "not valid direction\n");
    return 4;
}


int isValidField(int table[HEIGHT][WIDTH], int rowIndex, int columnIndex){
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (
                0 <= rowIndex+i && rowIndex+i < HEIGHT &&
                0 <= columnIndex+j && columnIndex+j < WIDTH
            ){
                if( table[rowIndex+i][columnIndex+j] != 10 ){
                    return 0;
                }
            }
        }
    }
    return 1;
}


int validate(int table[HEIGHT][WIDTH], int numberOfShips[4]){
    int maxNumberOfShips[4] = {1, 2, 1, 1};
    int counter = 0;
    int allShipSize = 0;
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (table[i][j] == 20){
                counter++;
            }
        }
    }
    
    for (int i = 0; i < 4; i++){
        if (maxNumberOfShips[i] != numberOfShips[i]){
            return 0;
        }
        allShipSize += maxNumberOfShips[i] * (i+2);
    }
    if (counter != allShipSize){
        return 0;
    }
    return 1;
}










