#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Box{
    int weight;
    struct Box *next;
};
typedef struct Box Box;

Box *top;


void initialize(void){
    free_stack();
    top = NULL;
}

int is_empty(void){
    return NULL == top;
}

int peek(void){
    if (is_empty()){
        return -1;
    }else{
        return top->weight;
        /*
        return(*top).weight;
        */
    }
    
}

void push(int w){
    if (w <= 0){
        /* invalid weight */
        return;
    }
    Box *item = (Box *)malloc(sizeof(Box));
    mem_check(item);
    item->weight = w;
    item->next = top;
    top = item;
}

int pop(void){
    if (is_empty()){
        return -1;
    }
    Box *current = top;
    int weight = current->weight;
    top = top->next;
    free(current);
    return weight;
}


void stupid_copy(void){
    Box *item = (Box *)malloc(sizeof(Box));
    mem_check(item);
    *item = *top;
}

void copy_top(void){
    push(peek());
}

void free_stack(void){
    while(!is_empty()){
        pop();
    }
}
void print_stack(void){
    Box *current = top;
    printf("stack: ");
    while(NULL != current){
        printf("%d, ", current->weight);
        current = current->next;
    }
    printf("\n");
}

void mem_check(void *p){
    if (!p){
        fprintf(stderr, "No mem\n");
        exit(1);
    }
}
