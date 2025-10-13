# 6. Gyakorlat, mutatók

## Mutató - pointer

A magyar nyelv használata miatt az órán a **mutat** igét arra fogjuk használni, hogy azt fejezzük ki vele, hogy melyik memóriaterületre _mutat_.
Magát a _mutatót_, amely azt a típust fejezi ki, ami _mutat_ valamilyen memóriaterületre, **pointer**nek fogjuk hívni.


## Pointer aritmetika

Amikor változókat deklarálunk, a típus után jelezhetjük minden változó előtt, hogy az adott változó pointer-e. Ez a tulajdonság a változóhoz tartozik és nem a típusához. Példák (ahol pointert írok, ott egy `int` típusra mutató pointerre gondolok):
```
    int* i1; /* az i1 egy pointer */
    int *i2; /* az i2 egy pointer, ez a jobb jelölés */
    int *i3, i4; /* az i3 egy pointer, az i4 egy int */
    int i5, *i6; /* az i5 egy int, az i6 egy pointer */
    int *i7, *i8; /* az i7 egy int, az i8 egy pointer */
```
Fontos, hogy a pointerünk milyen típusra mutat, mert egy pointer dereferálásával egy konkrét típust fogunk megkapni.
Operátorok a pointereknél:
- `*` : A dereferáláshoz az adott pointer neve előtt használjuk a `*` operátort.
- `&` : Egy változónak a memóriacímének lekérdezéséhez a változó neve előtt használjuk a `&` operátort.

### Pointer dereferálás
A pointer neve előtt használva a `*` operátort az adott pointert dereferáljuk. Ezzel a pointer tartalmát fogjuk tudni használni.

### Pointer növelés
A pointerhez egész számot adva eltolhatjuk a pointert. Ez azt jelenti, hogy növeljük annyival a pointert, amilyen típusra mutat (pointerre mutató pointer esetében pointermérettel toljuk el), pl. `int` esetén `sizeof(int)` byte-tal lesz eltolva, ha eggyel növeljük.
A tömbök adott elemeire való hivatkozás is ugyanígy működik, az alábbi két sornál az értékadás pontosan ugyanazt jelenti:
```
    int arr[10];
    arr[1] = 10; /* beállítja a tömb 1 indexű elemét (második elem) 10-re */
    *(arr+1) = 10; /* a tömb első elemére mutató pointert növeli eggyel és azt dereferálja, tehát ez pont a második elemre fog hivatkozni, így azt állítja be 10-re */
```

### Pointerek összehasonlítása
Amennyiben egy tömb két különböző elemére mutató pointereink vannak, akkor összehasonlíthatjuk őket a `<` vagy `>` operátorral. Ekkor kisebbnek fog számítani a kisebb elemre mutató pointer.


## Többszörös pointerek
Amennyiben egy pointerre akarunk mutatni egy pointerrel, akkor több `*` használatával tudjuk ezt megtenni.
```
    int i;
    int *p;
    int **pp;
    
    p = &i;
    pp = &p;
    /* "*p típusa: int" */
    /* "*pp típusa: int *" */
```

## Univerzális pointer
Az általános, byte-ra mutató pointer típusa lehet `void *`. Ezzel bármilyen típusra mutathatunk, és bármilyen pointert konvertálhatunk ilyen típusra. Ezzel lehet bizonyos esetekben megoldani, hogy nem ismerjük azt a típust, amelyre mutat a pointer.
