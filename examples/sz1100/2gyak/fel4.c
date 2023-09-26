#include <stdio.h>

int main(){
    int var;
    
    var = 3.14;
    printf("3.14: %d\n", var);

    var = '\n';
    printf("'\\n': %d\n", var);

    var = 0 > 1;
    printf("0 < 1: %d\n", var);

    var = "szia";
    printf("\"szia\": %d\n", var);

    return 0;
}
