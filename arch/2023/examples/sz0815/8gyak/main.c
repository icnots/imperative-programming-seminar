#include <stdio.h>

#define HEIGHT 10
#define LENGTH 10

void init(int table[HEIGHT][LENGTH], int numberOfShips[4]);
void printTable(int table[HEIGHT][LENGTH], int numberOfShips[4]);
int submit(
    int table[HEIGHT][LENGTH],
    int numberOfShips[4],
    int length,
    char x,
    int y,
    char direction
);
int placeable(int table[HEIGHT][LENGTH], int x, int y);
int validate(int table[HEIGHT][LENGTH], int numberOfShips[4]);

int main(){
    int table[HEIGHT][LENGTH];
    int numberOfShips[4];
    
    printTable(table, numberOfShips);
    init(table, numberOfShips);
    
    printTable(table, numberOfShips);
    
    int r = submit(table, numberOfShips, 4, 'A', 1, '|');
    printf("Succesfull: %d\n", r);
    
    r = submit(table, numberOfShips, 4, 'B', 4, '|');
    printf("Succesfull: %d\n", r);
    
    r = submit(table, numberOfShips, 2, 'H', 4, '_');
    printf("Succesfull: %d\n", r);
    r = submit(table, numberOfShips, 3, 'C', 2, '|');
    printf("Succesfull: %d\n", r);
    r = submit(table, numberOfShips, 3, 'E', 2, '|');
    printf("Succesfull: %d\n", r);
    r = submit(table, numberOfShips, 5, 'D', 9, '_');
    printf("Succesfull: %d\n", r);
    
    printTable(table, numberOfShips);
    printf("Valid table : %d\n", validate(table, numberOfShips));
    
    printf("Example2\n");
    init(table, numberOfShips);
    printTable(table, numberOfShips);
    submit(table, numberOfShips, 5, 'D', 9, '_');
    submit(table, numberOfShips, 6, 'D', 9, '_');
    submit(table, numberOfShips, 2, 'E', 9, '|');
    submit(table, numberOfShips, 2, 'A', 1, '|');
    submit(table, numberOfShips, 2, 'A', 4, '|');
    printTable(table, numberOfShips);
    printf("Valid table : %d\n", validate(table, numberOfShips));
    
    return 0;
}



void init(int table[HEIGHT][LENGTH], int numberOfShips[4]){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < LENGTH; j++){
            table[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++){
        numberOfShips[i] = 0;
    }
}


void printTable(int table[HEIGHT][LENGTH], int numberOfShips[4]){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < LENGTH; j++){
            printf("%c ", table[i][j] ? 'X' : '.');
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++){
        printf("%d ", numberOfShips[i]);
    }
    printf("\n");
}

/* returns 0 if the ship could not be placed */
int submit(
    int table[HEIGHT][LENGTH],
    int numberOfShips[4],
    int length,
    char x,
    int y,
    char direction
){
    if (2 > length || length > 5){
        return 0;
    }
    int coord1 = y - 1;
    int coord2 = x - 'A';
    if ('_' == direction && coord2+length > LENGTH){
        return 0;
    }
    if ('|' == direction && coord1+length > HEIGHT){
        return 0;
    }
    if ('_' == direction){
        for (int i = 0; i < length; i++){
            if ( 0 == placeable(table, coord1, coord2+i) ){
                return 0;
            }
        }
        for (int i = 0; i < length; i++){
            table[coord1][coord2+i] = 1;
        }
        numberOfShips[length-2]++;
    }
    if ('|' == direction){
        for (int i = 0; i < length; i++){
            if ( 0 == placeable(table, coord1+i, coord2) ){
                return 0;
            }
        }
        for (int i = 0; i < length; i++){
            table[coord1+i][coord2] = 1;
        }
        numberOfShips[length-2]++;
    }
    
    return 1;
}


int placeable(int table[HEIGHT][LENGTH], int x, int y){
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <=1; j++){
            if (
                0 <= x+i && x+i < HEIGHT &&
                0 <= y+j && y+j < LENGTH
            ){
                if ( 0 != table[x+i][y+j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}



int validate(int table[HEIGHT][LENGTH], int numberOfShips[4]){
    int counter = 0;
    int shipSizes = 0;
    int maxNumberOfShips[4] = {1, 2, 1, 1};
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < LENGTH; j++){
            if (0 != table[i][j]){
                counter++;
            }
        }
    }
    for (int i = 0; i < 4; i++){
        if (numberOfShips[i] != maxNumberOfShips[i]){
            return 0;
        }
        shipSizes += (i+2) * maxNumberOfShips[i];
    }
    if (counter != shipSizes){
        return 0;
    }
    return 1;
}

















