#include <stdio.h>

#include "stack.h"


int main(void){
    initialize();
    
    print_stack();
    for (int i = 10; i < 100; i++){
        push(i);
    }
    print_stack();
    printf("peek: %d\n", peek());
    pop();
    pop();
    pop();
    pop();
    printf("peek: %d\n", peek());
    print_stack();
    initialize();
    push(2);
    push(3);
    print_stack();
    
    initialize();
    copy_top();
    print_stack();
    push(3);
    copy_top();
    print_stack();

    
    free_stack();
    return 0;
}
