#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initial number length for input stdin
#define INITSIZE 5
// Number of numbers to read from stdin
#define INPUTNUMBER 10

// Reads a number from stdin and returns it in dynamic array
char *getCharNumber(void);
// Returns zero as char array
char *getZero(void);
// Returns true if the parameter ch is a digit as character
int isDigit(char ch);
// Returns the pointer to the last digit of the parameter char array
char *lastDigit(char *p);
// If the given parameter is nullptr it exits the program with error message
void pointerCheck(void *p);

// Returns a + b as dynamic array
char *plus(char *a, char *b);
// Returns parameter p without 0's in the beginning. It returns 0 if the parameter contains just 0's.
char *trim(char *p);
// Sums up the given character arrays and returns the sum
char *sum(char **t, int l);


int main(int argc, char **argv){
    char *result;
    if (argc == 1){ // if there is no command line argument we read from stdin
        char *t[INPUTNUMBER];
        for (int i = 0; i < INPUTNUMBER; i++){
            t[i] = getCharNumber();
        }
        
        result = sum( t, INPUTNUMBER );
        
        for (int i = 0; i < INPUTNUMBER; i++){
            free(t[i]);
        }        
    }else{ // if command line arguments available, we sum up them
        // first argument skipped, so the argc has to be decreased
        result = sum( argv+1, argc-1 );
    }
    
    printf("Sum: %s\n", result);

    free(result);
    
    return 0;
}

int isDigit(char ch){
    return ( ('0' <= ch) && (ch <= '9') );
}


void pointerCheck(void *p){
    if (!p){
        fprintf(stderr, "Pointer is nullpointer!\n");
        exit(7);
    }
}

char *lastDigit(char *p){
    while ('\0' != *p){
        p++;
    }
    return (p - 1);
}


char *plus(char *a, char *b){
    char *la = lastDigit(a);
    char *lb = lastDigit(b);
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    int length = lengthA > lengthB ? lengthA : lengthB;
    
    length += 2; // beginning and ending (Extend possible '0' to the beginning and '\0' to the end)
    char *first = (char *)malloc(length * sizeof(char));
    pointerCheck(first);
    
    char *last = first + length - 1;
    int result;
    int residual = 0;
    *last = '\0';
    
    for (char *current = last-1; current >= first; current--){
        int valueA = (la >= a) ? (*(la--) - '0') : 0;
        int valueB = (lb >= b) ? (*(lb--) - '0') : 0;

        result = valueA + valueB + residual;
        residual = result / 10;
        *current = (result % 10) + '0';
    }
    
    return first;
}

char *getCharNumber(void){
    char ch;
    int size = INITSIZE;
    int length = 0;
    char *p = (char *)malloc(size * sizeof(char));
    pointerCheck(p);
    
    while ( isDigit(ch = getchar()) ){
        if ( (size-1) <= length ){
            size *= 2;
            p = (char *)realloc(p, size * sizeof(char));
            pointerCheck(p);
        }
        p[length] = ch;
        length++;
    }
    if ( 0 == length ){ // no given number
        p[length++] = '0';
    }
    p[length] = '\0';
    
    return p;
}

char *getZero(void){
    char *p = (char *)malloc(2 * sizeof(char));
    pointerCheck(p);
    
    p[0] = '0';
    p[1] = '\0';
    
    return p;
}

char *trim(char *p){
    int length = strlen(p);
    // last points to the next element after '\0'
    char *last = p + length + 1; // '\0' !!!
    char *first = p;
    
    while (*first == '0'){
        first++;
    }
    
    char *new = (char *)malloc((last-first)*sizeof(char));
    pointerCheck(new);
    
    strcpy(new, first);
    
    free(p);
    
    if (1 == last - first){ // if the result is 0
        free(new);
        new = getZero();
    }
    
    return new;
}

char *sum(char **t, int l){
    char *res = getZero();
    
    for (int i = 0; i < l; i++){
        char *newRes = plus(res, t[i]);
        free(res);
        res = newRes;
    }
    
    res = trim(res);
    
    return res;
}
