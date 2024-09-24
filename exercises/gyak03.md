# 3. gyakorlat

## Típusok, vezérlési szerkezetek gyakorlása

***Javaslat:*** Az egyes feladatokat szervezzük ki saját alprogramba! 

### Kötelező feladatok

1. Írd ki, hogy a géped hány bájton ábrázol egy `int`, `long int`, `unsigned int`, `unsigned long int`, `char`, `_Bool`, `float`, `double`, `long double` értéket.
(Használd fel nyugodtan a már korábban elkészített kódodat, ha van!)
2. Próbáljuk ki az operator chaining-et (a\<b\<c)!
3. Írasd ki 10-től 0-ig csökkenő sorrendben az egész számokat. Próbáld `int` és `unsigned int` típusú ciklus változóval is megoldani a feladatot.
4. Írj programot, mely a standard inputról bekért számról eldönti, hogy szökőév-e. Szökőév minden néggyel osztható év, kivéve, ami százzal is osztható.  Viszont a négyszázzal oszthatók szintén szökőévek lesznek. 
> - A megoldásban **NE** használj `if`-et!


### Opcionális feladatok

1. Kitalálós játék (guessing): Mindaddig olvass be számot, míg az nem egyezik az általad választottal (először lehet beégetett konstans (`const`) vagy `#define`, aztán nézd meg/használd a `rand()` függvényt). Hibás tipp esetén segíts, hogy túl kicsi vagy túl nagy volt-e a tipp. 
> - Többféle ciklussal is próbálj megoldást adni
> - Próbáld ki hogyan helyettesíthetőek az `if` utasítások a '`?`' operátorral
2. Egészítsd ki a guessing programot a hibás próbálkozások számlálásával, majd ennek értéke alapján adj szöveges értékelést!
> - Kezdetnek egyszerűen kiírod, hogy hány próbálkozásból sikerült
> - Aztán a próbálkozások függvényében más-más dicséretet adsz a kimenetre ( Hasznos vezérlési szerkezet ehhez: `switch() case`)
3. Egészítsd ki a guessing programot, hogy a játék elején nehézségi szintet lehessen változtatni. Például:
> - **könnyű:** 1-10 között választ a program kitalálandó számot.
> - **közepes:** 1-100 között
> - **nehéz:** 1-10000 között
4. Nézd meg, milyen nem definiált viselkedések fordulhatnak elő C programokban: [Github lista](https://gist.github.com/Earnestly/7c903f481ff9d29a3dd1)


### Gyakorló feladatok

1. Szervezd úgy a guessing program kódját, hogy a `main()` függvényen kívül még három másik függvény szerepeljen (pl.: get_target, guessing, evaluate). Legyen minden függvénynek elődeklarációja is.
2. Rajzold ki a Pascal háromszög első n sorát (n-et kérd be)!
3. Olvass utána, hogy a C milyen bitműveleteket támogat (illetve ezeknek milyen gyakorlati haszna lehet): [Bitműveletek](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)


### Verseny feladat

1. Hányféleképpen tudod a 42-t kiíratni a képernyőre? Csak előjeles (`signed`), egész (`int`) típusokat, literálokat használj. Egyetlen `char` típusú változót használhatsz. Az értékadás kivételével más operátor nem használható.
> - Néhány tipp: oktális, hexa literálok, típuskonverziók, túlcsordulás.
> - Több mint 20 féle megoldás képzelhető el!