# 6. gyakorlat

## Pointerek

***Emlékeztető:*** 
- Fordítás közben használd a **-W -Wall -Wextra -pedantic** kapcsolókat!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)
- Pointerekről összefoglaló: [Pointerek](./demo06.md)

### Demó feladat
Rajzoljunk memóriatérképet (memory map) a következő kódhoz:
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

### Kötelező feladatok 

1. Változtasd meg egy változó értékét egy mutatón keresztül.
2. Változtasd meg egy mutató értékét egy mutatóra mutató mutatón keresztül. Ezután változtasd meg a mutatott mutató által mutatott értéket is!
3. Tudsz-e önmagára mutató mutatót létrehozni? Mi lenne a típusa? Miért (nem)? Hasonlítsd össze a különböző típusú változókra mutató mutatók méretét. Indokold meg miért logikus az eredmény!
4. Írj egy függvényt, ami egy paraméterül kapott tömbben lévő elemek összegével tér vissza. A tömböt az első elemre mutató mutató és egy hosszt tartalmazó egész változó segítségével adjuk át! Írjuk meg a függvényt, hogy a `[]` operátor használata nélkül is, pointer aritmetika segítségével. Ki lehet találni a tömb méretét a függvényen belül a hosszt tartalmazó változó nélkül?
5. Alakítsuk át az előző függvényt, hogy első elemre mutató mutató, és utolsó elem után mutató mutató segítségével kapjuk meg a tömböt. Mi történik, ha túlindexelünk eggyel? Mi történik, ha többel indexelünk túl?
6. Alakítsuk át az előző feladatot, hogy átlagot számoljon. Hogyan tudjuk kiszámolni a tömb méretét a mutatópárból?
7. Mi történik, ha egy függvény egy lokális változóra mutató mutatót ad vissza, amit dereferálunk?
8. Dereferáljunk egy `null` mutatót. Mi az eredmény?
9. Indokold meg, miért van szükség a `scanf()` esetében a `&` operátorra, mikor egész változóba olvasunk be.
10. Írj egy függvényt, ami két azonos tömbön belülre mutató mutatóról eldönti, hogy melyik mutat kisebb indexű elemre.

### Opcionális feladatok

1. Írj függvényt, ami egy paraméterül kapott tömb maximális elemére mutató mutatóval tér vissza. Mi az előnye és mi a hátránya ennek egy index visszaadásához képest?
2. Az előző feladatban megírt függvényt tudjuk egy tömbnek a felére alkalmazni? Hogyan?
3. Az előző feladatban megírt függvényt tudjuk egyetlen változóra alkalmazni, mintha az egy elemű tömb lenne?
4. Egy függvény visszatérési érték segítségével is tud értéket visszaadni, vagy egy pointer segítségével is (pl. `scanf()` ). Mikor melyiket érdemes használni? Melyek az előnyei/hátrányai a módszereknek?

### Gyakorló feladatok

1. Nézz utána hogyan lehet tömbre mutató mutatót deklarálni. Hogy néz ki egy függvény, ami tömbre mutató mutatóval tér vissza?
2. Nézz utána, hogy hogyan lehet függvényre mutató mutatót deklarálni. Hogy néz ki egy függvényre mutató mutatóval visszatérő függvény deklarációja?
3. Hogyan működik több dimenziós tömbben a pointer aritmetika?
