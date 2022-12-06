#include <stdio.h>
#include <stdlib.h>


struct Box{
    int weight;
    struct Box *next;
};

typedef struct Box Box;

Box *top;

void initialize(void);
int isEmpty(void);
int peek(void);
void push(int weight);
int pop(void);
void copyTop(void);
void copyTopShallow(void);
void copyTopDeep(void);
void printStack(void);


int main(void){
    initialize();
    if (isEmpty()){
        printf("Stack is empty\n");
    }
    printStack();
    push(13);
    push(25);
    push(38);
    printStack();
    copyTop();
    printStack();
    pop();
    pop();
    printStack();
    
    
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
    if (!box){
        fprintf(stderr, "No memory available.\n");
        exit(7);
    }
    box->weight = weight;
    box->next = top;
    top = box;
}

int pop(void){
    if (isEmpty()){
        return -1;
    }else{
        Box *nextTop = top->next;
        int weight = top->weight;
        free(top);
        top = nextTop;
        return weight;
    }
}

void copyTop(void){
    if (!isEmpty()){
        push(peek());
    }
}

void copyTopShallow(void){
    if (!isEmpty()){
        Box *box = top;
        top = box;
    }
}

void copyTopDeep(void){
    if (!isEmpty()){
        Box *box = (Box *)malloc(sizeof(Box));
        if (!box){
            fprintf(stderr, "No memory available.\n");
            exit(7);
        }
        box->weight = top->weight;
        box->next = top->next;
        top = box;
    }
}

void printStack(void){
    Box *current = top;
    while (NULL != current){
        printf("%d, ", current->weight);
        current = current->next;
    }
    printf("\n");
}
