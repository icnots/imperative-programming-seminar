#include <stdlib.h>
#include <stdio.h>

#include "funcs.h"


void print_menu(void){
    printf("Choices:\n");
    printf(" 0 - Test with default data\n");
    printf(" 1 - Add elem\n");
    printf(" 2 - Show tree\n");
    printf(" 3 - Show ordered list\n");
    printf(" 4 - Delete elem by value\n");
    printf(" 5 - Quit\n");
}


struct Node *create_pkg(int value){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == new_node){
        fprintf(stderr, "No memory, malloc failed\n");
        exit(1);
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}


void insert_pkg(struct Node **tree, int value){
    if (NULL == *tree){
        *tree = create_pkg(value);
    }else{
        int node_value = (*tree)->value;
        if (node_value < value){
            insert_pkg(&((*tree)->right), value);
        }else if (node_value > value){
            insert_pkg(&((*tree)->left), value);
        }else{
            fprintf(stderr, "value is matching with a previous value => no change\n");
            return;
        }
    }
}


void print_a_node(struct Node *node, int level){
    if (node != NULL){
        print_a_node(node->left, level+1);
        
        for (int i = 0; i < level; i++){
            printf("   ");
        }
        printf("%d\n", node->value);
        
        print_a_node(node->right, level+1);
    }
}


void print_tree(struct Node *tree){
    print_a_node(tree, 0);
}


struct NodeArray get_init_node_array(int size){
    struct NodeArray na;
    na.size = size;
    na.counter = 0;
    na.elems = (struct Node **)malloc(na.size * sizeof(struct Node *));
    
    if (NULL == na.elems){
        fprintf(stderr, "No memory, malloc failed\n");
        exit(1);
    }
    
    return na;
}


int len_tree(struct Node *tree){
    if (NULL == tree){
        return 0;
    }
    return len_tree(tree->left) + len_tree(tree->right) + 1;
}


void push_to_node_array(struct NodeArray *na, struct Node *tree){
    if (na->counter >= na->size){
        na->size *= 2;
        na->elems = (struct Node **)realloc(na->elems, na->size * sizeof(struct Node *));
        if (NULL == na->elems){
            fprintf(stderr, "Realloc failed, no mem\n");
            exit(1);
        }
    }
    
    na->elems[na->counter] = tree;
    na->counter += 1;
}


void add_array_to_node_array(struct NodeArray *na, struct Node *tree){
    if (NULL == tree){
        return;
    }
    
    add_array_to_node_array(na, tree->left);
    push_to_node_array(na, tree);
    add_array_to_node_array(na, tree->right);
}


struct NodeArray get_manifest(struct Node *tree){
    struct NodeArray na = get_init_node_array(4);
    
    if (NULL == tree){
        // intentionally blank
    }else{
        add_array_to_node_array(&na, tree);
    }
    
    return na;
}


void print_node_array(struct NodeArray na){
    int len = na.counter;
    for (int i = 0; i < len-1; i++){
        printf("%d, ", na.elems[i]->value);
    }
    printf("%d\n", na.elems[len-1]->value);
}


int children_counter(struct Node *node){
    if (NULL == node){
        return 0;
    }else{
        return (NULL != node->left) + (NULL != node->right);
    }
}

void swap_ints(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// This is called with the subtree in a way that the entry point can be modified
void delete_pkg(struct Node **tree, int value){
    if (NULL == *tree){
        fprintf(stderr, "value is not present in the tree\n");
        return;
    }
    
    if (value == (*tree)->value){
        // deleting the top of the tree
        int children_count = children_counter(*tree);
        if (children_count == 0){
            // no children, but the top has to be updated
            free(*tree);
            *tree = NULL;
        }else if (children_count == 1){
            // 1 children.
            if (NULL == (*tree)->left){
                struct Node *new_subnode = (*tree)->right;
                free(*tree);
                *tree = new_subnode;
            }else{
                struct Node *new_subnode = (*tree)->left;
                free(*tree);
                *tree = new_subnode;
            }
        }else if (children_count == 2){
            // in the ordered array of the nodes we find the element is the highest among the lower numbers and swap those numbers
            // this way we can eliminate from the smaller subtree the value
            struct NodeArray ordered_nodes = get_manifest(*tree);
            
            int index_of_value = 0;
            while(ordered_nodes.elems[index_of_value]->value != value){
                index_of_value += 1;
            }
            
            if (index_of_value == 0 || index_of_value == ordered_nodes.counter - 1){
                fprintf(stderr, "There should be 2 children of this node!\n");
            }
            
            swap_ints(&(ordered_nodes.elems[index_of_value]->value), &(ordered_nodes.elems[index_of_value-1]->value));
            
            free_node_array(ordered_nodes);
            
            // calling the left since the swap was done with a lower value
            delete_pkg(&((*tree)->left), value);
        }else{
            fprintf(stderr, "Sum of two logical values is not in set {0, 1, 2}\n");
        }
    }else{
        if (value < (*tree)->value){
            delete_pkg(&((*tree)->left), value);
        }else{
            delete_pkg(&((*tree)->right), value);
        }
    }
}


void free_tree(struct Node *tree){
    if (NULL == tree){
        return;
    }else{
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}


void free_node_array(struct NodeArray na){
    free(na.elems);
}

