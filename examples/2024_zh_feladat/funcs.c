#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

#include "helper.h"

#define ROWS 10
#define COLS 10

#define BUFFERSIZE 128



void menu(void){
    char buffer[BUFFERSIZE];
    int command = 0;
    Map map = {NULL, 0, 0};

    while (command != 8){
        print_menu();
        
        fgets(buffer, BUFFERSIZE, stdin);
        if (1 != sscanf(buffer, "%d", &command)){
            command = -1;
        }

        if (0 == command){
            /* print_menu(); // Not needed since the help is always printed. */
        }else if (1 == command){
            show_map(map, NULL, NULL);
        }else if (2 == command){
            print_bus_stop(map);
        }else if (3 == command){
            create_bus_stop(&map);
        }else if (4 == command){
            delete_bus_stop(&map);
        }else if (5 == command){
            save_list(map);
        }else if (6 == command){
            load_list(&map);
        }else if (7 == command){
            fastest_road(map);
        }else if (8 == command){
            free_map(map);
            printf("Exiting\n");
        }else{
            printf("Please provide valid command number!\n");
        }

    }

}

void print_menu(void){
    printf("0) Help\n");
    printf("1) Térkép – az aktuális város buszmegállóinak megjelenítése térképes módban a sztenderd kimenten\n");
    printf("2) Lista – az aktuális város buszmegállóinak felsorolása szöveges módban\n");
    printf("3) Új megálló – a felhasználó által új megálló létrehozása és hozzáadása az eddigiekhez\n");
    printf("4) Megálló törlés – a felhasználó által megadott sorszámú buszmegálló törlése\n");
    printf("5) Mentés – az aktuális város buszmegállóinak fájlba történő másolása\n");
    printf("6) Betöltés – a korábban fájlba mentett buszmegállók betöltése\n");
    printf("7) Útvonal – a felhasználó által két kiválasztott állomás között útvonal rajzolása\n");
    printf("8) Kilépés – a program befejezése\n");
}


void show_map(Map map, Stop *fst, Stop *snd){
    if (NULL == map.stops || 0 == map.counter){
        printf("No stops available.\n");
    }else{
        char blocks[ROWS][COLS];

        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                blocks[i][j] = ' ';
            }
        }

        for (int i = 0; i < map.counter; i++){
            blocks[map.stops[i].row][map.stops[i].col] = 'B';
        }

        
        if (NULL != fst && NULL != snd){
            int row = fst->row, col = fst->col;
            int rowCounter = signum(snd->row - fst->row);
            int colCounter = signum(snd->col - fst->col);
            for (; row != snd->row; row += rowCounter){
                if (blocks[row][col] == ' '){
                    blocks[row][col] = '|';
                }
            }
            if (blocks[row][col] != 'B'){
                blocks[row][col] = 'X';
            }
            for (; col != snd->col; col += colCounter){
                if (blocks[row][col] == ' '){
                    blocks[row][col] = '-';
                }
            }
        }


        printf(" ");
        for (int j = 0; j < COLS; j++){
            printf("%d ", j+1);
        }
        printf("\n");
        for (int i = 0; i < ROWS; i++){
            printf("%c", 'a' + i);
            for (int j = 0; j < COLS; j++){
                printf("%c ", blocks[i][j]);;
            }
            printf("\n");
        }
    }
}

void print_bus_stop(Map map){
    if (NULL == map.stops || 0 == map.counter){
        printf("No stops available.\n");
    }else{
        for (int i = 0; i < map.counter; i++){
            printf("%d. %s (%d, %d)\n", (i+1), map.stops[i].name, map.stops[i].row+1, map.stops[i].col+1);
        }
    }
}

void create_bus_stop(Map *map){
    char bufferName[BUFFERSIZE];
    char bufferCoords[BUFFERSIZE];
    int row = 0, col = 0;

    printf("Name of stop: ");
    char *res = fgets(bufferName, BUFFERSIZE, stdin);
    memCheck(res, "No data given.\n");

    printf("Coordinates: ");
    res = fgets(bufferCoords, BUFFERSIZE, stdin);
    memCheck(res, "No data given.\n");
    int return_sscanf = sscanf(bufferCoords, "%d %d", &row, &col);
    while (
        2 != return_sscanf
        || (1 > row)
        || (row > ROWS)
        || (1 > col)
        || (col > COLS)
    ){

        printf("Wrong format (1-10), Coordinates: ");
        res = fgets(bufferCoords, BUFFERSIZE, stdin);
        memCheck(res, "No data given.\n");
        return_sscanf = sscanf(bufferCoords, "%d %d", &row, &col);
    }

    addStop(map, bufferName, row, col);

}

