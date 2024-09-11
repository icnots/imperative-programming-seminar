# 8. gyakorlat

## Gyakorlás a ZH-ra

A zárthelyi alatt egy programozási feladatot kell megoldani, legfeljebb **50 pont**ért. Legalább **10 pont**ot kell gyűjteni a tárgy sikeres teljesítéshez. A megoldásra **180 perc** áll rendelkezésre. A megoldáshoz semmilyen segédeszköz nem használható, kivéve a [C referenciát](https://en.cppreference.com/w/c). A végén csak az egy darab forráskódot (**.c** állomány) kell feltölteni.

### Elvárások a programmal szemben
- A program végleges verziójának működő képesnek kell lennie. Forduljon és fusson! A nem forduló kód **0 pont**ot ér!
- Ne használj globális változókat! Csak a makrók megengedettek!
- Logikusan tagold a megoldást! A megoldás részeit külön függvényekben valósítsad meg!
- Kerüld a nem definiált viselkedést okozó utasításokat! **A végleges programban ezek megléte pont levonással jár!**


### Torpedó 

A torpedó egy olyan kétszemélyes játék, amelyet egy 10 * 10-es táblán játszanak, a sorokat 1-től 10-ig számokkal, az oszlopokat A-tól J-ig betűvel jelölik. A játék elején el kell helyeznünk 5 hajót a táblán olyan módon, hogy a hajók semmilyen módon ne érintkezzenek, még sarkokkal se. Az elhelyezendő hajók hossza: 2, 3, 3, 4, 5 egység. A feladat egy tábla felállításának, a hajók elhelyezésének validációja.


### 10 pont

A programban a táblát reprezentálja egy kétdimenziós, egészeket tároló tömb, ahol a tábla magassága (tehát a sorok száma) és szélessége (az oszlopok száma) 10.  A szélességet és a magasságot makróként vegyük fel.

Ezen felül legyen egy tömbünk, amelyben az elhelyezett hajók számát tudjuk karbantartani (sorrendben a két, három, négy és öt hosszúságú elhelyezett hajók számát).

Írjuk meg az `init` függvényt, amelyet a játék kezdetekor hívunk meg. Ez a függvény üresre állítja a tábla minden “mezőjét” és a hajók számát tároló tömböt is.

Legyen a programban egy `printTable` nevű függvény, amely a tábla aktuális állapotát jeleníti meg a képernyőn.


### 25 pont

Írjuk meg a `submit` függvényt, amely a tömbökön kívül paraméterként megkapja, hogy milyen pozíción kezdődik az elhelyezendő hajó, mekkora a hossza, valamint azt, hogy vízszintesen vagy függőlegesen kell elhelyezni a hajót. A függvény ellenőrzi, hogy a hajó lehelyezhető-e a megadott helyre, elhelyezi a táblában, és valamilyen módon visszajuttatja a hívóhoz azt az információt, hogy sikeresen lehet-e elhelyezni a hajót a pályán. Ehhez ellenőrizni kell, hogy az elhelyezendő hajó megfelelő méretű-e, nem lóg-e le pályáról, és nem érintkezik-e korábban már elhelyezett hajóval. Feltehető, hogy a megadott pozíció valid, de azt ellenőrizni kell, hogy a hajó nem lóg-e ki a pályáról.

A `submit` függvényhez készíthetsz segédfüggvényeket, amelyek a feltételvizsgálatokat végzik el. A függvények írjanak ki hibaüzenetet, ha valamelyik feltétel nem teljesül, és ebben az esetben lépjenek tovább a következő inputra.

*Megjegyzés: a pozíció átadható szöveges formátumban, pl. “C4”, vagy “E10” formátumban, de akár két külön paraméterként, pl. ‘C’, 4 vagy ‘E’, 10.*


### 15 pont

A `main` függvényben az előzőleg ismertetett `init` és `submit` függvények meghívásával állíts össze többféle állást és döntsd el, hogy a torpedó pálya szabályosan van-e összeállítva, azaz megfelelően elhelyezett és megfelelő számú hajó van-e lerakva. Átfogóan teszteld az eseteket. A pálya állása legalább egyszer, a játék végén jelenjen meg a képernyőn.

Egy példa input, ahol _ jelöli a vízszintes, | a függőleges irányt:

{"A1",3,'|'}, {"I3",2,'\_'}, {"I3",3,'\_'}, {"F6",5,'|'}, {"F7",5,'|'},
{"A1",2,'\_'}, {"I4",4,'|'}, {"C3",4,'\_'}, {"G9",3,'\_'}, {"B5",3,'\_'},
{"I7",3,'|'}, {"J7",2,'|'}, {"J7",1,'|'}