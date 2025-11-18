# 10. gyakorlat

## Dinamikus memóriakezelés

***Emlékeztető:***
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- A feladatokat headerekre és forrásfájlokra tagolva oldjuk meg!
- Törekedj a dinamikus memóriakezelésre!
- Ha elakadnál: [C reference](https://en.cppreference.com/w/c)
- [Dinamikus memóriakezelés](./demo10.md)

## Demó

Tekintsük a következő programot:
```
#include <stdio.h>

int main(){
    int t[] = {1, 2, 3};
    int *p = t;
    int j = 5;
    
    p++;
    p += 1;
    *p = 4;
    p = &j;
    *p = 6;
    
    int **pp = &p;
    
    *pp = t+1; // ugyanaz mint ez a sor: pp[0] = &t[1];
    
    *(pp[0]+1) = 7;
    pp[0][-1] = 8;
    **pp = 9;
    
    printf("t: [%d, %d, %d]\nj : %d\n", t[0], t[1], t[2], j);
    
    return 0;
}
```
Rajzoljunk hozzá memory map-et és utána a következő programhoz is!
```
#include <stdio.h>
#include <stdlib.h>

int main(){
    // int t[] = {1, 2, 3}; helyett:
    int *t = (int *)malloc(3 * sizeof(int));
    t[0] = 1;
    t[1] = 2;
    t[2] = 3;

    int *p = t;
    // int j = 5; helyett:
    int *j = (int *)malloc(sizeof(int)); // dinamikus j változó helye
    *j = 5;

    p++;
    p += 1;
    *p = 4;

    p = j;
    *p = 6;

    // int **pp = &p; helyett:
    int **pp = (int **)malloc(sizeof(int *));
    
    *pp = t + 1;
    *(pp[0] + 1) = 7;
    pp[0][-1] = 8;
    **pp = 9;

    printf("t: [%d, %d, %d]\nj : %d\n", t[0], t[1], t[2], *j);

    free(t);
    free(j);
    free(pp);
    
    return 0;
}
```
Vessük össze a kettőt!

### Kötelező feladatok

1. Írj egy programot, ami bekér a felhasználótól egy legfeljebb **20** karakter hosszú szöveget, és készít belőle egy másolatot. Ügyelj arra, hogy a másolat csak akkora memóriaterületet használjon, ami feltétlenül szükséges. (Használj segédfüggvényt a karakterek számának meghatározásához!) Szervezd ki függvénybe magát a másolatkészítést!
2. Írj programot, ami **5** sort olvas be a felhasználótól, és kiírja fordított sorrendben őket. A tároláshoz pontosan annyi memóriát használj, amennyit a szavak igényelnek! (Használd az 1. feladatban készített függvényt!)
3. Írj programot, amely tetszőleges számú számot tud beolvasni a felhasználótól, egészen addig, amíg nem érkezik **EOF** a bemeneten, majd kiírja őket fordított sorrendben. Ha végzett a kiírással, legalább egyszer újból várjon számokat. Ügyelj arra, hogy csak a szükséges mértékben használj memóriát és a működés közben ne keletkezzen memóriaszemét! (a `scanf` visszatérési értéke az a szám, ahány paramétert sikeresen olvasott be. Tehát ha nem sikeres a beolvasás, akkor 0 lesz a visszatérési érték. Az `fgets` használata esetén már ismert, hogy hogyan tudunk **EOF**-ig olvasni.)
4. Készíts egy _`reverse()`_ nevű függvényt, aminek egy string paramétere van. A függvény fordítsa meg a string karaktereit helyben. Azaz függvény az eredményt ugyanazon a memóriaterületen adja vissza, amit paraméterként kapott. Például egy palindrom string karakterei nem változnak meg a függvényben.
5. Módosítsd az előző _`reverse()`_ nevű függvényt úgy, hogy ne helyben cserélje a karaktereket, hanem egy másik stringet hozzon létre, és azzal térjen vissza. Dinamikusan foglald a szükséges memóriát!
6. A *3. feladat mintájára* írj egy programot, amely tetszőleges számú és hosszúságú szót tud beolvasni a felhasználótól, amíg **EOF** indikátor nem érkezik a bemeneten. Továbbra is ügyelj a takarékos és helyes memóriakezelésre!


### Opcionális feladatok

1. Készíts egy függvényt, ami egészek tömbjét várja paraméterül. A függvény térjen vissza egy másik tömbbel, amiben a paraméter tömb elemei szortírozva találhatók: elöl a párosak, hátul a páratlanok. Dinamikusan kezeld a memóriát!
2. Módosítsd a *2. Kötelező feladat* programját, úgy hogy parancssori argumentumként várjon egy számot, és annyi szót olvas be a felhasználótól, amennyit megadott. Ha mindet megadta, írja ki fordított sorrendben a szavakat.
3. Módosítsd az előző feladat megoldását úgy, hogy ha a felhasználó az **end** szót írja be, akkor a beolvasás véget ér, mielőtt elérné a parancssori argumentumként megadott limitet. Használj tömböt. Majd írd ki a tömb tartalmát fordított sorrendben.


### Gyakorló feladatok

1. Adott egy fájl, aminek minden sorában számok vannak szóközökkel elválasztva. Írj egy programot, mely soronként olvas ebből a fájlból, és minden sort növekvő számsorrendben kiír egy output.txt nevű fájlba. Dinamikusan kezeld a memóriát!
2. *(Haladó)* Írj programot, amely számontartja egy cég alkalmazottait a felvételük sorrendjében. Vegyél fel egy struktúrát, amely eltárolja az alkalmazott nevét és fizetését. A program futás közben folyamatosan kérjen be adatokat új alkalmazottakról, és minden "felvétel" után írja ki az összes alkalmazott adatait! A program fejezze be a futást, ha a felhasználó az **exit** szót írja be. Dinamikusan kezeld a memóriát! Ügyelj rá, hogy optimális legyen a dinamikus memóriafoglalás!
