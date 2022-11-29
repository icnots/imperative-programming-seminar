#include <stdio.h>

struct ExampleStruct{
    double d;  // 8
    int i;     // 4
    char t[6]; // 6
    char c;    // 1
};

typedef struct Miacsuda{
    int k, h;
} MiaCsuda;

typedef struct ExampleStruct ExampleStruct;

typedef union ExampleUnion{
    int i;
    double d;
    float f;
    char c;
}ExampleUnion;


enum ExampleEnum{
    EMPTY,
    SHIP = 5,
    NEIGHBOUR
};


int main(){
    ExampleStruct es = {9.7, 800, "Zoli", 'E'};
    ExampleStruct *p = &es;
    
    ExampleUnion eu = {.f = 2.4};
    
    printf("es.i: %d\n", es.i);
    
    es.i = 1999;
    
    printf("es.i: %d\n", es.i);
    
    (*p).i = 2001;
    
    printf("es.i: %d\n", es.i);
    
    p->i = 2003;
    
    printf("es.i: %d\n", es.i);
    
    
    printf("size of ExampleStruct: %ld\n", sizeof(ExampleStruct));

    enum ExampleEnum ee = SHIP;
    
    printf("ee: %d\n", ee);

    if (SHIP == ee){
        printf("ee is SHIP\n");
    }

    return 0;
}

