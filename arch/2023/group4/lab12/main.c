#include <stdio.h>
#include <stdlib.h>


struct Box{
    int weight;
    struct Box *next;
};

typedef struct Box Box;

struct Box *top;

void initialize(void);
int isEmpty(void);
int peek(void);
void push(int weight);
int pop(void);
void copyTop(void);
void copyTopShallow(void);
void copyTopDeep(void);

int main(){
    initialize();
    
    if (isEmpty()){
        printf("Stack is empty\n");
    }
    
    printf("Top->weight: %d\n", peek());

    push(3);
    push(5);
    
    printf("Top->weight: %d\n", peek());
    
    push(4);
    copyTopDeep();
    printf("Top->weight: %d\n", peek());
    
    pop();
    
    
    printf("Top->weight: %d\n", peek());
    
    while (!isEmpty()){
        pop();
    }

    return 0;
}


void initialize(void){
    top = NULL;
}

int isEmpty(void){
    return NULL == top;
}

int peek(void){
    if (isEmpty()){
        return -1;
    }else{
        return top->weight;
    }
}

void push(int weight){
    Box *box = (Box *)malloc(sizeof(Box));
    if (box){
        box->weight = weight;
        box->next = top;
        top = box;
    }else{
        fprintf(stderr, "No memory\n");
        exit(7);
    }    
}

int pop(void){
    if (isEmpty()){
        return -1;
    }else{
        struct Box *box = top;
        top = box->next;
        int weight = box->weight;
        free(box);
        return weight;
    }
}

void copyTop(void){
    if (! isEmpty()){
        push(peek());
    }
}
void copyTopShallow(void){
    if (! isEmpty()){
        Box *box;
        box = top;
        top = box;
    }
}
void copyTopDeep(void){
    if (! isEmpty()){
        Box *box = (Box *)malloc(sizeof(Box));
        if (box){
            box->weight = top->weight;
            box->next = top->next;
            top = box;
        }else{
            fprintf(stderr, "No memory\n");
            exit(7);
        }   
    }
}

