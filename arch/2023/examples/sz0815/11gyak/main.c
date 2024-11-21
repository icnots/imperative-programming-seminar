#include "fel2.h"

#include <stdio.h>

int main(){
    char str[] = "alma\n";
    removeNewline(str);
    reverse(str);
    
    char *copy = reversed(str);
    
    printf("%s\n", str);
    printf("%s\n", copy);
    
    free(copy);
    return 0;
}