void addStop(Map *map, char *bufferName, int row, int col){
    if (NULL == map->stops){
        map->size = 5;
        map->stops = (Stop *)malloc(map->size * sizeof(Stop));
        memCheck(map->stops, "No memory.");
        map->counter = 0;
    }else if (map->counter >= map->size){
        map->size *= 2;
        map->stops = (Stop *)realloc(map->stops, map->size * sizeof(Stop));
        memCheck(map->stops, "No memory.");
    }

    map->stops[map->counter].row = row-1;
    map->stops[map->counter].col = col-1;

    strip(bufferName);

    map->stops[map->counter].name = (char *)malloc((strlen(bufferName)+1) * sizeof(char));
    memCheck(map->stops[map->counter].name, "No memory.");

    strcpy(map->stops[map->counter].name, bufferName);
    map->counter++;
}


void delete_bus_stop(Map *map){
    if (0 == map->counter){
        printf("No stop to be deleted.\n");
    }

    char buffer[BUFFERSIZE];
    int index;
    fgets(buffer, BUFFERSIZE, stdin);
    sscanf(buffer, "%d", &index);

    if (0 < index && index <= map->counter){
        index -= 1;
        free(map->stops[index].name);
        for (int i = index; i < (map->counter-1); i++){
            map->stops[i] = map->stops[i+1];
        }
        map->counter -= 1;
    }else{
        printf("Not a valid index.\n");
    }
}


void save_list(Map map){
    char buffer[BUFFERSIZE];
    printf("Filename: ");
    fgets(buffer, BUFFERSIZE, stdin);
    strip(buffer);

    FILE *fp = fopen(buffer, "w");
    if (NULL == fp){
        printf("File can not be opened with name %s\n", buffer);
    }else{
        if (NULL != map.stops){
            for (int i = 0; i < map.counter; i++){
                fprintf(fp, "%s\n", map.stops[i].name);
                fprintf(fp, "%d %d\n", map.stops[i].row+1, map.stops[i].col+1);
            }
        }
        fclose(fp);
    }

}

void load_list(Map *map){
    char buffer[BUFFERSIZE];
    printf("Filename: ");
    fgets(buffer, BUFFERSIZE, stdin);
    strip(buffer);

    FILE *fp = fopen(buffer, "r");
    if (NULL == fp){
        printf("File can not be opened with name %s\n", buffer);
    }else{
        char bufferName[BUFFERSIZE];
        char bufferCoords[BUFFERSIZE];
        int row = 0, col = 0;
        
        while (NULL != fgets(bufferName, BUFFERSIZE, fp)){
            strip(bufferName);
            char *res = fgets(bufferCoords, BUFFERSIZE, fp);
            if (NULL == res){
                fclose(fp);
                return;
            }

            if (2 == sscanf(bufferCoords, "%d %d", &row, &col)){
                if (0 < row && row <= ROWS && 0 < col && col <= COLS){
                    addStop(map, bufferName, row, col);
                }
            }else{
                // skip
            }
        }
        fclose(fp);
    }
}


void fastest_road(Map map){
    int fst, snd;
    char buffer[BUFFERSIZE];
    printf("Index of first: ");
    fgets(buffer, BUFFERSIZE, stdin);
    sscanf(buffer, "%d", &fst);
    printf("Index of second: ");
    fgets(buffer, BUFFERSIZE, stdin);
    sscanf(buffer, "%d", &snd);
    fst -= 1;
    snd -= 1;

    if (fst < map.counter && snd < map.counter && fst != snd){
        show_map(map, map.stops + fst, map.stops + snd);
    }else{
        printf("Invalid indices\n");
    }
}


void free_map(Map map){
    if (NULL != map.stops){
        for (int i = 0; i < map.counter; i++){
            free (map.stops[i].name);
        }
        free (map.stops);
    }
}