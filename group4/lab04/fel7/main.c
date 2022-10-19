#include <stdio.h>

int main(){
    int i;
    int minusOne = -1;
    /* if I add 1 to -1, I get 0, so binary 11..11 corresponds to -1 in the memory. */
    
    scanf("%d", &i);
    i = i ^ minusOne; /* binary xor operator */
    i = ~ i; /* binary negation */
    i = -1 * i - 1; /* numerical meaning */
    printf("%d\n", i);

    return 0;
}


/* examples:
binary in the memory         decimal value
1111....1011            ->         -5
1111....1100            ->         -4
1111....1101            ->         -3
1111....1110            ->         -2
1111....1111            ->         -1
0000....0000            ->          0
0000....0001            ->          1
0000....0010            ->          2
0000....0011            ->          3
0000....0100            ->          4
*/
