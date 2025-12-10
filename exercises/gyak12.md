# 12. gyakorlat.

## Demó feladat:

A program célja:
* Definiálni egy struktúrát egy személy adatainak tárolására (név és életkor).
* Beolvasni egy szöveges fájlból személyek adatait.
* Dinamikusan allokálni memóriát a beolvasott személyek számára.
* Kiírni a beolvasott adatokat a konzolra.
* Felszabadítani a dinamikusan allokált memóriát.

Példa bemeneti fájl:
```
Alice,30
Bob,25
Charlie,40
```
Dolgozzuk fel a bemeneti adatokat `stdin`-ről EOF-ig vagy amennyiben adottak parancssori argumentumok, akkor azok által meghatározott fájlokból (tehát több fájl az összes embert az összes fájlból beolvassuk). Hibás fájlokat hagyjuk ki. Feltehető, hogy nincsenek hibás sorok a fájlokban.
A végén összegezzük, hogy hány embert olvastunk be.

## Példa ZH (tavalyi ZH): Canvasban letölthető zip formában
