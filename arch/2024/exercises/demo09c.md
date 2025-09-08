# 9. gyakorlat

## Parancssori argumentumok kezelése

Parancssori argumentumnak hívjuk azokat a paramétereket, amelyeket a parancssorban futtatáskor használunk (érts: a program neve utáni szavakat tekintjük parancssori argumentumnak).
C-ben ezt a belépési függvénynél, tehát a `main` függvénynél kell lekezelni.
A parancssorban megadott karaktersorozatokat szóközönként parse-olja az operációs rendszer és elhelyezi valahol a memóriában standard karaktertömbként (`'\0'`-val lezárva).
Ezeknek az első karakterére mutató pointerekből készít egy tömböt és azt adja át a `main` függvénynek paraméterül, amely a tömb méretével és a pointerekből álló tömb első elemére mutató pointerrel történik. A méretet egy `int argc` változóban szokás megkapni, míg a tömböt egy `char **argv` vagy `char *argv[]` típusban kell megkapnunk (az `argv` kétféle implementációja azonos!).
A 0 indexű argumentum mindig a program futtatási neve. Tehát az `argc` minden alkalommal pozitív egészt lesz.

Egy példaprogram, amely felsorolja a kapott parancssori argumentumokat:
```C
#include <stdio.h>

int main(int argc, char **argv){
    for (int i = 0; i < argc; i++){
        printf("%d: %s\n", i, argv[i]);
    }
    
    return 0;
}
```
> Amennyiben egy paramétert szeretnénk egy szónál hosszabbra megadni, a `"` karakterrel megadhatunk. Tehát a `./a.out "Hello World!"` programfuttatásnál két paraméter lesz, a második paraméter `Hello World` karaktertömb.
