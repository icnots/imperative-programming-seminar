#include <stdio.h>
#include <stdlib.h>

struct Example;

typedef struct Example Example;


struct Example{
    int i;  // 4
    int k;  // 4
    char j; // 1
    char m; // 1
    char l[10]; // 10
    Example *next;
};

typedef struct Example Example;


enum MyEnum{
    EMPTY,
    SHIP = 5,
    NEIGHBOUR
};


int main(){
    Example e;
    Example f;
    e.i = 1;
    f.j = 'K';
    
    Example *p;
    p = (Example *)malloc(sizeof(Example));
    
    (*p).i = 17;
    p->i = 19;
    
    enum MyEnum valami;
    valami = EMPTY;
    
    printf("size of Example: %ld\n", sizeof(Example));
    printf("size of MyEnum: %ld\n", sizeof(enum MyEnum));
    printf("EMPTY: %d\n", EMPTY);
    printf("SHIP: %d\n", SHIP);
    printf("NEIGHBOUR: %d\n", NEIGHBOUR);
    return 0;
}
