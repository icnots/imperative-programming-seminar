#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED



struct Node{
    struct Node *left;
    struct Node *right;
    int value;
};

struct NodeArray{
    struct Node **elems;
    int size;
    int counter;
};



void print_menu(void);

struct Node *create_pkg(int value);
void insert_pkg(struct Node **tree, int value);

void print_a_node(struct Node *node, int level);
void print_tree(struct Node *tree);

struct NodeArray get_init_node_array(int size);
int len_tree(struct Node *tree);
void push_to_node_array(struct NodeArray *na, struct Node *tree);
void add_array_to_node_array(struct NodeArray *na, struct Node *tree);

struct NodeArray get_manifest(struct Node *tree);
void print_node_array(struct NodeArray na);

int children_counter(struct Node *node);
void swap_ints(int *a, int *b);

// This is called with the subtree in a way that the entry point can be modified
void delete_pkg(struct Node **tree, int value);

void free_tree(struct Node *tree);
void free_node_array(struct NodeArray na);







struct Node *create_pkg(int value);
void insert_pkg(struct Node **tree, int value);


void print_a_node(struct Node *node, int level);
void print_tree(struct Node *tree);

int len_tree(struct Node *tree);
struct NodeArray get_manifest(struct Node *tree);

void swap_ints(int *a, int *b);
void delete_pkg(struct Node **tree, int value);

void free_tree(struct Node *tree);
void free_node_array(struct NodeArray na);

#endif
