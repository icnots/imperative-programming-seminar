#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


struct Box;
extern struct Box *top;


void initialize(void);
int is_empty(void);
int peek(void);
void push(int w);
void pop(void);
void stupid_copy(void);
void copy_top(void);

void free_stack(void);
void print_stack(void);
void mem_check(void *p);

#endif
