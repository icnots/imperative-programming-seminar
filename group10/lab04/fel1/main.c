#include <stdio.h>

int merolegesek(int a[4], int b[4]);
int main(){
    int x[4], y[4];
    
    for (int i = 0; i < 4; i++){
        scanf("%d %d", &x[i], &y[i]);
      /*scanf("%d %d", x + i, &y[i]);*/
    }
    
    merolegesek(x, y);
    


    return 0;
}


int merolegesek(int x[4], int y[4]){
    if (
        (x[0] - x[1]) * (x[2] - x[3])
        +
        (y[0] - y[1]) * (y[2] - y[3])
        == 0
    ){
        printf("Merolegesek\n");
    }else{
        printf("Nem merolegesek\n");
    }
    return 0;
}
