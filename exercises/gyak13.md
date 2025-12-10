## Francia kártyapakli kezelése kétirányú láncolt listával

### A feladat leírása

Írj C nyelven egy programot, amely egy **francia kártyapaklit** kezel **kétirányú (duplán láncolt)** listaként.
A programnak lehetőséget kell biztosítania:

1. **Egy teljes francia kártyapakli létrehozására**

   * 52 lap:

     * színek: pikk, kör, káró, treff
     * értékek: A, 2–10, J, Q, K

2. **A pakli kétirányú láncolt listában való tárolására**

   * Minden kártya tartalmazza a kártya értékét és színét.
   * `prev` és `next` pointerek legyenek a következő és az előző kártyára mutató pointerrel.

3. **Lap húzására a pakli elejéről vagy végéről**

   * A felhasználó választhat: „top” (eleje) vagy „bottom” (vége).
   * A húzott lapot jelenítsd meg.

4. **A pakli tartalmának kiírására**

   * Mindkét irányban bejárható: előre vagy visszafelé.

5. **Memória felszabadítására kilépéskor**

### Követelmények

* Hozz létre egy `Card` struktúrát, amely tartalmazza:

  * a lap értékét (`char*` vagy enum)
  * a színt (`char*` vagy enum)
  * `struct Card* prev`
  * `struct Card* next`
  
* Implementálj külön függvényeket:

  * `is_empty()` - visszatér egy logikai értékkel, hogy a deck üres vagy sem
  * `deck_size()` - visszatér a deck lapjainak számával
  * `create_deck()` - létrehozza az összes lapot
  * `push_front()` és `push_back()` - kártya deckhez adása
  * `pop_front()` és `pop_back()` - lap húzása
  * `print_deck_forward()` - pakli kiírása az elejétől
  * `print_deck_backward()` - pakli kiírása a végétől
  * `free_deck()` - memória felszabadítása
  * `pop_front_index()` - A paraméterül kapott index által meghatározott lap húzása (k. lap, ha k a paraméter).
  
* A főprogramban legyen egy egyszerű menü:

  * 1: Lap húzása az elejéről
  * 2: Lap húzása a végéről
  * 3: Pakli kiírása elölről
  * 4: Pakli kiírása hátulról
  * 5: Új pakli kérése
  * 6: Valahanyadik kártya húzása elölről
  * 0: Kilépés
  
* Bónusz:

  * Csináljunk keverést a `pop_front_index` használatával és random számokkal!
  * Lehessen több lapot húzni és akkor kézbe kapjuk a kezünkben lévő decket!
  
 

