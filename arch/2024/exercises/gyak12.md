# 12. gyakorlat

## Verem, Láncolt lista

***Emlékeztető:***
- Fordítás közben használd a **`-W -Wall -Wextra -pedantic`** kapcsolókat!
- A feladatokat headerekre és forrásfájlokra tagolva oldjuk meg!

### Kötelező feladatok
> A mai gyakorlaton egy programot fogunk írni, amelynek különböző funkcióit sorban fogjuk megvalósítani. Készíts hozzá külön fordítási egységet, amelyben az adatszerkezet függvényeit fogod megvalósítani és egy `main` főprogramot is, amelyben kipróbálod a már megírt függvényeket!

1. Valósítsunk meg egy olyan verem adatszerkezetet, amiben "dobozokat fogunk tudni egymásra pakolni". Ehhez hozzunk létre egy `Box` nevű struktúrát, ami rendelkezik egy egész szám típusú súly értékkel (`weight`) és egy Box struktúrára mutató pointerrel (`next`).
2. Hozzunk létre egy globális pointer változót a Box struktúrából (`top`). Írjuk meg az `initialize()` függvényt, amely `NULL`ra állítja a top változót. A `main()` függvényben hívjuk meg az `initialize()`-t!
3. Írjuk meg az `is_empty()` függvényt, amely visszaadja, hogy üres-e a stack vagy sem. (A stack akkor üres, ha a top változó `NULL` pointer.)
4. Írjuk meg a `peek()` függvényt, ami a jelenlegi legfelső Box súlyával tér vissza. (Ne feledkezzünk meg arról az esetről, amikor a stack üres!)
5. Írjuk meg a `push()` függvényt, ami egy egész számot kap paraméterül, ez lesz a következő doboz súlya. Hozzunk létre egy új elemet a heap-en, és állítsuk be a súlyát. Az új elem `next` adattagja az előző adattagra mutasson! A `top` változó mutasson az új elemre.
6. Írjuk meg a `pop()` függvényt, ami felszabadítja a verem tetején lévő elemet, és a top változót az eggyel alatta lévőre állítja. (Ne feledkezzünk meg az üres stack lehetőségéről sem!)
7. Írjuk meg a `copy_top()` függvényt, amely lemásolja a verem legfelső elemét, és a verem tetejére helyezi a másolatot. Nézzük meg, mi történik, ha csak a legfelső elemre mutató pointert másoljuk le, illetve ha új memóriaterületet allokálunk a másolatnak, és adattagonkénti másolást végzünk!

### Opcionális feladatok

1. Készítsünk el egy `Person` nevű struktúrát, amely tartalmaz (legalább) egy név és egy életkor értéket. A nevet egy `char[30]`-ban, az életkort pedig egy `int*` által hivatkozott memóriaterületen tároljuk el. A struktúra kényelmes használata érdekében alkalmazzunk típus alias-ozást.
2. A main függvényen belül hozzunk létre egy Persont, melynek beállítjuk az adatait. Hozzunk létre egy újabb Persont, ami értékül kapja az első Persont. (*pl: p2 = p1;*)
3. Írassuk ki a standard outputra a két Person értékeit. Módosítsuk az első Person életkorát. Ismét írjuk ki a két Person adatait. Miért változik meg a második Person életkorának adata? (*shallow copy*)
4. Javítsuk ki a programunkat úgy, hogy a Personok közötti értékadás helyett a konkrét mutatott értékeket másoljuk ki (*deep copy*). Ismét futtassuk le a programot, és demonstráljuk, hogy az első Person életkorának adatainak módosításával már nem változik meg a második Person életkora.

### Gyakorló feladatok

1. A kötelező feladat tapasztalatai alapján készítsünk egy saját két irányú láncolt lista implementációt.
    - Egy listaelemnek három mezője lesz: a tárolt adat, egy előző listaelemre mutató pointer valamint egy következő listaelemre mutató pointer. (Ha valamelyik elem nem létezik, akkor `NULL` pointer.)
    - Két kitüntetett pointer kell számontartani az első elemre mutatót (`First`) és az utolsó elemre(`Last`) mutatót
    - A következő alprogramokat szükséges implementálni:
        - `init()`: láncolt lista inicializálása
        - `is_empty()`: üres-e a láncolt lista
        - `add_first()`: Lánc bővítése az elején. A paraméter által meghatározott érték által létrejövő láncelem lesz a lánc új első eleme.
        - `add_last()`: Lánc bővítése a végén. A paraméter által meghatározott érték által létrejövő láncelem lesz a lánc új utolsó eleme.
        - `remove_first()`: Lánc első elemének eltávolítása. A metódus hívása után a második láncelem lesz az új első.
        - `remove_last()`: Lánc utolsó elemének eltávolítása. A metódus hívása után az utolsó előtti láncelem lesz az új utolsó.

2. Fejlesszük tovább a két irányú láncolt lista adatszerkezetünket a további alprogramokkal:
    - `find()`: Megkeresi a paraméter által meghatározott értékhez tartozó első láncelemet és visszatér egy rámutató pointerrel.
    - `find_last()`: Megkeresi a paraméter által meghatározott értékhez tartozó utolsó láncelemet és visszatér egy rámutató pointerrel.
    - `remove_act()`: Törli a paraméterben megadott láncelemet. A törlendő elem szomszédjait előtte összeköti, hogy a lánc folytonos maradjon.
    - `add_after()`: A lánc bővítése az első paraméter által meghatározott láncelem után. A második paraméter az új láncelem értékét határozza meg.
    - `add_before()`: A lánc bővítése az első paraméter által meghatározott láncelem előtt. A második paraméter az új láncelem értékét határozza meg.

3. Teszteljük az elkészült láncolt listát
