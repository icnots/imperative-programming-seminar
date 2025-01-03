#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

// test with default values
// avoiding repeated inputs
void test(void){
    int values[] = {5, 3, 4, 2, 7, 9, 8, 10, 6, 1};
    
    for (unsigned int q = 0; q < sizeof(values) / sizeof(values[0]); q++){
        
        struct Node *tree = NULL;
        for (unsigned int i = 0; i < sizeof(values) / sizeof(values[0]); i++){
            insert_pkg(&tree, values[i]);
        }
        printf("Original tree:\n");
        print_tree(tree);
        
        delete_pkg(&tree, q+1);
        printf("Deleted tree with deleted value %d:\n", q+1);
        print_tree(tree);
        
        free_tree(tree);
        
        printf("\n\n");
    }
    
    
    struct Node *tree = NULL;
    for (unsigned int i = 0; i < sizeof(values) / sizeof(values[0]); i++){
        insert_pkg(&tree, values[i]);
    }
    
    print_tree(tree);
    
    struct NodeArray ordered_nodes = get_manifest(tree);
    for (int i = 0; i < ordered_nodes.counter; i++){
        printf("%d, ", ordered_nodes.elems[i]->value);
    }
    printf("\n");
    free_node_array(ordered_nodes);
    
    free_tree(tree);
}


int main(void){
    struct Node *tree = NULL;
    print_menu();
    int choice;
    scanf("%d", &choice);
    while (5 != choice){
        switch (choice){
            case 0:
                free_tree(tree);
                test();
                return 0;
                
            case 1: {
                    int value;
                    printf("Elem value number:\n");
                    scanf("%d", &value);
                    insert_pkg(&tree, value);
                }
                break;
            case 2:
                print_tree(tree);
                break;
            case 3: {
                    struct NodeArray na = get_manifest(tree);
                    print_node_array(na);
                    free_node_array(na);
                }
                break;
            case 4: {
                    int value;
                    printf("Elem value number:\n");
                    scanf("%d", &value);
                    delete_pkg(&tree, value);
                }
                break;
            case 5:
                free_tree(tree);
                return 0;
            default:
                printf("Operation not supported, try again\n");
        }
        print_menu();
        scanf("%d", &choice);
    }
    
    return 0;
}
