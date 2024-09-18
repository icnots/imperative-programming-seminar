# 1. Gyakorlat, példaprogramok

## Parancssor használata:

### Current working directory
A parancssorunk mindig egy aktuális könyvtárban áll.
Ennek könyvtárnak teljes elérési útjának kiírásához a `pwd` parancsot használhatjuk.

### Adott könyvtár tartalmának listázása
Az adott könyvtárunk tartalmának kiírásához az `ls` parancsot használjuk.
Ennek különböző kapcsolóit néztük meg:
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
