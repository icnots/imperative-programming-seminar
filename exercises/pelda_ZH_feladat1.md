# Feladat: Fordított szövegkezelő (C nyelven)

A feladatod egy olyan program elkészítése, amely képes több szöveges állományt beolvasni, azokat a memóriában dinamikusan tárolni, majd a tartalmukat ``duplán megfordítva'' (a fájlbeli sorok sorrendjét, és a karakterek sorrendjét is sorokon belül) megjeleníteni.

## Elvárások a programmal szemben

* 
**Segédeszközök:** Csak a [C referencia](https://en.cppreference.com/w/c) használható.


* **Működőképesség:** A programnak fordulnia és futnia kell. A nem forduló kód 0 pontot ér! 


* 
**Globális változók:** Használatuk tilos, csak makrók megengedettek.


* 
**Kódminőség:** Törekedj az áttekinthető kódolásra, használj indentálást és kerüld a kódismétlést.


* 
**Memóriakezelés:** Ne foglalj felesleges memóriát, és minden dinamikusan foglalt területet szabadíts fel a program végén (kerüld a memóriaszivárgást).


* 
**Modularitás:** Logikusan tagold a megoldást függvényekre és fájlokra.



---

## 1. Rész: Adatszerkezet és beolvasás (20 pont)

### Reprezentáció

Hozzon létre egy `FileContent` struktúrát, amely egy fájl tartalmát reprezentálja! A struktúra tárolja el:

1. A fájl sorait egy dinamikusan foglalt sztring-tömbben (`char**`).
2. A sorok számát. (Esetlegesen más segítő változókat is.)

### Beolvasás függvény

Készítsen egy függvényt, amely paraméterként kap egy `FILE *stream`-et, és visszatér egy feltöltött `FileContent` struktúrával!

* A sorokat dinamikusan tárolja el. Minden sorhoz pontosan annyi memóriát foglaljon, amennyi szükséges.

---

## 2. Rész: Megfordítás és kiírás (20 pont)

### Karakterek megfordítása

Készítsen egy függvényt, amely egy karaktertömböt (sztringet) helyben megfordít (pl. "alma" -> "amla").
(Esetleg más algoritmussal is elfogadható!)
Figyeljen az újsor karakterek kezelésére! (Ennek nem kell a sor elejére kerülnie!)

### Tartalom megjelenítése

Készítsen egy függvényt, amely egy `FileContent` struktúrát kap paraméterül, és a következő módon írja ki a tartalmát:

* A sorokon hátulról előre haladva menjen végig.
* Minden egyes sort fordítson meg karakterenként a kiírás előtt.

---

## 3. Rész: Felszabadítás és `main` (10 pont)

### Memóriakezelés

Készítsen egy függvényt, amely egy `FileContent` struktúra összes dinamikusan foglalt memóriaterületét felszabadítja.

### Főprogram (Main)

A `main` függvény valósítsa meg a vezérlési logikát:
* A függvény nyissa meg a fájlt. Ha a fájl nem nyitható meg, jelezze ezt a hívónak (pl. nullázott mezőkkel), és a program lépjen a következő fájlra.

1. Dolgozza fel a parancssori argumentumokat.
2. Nyissa meg a fájlokat, amennyiben sikeres a megnyitás, akkor olvassa be a fájlokat egy dinamikusan foglalt `FileContent` tömbbe az első részben adott függvénnyel.
3. Ha nem érkezett egyetlen argumentum sem, olvasson az `stdin`-ről EOF beolvasásáig.
4. Hajtsa végre a fordított kiírást az összes sikeresen beolvasott tartalomra, a sikertelenekre írjon hibaüzenetet a fájl nevével.
5. Szabadítson fel minden lefoglalt memóriát a kilépés előtt.



---

### Példa a működésre

Ha a `teszt.txt` tartalma:

```
Elso sor
Masodik sor
...
```

A futtatás eredménye (`./program teszt.txt`):

```
...
ros kidosaM
ros oslE
```

