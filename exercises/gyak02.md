# 2. gyakorlat

## Alaptípusok, vezérlési szerkezetek

***Emlékeztető:*** Fordítás közben használd a **-W, -Wall, -Wextra, -pedantic** kapcsolókat!
***Segítség:*** [Az újdonságok a mai feladatsorból](./demo02.md)

### Kötelező feladatok

1. Deklarálj egy `int` típusú változót, és írd ki az értékét. Figyeld meg, hogy mi egy változó kezdőértéke!
2. Adj új értéket az előző változónak, majd írd ki, hogy a változó értéke páros vagy páratlan.
> - Próbáld ki mi történik, ha használod a változó előtt a `const` kulcsszót
3. Írj programot, amely egy számot kér a felhasználótól ( pl `scanf()`-el beolvasva a billentyűzetről ), de csak páratlant fogad el. Addig várakozik bemenetre, amíg megfelelő értéket nem kap.
4. Próbálj meg értékül adni az `int` típusú változónak egy valós számot, egy karaktert, egy logikai ( `bool` ) értéket, és egy karakter láncot (*stringet*). Ha sikerül az értékadás, akkor írd ki a változó értékét.
> - A `bool` típus csak C99 szabvány óta létezik, az `stdbool.h` könyvtár használatával érhető el. Ennél a feladatnál nyugodtan lehet használni azt, hogy konkrét feltételt írsz be, pl.: `0<1`.
5. Határozd meg két szám átlagát. Figyelj arra, hogy az eredmény valós szám!
6. Írd ki 0-tól 1-ig a valós számokat 0.1-es lépésközzel.
7. Határozd meg, hogy melyik a legnagyobb és legkisebb ábrázolható egész szám `int` típus esetén ( `sizeof()` )! A legnagyobb ábrázolható egész számot tedd egy változóba, majd adj a változóhoz 1-et. Figyeld meg mi lett az eredmény!
> - Egyes Linux rendszereken a `math.h` könyvtár függvényeinek használata problémás lehet, mert a linker nem találja meg a referenciákat. A fordításkor a parancs végén a **-lm** kapcsolóval orvosolható a probléma a linker megfelelően fog működni.



### Opcionális feladatok

1. Írd ki, hogy a szám pozitív, negatív, vagy nulla-e.
2. Készíts egy Fahrenheit-Celsius átalakító programot ( *C = (F-32)/1.8* ). Írd ki a [-20; 200] intervallum Fahrenheit értékeit 10-es léptékkel, és a hozzájuk tartozó Celsius-fokot.
3. Írd ki két sorban a *"Hello"* és *"world"* szavakat, egy `printf()` hívással. A két szót tedd idézőjelek közé a kimenetben.
4. Írj programot, ami bekér egy számot és megfordítja azt. Csak aritmetikai műveleteket használj. *Pl.: 12345 -> 54321*
5. Írd ki egy szám összes osztóját.
6. Határozd meg két szám legnagyobb közös osztóját, lehet brute force, [kivonásos módszer](https://hu.wikipedia.org/wiki/Legnagyobb_k%C3%B6z%C3%B6s_oszt%C3%B3) vagy az [Euklideszi algoritmus](https://hu.wikipedia.org/wiki/Euklideszi_algoritmus)
7. Írj ki egy 10x10-es szorzótáblát. Az egy sorban lévő számokat tabulátorral válaszd el.
8. Rajzolj ki egy üres sakktáblát. A sötét mezőket [] jelölje, a világosakat pedig *két space*. Használd a kettővel való oszthatóságot.
9. Írd ki, hogy a géped hány bájton ábrázol egy `int`, `long int`, `unsigned int`, `unsigned long int`, `char`, `bool`, `float`, `double`, `long double` értéket.
10. A 4. kötelező feladat mintájára vizsgáld meg az összes alaptípus közti átjárhatóságot. Minden alaptípus átkonvertálható mindegyik másikra? Ha igen, akkor mi a konverzió szabálya?
11. Vizsgáld meg egy számról, hogy palindrom-e. A megoldáshoz csak aritmetikai műveleteket használj. *Pl.: 12321 palindrom, de 12345 nem az.*

### Gyakorló feladatok

1. Határozd meg két egész számról, hogy barátságosak-e. Két egész szám barátságos, ha az egyik önmagánál kisebb osztóinak összege megegyezik a másikkal, és fordítva. *Pl.: 220 és 284*
2. Határozd meg, hogy egy adott szám prím-e. Írd ki 1000-ig a prímeket.
3. Add meg egy másodfokú egyenlet megoldásait.
> - Általános alak: *ax<sup>2</sup>+bx+c=0, ahol a,b,c∈ ℝ és a ≠ 0*
> - Ne felejtkezz el a megoldhatóság ellenőrzéséről!
4. Az opcionális feladatoknál kiírtuk különböző alaptípusok bájtban megadott méretét. Határozzuk meg ugyanezt az ezekre a típusokra mutató pointerek, illetve ilyen típusú elemeket tartalmazó tömbök esetében is.
