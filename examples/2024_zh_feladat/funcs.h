#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED


struct Stop{
    char *name;
    int row, col;
};
typedef struct Stop Stop;

struct Map{
    Stop *stops;
    int counter;
    int size;
};
typedef struct Map Map;


void menu(void);
void print_menu(void);
void show_map(Map map, Stop *fst, Stop *snd);
void print_bus_stop(Map map);
void create_bus_stop(Map *map);
void addStop(Map *map, char *bufferName, int row, int col);
void delete_bus_stop(Map *map);
void save_list(Map map);
void load_list(Map *map);
void fastest_road(Map map);
void free_map(Map map);


#endif
