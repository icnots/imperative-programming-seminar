# 11. gyakorlat

## Összetett adatszerkezetek

Amikor egy adatot több változó tárolna el, akkor megtehetjük, hogy létrehozunk egy nagyobb típust több már létező típus felhasználásával.

### struct

Ha több adatot akarunk szimplán összefűzni, akkor `struct Tipus`-t hozunk létre.
Ezzel mintegy egymás mellé helyezünk akár különböző típusú változókat, amelyeket együtt fogunk kezelni.
Példa: fűzzünk össze egy `char` egy `int` és egy `double` típusú változót!
```C
struct Example1{
    char c;
    int i;
    double d;
};
```
Az így létrejött típusnak a neve `struct Example1`, tehát így tudunk hivatkozni rá a továbbiakban.
Amennyiben `Example1` néven akarunk hivatkozni rá, akkor `typedef` segítségével tehető ez meg.

Egy `struct Example1` típusú változónak a mezőire a `.` segítségével hivatkozhatunk és a tömbök inicializáló listájához hasonlóan inicializálhatjuk:
```C
    struct Example1 ex = {'a', 12, 3.14};
    
    printf("ex: %c, %d, %lf\n", ex.c, ex.i, ex.d);
    //                          char, int,  double típusúak a mezők, amelyeket rendre
    //                          c, i és d nevekkel jelöltünk.
    
    ex.i += 1;
    ex.d = ex.d / 2;
    printf("ex: %c, %d, %lf\n", ex.c, ex.i, ex.d);
```

Ha pointerként hivatkozunk a `struct Example1` típusra, akkor a dereferálást és a `.` operátort egyszerre használhatjuk a `->` operátorral:
```C
    struct Example1 ex = {'a', 12, 3.14};
    struct Example1 *p = &ex;
    
    printf("ex: %c, %d, %lf\n", ex.c, ex.i, ex.d);
    
    p->c = 'b'; // ekvivalens: (*p).c = 'b';
    
    printf("ex: %c, %d, %lf\n", ex.c, ex.i, ex.d);
```

### union

Amennyiben egy adott memóriaterület felhasználását szeretnénk többféleképpen megtenni, akkor union-t használunk. Ekkor a felhasznált memóriaterület többféleképpen tudjuk használni, ezeket tudjuk megkülönböztetni a mezők neveivel.
Példa: Egy memóriaterületet foglaljunk le egy opcionálisan `float` vagy `int` típusnak, majd használjuk mindkét módon!
```C
#include <stdio.h>

union ExampleUnion{
    int i;
    float f;
};

int main(void){
    // inicializáláskor meg kell mondani, hogy milyen típusként szeretném inicializálni, ezt a . operátorral és a mező nevével tehetem meg!
    union ExampleUnion u = {.f = 1.2};
    
    printf("int: %d\n", u.i); // int-ként használva memóriaszemétnek néz ki
    printf("flo: %f\n", u.f); // normális használat
    
    union ExampleUnion *pu = &u;
    pu->i = 1051207926; // értékadás int-ként
    // ekvivalens: (*pu).i = 1051207926;
    printf("int: %d\n", u.i); // normális használat
    printf("flo: %f\n", u.f); // float-ként használva memóriaszemétnek néz ki
    
    return 0;
}
```
Ekkor a felhasznált memória ugyanaz. így láthatjuk, hogy ugyanazt a memóriaterületet hogyan lehet többféle célra használni.
A `->` operátor ugyanúgy használható mint a `struct` esetében.

### enum

Az `enum`-ot magyarul felsorolási típusnak szoktuk hívni. Ez a típus igazából `int` változónak különböző értékeinek elnevezésére szolgál. Felsorolva a neveket létrehozunk egy-egy aliast az adott névnek 0-tól számozva szépen sorban. Amennyiben explicit meg akarunk adni egy értéket az egyik névnek, azt az `=` jellel megtehetjük, ekkor innen folytatódik a számolás. Esetlegesen több névnek is megfelelhet ugyanaz a szám.
Példa: hozzunk létre felsorolási típust úgy, hogy a `FIRST` a 0-nak feleljen meg, a `SECOND` a 2-nek, a `THIRD` a következőnek, a `HUNDREDTH` pedig a 100-nak.
```C
#include <stdio.h>

enum ExampleEnum{
    FIRST,
    SECOND = 2,
    THIRD,
    HUNDREDTH = 100
};

int main(void){
    enum ExampleEnum e;
    e = FIRST;
    printf("value of FIRST: %d\n", e);
    e = SECOND;
    printf("value of SECOND: %d\n", e);
    e = THIRD;
    printf("value of THIRD: %d\n", e);
    e = HUNDREDTH;
    printf("value of HUNDREDTH: %d\n", e);
    
    return 0;
}
```


### `typedef`

A kényelem érdekében a típusokat elláthatjuk egyszavas névvel is, amelyet a `typedef` paranccsal tehetünk meg:
A `struct Example1` osztálynak az elnevezése `Example` névre a következő kóddal tehető meg:
```C
typedef struct Example1 Example;
```
Innentől kezdve hozhatunk létre `Example` típusú változókat is.

## Random számok
Definiáljunk egy függvényt, ami `from` és `to` egészek közt készít random számot (a határokat is beleértve:
```C
int getRandom(int from, int to){
    return rand() % (to - from + 1) + from;
}
```

A seed-elés egyszer történjen meg a program futása során! Így általában a `main` függvénybe rakjuk be:
```C
    srand(time(NULL));
```
Ehhez kell a `stdlib.h` és a `time.h` include-ja is!
