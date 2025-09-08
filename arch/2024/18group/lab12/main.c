#include <stdio.h>
#include "stack.h"


int main(void){
    initialize();
    initialize();
    initialize();
    
    printf("The stack is currently %s\n",
        is_empty() ?
        "empty" :
        "non-empty"
    );
    printf("peek: %d\n", peek());
    push(10);
    printf("peek: %d\n", peek());
    push(20);
    printf("peek: %d\n", peek());
    push(3);
    printf("peek: %d\n", peek());
    push(4);
    printf("peek: %d\n", peek());
    push(5);
    print_stack();
    
    initialize();
    print_stack();
    push(15);
    print_stack();
    copy_top();
    print_stack();
    pop();
    print_stack();
    
    
    
    
    free_stack();
    return 0;
}
