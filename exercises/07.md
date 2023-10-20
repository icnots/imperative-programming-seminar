# 7. gyakorlat

## Tömbök, pointerek

***Emlékeztető:*** 
- Fordítás közben használd a **-W, -Wall, -Wextra, -pedantic** kapcsolókat!
- Használjuk segítségnek a hivatalos dokumentációt is: [C reference](https://en.cppreference.com/w/c)

### Kötelező feladatok 

1. Olvassunk be hexadecimális számokat a standard bemenetről (*0-9,a,b,c,d,e,f* karakterek), amíg `EOF` nem érkezik.
A beolvasott számokat konvertáljuk át 10-es számrendszerbe, majd tároljuk őket.
> - Használd ki a karakter-szám "átjárhatóságot"
> - Csak a megfelelő karaktereket fogadjuk el, minden mást vessünk el (nagybetű belefér) és jelezzük a hibát
> - `EOF` használata linuxban: **Ctrl+D**; windowsban: **Ctrl+Z** (**Enter**)
> - Jobb eszköz híján válasszunk egy "kellően" nagy tömböt a várható számok tárolásához
2. Készíts egy alprogramot, amely egy paraméterben kapott nxn-es mátrixot feltölt az n-es szorzótábla értékeivel. Majd írasd ki a főprogramban az egészet a standard kimenetre a következő formátumban: *a x b = c*, ahol *a* és *b* a szorzandó elemek, *c* pedig a mátrixban tárolt érték.
3. Írj programot, amely 1-től n-ig kiszámolja a pozitív számok összegét. *n*-et olvasd be a standard inputról, ad át a paramétert egy alprogramnak, mely visszatér az eredménnyel.
4. Írj programot, amely kiírja egy szám első n hatványát! A számot olvasd be a standard inputról.
5. Írj programot, amely megcseréli egy legalább *3* jegyű szám első és utolsó számjegyét!
> - Tetszőleges sok számjegyű számra működjön!
6. Készíts egy alprogramot, mely feltölt egy kapott tömböt 0 és 100 közötti véletlen valós értékekkel. Ezután a főprogram állapítsa meg a tömbről, hogy hány eleme nagyobb 50-nél.


### Gyakorló feladatok

1. Olvass be egy számot, és számítsd ki a számjegyeinek szorzatát!
2. Az előző feladathoz írd ki, hogy hány páros és páratlan számjegye van a számnak!
3. Találd meg és írd ki a képernyőre az összes Armstrong-számot 0 és N között. *N*-et olvasd be a standard inputról. Armstrong-számnak nevezünk egy *n* jegyű számot, ha minden számjegyét az *n*-edik hatványra emelve és összeadva, az eredeti számot kapjuk.
> - *Például a 153 esetében 153=1^3+3^3+5^3*.
4. Írj alprogramot, amely kiszámítja egy egész szám faktoriálisát! Milyen korlátai vannak a megoldásnak?


### Haladó feladatok

1. Rajzold ki a Pascal háromszög első n sorát (n-et kérd be)! A 3. gyakorlattal ellentétben, most ne a képletet (n alatt k) használd, hanem segéd tömbök segítségével old meg és törd át a korábban jelentkező ábrázolási korlátot!
2. Írj két függvényt, melyek egymást felváltva futnak. Az egyik, nevezzük a-nak, 2-vel osztja a paraméterként kapott értéket majd meghívja a b függvényt az eredménnyel, ha az nagyobb mint 0. A b függvény kivon 1-et a kapott értékből majd meghívja a-t a csökkentett értékkel, ha az még nagyobb mint 0. A kiinduló számot a felhasználótól kérd be, és számold, hány a-b iteráció történik, míg eléri a 0-át.
3. Tárolj el egy 4x4 mátrixban egy balra igazított karakterekből álló háromszöget. (Lásd a példát lent.) A felhasználó adhasson meg 1-től 4-ig egy értéket, mellyel szabályozhatja, hogy a háromszöget milyen orientációval rajzoljuk ki a kimenetre. (Balos, balos fejtetőn, jobbos, jobbos fejtetőn.) Kerüljük a kódismétlést! Egyetlen dupla ciklus segítségével old meg a kirajzolásokat!
> - &
> - && 
> - &&&
> - &&&&


