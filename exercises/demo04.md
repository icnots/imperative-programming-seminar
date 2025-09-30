# 4. Gyakorlat, példaprogramok

## Előjel nélküli egészek

Amennyiben tudjuk egy változóról, hogy olyan egészek lesznek benne, amely csak nemnegatív lehet, használhatunk `unsigned`, tehát előjel nélküli egész típust, amely kulcsszót odahelyezve a típus elé megváltoztatható a típus.
Pl.
* `unsigned int`
* `unsigned long`

A `long` típus a `long int`˙típus rövidítése.

## A `?:` operátor

Amennyiben egy értékadásnál egy egyszerű feltétel szerint akarunk kétféle értéket kiírni, használhatjuk a `?:` operátort, amely szintaxisa így néz ki:
* `feltétel ? igaz : hamis`. Amennyiben a `feltétel` igaz volt, akkor az `igaz` rész fog lefutni, különben a `hamis`.
Pl.:
* `int length = n > 0 ? n : 0;` Amennyiben az `n` változó értéke legalább 1, akkor `n` lesz a változó értéke, más esetben 0.

## Saját alprogramok írása.

A `main` függvényünk mintájára létrehozhatunk más alprogramokat is, amelyeket a nevükkel és a paramétereikkel meghívhatóak a `main` függvényünkből is.
Pl.
```
    int func(){
        printf("Hello World!\n");
        
        return 0;
    }
    int main(){
        func();
        func();
        
        return 0;
    }
```

## Random számok

Random számok (pszeudo-random) generálásához a `rand()` függvényt fogjuk használni, amely egy pszeudo random sorozatban számol egy előző számból. Ezt a random generátort seed-elni kell, amellyel megadjuk a kezdő számot, amitől kezdve számoljon a pszeudo random sorozatban. Enélkül a számok ugyanazok lesznek determinisztikusan.
A seed-elés az `srand()` függvénnyel tehető meg, amelyet legtöbbször a `time(NULL)` függvénnyel paraméterezve teszünk meg, ezzel  1970. január 1. óta eltelt időt rakjuk be másodpercekben.
A random szám generálásával kapcsolatos függvények (`rand()` és `srand()`) az `stdlib.h` include-olásával érhető el.
A `time` függvény elérése a `time.h` include-olásával érhető el.

A random szám egy random számot ad 0 és 2147483647 között. Ebből maradékos osztással kaphatunk kisebb számokat.
A következő függvény két szám közötti részbe transzformálja a random számot, amit kapunk:

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Generate random number between parameters from and to (borders included) */
int getRandomNumber(int from, int to){
    int range = to - from + 1;
    
    int value = rand() % range; /* 0, 1, 2, ..., range-1 */
    
    return value + from; /* from, from+1, from+2, ..., to */
}

int main(){
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++){
        int random = getRandomNumber(12, 20);
        printf("next random number: %d\n", random);
    }

    return 0;
}
```
