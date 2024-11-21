# 1. Gyakorlat, példaprogramok

## Parancssor használata:

### Current working directory
A parancssorunk mindig egy aktuális könyvtárban áll.
Ennek könyvtárnak teljes elérési útjának kiírásához a `pwd` parancsot használhatjuk.

### Adott könyvtár tartalmának listázása
Az adott könyvtárunk tartalmának kiírásához az `ls` parancsot használjuk.
Ennek különböző kapcsolóit néztük meg:o
* `ls -l`: hosszabb formában írja ki a mappa tartalmát, jogosultságokkal, létrehozási dátumokkal együtt
* `ls -a`: minden "el-hide-olt" mappát is kiír:
  * `./`: az aktuális mappára mutat, ezzel tudunk saját programot futtatni, amely nincs hozzáadva az operációs rendszer parancsaihoz
  * `../`: az aktuális mappa feletti könyvtárra mutat, ezzel tudunk hivatkozni a feljebb levő könyvtárra
  
### Könyvtár létrehozása
Az aktuális könyvtárunkban új könyvtárat `valami` névvel az `mkdir valami` paranccsal tudunk létrehozni.

### Aktuális könyvtár megváltoztatása
Az aktuális könyvtárunkat a `cd` (change directory) paranccsal tudjuk megváltoztani. Ennek paraméteréül meg kell adni, hogy hova szeretnénk megváltoztatni az aktuális könyvtárat. Ha nincs paraméter megadva, a felhasználónk home könyvtárába ugrik.
* `cd valami`: az aktuális könyvtáron belüli `valami` nevű könyvtárba próbál meg belelépni.
* `cd ..`: az eggyel felettünk lévő könyvtárba lép bele
* `cd ../..`: a kettővel felettünk lévő könyvtárba lép bele

### Szövegfájl tartalmának kiírása konzolra
Egy adott szöveges fájl (`valami.txt`) kiírása a konzollal legegyszerűbben a `cat valami.txt` paranccsal tehető meg.

### Másolás
A fájlokat másolni a `cp` paranccsal tudunk. Ennek használatakor több paramétert is meg kell adni. Az utolsó a másolási név, amely ha `/` karakterrel fejeződik be, akkor kiegészül az eredeti névvel. Az előtte lévő paraméterek a másolni kívánt fájlok nevei.
* `cp valami.txt mappa/`: bemásolja a `valami.txt` fájlt a `mappa` nevű könyvtárba
* `cp valami.txt masvalami.txt`: bemásolja a `valami.txt` fájlt a `masvalami.txt` nevű fájlba
* `cp valami1.txt valami2.txt ../`: bemásolja a `valami1.txt` és `valami2.txt` nevű fájlokat az eggyel felettünk lévő könyvtárba.

Ez a parancs felül tud írni fájlokat és mappákat is, így óvatosan használd!

### Áthelyezés
Áthelyezni és átnevezni az `mv` paranccsal tudunk.
Ugyanolyan a paramétereinek használata mint a `cp`-nél, csak az eredménynél a kiindulási fájlok eltűnnek (átneveződnek).
* `mv valami.txt mappa/`: áthelyezi a `valami.txt` fájlt a `mappa` nevű könyvtárba
* `mv valami.txt masvalami.txt`: átnevezi a `valami.txt` fájlt a `masvalami.txt` nevűre
* `mv valami1.txt valami2.txt ../`: áthelyezi a `valami1.txt` és `valami2.txt` nevű fájlokat az eggyel felettünk lévő könyvtárba.

Ez a parancs felül tud írni fájlokat és mappákat is, így óvatosan használd!

### Törlés
Törölni az `rm` paranccsal tudunk (remove). Könyvtárak törlésénél rekurzívan meg kell hívnunk a parancsot a könyvtár tartalmára is, ezért ott a `-r` kapcsolót is használjuk.

## C példaprogramok

### C program

C programozási nyelven a programjaink függvényekből állnak. Ezen függvények belsejében történik a program végrehajtása. Az adatok tárolására változókat fogunk használni, a függvények közti paraméteráramlást paraméterekkel oldjuk meg.

### `main`

A programunk futása a `main` függvénnyel kezdődik, amelynek a visszatérési értéke `int` típusú és a paramétere a parancssori argumentumoknak felel meg, amelyeket később tárgyalunk.

A `main` függvényen kívül tetszőleges számú saját függvényt létrehozhatunk. C nyelven nem megengedett, hogy két függvénynek azonos legyen a neve, így mindenképpen különböző nevekkel kell ellátnunk a függvényeinket.
Minden programban kell lennie pontosan egy `main` nevű függvénynek, különben nem tud megtörténni a fordítás teljes egészében, nem tud elkészülni a futtatható állomány.

#### Paraméterek

A paraméterek lokális változóként viselkednek annyi különbséggel, hogy a függvény hívásakor inicalizálódnak a paraméterek meghívott értékével.

### Első program

A legegyszerűbb C program, amely fordítható, egy üres `main` függvényt tartalmaz:
```C
int main(){
    return 0;
}
```
A program a 0 visszatérési érték egy konvencionális érték, amellyel a program helyes futását jelezzük.

A programot a `main.c` forrásfájlba helyezve a következő paranccsal fordítható `gcc`-vel:

`gcc main.c`

Ez a parancs végrehajtja a fordítás preprocessing, compilation, linking részét is, így elkészülhet a futtatható, default-ként `a.out` vagy `a.exe` nevű állományunk.

### Hello World

A legegyszerűbb program, amely kiír valamit, a `printf` függvényt fogja használni, amely a standard input/output könyvtárban található meg, így a használatához be kell include-olnunk ezt a könyvtárt hozzá:
```C
#include <stdio.h>

int main(){
    printf("Hello World\n");

    return 0;
}
```
Feltételezve, hogy ez a tartalma a `hello.c` forrásfájlnak, a `gcc hello.c -o hello.out` paranccsal tudjuk lefordítani és a `hello.out` futtatható állományt létrehozni. A futtatható állomány nevét a `-o` kapcsolóval tudjuk beállítani a `gcc` fordítóprogramban.
