# 9. gyakorlat

## Fájlkezelés

* A legegyszerűbb egy online útmutatót használni, hogy ezt gyorsan megértsétek, de néhány dolgot én is leírok itt. Például: [Geeksforgeeks](https://www.geeksforgeeks.org/basics-file-handling-c/)

A fájlokat egy `FILE` nevű makróval fogjuk tudni kezelni, amely az `stdio.h` headerben található meg, tehát ezt include-olni kell, amikor fájlkezelést akarunk végrehajtani.
A fájlokat egy ilyen típusra mutató pointerrel fogjuk kezelni, eltárolni. Tehát egy fájl például egy `FILE *fp` változóval kezelhetőek le.
Ez erőforráskezelésnek minősül, úgyhogy minden fájl megnyitáshoz kell tartoznia egy becsukásnak is, valamint ellenőrizni kell, hogy sikeres volt-e a fájl megnyitása.
A `valami.txt` nevű fájlhoz a megnyitás az `fopen` függvénnyel nyitható meg.
* Ez a megnyitás egy `FILE *` típusú pointerrel fog visszatérni, amelyet elmentünk egy fájlba.
* A második paraméter megadja, hogy milyen módban nyitjuk meg. Ez alapvetően háromféle lesz:
  * `"w"` írás
  * `"r"` olvasás
  * `"a"` appendolás, hozzáírás a fájlhoz
Tehát a fájl megnyitása így néz ki olvasásra való megnyitáskor:
```C
    FILE *fp;
    fp = fopen("valami.txt", "r");
```
A megnyitás után ellenőrizni kell, hogy sikeres volt-e a megnyitás:
```C
#include <stdio.h>
#define BUFFERSIZE 50

int main(){
    FILE *fp;
    fp = fopen("valami.txt", "r");

    if (NULL != fp){
        // Itt olvashatunk az fp pointerből
        int n;
        fscanf(fp, "%d", &n); // ugyanúgy használjuk mint a scanf függvényt, csak az első paraméternek berakjuk a FILE * pointert
        
        char buffer[BUFFERSIZE];
        // az fgets biztonságosan, legfeljebb BUFFERSIZE-1 karaktert olvas a fájlból, így ezt ajánlom használatra.
        // a -1 azért van, mert a lezáró '\0' karakter kerül a végére!
        while (NULL != fgets(buffer, BUFFERSIZE, fp)){
            // Itt BUFFERSIZE-1 méretenként beolvasunk a fájlból
            // Használhatjuk a buffer-ünket itt úgy, ahogy akarjuk.
        }
        
        fclose(fp);
    }
    
    return 0;
}
```

Írásra hasonlóan a `printf`-hez az `fprintf` függvény használható, amely első paraméterül kapja, hogy hova írjon.
```C
#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen("valami.txt", "w"); // ez létrehozza a fájlt, ha nem létezett, és ha létezett, felülírja üres fájllal!
    
    if (NULL != fp){
        // Itt írhatunk az fp pointerbe
        int n = 12;
        fprintf(fp, "%d\n", n); // ugyanúgy használjuk mint a printf függvényt, csak az első paraméternek berakjuk a FILE * pointert
        
        fclose(fp);
    }
    
    return 0;
}
```
