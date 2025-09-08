# 13. gyakorlat
A gyakorlaton a tavalyi év közbeni ZH megoldása lesz kicsit átírva. A tavalyi feladatkiírás: [pdf](./ImpProgZH_2023nov10.pdf)


## Elvárások a programmal szemben
- A programot tagold több fordítási egységre
- A program végleges verziójának működőképesnek kell lennie. **Forduljon és fusson!** A nem forduló kód **0 pontot ér!**
- Kerüld a nem definiált viselkedést okozó utasításokat! Ezekért pontlevonás jár.
- Logikusan tagold a megoldást! A megoldás részeit külön függvényekben valósítsd meg!
- Ne használj globális változókat! Legfeljebb a makrók megengedettek
- A megoldáshoz semmilyen segédeszköz nem használható, kivéve a [C referenciát](https://en.cppreference.com/w/c)
- Amely tömb esetében előfordulhat futás közbeni méretváltozás, ott használj dinamikus memóriakezelést! A kígyó méretét dinamikusan kezeld!
- A kígyó szegmenseinek reprezentálására használhatsz `struct`-ot
- A pálya dimenziót parancssori argumentumokban adjuk meg (tetszőleges méret lehet, de legyen azért értelmes méret, (pl. 3 < méret < 1000 minden oldalra))
- A begyűjtendő almák száma legyen a pálya méretének valamilyen függvénye, esetleg valami nehézség értéktől is függhet (pl.: Az összmezőszám 5%-a felfelé kerekítve)
- Hozz létre struktúrát ott, ahol logikusnak tartod. (Amikor mátrixot kell átadni paraméterül a dimenzióival együtt, létrehozhatsz egy struktúrát hozzá és azt adod át.)
- A kígyó mérete a játék során változik, ekkor update-eld a hosszt és megfelelően kezeld a memóriát.

---

## Egyszerű Snake játék

### Feladat leírása
Készítsd el a Snake játék leegyszerűsített verzióját! A játékos lépésenként irányíthatja a kígyót a játékmezőn, hogy a játék elején véletlenszerű pozíciókban megjelent almákat összegyűjtse, miközben igyekszik nem lefutni a pályáról, illetve nem összeütközni önmagával.

---

## Kötelezően megvalósítandó alprogramok

### Játéktér inicializálása – `init_field()` (7 pont)
- A játékteret egy **`height` x `width` karaktereket tároló "kétdimenziós" tömb** reprezentálja (ez legyen egy sorfolytonos egydimenziós tömbként létrehozva a memóriában).
- A feladatleírás szerint a `height` és a `width` paraméterei a játéktérnek parancssori argumentumként érkeznek. (Pl. `atoi` vagy `sscanf` segítségével alakítsd át `int`-re.)
- Helyezz el véletlenszerűen megfelelő számú almát a játéktéren! Ügyelj, hogy minden alma külön mezőre kerüljön. (Megfelelő szám pl.: 5%-a a mezők számának felfelé kerekítve.)
- Üres mező: `' '` (SPACE), alma: `'a'`.
- A függvény paraméterei:
  - A játékteret tároló mátrix (és a dimenziói).
  - Az almák száma. (Ha a méretből egyértelműen következik az almák száma, akkor ezt kihagyhatod.)

### Kígyó inicializálása – `init_snake()` (5 pont)
- A kígyó kezdetben legyen 5 egység hosszú. A koordinátákat kétféle módon tárolhatod:
  - Egy külön erre a célra létrehozott `struct`-okból álló tömbben **VAGY**
  - Egy a sorfolytonos tömbbeli koordinátákat tároló `int`-ekből álló tömbben.
- Kezdő pozíciók érvényesek legyenek! (Ha nincs más ötleted, az első sor első 5 eleme legyen. Ebben az esetben úgy legyenek a feltételek megadva a tábla méretére, hogy azok ehhez illeszkedjenek!)
- (Nem kell figyelni az almák helyzetére, az nem probléma, ha véletlenül pont rákerül a kígyó egy-egy szegmense az almára!)
- A függvény paramétere:
  - A kígyót tároló tömb,
  - A kígyó hossza (ezt ez a függvény állítsa be, így megfelelő módon add át paraméterül).

### Játék aktuális állapotának kirajzolása – `print_game()` (11 pont)
- Vizualizáció: másold le a játéktér mátrixot egy **munka mátrixra**.
- A kígyó fejét jelöld: `'8'`, testét: `'0'`.
- Rajzold ki a játékteret kerettel (`'#'`) és sarkokkal!
- A függvény paraméterei:
  - A játékteret tároló mátrix és dimenziói,
  - A kígyót tároló tömb és a hossza.

### Kígyó frissítése – `update_snake()` (17 pont)
- Frissítsd a kígyó testének koordinátáit.
- Ellenőrizd az alábbiakat és a függvény visszatérési értéke legyen a zárójelben lévő szám:
  - Pálya szélével való ütközés (-1)
  - Kígyó önmagával való ütközése (-2)
  - Alma begyűjtés (1)
  - Egyéb eset (0).
- Vezérlő karakterek: `'a'` (balra), `'s'` (lefelé), `'w'` (felfelé), `'d'` (jobbra).
- A függvény paraméterei:
  - A játékteret tároló mátrix és dimenziói,
  - A kígyót tároló tömb és hossza, (A hossz és a kígyót tároló tömb is update-elhetőként legyen átadva!)
  - Az elmozdulás iránya (karakter).

### Főprogram – `main()` (10 pont)
- Köszöntsd a játékost, és ismertesd a játékszabályokat röviden!
- Deklaráld a szükséges változókat és tárolókat.
- Hívd meg az inicializáló alprogramokat, és jelenítsd meg a kezdő állapotot.
- **Vezérlés**:
  - A játékos az `'aswd'` karakterekkel irányít, majd az <ENTER> lenyomásával lépteti a kígyót.
  - EOF megadásával kilépés.
  - Érvénytelen karakterek ignorálása.
  - A beolvasást `fgets` függvénnyel oldd meg egy `buffer` karaktertömbbe és a megadott karaktereken végigiterálva az értelmes karakterek vezérlését hajtsd végre. Ha több értelmes karakter van, akkor nem kell köztes állapotokat kiírni.
- Játék vége:
  - Alma begyűjtéskor frissítsd az almák számát.
  - Minden alma begyűjtése után gratulálj a játékosnak, és álljon le a program.

---

