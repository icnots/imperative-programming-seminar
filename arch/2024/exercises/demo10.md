# 10. gyakorlat

## Dinamikus memóriakezelés

### Univerzális pointer

Amikor egy memóriaterületről nem tudjuk, hogy milyen típusú adatot tartalmaz, az univerzális pointert, `void *` pointert használunk. Ezzel fogjuk függvényeknél jelezni, hogy valamilyen memóriaterületre mutató pointerrel térünk vissza vagy adunk paraméterül egy ugyanilyen területet.

### Memória

A memóriára úgy gondolunk, mint valami hosszú bájtsor a gépben, amelynek minden bájt részének van egy sorszáma, ez a memóriacím. A programunk futása során többféle memóriát használunk.
* A futtatási verem (stack) memória tárolja el az automatikus élettartamú változókat és a paramétereket. Ez a függvények futtatásából fakadóan egyértelműen tudható, hogy mikor melyik változónak van elérhetősége és melyiknek nincs.
* A másik memóriaterület, amivel most ismerkedünk meg, a heap memóriaterület. Ez valahol függetlenül a stack-től található meg a memóriában. Alapvető tulajdonsága, hogy az itt lefoglalt és használt memóriaterületet külön függvényekkel kezeljük, viszont a függvények futásától függetlenül rendelkezik élettartammal, így a programozás során kell figyelnünk arra, hogy mely változó érhető el, melyik nem. Amennyiben nem törlünk ki használaton kívüli memóriát, akkor az memóriaszemetet fog jelenteni a program futása során és csak a program végén, az operációs rendszer szabadítja fel. A terület nincs inicializálva, így a lefoglalás után gondolnunk kell az inicializálásra.

### Dinamikus memóriakezelés függvényei:

A dinamikus memóriakezeléshez tartozó függvények az `stdlib.h` header-ben találhatóak meg, így ezt kell include-olni a forrásfájlok elején, ahol ezeket használni szeretnénk.

* `void *malloc(size_t size);`
  * Ez a függvény lefoglal a heap-en `size` mennyiségű bájtot folytonosan, majd sikeres foglalás esetén visszatér a kezdő memória címével, sikertelen esetén `NULL` pointerrel tér vissza. (Emiatt ellenőrizni kell a függvényhívás után, hogy sikeres volt-e a memóriafoglalás.)
  * Mivel univerzális pointerrel tér vissza, általában explicit jelezzük, hogy milyen pointert jelent a kódunkban.
  * A folytonos memóriafoglalás volta miatt úgy kezeletjük ezt a területet mint egy tömb!
  * A memóriaterület nem inicalizálódik!

Pl.:
```C
    int *t;
    t = (int *)malloc(3 * sizeof(int)); // 3 elemű intekből álló tömb létrehozása
    if (!t){
        return 1; // ha nem sikeres a memóriafoglalás, akkor lépjen ki a program. Ellenkező esetben seg. fault-ot dobna a *t
    }
    t[0] = 10; // úgy használhatjuk mint egy tömböt.
    t[1] = t[0]+1;
    t[2] = t[2] + t[1];
    
    double *d = (double *)malloc(sizeof(double)); // 1 elemű double-ból álló tömb
    if (!d){
        return 1; // ha nem sikeres a memóriafoglalás, akkor lépjen ki a program. Ellenkező esetben seg. fault-ot dobna a *d
    }
    *d = 12.3; // értékadás során úgy használjuk mint egy tömböt!
    d[0] = 12.3; // ekvivalens az eggyel felettünk lévő sorral.
```

* `void free(void *ptr);`
  * A memóriaterület felszabadítását végző függvény. Hívása után a memóriaterület nem lesz elérhető számunkra.
  * Beépítetten tudja a felszabadítandó memóriaterület méretét! Tehát ezzel nem kell a programozónak foglalkoznia.
  
* `void *realloc(void *ptr, size_t size);`
  * Kiegészíti (vagy csökkenti) a `ptr` által meghatározott már korábban lefoglalt memóriaterületet `size` bájtnyi méretűre.
  * Ugyanúgy működik a visszatérési értéke mint a `malloc` függvénynek.
  * Amennyiben nem fér el a heap-en a kívánt méretű tömb, az egészet áthelyezi máshova, tehát az értékek bennmaradnak.
  
A többi függvényt nem fogjuk alapvetően használni, amennyiben valakit érdekel, a `calloc` függvényről egy [példa](https://www.tutorialspoint.com/c_standard_library/c_function_calloc.htm).

## Az órai demo feladat példamegoldása:

```C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 51

int main(void){
    int n;
    char buffer[BUFFERSIZE];
    
    fgets(buffer, BUFFERSIZE, stdin);
    sscanf(buffer, "%d", &n);
    
    char **t; // pointer for the array
    t = (char **)malloc(n * sizeof(char *));
    if (t){
        for (int i = 0; i < n; i++){
            printf("%d: ", i+1);
            fgets(buffer, BUFFERSIZE, stdin);
            
            int len = strlen(buffer) + 1;
            t[i] = (char *)malloc(len * sizeof(char));
            
            if (t[i]){
                strcpy(t[i], buffer);
            }else{
                fprintf(stderr, "Not enough memory\n");
                return 0;
            }
        }
        
        printf("Reversed order:\n");
        for (int i = n-1; i >= 0; i--){
            printf("%d: %s\n", i+1, t[i]);
        }
        
        for (int i = 0; i < n; i++){
            free(t[i]);
        }
        free(t);
    }else{
        fprintf(stderr, "Not enough memory\n");
    }
    
    return 0;
}
```
