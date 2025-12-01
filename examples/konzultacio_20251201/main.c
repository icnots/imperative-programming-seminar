#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a.h"
#include "d.h"
#include "funcs.h"

#include "main.h"




int main(void){

    Point *z, *r;
    
    f(&z, &r);

    free(r);
    free(z);

    a();
    d();
    e();
    c();
    g();
    c();
    
    return 0;
}

