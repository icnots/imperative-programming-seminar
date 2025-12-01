#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "funcs.h"


struct Point{
    double x, y;
    char name[30];
    int id;
};



void printPoint(Point p){
    printf("Point: x: %lf, y: %lf, name: %s, id: %d\n", p.x, p.y, p.name, p.id);
}


void f(Point **pz, Point **pr){
    {

        Point p = {0.0, 1.0, "ferike", 0};
        printPoint(p);
        p.name[3] = 'j';

        Point *q = &p;
        (*q).id += 1;
        q->name[0] = 'F';
        
        printPoint(*q);

        q = (Point *)malloc(sizeof(Point));
        if (!q){
            fprintf(stderr, "No memory\n");
            exit(-1);
        }
        mallocCheck(q);
        (*q).id = 2; // q->id = 2;
        q->x = 1.0;
        q->y = 0.0;



        Point t[] = {
            {0.0, 1.0, "Alma", 0},
            {0.0, 2.0, "Barack", 1},
            {0.0, 3.0, "Citrom", 2},
            {0.0, 4.0, "Dinnye", 3},
            {0.0, 5.0, "Eper", 4}
        };

        *pz = q;
        q = t;
        q[3].x = 12.0;
        (q+3)->y = 13.0;

        q = (Point *)malloc(5 * sizeof(Point));
        mallocCheck(q);
        for (int i = 0; i < 5; i++){
            q[i].x = 0.0;
            q[i].y = i+1;
            strcpy(q[i].name, t[i].name);
            q[i].id = i;
        }

        q[3] = q[2];
        *pr = q;



        for (int i = 0; i < 5; i++){
            printPoint(t[i]);
        }
        for (int i = 0; i < 5; i++){
            printPoint(q[i]);
        }


    }


    Point **e = (Point **)malloc(5 * sizeof(Point *));
    mallocCheck(e);
    //(*(e[2])).id = 2;
    //e[2]->id = 2;



    for (int i = 0; i < 5; i++){
        e[i] = (Point *)malloc(1* sizeof(Point));
        mallocCheck(e[i]);
        e[i]->x = 0.0;
        e[i]->y = i+1;
        strcpy(e[i]->name, (*pr)[i].name);
        e[i]->id = i;
    }

    for (int i = 0; i < 5; i++){
        printPoint(e[i][0]);
        free(e[i]);
    }
    free(e);



}


void mallocCheck(void *p){
    if (NULL == p){
        fprintf(stderr, "No memory\n");
        exit(-1);
    }
}

