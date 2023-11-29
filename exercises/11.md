# 11. gyakorlat

## Dinamikus memóriakezelés

***Emlékeztető:***
- Fordítás közben használd a **-W, -Wall, -Wextra, -pedantic** kapcsolókat!
- A feladatokat headerekre és forrásfájlokra tagolva oldjuk meg!

### Kötelező feladatok

1. Írj egy programot, ami bekér a felhasználótól egy legfeljebb **20** karakter hosszú szöveget, és készít belőle egy másolatot. Ügyelj arra, hogy a másolat csak akkora memóriaterületet használjon, ami feltétlenül szükséges.
2. Készíts egy _`reverse()`_ nevű függvényt, aminek egy string paramétere van. A függvény fordítsa meg a string karaktereit helyben. Azaz függvény az eredményt ugyanazon a memóriaterületen adja vissza, amit paraméterként kapott. Például egy palindrom string karakterei nem változnak meg a függvényben.
3. Módosítsd az előző _`reverse()`_ nevű függvényt úgy, hogy ne helyben cserélje a karaktereket, hanem egy másik stringet hozzon létre, és azzal térjen vissza. Dinamikusan foglald a szükséges memóriát!
4. Írj programot, ami **5** szót olvas be a felhasználótól, és kiírja fordított sorrendben őket. Használj dinamikus tömböt! 
5. Írj egy programot, ami parancssori argumentumként vár egy számot, és annyi szót olvas be a felhasználótól, amennyit megadott. Ha mindet megadta, írja ki fordított sorrendben a szavakat. Használj dinamikus tömböt!
6. Módosítsd az előző feladat megoldását úgy, hogy ha a felhasználó az **end** szót írja be, akkor a beolvasás véget ér, mielőtt elérné a parancssori argumentumként megadott limitet. Használj dinamikus tömböt! Majd írd ki a tömb tartalmát fordított sorrendben.
7. Módosítsd az előző feladat megoldását úgy, hogy a program már nem kér be a felhasználótól parancssori argumentumot, hanem addig olvasunk be szavakat a felhasználótól, amíg nem **EOF** a bemenet, majd kiírja őket fordított sorrendben. Ha végzett a kiírással, újból várjon szavakat. Használj dinamikus tömböt! Ügyelj arra, hogy ne keletkezzen memóriaszemét.

### Opcionális feladatok

1. Készíts egy függvényt, ami egészek tömbjét várja paraméterül. A függvény térjen vissza egy másik tömbbel, amiben a paraméter tömb elemei szortírozva találhatók: elöl a párosak, hátul a páratlanok. Dinamikusan kezeld a memóriát!

### Gyakorló feladatok

1. Adott egy fájl, aminek minden sorában számok vannak szóközökkel elválasztva. Írj egy programot, mely soronként olvas ebből a fájlból, és minden sort növekvő számsorrendben kiír egy output.txt nevű fájlba. Dinamikusan kezeld a memóriát!
2. Írj programot, amely számontartja egy cég alkalmazottai a felvételük sorrendjében. Vegyél fel egy struktúrát, amely eltárolja az alkalmazott nevét és fizetését. A program futás közben folyamatosan kérjen be adatokat új alkalmazottakról, és minden "felvétel" után írja ki az összes alkalmazott adatait! A program fejezze be a futást, ha a felhasználó az **exit** szót írja be. Dinamikusan kezeld a memóriát! Ügyelj rá, hogy optimális legyen a dinamikus memóriafoglalás!
