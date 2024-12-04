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
    return NULL == top; // return !top;
}

int peek(void){
    if (is_empty()){
        return -1;
    }
    return top->weight;
}

void push(int w){
    Box *p = (Box *)malloc(sizeof(Box));
    mem_check(p);
    p->weight = w;
    p->next = top;
    top = p;
}

void pop(void){
    if (!is_empty()){
        Box *last_top = top;
        top = top->next;
        free(last_top);
    }
}

void stupid_copy(void){
    if (is_empty()){
        return;
    }
    Box *p = (Box *)malloc(sizeof(Box));
    mem_check(p);
    *top = *p;
    top = p;
}

void copy_top(void){
    if (is_empty()){
        return;
    }
    push(peek());
}

void free_stack(void){
    while(!is_empty()){
        pop();
    }
}

void print_stack(void){
    Box *curr = top;
    if (is_empty()){
        printf("stack is empty\n");
    }else{
        printf("stack: ");
        while (curr != NULL){
            printf("%d, ", curr->weight);
            curr = curr->next;
        }
        printf("\n");
    }
}

void mem_check(void *p){
    if (NULL == p){
        fprintf(stderr, "No memory\n");
        exit(1);
    }
}
